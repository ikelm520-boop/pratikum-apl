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
    try {
        cout << "\n=== Tambah Pemain ===\n";
        cin.ignore();

        cout << "Nama pemain : ";
        getline(cin, (tim + *jumlah)->nama);
        if((tim + *jumlah)->nama.empty())
            throw "Nama tidak boleh kosong!";

        cout << "Posisi : ";
        getline(cin, (tim + *jumlah)->posisi);

        cout << "Tinggi badan (cm) : ";
        if(!(cin >> (tim + *jumlah)->tinggi))
            throw "Tinggi harus angka!";

        cout << "Nomor punggung : ";
        if(!(cin >> (tim + *jumlah)->nomor))
            throw "Nomor harus angka!";

        (*jumlah)++;
        cout << "Data berhasil ditambahkan!\n";
    }
    catch(const char* e) {
        cin.clear();
        cin.ignore(1000, '\n');
        cout << "Error: " << e << endl;
    }
}

void update(Pemain *tim, int jumlah) {
    try {
        if(jumlah == 0)
            throw "Data kosong!";

        read(tim, jumlah);

        int pilih;
        cout << "\nPilih nomor pemain yang ingin diubah: ";
        if(!(cin >> pilih))
            throw "Input harus angka!";

        if(pilih < 1 || pilih > jumlah)
            throw "Data tidak ditemukan!";

        cin.ignore();
        cout << "Nama baru : ";
        getline(cin, (tim + pilih - 1)->nama);

        cout << "Posisi baru : ";
        getline(cin, (tim + pilih - 1)->posisi);

        cout << "Tinggi baru : ";
        if(!(cin >> (tim + pilih - 1)->tinggi))
            throw "Tinggi harus angka!";

        cout << "Nomor punggung baru : ";
        if(!(cin >> (tim + pilih - 1)->nomor))
            throw "Nomor harus angka!";

        cout << "Data berhasil diubah!\n";
    }
    catch(const char* e){
        cin.clear();
        cin.ignore(1000, '\n');
        cout << "Error: " << e << endl;
    }
}

void hapus(Pemain *tim, int *jumlah) {
    try {
        if(*jumlah == 0)
            throw "Data kosong!";

        read(tim, *jumlah);

        int pilih;
        cout << "\nPilih nomor pemain yang ingin dihapus: ";
        if(!(cin >> pilih))
            throw "Input harus angka!";

        if(pilih < 1 || pilih > *jumlah)
            throw "Data tidak ditemukan!";

        for(int i = pilih-1; i < *jumlah-1; i++){
            *(tim+i) = *(tim+i+1);
        }

        (*jumlah)--; 
        cout << "Data berhasil dihapus!\n";
    }
    catch(const char* e){
        cin.clear();
        cin.ignore(1000, '\n');
        cout << "Error: " << e << endl;
    }
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
    try {
        if(jumlah == 0)
            throw "Data kosong!";

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

        if(!ditemukan)
            throw "Data tidak ditemukan!";
    }
    catch(const char* e){
        cout << "Error: " << e << endl;
    }
}

void searchNomor(Pemain *tim, int jumlah){
    try {
        if(jumlah == 0)
            throw "Data kosong!";

        sortNomorAsc(tim, jumlah);

        int cari;
        cout << "Masukkan nomor yang dicari: ";
        if(!(cin >> cari))
            throw "Input harus angka!";

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

        if(!ditemukan)
            throw "Data tidak ditemukan!";
    }
    catch(const char* e){
        cin.clear();
        cin.ignore(1000, '\n');
        cout << "Error: " << e << endl;
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

        try {
            if(cin.fail())
                throw "Input menu harus angka!";
        }
        catch(const char* e){
            cin.clear();
            cin.ignore(1000,'\n');
            cout << "Error: " << e << endl;
            continue;
        }

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