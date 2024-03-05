#include <iostream>
#include <string>

using namespace std;

bool isLoggedIn = false;
int attempt = 0;
string nama_id, nim_pass;

void login() {
while (attempt < 3 && !isLoggedIn) {
    cout << "Masukkan Nama: ";
    cin >> nama_id;
    cout << "Masukkan NIM: ";
    cin >> nim_pass;

    if (nama_id == "Dimas" && nim_pass == "2309106121") {
        isLoggedIn = true;
        cout << "Login Berhasil!" << endl;
    } else {
        attempt++;
        cout << "Login Gagal! Sisa Percobaan: " << (3 - attempt) << endl;
    }
    }

    if (attempt == 3) {
    cout << "Login Gagal 3 kali! Program ditutup." << endl;
    exit(0);
    }
}

void konversiCelcius() {
    float celcius, reamur, fahrenheit, kelvin;

    cout << "Masukkan suhu Celcius: ";
    cin >> celcius;

    reamur = 0.8 * celcius;
    fahrenheit = (9 * celcius) / 5 + 32;
    kelvin = celcius + 273.15;

    cout << "Suhu Reamur: " << reamur << endl;
    cout << "Suhu Fahrenheit: " << fahrenheit << endl;
    cout << "Suhu Kelvin: " << kelvin << endl;
}

void konversiReamur() {
    float celcius, reamur, fahrenheit, kelvin;

    cout << "Masukkan suhu Reamur: ";
    cin >> reamur;

    celcius = reamur / 0.8;
    fahrenheit = (9 * celcius) / 5 + 32;
    kelvin = celcius + 273.15;

    cout << "Suhu Celcius: " << celcius << endl;
    cout << "Suhu Fahrenheit: " << fahrenheit << endl;
    cout << "Suhu Kelvin: " << kelvin << endl;
}

void konversiFahrenheit() {
    float celcius, reamur, fahrenheit, kelvin;

    cout << "Masukkan suhu Fahrenheit: ";
    cin >> fahrenheit;

    celcius = (fahrenheit - 32) * 5 / 9;
    reamur = 0.8 * celcius;
    kelvin = celcius + 273.15;

    cout << "Suhu Celcius: " << celcius << endl;
    cout << "Suhu Reamur: " << reamur << endl;
    cout << "Suhu Kelvin: " << kelvin << endl;
}

void konversiKelvin() {
    float celcius, reamur, fahrenheit, kelvin;

    cout << "Masukkan suhu Kelvin: ";
    cin >> kelvin;

    celcius = kelvin - 273.15;
    reamur = 0.8 * celcius;
    fahrenheit = (9 * celcius) / 5 + 32;

    cout << "Suhu Celcius: " << celcius << endl;
    cout << "Suhu Reamur: " << reamur << endl;
    cout << "Suhu Fahrenheit: " << fahrenheit << endl;
}

int main() {
    login();

while (true) {
    int pilihan;

    cout << endl;
    cout << "Menu Konversi Suhu" << endl;
    cout << "1. Konversi Celcius ke (Reamur, Farenheit, Kelvin)" << endl;
    cout << "2. Konversi Reamur ke (Celcius, Farenheit, Kelvin)" << endl;
    cout << "3. Konversi Farenheit ke (Celcius, Reamur, Kelvin)" << endl;
    cout << "4. Konversi Kelvin ke (Celcius, Reamur, Farenheit)" << endl;
    cout << "5. Keluar" << endl;

    cout << "Masukkan pilihan: ";
    cin >> pilihan;

    switch (pilihan) {
    case 1:
        konversiCelcius();
        break;
    case 2:
        konversiReamur();
        break;
    case 3:
        konversiFahrenheit();
        break;
    case 4:
        konversiKelvin();
        break;
    case 5:
        exit(0);
        break;
    default:
        cout << "Pilihan tidak valid." << endl;
    }
}

return 0;
}