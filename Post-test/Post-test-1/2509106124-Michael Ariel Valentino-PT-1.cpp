#include <iostream> 
using namespace std;

int main() {
    const string nama = "Michael";
    const string password = "124";

    int percobaan = 0;

    while (percobaan < 3) {
        string inputNama, inputPassword;
        cout << "Masukkan Nama: ";
        cin >> inputNama;
        cout << "Masukkan Password: ";
        cin >> inputPassword;

        if (inputNama == nama && inputPassword == password) {
            cout << "Login Berhasil!" << endl;
            break;
        } else {
            cout << "Login Gagal!" << endl;
            percobaan++;
        }
    }
    if (percobaan == 3) {
        cout << "Anda telah mencoba login sebanyak 3 kali. Program berhenti." << endl;
        return 0;
    }
    int pilihan;

    do{
        cout << "Menu Konversi Satuan Panjang" << endl;
        cout << "1. Meter ke Kilometer dan Centimeter" << endl;
        cout << "2. Kilometer ke Meter dan Centimeter" << endl;
        cout << "3. Centimeter ke Meter dan Kilometer" << endl;
        cout << "4. Keluar" << endl;
        cout << "Pilih opsi (1-4): ";
        cin >> pilihan;

        double nilai;

        if (pilihan == 1) {
            cout << "Masukkan nilai dalam Meter: ";
            cin >> nilai;
            cout << nilai << " Meter = " << nilai / 1000 << " Kilometer" << endl;
            cout << nilai << " Meter = " << nilai * 100 << " Centimeter" << endl;
        } 
        else if (pilihan == 2) {
            cout << "Masukkan nilai dalam Kilometer: ";
            cin >> nilai;
            cout << nilai << " Kilometer = " << nilai * 1000 << " Meter" << endl;
            cout << nilai << " Kilometer = " << nilai * 100000 << " Centimeter" << endl;
        } 
        else if (pilihan == 3) {
            cout << "Masukkan nilai dalam Centimeter: ";
            cin >> nilai;
            cout << nilai << " Centimeter = " << nilai / 100000 << " Kilometer" << endl;
            cout << nilai << " Centimeter = " << nilai / 100 << " Meter" << endl;
        } 
        else if (pilihan == 4) {
            cout << "Keluar dari program." << endl;
        } 
        else {
            cout << "Pilihan tidak valid. Silakan coba lagi." << endl;
        }
    } while (pilihan != 4);
    return 0;
}