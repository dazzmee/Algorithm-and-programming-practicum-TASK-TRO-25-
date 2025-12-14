
# 🧠 Level 3–4 — Gambaran Umum Materi

## ## 🔵 Level 3 — *Kondisional & Looping*

Level 3 membahas bagaimana membuat program **mengambil keputusan** dan **melakukan pekerjaan berulang**. Ini adalah fondasi logika dalam pemrograman.

---

### ### 1. Kondisional

Digunakan untuk membuat program memilih *alur berbeda* berdasarkan kondisi tertentu.

#### **if**

Menjalankan kode hanya jika kondisinya benar.

#### **else if**

Dipakai ketika ada alternatif kondisi lain.

#### **else**

Dijalankan jika semua kondisi sebelumnya salah.

#### **Logika Boolean**

Menggunakan operator seperti:

* `&&` (AND)
* `||` (OR)
* `!` (NOT)

Contoh penggunaan boolean:

```cpp
if (umur >= 18 && punyaKTP) { ... }
```

---

### ### 2. Loop (Perulangan)

Loop berguna saat kamu ingin program mengulang pekerjaan tanpa menulis kode berulang.

#### **for loop**

Jumlah perulangannya *jelas*, misalnya 1–10.

#### **while loop**

Mengulang selama kondisi masih benar.

#### **do–while loop**

Selalu berjalan minimal **1 kali**, lalu mengecek kondisi.

#### **Loop pada array**

Digunakan untuk membaca atau memproses data dalam array:

```cpp
for (int i = 0; i < ukuran; i++) {
    cout << arr[i];
}
```

---

### ### 3. Latihan Level 3

Beberapa latihan umum:

* **Program Mencari Rata-rata nilai**
  Input banyak nilai, lalu hitung rata-rata menggunakan loop.

* **Program Tabel Perkalian**
  Menggunakan nested-loop (loop di dalam loop) untuk menampilkan tabel 1–10.

---

---

# 🟢 Level 4 — *Parameter, Function Prototype, Modular Code*

Pada level ini kamu belajar bagaimana membuat kode lebih **rapi**, **terorganisir**, dan **modular**.

---

## ## 1. Parameter Copy vs Reference

Ketika kamu mengirim data ke fungsi, ada dua cara:

### **1. Pass by Copy (Value)**

* Data **disalin** ke parameter fungsi.
* Perubahan di dalam fungsi **tidak mempengaruhi** variabel asli.

### **2. Pass by Reference**

* Tidak membuat salinan. Parameter mengacu ke variabel asli.
* Perubahan di fungsi **langsung mengubah** nilai aslinya.
* Ditulis dengan tanda `&`.

Contoh:

```cpp
void tambah(int &x) { x++; }
```

---

## ## 2. Function Prototype

Agar sebuah fungsi bisa dipakai sebelum definisinya ditulis, kamu membutuhkan **prototipe**.

Contoh:

```cpp
int tambah(int a, int b);   // prototype

int main() { ... }
int tambah(int a, int b) { return a + b; }
```

---

## ## 3. Organisasi Kode (Header & Source File)

Ini bagian penting pada Level 4 — memisahkan kode menjadi beberapa file.

### **File .hpp (header)**

Berisi:

* deklarasi fungsi (prototype)
* struktur data
* variabel global (jika ada)

### **File .cpp (source)**

Berisi:

* definisi fungsi
* implementasi logika

Tujuannya:

* lebih rapi
* mudah di-maintenance
* mudah dipakai ulang

---

## ## 4. Kompilasi & Eksekusi via Terminal

Jika file dipisah:

```
fungsi.hpp
fungsi.cpp
main.cpp
```

Cara compile:

```sh
g++ main.cpp fungsi.cpp -o program
./program
```

---

## ## 5. Latihan Level 4

berupa tugas *modular*:

* membuat program dengan fungsi-fungsi terpisah
* menggunakan parameter reference & copy
* menyusun file menjadi `.hpp` + `.cpp`
* compile manual via terminal
