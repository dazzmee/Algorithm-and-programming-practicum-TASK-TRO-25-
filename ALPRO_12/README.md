# Flappy Bird (C++ / SDL2)

Game Flappy Bird sederhana ditulis dengan C++ dan SDL2. Desain menggunakan shape sederhana (rectangles) dan renderer custom untuk angka skor (seven-segment) sehingga tidak perlu font eksternal.

Fitur
- Kontrol: `Space` atau klik mouse untuk 'flap'
- Sistem poin: bertambah setiap kali melewati pipa
- Restart: tekan `R` atau `Space` setelah mati
- UI: background gradient, clouds, pipes, ground, dan score stylized

Persyaratan di Windows
- MSYS2 (direkomendasikan) atau MinGW yang sudah terpasang
- Paket SDL2 dev

Instalasi (MSYS2 UCRT64): buka `MSYS2 UCRT64` shell dan jalankan:

```
pacman -Syu
pacman -S mingw-w64-ucrt-x86_64-gcc mingw-w64-ucrt-x86_64-SDL2
```

Kompilasi (di shell mingw ucrt64):

```
g++ game_floppybird.cpp -o game_floppybird.exe -lmingw32 -lSDL2main -lSDL2
```

Jika Anda menggunakan MinGW-w64 (MSYS2 mingw64), gunakan paket `mingw-w64-x86_64-SDL2` dan jalankan dari `MSYS2 MinGW 64-bit` shell.

Menjalankan dari PowerShell

Jika Anda sudah berada di folder proyek dan memiliki `game_floppybird.exe`:

```powershell
.\game_floppybird.exe
```

Troubleshooting
- Jika muncul error `SDL2.dll not found`, pastikan `SDL2.dll` ada di PATH atau di folder exe (salin dari `mingw64/bin` jika perlu).
- Jika build gagal karena missing `SDL2main`/`SDL2`, pastikan Anda menggunakan compiler/linker yang sesuai (MSYS2 mingw shell biasanya benar environment-nya).

Pengembangan lebih lanjut (opsional)
- Tambahkan suara (SDL_mixer)
- Gunakan font TTF (SDL_ttf) untuk teks yang lebih bagus
- Tambahkan sprite/better graphics

Jika mau, saya dapat: menambahkan sprites, menambahkan suara, atau menuliskan script build otomatis (CMake / Makefile). Katakan saja mana yang Anda inginkan.
