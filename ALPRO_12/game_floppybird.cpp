// Flappy Bird - SDL2 implementation
// Build (MSYS2 UCRT64):
// pacman -S mingw-w64-ucrt-x86_64-gcc mingw-w64-ucrt-x86_64-SDL2
// g++ game_floppybird.cpp -o game_floppybird.exe -lmingw32 -lSDL2main -lSDL2
// Alternatively with MinGW: link against SDL2 and SDL2main as appropriate for your environment.

#include <SDL.h>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <string>
#include <algorithm>

// Window
const int WINDOW_W = 480;
const int WINDOW_H = 640;

// Bird
struct Bird {
    float x, y;
    float vy;
    int size;
    bool alive;
    Bird(): x(WINDOW_W*0.25f), y(WINDOW_H*0.5f), vy(0), size(28), alive(true) {}
    SDL_Rect rect() const { return SDL_Rect{int(x - size/2), int(y - size/2), size, size}; }
};

// Pipe
struct Pipe {
    float x;
    int gapY;
    int w;
    int gapH;
    bool passed;
    Pipe(float startX, int gapY_, int w_, int gapH_): x(startX), gapY(gapY_), w(w_), gapH(gapH_), passed(false) {}
};

// Draw helpers
void drawFilledRect(SDL_Renderer* r, int x, int y, int w, int h, SDL_Color c){
    SDL_SetRenderDrawColor(r, c.r, c.g, c.b, c.a);
    SDL_Rect rect{ x, y, w, h };
    SDL_RenderFillRect(r, &rect);
}

// Draw a rounded-ish bird (circle) using filled rectangles (cheap approximation)
void drawBird(SDL_Renderer* renderer, const Bird& b, SDL_Color col){
    SDL_SetRenderDrawColor(renderer, col.r, col.g, col.b, col.a);
    SDL_Rect r = b.rect();
    // fill center
    SDL_RenderFillRect(renderer, &r);
    // small eye
    SDL_Rect eye{ int(b.x + b.size*0.12f), int(b.y - b.size*0.15f), b.size/6, b.size/6 };
    SDL_SetRenderDrawColor(renderer, 0,0,0,255);
    SDL_RenderFillRect(renderer, &eye);
}

// Seven-segment digit renderer for score (avoids TTF dependency)
void drawSegment(SDL_Renderer* r, int x, int y, int w, int h, bool on, SDL_Color c){
    if(!on) return;
    drawFilledRect(r, x, y, w, h, c);
}

// digits segments order: a,b,c,d,e,f,g
const bool DIGITS[10][7] = {
    {1,1,1,1,1,1,0}, //0
    {0,1,1,0,0,0,0}, //1
    {1,1,0,1,1,0,1}, //2
    {1,1,1,1,0,0,1}, //3
    {0,1,1,0,0,1,1}, //4
    {1,0,1,1,0,1,1}, //5
    {1,0,1,1,1,1,1}, //6
    {1,1,1,0,0,0,0}, //7
    {1,1,1,1,1,1,1}, //8
    {1,1,1,1,0,1,1}  //9
};

void drawDigit(SDL_Renderer* r, int x, int y, int scale, int digit, SDL_Color color){
    int segW = scale;
    int segL = scale*4;
    // a
    drawSegment(r, x + segW, y, segL, segW, DIGITS[digit][0], color);
    // b
    drawSegment(r, x + segW + segL, y + segW, segW, segL, DIGITS[digit][1], color);
    // c
    drawSegment(r, x + segW + segL, y + segW + segL + segW, segW, segL, DIGITS[digit][2], color);
    // d
    drawSegment(r, x + segW, y + segW + segL + segW + segL, segL, segW, DIGITS[digit][3], color);
    // e
    drawSegment(r, x, y + segW + segL + segW, segW, segL, DIGITS[digit][4], color);
    // f
    drawSegment(r, x, y + segW, segW, segL, DIGITS[digit][5], color);
    // g
    drawSegment(r, x + segW, y + segW + segL, segL, segW, DIGITS[digit][6], color);
}

void drawNumber(SDL_Renderer* r, int x, int y, int scale, int number, SDL_Color color){
    std::string s = std::to_string(number);
    int w = scale*6; // approximate width per digit
    for(size_t i=0;i<s.size();++i){
        drawDigit(r, x + int(i*w), y, scale, s[i]-'0', color);
    }
}

