#include <iostream>
#include <iomanip>
using namespace std;

struct Pemain {
    string nama;
    string posisi;
    int tinggi;
    int nomor;
};

struct User {
    string username;
    string nim;
};

void read(Pemain *tim, int jumlah) {
    cout << "\n=== Daftar Pemain ===\n";
    if(jumlah == 0){
        cout << "Belum ada data pemain.\n";
        return;
    }

    cout << left << setw(5) << "No"
         << setw(20) << "Nama"
         << setw(15) << "Posisi"
         << setw(15) << "Tinggi"
         << setw(10) << "Nomor" << endl;

    for(int i=0;i<jumlah;i++){
        cout << left << setw(5) << i+1
             << setw(20) << (tim+i)->nama
             << setw(15) << (tim+i)->posisi
             << setw(15) << (tim+i)->tinggi
             << setw(10) << (tim+i)->nomor << endl;
    }
}

void create(Pemain *tim, int *jumlah) {
    cout << "\n=== Tambah Pemain ===\n";
    cin.ignore();
    cout << "Nama pemain : ";
    getline(cin, (tim + *jumlah)->nama);
    cout << "Posisi : ";
    getline(cin, (tim + *jumlah)->posisi);
    cout << "Tinggi badan (cm) : ";
    cin >> (tim + *jumlah)->tinggi;
    cout << "Nomor punggung : ";
    cin >> (tim + *jumlah)->nomor;

    (*jumlah)++;
    cout << "Data berhasil ditambahkan!\n";
}

void update(Pemain *tim, int jumlah) {
    if(jumlah == 0){
        cout << "Belum ada data pemain.\n";
        return;
    }

    read(tim, jumlah);
    int pilih;
    cout << "\nPilih nomor pemain yang ingin diubah: ";
    cin >> pilih;

    if(pilih < 1 || pilih > jumlah){
        cout << "Data tidak ditemukan!\n";
        return;
    }

    cin.ignore();
    cout << "Nama baru : ";
    getline(cin, (tim + pilih - 1)->nama);
    cout << "Posisi baru : ";
    getline(cin, (tim + pilih - 1)->posisi);
    cout << "Tinggi baru : ";
    cin >> (tim + pilih - 1)->tinggi;
    cout << "Nomor punggung baru : ";
    cin >> (tim + pilih - 1)->nomor;

    cout << "Data berhasil diubah!\n";
}

void hapus(Pemain *tim, int *jumlah) {
    if(*jumlah == 0){
        cout << "Belum ada data pemain.\n";
        return;
    }

    read(tim, *jumlah);
    int pilih;
    cout << "\nPilih nomor pemain yang ingin dihapus: ";
    cin >> pilih;

    if(pilih < 1 || pilih > *jumlah){
        cout << "Data tidak ditemukan!\n";
        return;
    }

    for(int i = pilih-1; i < *jumlah-1; i++){
        *(tim+i) = *(tim+i+1);
    }

    (*jumlah)--; 
    cout << "Data berhasil dihapus!\n";
}

bool login(User *user) {
    string username, password;
    int kesempatan = 3;

    while(kesempatan > 0){
        cout << "\n=== LOGIN ===\n";
        cout << "Username : ";
        cin >> username;
        cout << "NIM : ";
        cin >> password;

        if(username == user->username && password == user->nim){
            cout << "Login berhasil!\n";
            return true;
        } else {
            kesempatan--;
            cout << "Login gagal! Sisa percobaan: " << kesempatan << endl;
        }
    }
    return false;
}

int main() {
    User user = {"Michael","124"};
    Pemain tim[100];
    int jumlah = 0;

    if(!login(&user)){
        cout << "Anda gagal login 3 kali. Program berhenti.\n";
        return 0;
    }

    int pilihan;
    do {
        cout << "\n=== MENU UTAMA ===\n";
        cout << "1. Tambah Pemain\n";
        cout << "2. Lihat Pemain\n";
        cout << "3. Update Pemain\n";
        cout << "4. Hapus Pemain\n";
        cout << "5. Keluar\n";
        cout << "Pilihan : ";
        cin >> pilihan;

        switch(pilihan){
            case 1: create(tim, &jumlah); break;     
            case 2: read(tim, jumlah); break;
            case 3: update(tim, jumlah); break;
            case 4: hapus(tim, &jumlah); break;      
            case 5: cout << "Program selesai.\n"; break;
            default: cout << "Pilihan tidak tersedia!\n";
        }
    } while(pilihan != 5);

    return 0;
}
