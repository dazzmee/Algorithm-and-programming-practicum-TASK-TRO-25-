# Penjelasan Lengkap OOP C++ -- Pertemuan 14 (Level 5)

## 1. Pengertian OOP (Object-Oriented Programming)

OOP atau Object-Oriented Programming adalah paradigma pemrograman yang
berfokus pada penggunaan *objek* sebagai representasi data dan perilaku.
Setiap objek berasal dari *class*, yang merupakan cetak biru (blueprint)
dari objek tersebut.

### Fungsi Utama OOP

1.  **Menyederhanakan program besar** -- kode menjadi modular dan mudah
    dikelola.
2.  **Mempermudah perawatan (maintenance)** -- perubahan pada satu class
    tidak merusak keseluruhan program.
3.  **Meningkatkan keamanan data** -- melalui *encapsulation*.
4.  **Mendukung penggunaan ulang kode (reusability)** -- melalui
    *inheritance*.

------------------------------------------------------------------------

## 2. Konsep Dasar OOP

OOP memiliki empat pilar utama:

### 2.1 Class

Blueprint atau template untuk membuat objek. Di dalam class terdapat: -
Atribut → data milik object. - Method → fungsi yang dimiliki object.

### 2.2 Object

Instance dari class, yaitu bentuk nyata dari blueprint.

### 2.3 Inheritance

Pewarisan class ke class lain, sehingga class turunan memiliki atribut
dan method class induk.

------------------------------------------------------------------------

## 3. Membuat Class dengan Atribut dan Constructor

Constructor adalah fungsi khusus yang dipanggil otomatis saat objek
dibuat.\
Fungsinya untuk mengisi nilai awal atribut.

Contoh:

``` cpp
class Mahasiswa {
private:
    string nama;
    int umur;

public:
    Mahasiswa(string nm, int um) {
        nama = nm;
        umur = um;
    }
};
```

------------------------------------------------------------------------

## 4. Menambahkan Method ke Dalam Class

Method adalah fungsi yang berada di dalam class.\
Digunakan untuk memproses atau menampilkan data objek.

Contoh:

``` cpp
void tampilkan() {
    cout << "Nama: " << nama << endl;
}
```

Method dapat digunakan untuk: - Menampilkan data - Mengubah data -
Mengembalikan nilai (`return`)

------------------------------------------------------------------------

## 5. Membuat Objek dan Mengakses Method/Atribut

Objek dibuat di dalam `main()` menggunakan syntax:

``` cpp
Mahasiswa m1("Izzad", 18);
m1.tampilkan();
```

Saat objek dibuat, constructor dijalankan otomatis.

------------------------------------------------------------------------

## 6. Access Modifier (public, private, protected)

Access modifier mengatur **siapa saja** yang dapat mengakses atribut dan method dalam class.

### Public

Dapat diakses dari mana saja, baik dari luar maupun dalam class.

### Private

Hanya bisa diakses oleh class itu sendiri. Cocok untuk data sensitif.

### Protected

Hanya bisa diakses oleh class itu sendiri dan class turunan. Cocok untuk konsep inheritance.


## 7. Pemisahan Kode Menjadi File `.hpp` dan `.cpp`

Tujuannya: - Kode lebih rapi - Mudah diatur pada project besar -
Memisahkan deklarasi (header) dan implementasi (source)

### Header file (.hpp)

Berisi deklarasi class dan fungsinya.

### Source file (.cpp)

Berisi implementasi method.

------------------------------------------------------------------------

## 8. Inheritance (Pewarisan Class)

Class turunan akan mewarisi seluruh atribut dan method dari class induk.

Contoh:

``` cpp
class Mahasiswa : public Manusia {
};
```

Manfaat: - Mengurangi duplikasi kode - Membuat struktur program lebih
teratur - Mendukung hubungan *is-a* (Mahasiswa adalah Manusia)

------------------------------------------------------------------------

## 9. Contoh Struktur Folder Project

    ProjectOOP/
    │
    ├── main.cpp
    ├── Manusia.hpp
    ├── Manusia.cpp
    ├── Mahasiswa.hpp
    ├── Mahasiswa.cpp

------------------------------------------------------------------------

## 10. Kesimpulan

Materi OOP pada C++ sangat penting untuk membangun program yang
terstruktur dan mudah dikembangkan.
Dengan memahami class, object, method, constructor, pemisahan file, dan
inheritance, mahasiswa dapat membuat program yang profesional, modular,
dan efisien.
