#include <iostream>
#include <string>
using namespace std;

const int MAX_ANIME = 100;

// Struktur untuk menyimpan data anime
struct Anime {
    string judul;
    string genre;
    string jumlahEpisode;
    string jumlahSeason;
    string rating;
};

Anime anime[MAX_ANIME] = {
    {"Naruto", "Action", "220", "9", "8.5"},
    {"One Piece", "Adventure", "1100", "20", "9.0"},
    {"Attack on Titan", "Action", "75", "4", "9.1"},
    {"Death Note", "Thriller", "37", "1", "8.7"},
    {"Demon Slayer", "Action", "55", "3", "8.6"}
};
int jumlahAnime = 5;

const string adminNIM = "2409106062";
const string userNIM = "2409106063";

// Tambah data
void tambahAnime(Anime anime[], int &jumlahAnime) {
    if (jumlahAnime >= MAX_ANIME) {
        cout << "Data anime sudah penuh!" << endl;
    } else {
        cout << "\nMasukkan data anime:" << endl;
        cout << "Judul: ";
        cin.ignore();
        getline(cin, anime[jumlahAnime].judul);
        cout << "Genre: ";
        getline(cin, anime[jumlahAnime].genre);
        cout << "Jumlah Episode: ";
        cin >> anime[jumlahAnime].jumlahEpisode;
        cout << "Jumlah Season: ";
        cin >> anime[jumlahAnime].jumlahSeason;
        cout << "Rating: ";
        cin >> anime[jumlahAnime].rating;
        jumlahAnime++;
        cout << "Anime berhasil ditambahkan!" << endl;
    }
}

// Tampilkan data
void tampilAnime(Anime anime[], int jumlahAnime) {
    for (int i = 0; i < jumlahAnime; i++) {
        cout << "\nAnime ke-" << i + 1 << ":" << endl;
        cout << "Judul: " << anime[i].judul << endl;
        cout << "Genre: " << anime[i].genre << endl;
        cout << "Jumlah Episode: " << anime[i].jumlahEpisode << endl;
        cout << "Jumlah Season: " << anime[i].jumlahSeason << endl;
        cout << "Rating: " << anime[i].rating << endl;
    }
}

// Update data
void updateAnime(Anime anime[], int jumlahAnime) {
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
        getline(cin, anime[index].judul);
        cout << "Genre: ";
        getline(cin, anime[index].genre);
        cout << "Jumlah Episode: ";
        cin >> anime[index].jumlahEpisode;
        cout << "Jumlah Season: ";
        cin >> anime[index].jumlahSeason;
        cout << "Rating: ";
        cin >> anime[index].rating;
        cout << "Anime berhasil diupdate!" << endl;
    }
}

// Hapus data
void hapusAnime(Anime anime[], int &jumlahAnime) {
    int index;
    cout << "Masukkan nomor anime yang ingin dihapus: ";
    cin >> index;
    if (index < 1 || index > jumlahAnime) {
        cout << "Nomor tidak valid!" << endl;
    } else {
        index--;
        for (int i = index; i < jumlahAnime - 1; i++) {
            anime[i] = anime[i + 1];
        }
        jumlahAnime--;
        cout << "Anime berhasil dihapus!" << endl;
    }
}

int main() {
    string nama, nim, role;
    int kesempatan = 3;
    bool loginBerhasil = false;

    while (kesempatan > 0) {
        cout << "Masukkan Nama: ";
        cin.ignore();
        getline(cin, nama);
        cout << "Masukkan NIM: ";
        getline(cin, nim);

        if (nim == adminNIM) {
            role = "admin";
        } else if (nim == userNIM) {
            role = "user";
        } else {
            kesempatan--;
            cout << "Login gagal! Kesempatan tersisa: " << kesempatan << endl;
            continue;
        }
        loginBerhasil = true;
        break;
    }

    if (!loginBerhasil) {
        cout << "\nTerlalu banyak percobaan. Program berhenti." << endl;
        return 0;
    }

    int pilihan;
    do {
        cout << "\n=== Sistem Manajemen Anime ===" << endl;
        cout << "1. Tambah Anime (Admin)" << endl;
        cout << "2. Lihat Anime" << endl;
        cout << "3. Update Anime (Admin)" << endl;
        cout << "4. Hapus Anime (Admin)" << endl;
        cout << "5. Keluar" << endl;
        cout << "Pilihan: ";
        cin >> pilihan;

        if (pilihan == 1 && role == "admin") {
            tambahAnime(anime, jumlahAnime);
        } else if (pilihan == 2) {
            tampilAnime(anime, jumlahAnime);
        } else if (pilihan == 3 && role == "admin") {
            updateAnime(anime, jumlahAnime);
        } else if (pilihan == 4 && role == "admin") {
            hapusAnime(anime, jumlahAnime);
        } else if (pilihan == 5) {
            cout << "Terima kasih telah menggunakan sistem ini!" << endl;
        } else {
            cout << "Akses ditolak atau pilihan tidak valid!" << endl;
        }
    } while (pilihan != 5);

    return 0;
}