int main(int argc, char** argv){
    srand((unsigned)time(NULL));
    if(SDL_Init(SDL_INIT_VIDEO | SDL_INIT_TIMER | SDL_INIT_AUDIO) != 0){
        SDL_Log("SDL_Init Error: %s", SDL_GetError());
        return 1;
    }

    SDL_Window* window = SDL_CreateWindow("Flappy Bird - C++ SDL2", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, WINDOW_W, WINDOW_H, SDL_WINDOW_SHOWN);
    if(!window){ SDL_Log("CreateWindow Error: %s", SDL_GetError()); SDL_Quit(); return 1; }
    SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
    if(!renderer){ SDL_Log("CreateRenderer Error: %s", SDL_GetError()); SDL_DestroyWindow(window); SDL_Quit(); return 1; }

    Bird bird;

    std::vector<Pipe> pipes;
    Uint64 lastPipeTime = SDL_GetTicks64();
    const Uint64 pipeInterval = 1500; // ms

    int score = 0;
    bool running = true;
    bool mouseDown = false;

    const float gravity = 1200.f; // px/s^2
    const float flapImp = -360.f; // px/s

    Uint64 lastTime = SDL_GetTicks64();

    while(running){
        Uint64 now = SDL_GetTicks64();
        float dt = (now - lastTime) / 1000.0f;
        if(dt > 0.05f) dt = 0.05f;
        lastTime = now;

        SDL_Event e;
        while(SDL_PollEvent(&e)){
            if(e.type == SDL_QUIT) running = false;
            else if(e.type == SDL_KEYDOWN){
                if(e.key.keysym.sym == SDLK_ESCAPE) running = false;
                if(e.key.keysym.sym == SDLK_SPACE){ if(bird.alive) { bird.vy = flapImp; } else { // restart
                    bird = Bird(); pipes.clear(); score = 0; lastPipeTime = SDL_GetTicks64(); }
                }
                if(e.key.keysym.sym == SDLK_r){ bird = Bird(); pipes.clear(); score = 0; lastPipeTime = SDL_GetTicks64(); }
            } else if(e.type == SDL_MOUSEBUTTONDOWN){ mouseDown = true; if(bird.alive) bird.vy = flapImp; }
            else if(e.type == SDL_MOUSEBUTTONUP){ mouseDown = false; }
        }

        // spawn pipes
        if(now - lastPipeTime > pipeInterval){
            lastPipeTime = now;
            int gapH = 170 + (rand()%61 - 30); // vary
            int minY = 80; int maxY = WINDOW_H - 200;
            int gapY = minY + rand() % (maxY - minY + 1);
            pipes.emplace_back((float)WINDOW_W + 50, gapY, 80, gapH);
        }

        // update bird
        if(bird.alive){
            bird.vy += gravity * dt;
            bird.y += bird.vy * dt;
        }

        // update pipes
        for(auto &p : pipes) p.x -= 200.0f * dt; // speed

        // collision & scoring
        SDL_Rect brect = bird.rect();
        for(auto &p : pipes){
            SDL_Rect top{ int(p.x), 0, p.w, p.gapY };
            SDL_Rect bot{ int(p.x), p.gapY + p.gapH, p.w, WINDOW_H - (p.gapY + p.gapH) };
            if(bird.alive){
                if(SDL_HasIntersection(&brect, &top) || SDL_HasIntersection(&brect, &bot)){
                    bird.alive = false;
                }
            }
            if(!p.passed && p.x + p.w < bird.x - bird.size/2){ p.passed = true; score++; }
        }

        // remove offscreen pipes
        pipes.erase(std::remove_if(pipes.begin(), pipes.end(), [](const Pipe& p){ return p.x + p.w < -50; }), pipes.end());

        // ground collision
        int groundY = WINDOW_H - 80;
        if(bird.y + bird.size/2 >= groundY){ bird.alive = false; bird.y = groundY - bird.size/2; }
        if(bird.y - bird.size/2 <= 0){ bird.y = bird.size/2; bird.vy = 0; }

        // Rendering
        // background sky gradient
        SDL_SetRenderDrawBlendMode(renderer, SDL_BLENDMODE_BLEND);
        SDL_Color topCol{ 100, 180, 255, 255 };
        SDL_Color botCol{ 30, 120, 200, 255 };
        for(int i=0;i<WINDOW_H;i++){
            float t = float(i) / WINDOW_H;
            Uint8 r = Uint8(topCol.r*(1-t) + botCol.r*t);
            Uint8 g = Uint8(topCol.g*(1-t) + botCol.g*t);
            Uint8 b = Uint8(topCol.b*(1-t) + botCol.b*t);
            SDL_SetRenderDrawColor(renderer, r,g,b,255);
            SDL_RenderDrawLine(renderer, 0, i, WINDOW_W, i);
        }

        // moving clouds (simple)
        SDL_SetRenderDrawColor(renderer, 255,255,255,60);
        for(int i=0;i<5;i++){
            int cx = (int)((now/10 + i*120) % (WINDOW_W+200)) - 100;
            int cy = 60 + (i%3)*30;
            SDL_Rect cloud{cx-40, cy-12, 80, 24};
            SDL_RenderFillRect(renderer, &cloud);
        }

        // pipes
        SDL_Color pipeCol{ 40,160,60,255 };
        for(auto &p : pipes){
            // top
            drawFilledRect(renderer, int(p.x), 0, p.w, p.gapY, pipeCol);
            // cap
            drawFilledRect(renderer, int(p.x)-6, p.gapY - 14, p.w+12, 14, {20,120,30,255});
            // bottom
            drawFilledRect(renderer, int(p.x), p.gapY + p.gapH, p.w, WINDOW_H - (p.gapY + p.gapH), pipeCol);
            drawFilledRect(renderer, int(p.x)-6, p.gapY + p.gapH, p.w+12, 14, {20,120,30,255});
        }

        // ground
        drawFilledRect(renderer, 0, groundY, WINDOW_W, WINDOW_H-groundY, {150,100,40,255});

        // bird
        drawBird(renderer, bird, {255,220,0,255});

        // score
        drawNumber(renderer, WINDOW_W/2 - 40, 30, 4, score, {255,255,255,255});

        // if dead, draw overlay
        if(!bird.alive){
            SDL_SetRenderDrawColor(renderer, 0,0,0,120);
            SDL_Rect overlay{0,0,WINDOW_W,WINDOW_H};
            SDL_RenderFillRect(renderer, &overlay);
            // draw small restart hint using digits for 'R'
            // simple text substitute
            drawNumber(renderer, WINDOW_W/2 - 60, WINDOW_H/2 - 20, 3, score, {255,255,0,255});
        }

        SDL_RenderPresent(renderer);

        // small delay is handled by present vsync
    }

    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
    return 0;
}
