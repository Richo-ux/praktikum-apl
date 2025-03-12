#include <iostream>
using namespace std;

const int PIN = 6062; // 4 digit terakhir NIM
int saldo = 1000000; // Saldo awal

void menuATM() { // Menu ATM
    int pilihan;
    do {
        cout << "\n=== Menu ATM ===" << endl;
        cout << "1. Setor Tunai" << endl;
        cout << "2. Cek Saldo" << endl;
        cout << "3. Tarik Tunai" << endl;
        cout << "4. Keluar" << endl;
        cout << "Pilihan: ";
        cin >> pilihan;

        switch (pilihan) {
            case 1: { // Setor tunai
                int setor;
                do {
                    cout << "Masukkan nominal setor: ";
                    cin >> setor;
                    if (setor > 0) {
                        saldo += setor;
                        cout << "Setor tunai berhasil. Saldo Anda: " << saldo << endl;
                    } else {
                        cout << "Nominal setor harus angka positif" << endl;
                    }
                } while (setor <= 0);
                cin.ignore();
                cin.get();
                break;
            }
            case 2: // Cek saldo
                cout << "Saldo Anda: " << saldo << endl;
                cin.ignore();
                cin.get();
                break;
            
            case 3: { // Tarik tunai
                int tarik;
                do {
                    cout << "Masukkan nominal tarik: ";
                    cin >> tarik;
                    if (tarik > 0) {
                        if (tarik > saldo) {
                            cout << "Saldo tidak mencukupi" << endl;
                        } else {
                            saldo -= tarik;
                            cout << "Tarik tunai berhasil. Saldo Anda: " << saldo << endl;
                        }
                    } else {
                        cout << "Nominal tarik harus angka positif" << endl;
                    }
                } while (tarik <= 0);
                cin.ignore();
                cin.get();
                break;
            }
            case 4: // Pesan keluar
                cout << "Terima kasih telah menggunakan ATM kami" << endl;
                cin.ignore();
                cin.get();
                break;
            default: // Pilihan tidak valid
                cout << "Pilihan tidak valid. Coba lagi" << endl;
        }
    } while (pilihan != 4);
}

int main() {
    int inputPIN;
    int kesempatan = 3; // Jumlah kesempatan

    while (kesempatan > 0) {
        cout << "Masukkan PIN: ";
        cin >> inputPIN;

        if (inputPIN == PIN) {
            cout << "PIN benar. Selamat datang di ATM" << endl;
            menuATM();
            break;
        } else {
            kesempatan--;
            cout << "PIN salah. Kesempatan tersisa: " << kesempatan << endl;
        }
    }

    if (kesempatan == 0) {
        cout << "Akun Anda terblokir. Silakan hubungi bank" << endl;
    }

    return 0;
}