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

    void cariData() {
        if (jumlah == 0) {
            cout << "\nBelum ada data.\n";
            return;
        }

        string cari;
        bool ketemu = false;

        cout << "\nMasukkan NIM yang dicari : ";
        cin >> cari;

        for (int i = 0; i < jumlah; i++) {
            if (nim[i] == cari) {
                cout << "\nData ditemukan\n";
                cout << "NIM      : " << nim[i] << endl;
                cout << "Nama     : " << nama[i] << endl;
                cout << "Jurusan  : " << jurusan[i] << endl;
                ketemu = true;
                break;
            }
        }

        if (!ketemu) {
            cout << "\nData tidak ditemukan.\n";
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
        cout << "3. Cari Data\n";
        cout << "4. Urutkan Nim\n";
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
                mhs.cariData();
                break;

            case 4:
                mhs.urutNama();
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