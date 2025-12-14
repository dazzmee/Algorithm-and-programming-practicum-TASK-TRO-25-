// Simple Win32 GUI Calculator
// Build with CMake; target is a WIN32 application (no console).

#define UNICODE
#include <windows.h>
#include <string>
#include <vector>
#include <sstream>
#include <cmath>

// UI constants
static const int WINDOW_WIDTH = 360;
static const int WINDOW_HEIGHT = 520;

struct Button { std::wstring label; RECT rc; };

// Calculator state
static std::wstring currentInput = L"0";
static double accumulator = 0.0;
static wchar_t pendingOp = 0; // '+', '-', '*', '/'
static bool newInput = true; // start new input after operator

std::vector<Button> buttons;

void initButtons()
{
    buttons.clear();
    // grid: 4 columns x 5 rows
    int cols = 4, rows = 5;
    int margin = 12;
    int btnW = (WINDOW_WIDTH - margin*2 - (cols-1)*8) / cols;
    int btnH = (WINDOW_HEIGHT - 140 - margin*2 - (rows-1)*8) / rows;

    std::vector<std::wstring> labels = {
        L"C", L"/", L"*", L"<-",
        L"7", L"8", L"9", L"-",
        L"4", L"5", L"6", L"+",
        L"1", L"2", L"3", L"=",
        L"0", L".", L"", L""
    };

    int idx = 0;
    for(int r=0;r<rows;r++){
        for(int c=0;c<cols;c++){
            int x = margin + c*(btnW+8);
            int y = 120 + margin + r*(btnH+8);
            RECT rc = { x, y, x+btnW, y+btnH };
            Button b{ labels[idx++], rc };
            buttons.push_back(b);
        }
    }
    // Make the bottom-left '0' wide (span two columns)
    buttons[16].rc.right = buttons[17].rc.right;
    buttons[17].label = L"."; // ensure label correct
}

double applyOp(double a, double b, wchar_t op)
{
    if(op==L'+') return a+b;
    if(op==L'-') return a-b;
    if(op==L'*') return a*b;
    if(op==L'/') return b==0.0 ? NAN : a/b;
    return b;
}

void pressButton(const std::wstring &lab, HWND hwnd)
{
    if(lab==L"C"){
        currentInput = L"0";
        accumulator = 0.0;
        pendingOp = 0;
        newInput = true;
        InvalidateRect(hwnd, NULL, TRUE);
        return;
    }
    if(lab==L"<-"){
        if(currentInput.size()>1) currentInput.pop_back(); else currentInput = L"0";
        InvalidateRect(hwnd, NULL, TRUE);
        return;
    }
    if(lab==L"="){
        if(pendingOp){
            try{
                double v = _wtof(currentInput.c_str());
                double res = applyOp(accumulator, v, pendingOp);
                std::wostringstream ss; ss.precision(12);
                ss<<res;
                currentInput = ss.str();
                accumulator = res;
            }catch(...){ currentInput = L"Error"; }
            pendingOp = 0;
            newInput = true;
            InvalidateRect(hwnd, NULL, TRUE);
        }
        return;
    }
    // operators
    if(lab==L"+" || lab==L"-" || lab==L"*" || lab==L"/"){
        double v = _wtof(currentInput.c_str());
        if(pendingOp){
            accumulator = applyOp(accumulator, v, pendingOp);
        } else {
            accumulator = v;
        }
        pendingOp = lab[0];
        newInput = true;
        std::wostringstream ss; ss<<accumulator; currentInput = ss.str();
        InvalidateRect(hwnd, NULL, TRUE);
        return;
    }
    // digit or dot
    if((lab.size()==1 && iswdigit(lab[0])) || lab==L"."){
        if(newInput || currentInput==L"0"){
            currentInput = L"";
            newInput = false;
        }
        if(lab==L"."){
            if(currentInput.find(L'.')==std::wstring::npos) currentInput += L'.';
        } else {
            currentInput += lab;
        }
        if(currentInput.empty()) currentInput = L"0";
        InvalidateRect(hwnd, NULL, TRUE);
        return;
    }
}

void drawRoundedRect(HDC hdc, RECT rc, COLORREF color, int radius)
{
    HBRUSH br = CreateSolidBrush(color);
    // Use RoundRect for simple rounded corners
    HRGN rgn = CreateRoundRectRgn(rc.left, rc.top, rc.right, rc.bottom, radius, radius);
    FillRgn(hdc, rgn, br);
    DeleteObject(rgn);
    DeleteObject(br);
}

