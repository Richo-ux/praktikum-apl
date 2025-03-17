#include <iostream>
#include <string>
using namespace std;

const int MAX_ANIME = 10;
string anime[MAX_ANIME][5] = {
    {"Naruto", "Action", "220", "9", "8.5"},
    {"One Piece", "Adventure", "1100", "20", "9.0"},
    {"Attack on Titan", "Action", "75", "4", "9.1"},
    {"Death Note", "Thriller", "37", "1", "8.7"},
    {"Demon Slayer", "Action", "55", "3", "8.6"}
};
int jumlahAnime = 5;

int main() {
    string nama, nim, role; // tipe data variabel nama, nim, dan role
    int kesempatan = 3; // jumlah kesempatan login
    bool loginBerhasil = false; // status login

    // Login User
    while (kesempatan > 0) {
        cout << "Masukkan Nama: ";
        cin.ignore();
        getline(cin, nama);
        cout << "Masukkan NIM: ";
        getline(cin, nim);

        if (nim == "2409106062") { // NIM admin
            role = "admin";
            break;
        } else if (nim == "2409106063") { // NIM user
            role = "user";
            break;
        } else {
            kesempatan--;
            cout << "Login gagal! Kesempatan tersisa: " << kesempatan << endl;
            continue;
        }
        loginBerhasil = true;
        break;
    }
    if (kesempatan == 0) {
        cout << "\nTerlalu banyak percobaan. Program berhenti." << endl;
        return 0;
    }

    int pilihan;
    do {
        cout << "\n=== Sistem Manajemen Anime ===" << endl;
        cout << "1. Tambah Anime (Admin)" << endl;
        cout << "2. Lihat daftar Anime" << endl;
        cout << "3. Update daftar Anime (Admin)" << endl;
        cout << "4. Hapus Anime (Admin)" << endl;
        cout << "5. Keluar" << endl;
        cout << "Pilihan: ";
        cin >> pilihan;

        if (pilihan == 1 && role == "admin") {
            if (jumlahAnime >= MAX_ANIME) {
                cout << "Data anime sudah penuh!" << endl;
            } else {
                cout << "\nMasukkan data anime:" << endl;
                cout << "Judul: ";
                cin.ignore();
                getline(cin, anime[jumlahAnime][0]);
                cout << "Genre: ";
                getline(cin, anime[jumlahAnime][1]);
                cout << "Jumlah Episode: ";
                cin >> anime[jumlahAnime][2];
                cout << "Jumlah Season: ";
                cin >> anime[jumlahAnime][3];
                cout << "Rating: ";
                cin >> anime[jumlahAnime][4];
                jumlahAnime++;
                cout << "Anime berhasil ditambahkan!" << endl;
            }
        } else if (pilihan == 2) {
            for (int i = 0; i < jumlahAnime; i++) {
                cout << "\nAnime ke-" << i + 1 << ":" << endl;
                cout << "Judul: " << anime[i][0] << endl;
                cout << "Genre: " << anime[i][1] << endl;
                cout << "Jumlah Episode: " << anime[i][2] << endl;
                cout << "Jumlah Season: " << anime[i][3] << endl;
                cout << "Rating: " << anime[i][4] << endl;
            }
        } else if (pilihan == 3 && role == "admin") {
            int index;
            cout << "Masukkan nomor anime yang ingin diupdate: ";
            cin >> index;
            if (index < 1 || index > jumlahAnime) {
                cout << "Nomor tidak valid!" << endl;
            } else {
                index--;
                cout << "\nMasukkan data baru untuk anime:" << endl;
                cout << "Judul: ";
                cin.ignore();
                getline(cin, anime[index][0]);
                cout << "Genre: ";
                getline(cin, anime[index][1]);
                cout << "Jumlah Episode: ";
                cin >> anime[index][2];
                cout << "Jumlah Season: ";
                cin >> anime[index][3];
                cout << "Rating: ";
                cin >> anime[index][4];
                cout << "Anime berhasil diupdate!" << endl;
            }
        } else if (pilihan == 4 && role == "admin") {
            int index;
            cout << "Masukkan nomor anime yang ingin dihapus: ";
            cin >> index;
            if (index < 1 || index > jumlahAnime) {
                cout << "Nomor tidak valid!" << endl;
            } else {
                index--;
                for (int i = index; i < jumlahAnime - 1; i++) {
                    anime[i][0] = anime[i + 1][0];
                    anime[i][1] = anime[i + 1][1];
                    anime[i][2] = anime[i + 1][2];
                    anime[i][3] = anime[i + 1][3];
                    anime[i][4] = anime[i + 1][4];
                }
                jumlahAnime--;
                cout << "Anime berhasil dihapus!" << endl;
            }
        } else if (pilihan == 5) {
            cout << "Terima kasih telah menggunakan program ini. Sayonara :)" << endl;
        } else {
            cout << "Akses ditolak atau pilihan tidak valid!" << endl;
        }
    } while (pilihan != 5);
    return 0;
}