#include <iostream>
#include <string>
using namespace std;

struct DataHukuman {
    int noNapi;
    int masaHukuman;
};

struct DataKeluarga {
    string namaIstri;
    int jumlahAnak;
};

struct DataPribadi {
    string nama;
    int umur;
    string alamat;
};

struct Napi {
    DataPribadi dataPribadi;
    DataKeluarga dataKeluarga;
    DataHukuman dataHukuman;
};

const int MAX_NAPI = 100;
Napi daftarNapi[MAX_NAPI];
int jumlahNapi = 0;

string namaUser = "Dimas";
string nimUser = "121";
int percobaan = 0;

// Fungsi untuk melakukan validasi login (fungsi rekursif)
bool login() {
    string inputNama, inputNim;
    cout << "Masukkan Nama: ";
    cin >> inputNama;
    cout << "Masukkan NIM: ";
    cin >> inputNim;

    if (inputNama == namaUser && inputNim == nimUser) {
        return true;
    } else {
        percobaan++;
        if (percobaan == 3) {
            cout << "Anda telah 3 kali salah memasukkan Nama dan NIM. Program akan berhenti." << endl;
            return false;
        } else {
            cout << "Nama atau NIM salah. Silakan coba lagi." << endl;
            return login(); // Memanggil fungsi login() secara rekursif
        }
    }
}

// Prosedur untuk menambahkan data napi (prosedur)
void tambahNapi() {
    if (jumlahNapi == MAX_NAPI) {
        cout << "Data sudah penuh. Tidak dapat menambah napi baru." << endl;
        return;
    }

    Napi napiBaru;
    cout << "Masukkan Nama Napi: ";
    cin.ignore();
    getline(cin, napiBaru.dataPribadi.nama);
    cout << "Masukkan Umur Napi: ";
    cin >> napiBaru.dataPribadi.umur;
    cout << "Masukkan Alamat Napi: ";
    cin.ignore();
    getline(cin, napiBaru.dataPribadi.alamat);
    cout << "Masukkan Nama Istri: ";
    getline(cin, napiBaru.dataKeluarga.namaIstri);
    cout << "Masukkan Jumlah Anak: ";
    cin >> napiBaru.dataKeluarga.jumlahAnak;
    cout << "Masukkan Nomor Napi: ";
    cin >> napiBaru.dataHukuman.noNapi;
    cout << "Masukkan Masa Hukuman (dalam tahun): ";
    cin >> napiBaru.dataHukuman.masaHukuman;

    daftarNapi[jumlahNapi] = napiBaru;
    jumlahNapi++;
    cout << "Data napi berhasil ditambahkan." << endl;
}

// Fungsi untuk mencari data napi berdasarkan nomor napi (fungsi)
int cariNapi(int noNapi) {
    for (int i = 0; i < jumlahNapi; i++) {
        if (daftarNapi[i].dataHukuman.noNapi == noNapi) {
            return i; // Mengembalikan indeks napi yang ditemukan
        }
    }
    return -1; // Mengembalikan -1 jika napi tidak ditemukan
}

// Prosedur untuk melihat data napi (prosedur)
void tampilkanNapi() {
    if (jumlahNapi == 0) {
        cout << "Tidak ada data napi." << endl;
        return;
    }

    cout << "Daftar Napi:" << endl;
    for (int i = 0; i < jumlahNapi; i++) {
        cout << "Nama: " << daftarNapi[i].dataPribadi.nama << endl;
        cout << "Umur: " << daftarNapi[i].dataPribadi.umur << endl;
        cout << "Alamat: " << daftarNapi[i].dataPribadi.alamat << endl;
        cout << "Nama Istri: " << daftarNapi[i].dataKeluarga.namaIstri << endl;
        cout << "Jumlah Anak: " << daftarNapi[i].dataKeluarga.jumlahAnak << endl;
        cout << "Nomor Napi: " << daftarNapi[i].dataHukuman.noNapi << endl;
        cout << "Masa Hukuman: " << daftarNapi[i].dataHukuman.masaHukuman << " tahun" << endl;
        cout << "-------------------" << endl;
    }
}

// Prosedur untuk mengubah data napi
void ubahNapi() {
    if (jumlahNapi == 0) {
        cout << "Tidak ada data napi." << endl;
        return;
    }

    int noNapi;
    cout << "Masukkan Nomor Napi yang ingin diubah: ";
    cin >> noNapi;

    int indeksNapi = cariNapi(noNapi); // Memanggil fungsi cariNapi untuk mendapatkan indeks napi
    if (indeksNapi != -1) {
        cout << "Masukkan Nama Napi Baru: ";
        cin.ignore();
        getline(cin, daftarNapi[indeksNapi].dataPribadi.nama);
        cout << "Masukkan Umur Napi Baru: ";
        cin >> daftarNapi[indeksNapi].dataPribadi.umur;
        cout << "Masukkan Alamat Napi Baru: ";
        cin.ignore();
        getline(cin, daftarNapi[indeksNapi].dataPribadi.alamat);
        cout << "Masukkan Nama Istri Baru: ";
        getline(cin, daftarNapi[indeksNapi].dataKeluarga.namaIstri);
        cout << "Masukkan Jumlah Anak Baru: ";
        cin >> daftarNapi[indeksNapi].dataKeluarga.jumlahAnak;
        cout << "Masukkan Masa Hukuman Baru (dalam tahun): ";
        cin >> daftarNapi[indeksNapi].dataHukuman.masaHukuman;
        cout << "Data napi berhasil diubah." << endl;
    } else {
        cout << "Nomor Napi tidak ditemukan." << endl;
    }
}

// Prosedur untuk menghapus data napi
void hapusNapi() {
    if (jumlahNapi == 0) {
        cout << "Tidak ada data napi." << endl;
        return;
    }

    int noNapi;
    cout << "Masukkan Nomor Napi yang ingin dihapus: ";
    cin >> noNapi;

    int indeksNapi = cariNapi(noNapi); // Memanggil fungsi cariNapi untuk mendapatkan indeks napi
    if (indeksNapi != -1) {
        for (int j = indeksNapi; j < jumlahNapi - 1; j++) {
            daftarNapi[j] = daftarNapi[j + 1];
        }
        jumlahNapi--;
        cout << "Data napi berhasil dihapus." << endl;
    } else {
        cout << "Nomor Napi tidak ditemukan." << endl;
    }
}

// Main program
int main() {
    bool programBerjalan = true;
    bool berhasilLogin;

    while (programBerjalan) {
        berhasilLogin = login();
        if (!berhasilLogin) {
            break;
        }

        while (true) { // Loop untuk mempertahankan menu utama
            int pilihan;
            cout << endl;
            cout << "Menu:" << endl;
            cout << endl;
            cout << "1. Tambah Napi" << endl;
            cout << "2. Tampilkan Daftar Napi" << endl;
            cout << "3. Ubah Data Napi" << endl;
            cout << "4. Hapus Data Napi" << endl;
            cout << "5. Keluar" << endl;
            cout << "Pilihan Anda: ";
            cin >> pilihan;

            switch (pilihan) {
                case 1:
                    tambahNapi();
                    break;
                case 2:
                    tampilkanNapi();
                    break;
                case 3:
                    ubahNapi();
                    break;
                case 4:
                    hapusNapi();
                    break;
                case 5:
                    programBerjalan = false;
                    cout << "Terima kasih telah menggunakan program ini." << endl;
                    return 0;
                default:
                    cout << "Pilihan tidak valid. Silakan coba lagi." << endl;
                    break;
            }
        }
    }

    return 0;
}