LRESULT CALLBACK WndProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
    switch(msg){
    case WM_CREATE:
        initButtons();
        return 0;
    case WM_SIZE:
        // Re-init buttons if window resized? Keep fixed layout for simplicity
        return 0;
    case WM_LBUTTONDOWN:{
        int x = LOWORD(lParam), y = HIWORD(lParam);
        for(auto &b : buttons){
            if(x>=b.rc.left && x<b.rc.right && y>=b.rc.top && y<b.rc.bottom){
                if(!b.label.empty()) pressButton(b.label, hwnd);
                break;
            }
        }
        return 0;
    }
    case WM_PAINT:{
        PAINTSTRUCT ps;
        HDC hdc = BeginPaint(hwnd, &ps);

        // double buffering
        RECT client; GetClientRect(hwnd, &client);
        int w = client.right - client.left;
        int h = client.bottom - client.top;
        HDC mem = CreateCompatibleDC(hdc);
        HBITMAP hbmp = CreateCompatibleBitmap(hdc, w, h);
        SelectObject(mem, hbmp);

        // Background
        HBRUSH bg = CreateSolidBrush(RGB(245,248,250));
        FillRect(mem, &client, bg);
        DeleteObject(bg);

        // Display area
        RECT disp = {12, 12, w-12, 100};
        drawRoundedRect(mem, disp, RGB(250,250,255), 12);

        // Display text
        SetBkMode(mem, TRANSPARENT);
        HFONT hFont = CreateFontW(28,0,0,0,FW_BOLD,0,0,0,DEFAULT_CHARSET,OUT_DEFAULT_PRECIS,
            CLIP_DEFAULT_PRECIS,CLEARTYPE_QUALITY,VARIABLE_PITCH,L"Segoe UI");
        HFONT hOld = (HFONT)SelectObject(mem, hFont);
        SetTextColor(mem, RGB(40,40,40));
        // Right align
        RECT textRc = disp; textRc.left += 12; textRc.right -= 12;
        DrawTextW(mem, currentInput.c_str(), -1, &textRc, DT_SINGLELINE | DT_VCENTER | DT_RIGHT);
        SelectObject(mem, hOld); DeleteObject(hFont);

        // Draw buttons
        HFONT btnFont = CreateFontW(20,0,0,0,FW_SEMIBOLD,0,0,0,DEFAULT_CHARSET,OUT_DEFAULT_PRECIS,
            CLIP_DEFAULT_PRECIS,CLEARTYPE_QUALITY,VARIABLE_PITCH,L"Segoe UI");
        HFONT oldBtnFont = (HFONT)SelectObject(mem, btnFont);

        for(auto &b : buttons){
            // button background
            COLORREF fill = RGB(235,241,246);
            if(b.label==L"=") fill = RGB(150,200,170);
            if(b.label==L"C") fill = RGB(250,180,180);
            drawRoundedRect(mem, b.rc, fill, 10);

            // label
            RECT lab = b.rc; lab.left += 8; lab.right -= 8;
            SetTextColor(mem, RGB(30,30,30));
            DrawTextW(mem, b.label.c_str(), -1, &lab, DT_SINGLELINE|DT_VCENTER|DT_CENTER);
        }

        SelectObject(mem, oldBtnFont); DeleteObject(btnFont);

        // Blit
        BitBlt(hdc, 0,0,w,h, mem, 0,0, SRCCOPY);

        DeleteObject(hbmp);
        DeleteDC(mem);

        EndPaint(hwnd, &ps);
        return 0;
    }
    case WM_DESTROY:
        PostQuitMessage(0);
        return 0;
    }
    return DefWindowProcW(hwnd,msg,wParam,lParam);
}

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE, LPSTR, int)
{
    // Make DPI aware for crisper UI
    typedef BOOL (WINAPI *SetDPIAware_t)();
    HMODULE user32 = LoadLibraryW(L"user32.dll");
    if(user32){
        SetDPIAware_t f = (SetDPIAware_t)GetProcAddress(user32, "SetProcessDPIAware");
        if(f) f();
        FreeLibrary(user32);
    }

    WNDCLASSEXW wc = { sizeof(WNDCLASSEXW) };
    wc.style = CS_HREDRAW|CS_VREDRAW;
    wc.lpfnWndProc = WndProc;
    wc.hInstance = hInstance;
    wc.hCursor = LoadCursor(NULL, IDC_ARROW);
    wc.hbrBackground = (HBRUSH)(COLOR_WINDOW+1);
    wc.lpszClassName = L"KalkulatorClass";
    RegisterClassExW(&wc);

    HWND hwnd = CreateWindowExW(0, wc.lpszClassName, L"Kalkulator",
        WS_OVERLAPPEDWINDOW & ~WS_THICKFRAME, CW_USEDEFAULT, CW_USEDEFAULT,
        WINDOW_WIDTH, WINDOW_HEIGHT, NULL, NULL, hInstance, NULL);

    if(!hwnd) return -1;

    ShowWindow(hwnd, SW_SHOWDEFAULT);
    UpdateWindow(hwnd);

    MSG msg;
    while(GetMessageW(&msg, NULL, 0, 0)){
        TranslateMessage(&msg);
        DispatchMessageW(&msg);
    }

    return (int)msg.wParam;
}
