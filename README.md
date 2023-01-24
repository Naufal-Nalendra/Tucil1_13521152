# Pencarian Solusi dari Permainan 24 Game dengan Algoritma Brute Force
Disusun untuk memenuhi Tugas Kecil 1 IF2211 Strategi Algoritma

## Daftar Isi
* [Deskripsi Singkat](#deskripsi-singkat)
* [Requirement](#requirement)
* [Cara Compile](#cara-compile)
* [Cara Menggunakan Program](#cara-menggunakan-program)
* [Author](#author)

## Deskripsi Singkat Program
Program ini berfungsi mencari semua solusi yang mungkin dari permainan 24 Game, yaitu mencari operasi yang mungkin
untuk 4 buah kartu agar menghasilkan angka 24

## Requirement Program
* C/C++ Compiler

## Cara Kompilasi Program
1. Pastikan C/C++ Compiler sudah terpasang pada mesin (Jika ragu dapat menjalankan command `g++ --version` pada command prompt untuk melihat versi compiler).
2. Compile program pada "src/main.cpp" dengan cara menekan tombol compile pada code editor atau dengan menjalankan command `g++ src\main.cpp -o bin\main.exe` 
3. Hasil compile akan muncul pada folder bin

## Cara Menjalankan Program
1. Jika compile berhasil, program akan meminta user untuk memilih jenis input
2. Jika memilih input secara manual maka user harus memasukkan input berupa 4 kartu (A,2,3,4,5,6,7,8,9,10,J,Q,K) yang dipisah dengan spasi. Setiap kartu memiliki nilai bilangan itu sendiri kecuali As (1),Jack (11),Queen (12),King (13).
3. Setelah solusi ditemukan, program akan menanyakan pada user jika ingin menyimpan solusi ke file .txt yang dapat dieksekusi dengan cara menginput huruf `Y/y`

## Author
* Nama: Muhammad Naufal Nalendra
* NIM: 13521152
* Prodi : Teknik Informatika