// #include <iostream>
// using namespace std;

// // / Bagian Definisi Prosedur
// // / Di sini 'namaHero', 'level', dan 'hp' adalah PARAMETER.
// // / Mereka hanyalah "variabel kosong" yang menunggu nilai.
// void tampilkanStatus(string namaHero, int level, double hp) {
// cout << " = STATUS HERO =" << endl;
// cout << "Nama : " << namaHero << endl;
// cout << "Level : " << level << endl;
// cout << "Darah : " << hp << "%" << endl;
// cout << "===================" << endl;
// cout << endl;
// }

// int main() {
// // Bagian pengambilan argumen
// // Kasus 1: Mengirim nilai secara langsung
// // "Alucard", 15, dan 90.5 adalah argumen.
// tampilkanStatus("Alucard", 15, 90.5);

// // Kasus 2: Mengirim menggunakan variabel lain
// string hero2 = "Miya";
// int lvl2 = 12;
// double hp2 = 45.0;

// // Variabel 'hero2', 'lvl2', dan 'hp2' dikirim sebagai argumen
// tampilkanStatus(hero2, lvl2, hp2);
// return 0;
// }

// #include <iostream>
// using namespace std;
// // Fungsi menjumlahkan bilangan bulat
// int tambah(int a, int b) {
// return a + b;
// }
// // Fungsi 2 menjumlahkan bilangan desimal
// double tambah(double a, double b) {
// return a + b;
// }
// int main() {
// cout << "Hasil Int : " << tambah(5, 6) << endl;
// cout << "Hasil Double : " << tambah(5.5, 6.6) << endl;
// return 0;
// }

#include <iostream>
using namespace std;

int hitungLuas(int panjang, int lebar) {
int hasil = panjang * lebar;
return hasil; // return mengembalikan nilai hasil
}
int main() {
int p = 10;
int l = 5;
/// pemanggilan fungsi
int luasTanah = hitungLuas(p, l);
cout << "Panjang: " << p << "m, Lebar: " << l << "m" << endl;
// Sekarang variabel luasTanah sudah memiliki nilai yang dikembalikan
cout << "Total Luas Tanah: " << luasTanah << " meter persegi." <<
endl;
return 0;
}