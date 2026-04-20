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


void sortNamaDesc(Pemain *tim, int jumlah){
    for(int i=0; i<jumlah-1; i++){
        for(int j=0; j<jumlah-i-1; j++){
            if((tim+j)->nama < (tim+j+1)->nama){
                swap(*(tim+j), *(tim+j+1));
            }
        }
    }
    cout << "Sorting nama (Z-A) berhasil!\n";
}

void sortTinggiAsc(Pemain *tim, int jumlah){
    for(int i=0; i<jumlah-1; i++){
        for(int j=0; j<jumlah-i-1; j++){
            if((tim+j)->tinggi > (tim+j+1)->tinggi){
                swap(*(tim+j), *(tim+j+1));
            }
        }
    }
    cout << "Sorting tinggi (ascending) berhasil!\n";
}

void sortNomorAsc(Pemain *tim, int jumlah){
    for(int i=0; i<jumlah-1; i++){
        for(int j=0; j<jumlah-i-1; j++){
            if((tim+j)->nomor > (tim+j+1)->nomor){
                swap(*(tim+j), *(tim+j+1));
            }
        }
    }
}


void searchNama(Pemain *tim, int jumlah){
    if(jumlah == 0){
        cout << "Data kosong!\n";
        return;
    }

    cin.ignore();
    string cari;
    cout << "Masukkan nama yang dicari: ";
    getline(cin, cari);

    bool ditemukan = false;
    for(int i = 0; i < jumlah; i++){
        if((tim+i)->nama == cari){
            cout << "\nData ditemukan:\n";
            cout << "Nama   : " << (tim+i)->nama << endl;
            cout << "Posisi : " << (tim+i)->posisi << endl;
            cout << "Tinggi : " << (tim+i)->tinggi << endl;
            cout << "Nomor  : " << (tim+i)->nomor << endl;
            ditemukan = true;
        }
    }

    if(!ditemukan){
        cout << "Data tidak ditemukan!\n";
    }
}

void searchNomor(Pemain *tim, int jumlah){
    if(jumlah == 0){
        cout << "Data kosong!\n";
        return;
    }

    sortNomorAsc(tim, jumlah); 

    int cari;
    cout << "Masukkan nomor yang dicari: ";
    cin >> cari;

    int kiri = 0, kanan = jumlah - 1;
    bool ditemukan = false;

    while(kiri <= kanan){
        int tengah = (kiri + kanan) / 2;

        if((tim+tengah)->nomor == cari){
            cout << "\nData ditemukan:\n";
            cout << "Nama   : " << (tim+tengah)->nama << endl;
            cout << "Posisi : " << (tim+tengah)->posisi << endl;
            cout << "Tinggi : " << (tim+tengah)->tinggi << endl;
            cout << "Nomor  : " << (tim+tengah)->nomor << endl;
            ditemukan = true;
            break;
        }
        else if((tim+tengah)->nomor < cari){
            kiri = tengah + 1;
        }
        else{
            kanan = tengah - 1;
        }
    }

    if(!ditemukan){
        cout << "Data tidak ditemukan!\n";
    }
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
        cout << "5. Sorting Nama (Z-A)\n";
        cout << "6. Sorting Tinggi (Asc)\n";
        cout << "7. Cari Nama (Sequential)\n";
        cout << "8. Cari Nomor (Binary)\n";
        cout << "9. Keluar\n";
        cout << "Pilihan : ";
        cin >> pilihan;

        switch(pilihan){
            case 1: create(tim, &jumlah); break;
            case 2: read(tim, jumlah); break;
            case 3: update(tim, jumlah); break;
            case 4: hapus(tim, &jumlah); break;
            case 5: sortNamaDesc(tim, jumlah); break;
            case 6: sortTinggiAsc(tim, jumlah); break;
            case 7: searchNama(tim, jumlah); break;
            case 8: searchNomor(tim, jumlah); break;
            case 9: cout << "Program selesai.\n"; break;
            default: cout << "Pilihan tidak tersedia!\n";
        }
    } while(pilihan != 9);

    return 0;
}