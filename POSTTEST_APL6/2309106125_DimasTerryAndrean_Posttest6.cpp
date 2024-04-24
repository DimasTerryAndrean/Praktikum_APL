#include <iostream>
#include <string>
#include <algorithm> // Untuk fungsi std::sort
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
Napi* daftarNapi = new Napi[MAX_NAPI]; // Pointer untuk daftarNapi
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

// Fungsi untuk menampilkan daftar napi secara descending berdasarkan nomor napi
void tampilkanNapiSecaraDescendingNomor(Napi* daftarNapi, int jumlahNapi) {
    // Lakukan sorting terlebih dahulu berdasarkan nomor napi secara descending
    sort(daftarNapi, daftarNapi + jumlahNapi, [](const Napi& a, const Napi& b) {
        return a.dataHukuman.noNapi > b.dataHukuman.noNapi;
    });

    // Tampilkan data napi
    cout << "Data Napi (Descending berdasarkan Nomor Napi):" << endl;
    for (int i = 0; i < jumlahNapi; ++i) {
        cout << "Nama: " << daftarNapi[i].dataPribadi.nama << ", Nomor Napi: " << daftarNapi[i].dataHukuman.noNapi << endl;
    }
}

// Fungsi untuk menampilkan daftar napi secara ascending berdasarkan nomor napi
void tampilkanNapiSecaraAscendingNomor(Napi* daftarNapi, int jumlahNapi) {
    // Lakukan sorting terlebih dahulu berdasarkan nomor napi secara ascending
    sort(daftarNapi, daftarNapi + jumlahNapi, [](const Napi& a, const Napi& b) {
        return a.dataHukuman.noNapi < b.dataHukuman.noNapi;
    });

    // Tampilkan data napi
    cout << "Data Napi (Ascending berdasarkan Nomor Napi):" << endl;
    for (int i = 0; i < jumlahNapi; ++i) {
        cout << "Nama: " << daftarNapi[i].dataPribadi.nama << ", Nomor Napi: " << daftarNapi[i].dataHukuman.noNapi << endl;
    }
}

// Fungsi untuk menampilkan daftar napi secara ascending berdasarkan umur
void tampilkanNapiSecaraAscendingUmur(Napi* daftarNapi, int jumlahNapi) {
    // Lakukan sorting terlebih dahulu berdasarkan umur napi secara ascending
    sort(daftarNapi, daftarNapi + jumlahNapi, [](const Napi& a, const Napi& b) {
        return a.dataPribadi.umur < b.dataPribadi.umur;
    });

    // Tampilkan data napi
    cout << "Data Napi (Ascending berdasarkan Umur):" << endl;
    for (int i = 0; i < jumlahNapi; ++i) {
        cout << "Nama: " << daftarNapi[i].dataPribadi.nama << ", Umur: " << daftarNapi[i].dataPribadi.umur << endl;
    }
}

// Prosedur untuk menambahkan data napi (prosedur)
void tambahNapi(Napi* daftarNapi, int* jumlahNapi) { // Parameter address-of untuk daftarNapi dan jumlahNapi
    if (*jumlahNapi == MAX_NAPI) {
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

    daftarNapi[*jumlahNapi] = napiBaru; // Dereference untuk mengakses elemen array
    (*jumlahNapi)++;
    cout << "Data napi berhasil ditambahkan." << endl;
}

// Fungsi untuk mencari data napi dengan lama tahanan paling tinggi dan menampilkan secara descending dari yang paling tinggi
void searchDescendingByHukuman(Napi* daftarNapi, int jumlahNapi) {
    if (jumlahNapi == 0) {
        cout << "Tidak ada data napi." << endl;
        return;
    }

    // Lakukan sorting terlebih dahulu berdasarkan lama tahanan secara descending
    sort(daftarNapi, daftarNapi + jumlahNapi, [](const Napi& a, const Napi& b) {
        return a.dataHukuman.masaHukuman > b.dataHukuman.masaHukuman;
    });

    // Tampilkan data napi
    cout << "Data Napi (Descending berdasarkan Lama Tahanan):" << endl;
    for (int i = 0; i < jumlahNapi; ++i) {
        cout << "Nama: " << daftarNapi[i].dataPribadi.nama << ", Masa Hukuman: " << daftarNapi[i].dataHukuman.masaHukuman << " tahun" << endl;
    }
}

// Fungsi untuk mencari data napi dengan lama tahanan paling rendah dan menampilkan secara ascending
void searchAscendingByHukuman(Napi* daftarNapi, int jumlahNapi) {
    if (jumlahNapi == 0) {
        cout << "Tidak ada data napi." << endl;
        return;
    }

    // Lakukan sorting terlebih dahulu berdasarkan lama tahanan secara ascending
    sort(daftarNapi, daftarNapi + jumlahNapi, [](const Napi& a, const Napi& b) {
        return a.dataHukuman.masaHukuman < b.dataHukuman.masaHukuman;
    });

    // Tampilkan data napi
    cout << "Data Napi (Ascending berdasarkan Lama Tahanan):" << endl;
    for (int i = 0; i < jumlahNapi; ++i) {
        cout << "Nama: " << daftarNapi[i].dataPribadi.nama << ", Masa Hukuman: " << daftarNapi[i].dataHukuman.masaHukuman << " tahun" << endl;
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

        while (true) { // loop untuk mempertahankan menu utama
            int pilihan;
            cout << endl;
            cout << "Menu:" << endl;
            cout << endl;
            cout << "1. Tambah Napi" << endl;
            cout << "2. Tampilkan Daftar Napi" << endl;
            cout << "3. Cari Napi dengan Lama Tahanan Paling Tinggi (Descending)" << endl;
            cout << "4. Cari Napi dengan Lama Tahanan Paling Rendah (Ascending)" << endl;
            cout << "5. Keluar" << endl;
            cout << "Pilihan Anda: ";
            cin >> pilihan;

            switch (pilihan) {
                case 1:
                    tambahNapi(daftarNapi, &jumlahNapi); // menggunakan parameter address-of untuk jumlahNapi
                    break;
                case 2: {
                    int subPilihan;
                    cout << "Pilihan tampilan:" << endl;
                    cout << "1. Nomor Napi secara Descending" << endl;
                    cout << "2. Nomor Napi secara Ascending" << endl;
                    cout << "3. Umur Napi secara Ascending" << endl;
                    cout << "Pilihan Anda: ";
                    cin >> subPilihan;

                    switch (subPilihan) {
                        case 1:
                            tampilkanNapiSecaraDescendingNomor(daftarNapi, jumlahNapi);
                            break;
                        case 2:
                            tampilkanNapiSecaraAscendingNomor(daftarNapi, jumlahNapi);
                            break;
                        case 3:
                            tampilkanNapiSecaraAscendingUmur(daftarNapi, jumlahNapi);
                            break;
                        default:
                            cout << "Pilihan tidak valid. Silakan coba lagi." << endl;
                            break;
                    }
                    break;
                }
                case 3:
                    searchDescendingByHukuman(daftarNapi, jumlahNapi);
                    break;
                case 4:
                    searchAscendingByHukuman(daftarNapi, jumlahNapi);
                    break;
                case 5:
                    programBerjalan = false;
                    cout << "Terima kasih telah menggunakan program ini." << endl;
                    delete[] daftarNapi; // menghapus array
                    return 0;
                default:
                    cout << "Pilihan tidak valid. Silakan coba lagi." << endl;
                    break;
            }
        }
    }

    delete[] daftarNapi; // menghapus array
    return 0;
}
