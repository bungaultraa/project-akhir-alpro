#include <iostream>
#include <string>
using namespace std;

class Mahasiswa {
private:
    string nim[100];
    string nama[100];
    string jurusan[100];
    int jumlah;

public:
    Mahasiswa() {
        jumlah = 0;
    }

    void tambahData() {
        if (jumlah == 100) {
            cout << "\nData sudah penuh!\n";
            return;
        }

        cout << "\n=== Tambah Data Mahasiswa ===\n";
        cout << "NIM      : ";
        cin >> nim[jumlah];
        cin.ignore();

        cout << "Nama     : ";
        getline(cin, nama[jumlah]);

        cout << "Jurusan  : ";
        getline(cin, jurusan[jumlah]);

        jumlah++;

        cout << "\nData berhasil ditambahkan.\n";
    }

    void tampilData() {
        if (jumlah == 0) {
            cout << "\nBelum ada data.\n";
            return;
        }

        cout << "\n===== DATA MAHASISWA =====\n";

        for (int i = 0; i < jumlah; i++) {
            cout << "\nData ke-" << i + 1 << endl;
            cout << "NIM      : " << nim[i] << endl;
            cout << "Nama     : " << nama[i] << endl;
            cout << "Jurusan  : " << jurusan[i] << endl;
        }
    }

    
    void urutNama() {
    if (jumlah == 0) {
        cout << "\nBelum ada data.\n";
        return;
    }

    for (int i = 0; i < jumlah - 1; i++) {
        for (int j = 0; j < jumlah - i - 1; j++) {

            if (nim[j] > nim[j + 1]) {

                string temp;

                temp = nim[j];
                nim[j] = nim[j + 1];
                nim[j + 1] = temp;

                temp = nama[j];
                nama[j] = nama[j + 1];
                nama[j + 1] = temp;

                temp = jurusan[j];
                jurusan[j] = jurusan[j + 1];
                jurusan[j + 1] = temp;
            }
        }
    }

    cout << "\nData berhasil diurutkan berdasarkan NIM.\n";
    }

    void cariData() {
        if (jumlah == 0) {
            cout << "\nBelum ada data.\n";
            return;
        }

        string cari;
        cout << "\nMasukkan NIM yang dicari : ";
        cin >> cari;

        // Inisialisasi batas awal (kiri) dan batas akhir (kanan)
        int kiri = 0;
        int kanan = jumlah - 1;
        int indexKetemu = -1;

        // Proses Binary Search
        while (kiri <= kanan) {
            int tengah = kiri + (kanan - kiri) / 2; // Mencari titik tengah secara aman

            if (nim[tengah] == cari) {
                indexKetemu = tengah; // Data ditemukan!
                break;
            }
            else if (nim[tengah] < cari) {
                kiri = tengah + 1; // Geser batas kiri ke kanan jika NIM tengah lebih kecil
            }
            else {
                kanan = tengah - 1; // Geser batas kanan ke kiri jika NIM tengah lebih besar
            }
        }

        // Output Hasil Pencarian
        if (indexKetemu != -1) {
            cout << "\nData ditemukan\n";
            cout << "NIM      : " << nim[indexKetemu] << endl;
            cout << "Nama     : " << nama[indexKetemu] << endl;
            cout << "Jurusan  : " << jurusan[indexKetemu] << endl;
        } else {
            cout << "\nData tidak ditemukan.\n";
        }
    }
    

    void hapusData() {
        if (jumlah == 0) {
            cout << "\nBelum ada data.\n";
            return;
        }

        string cari;
        cout << "\nMasukkan NIM yang akan dihapus : ";
        cin >> cari;

        int index = -1;

        for (int i = 0; i < jumlah; i++) {
            if (nim[i] == cari) {
                index = i;
                break;
            }
        }

        if (index == -1) {
            cout << "\nData tidak ditemukan.\n";
            return;
        }

        for (int i = index; i < jumlah - 1; i++) {
            nim[i] = nim[i + 1];
            nama[i] = nama[i + 1];
            jurusan[i] = jurusan[i + 1];
        }

        jumlah--;

        cout << "\nData berhasil dihapus.\n";
    }
};

int main() {

    Mahasiswa mhs;
    int pilih;

    do {
        cout << "\n=============================\n";
        cout << " SISTEM MANAJEMEN MAHASISWA\n";
        cout << "=============================\n";
        cout << "1. Tambah Data\n";
        cout << "2. Tampilkan Data\n";
        cout << "3. Urutkan Data\n";
        cout << "4. Cari Data\n";
        cout << "5. Hapus Data\n";
        cout << "0. Keluar\n";
        cout << "Pilih : ";
        cin >> pilih;

        switch (pilih) {
            case 1:
                mhs.tambahData();
                break;

            case 2:
                mhs.tampilData();
                break;

            case 3:
                mhs.urutNama();
                break;

            case 4:
                mhs.cariData();
                break;

            case 5:
                mhs.hapusData();
                break;

            case 0:
                cout << "\nProgram selesai.\n";
                break;

            default:
                cout << "\nPilihan tidak tersedia.\n";
        }

    } while (pilih != 0);

    return 0;
}