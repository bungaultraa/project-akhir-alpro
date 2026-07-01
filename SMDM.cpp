#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

//=========================================
// Struct Mahasiswa
//=========================================
struct Mahasiswa
{
    string nim;
    string nama;
    string jurusan;
    int semester;
    float ipk;
};

//=========================================
// Class Sistem Manajemen Mahasiswa
//=========================================
class SistemMahasiswa
{
private:
    Mahasiswa data[100];
    int jumlah;

public:

    SistemMahasiswa()
    {
        jumlah = 0;
    }

    //=====================================
    // Tambah Data
    //=====================================
    void tambahData()
    {
        if (jumlah >= 100)
        {
            cout << "\nData sudah penuh!\n";
            return;
        }

        cout << "\n========== TAMBAH DATA ==========\n";

        cin.ignore();

        cout << "NIM        : ";
        getline(cin, data[jumlah].nim);

        // Validasi NIM Tidak Boleh Sama
        for(int i=0;i<jumlah;i++)
        {
            if(data[i].nim == data[jumlah].nim)
            {
                cout << "\nNIM sudah digunakan!\n";
                return;
            }
        }

        cout << "Nama       : ";
        getline(cin,data[jumlah].nama);

        cout << "Jurusan    : ";
        getline(cin,data[jumlah].jurusan);

        cout << "Semester   : ";
        cin >> data[jumlah].semester;

        cout << "IPK        : ";
        cin >> data[jumlah].ipk;

        jumlah++;

        cout << "\nData berhasil ditambahkan.\n";
    }

    //=====================================
    // Tampilkan Data
    //=====================================
    void tampilData()
    {
        if(jumlah==0)
        {
            cout<<"\nBelum ada data mahasiswa.\n";
            return;
        }

        cout<<"\n";
        cout<<"====================================================================================================\n";
        cout<<left
            <<setw(5)<<"No"
            <<setw(15)<<"NIM"
            <<setw(25)<<"Nama"
            <<setw(25)<<"Jurusan"
            <<setw(10)<<"Semester"
            <<setw(10)<<"IPK"<<endl;

        cout<<"====================================================================================================\n";

        for(int i=0;i<jumlah;i++)
        {
            cout<<left
                <<setw(5)<<i+1
                <<setw(15)<<data[i].nim
                <<setw(25)<<data[i].nama
                <<setw(25)<<data[i].jurusan
                <<setw(10)<<data[i].semester
                <<setw(10)<<fixed<<setprecision(2)<<data[i].ipk
                <<endl;
        }

        cout<<"====================================================================================================\n";
    }

    //=====================================
// Cari Data (Linear Search)
//=====================================
void cariData()
{
    if (jumlah == 0)
    {
        cout << "\nBelum ada data mahasiswa.\n";
        return;
    }

    int pilihan;
    bool ditemukan = false;

    cout << "\n========== CARI DATA ==========\n";
    cout << "1. Cari berdasarkan NIM\n";
    cout << "2. Cari berdasarkan Nama\n";
    cout << "Pilihan : ";
    cin >> pilihan;

    cin.ignore();

    if (pilihan == 1)
    {
        string cari;

        cout << "Masukkan NIM : ";
        getline(cin, cari);

        for (int i = 0; i < jumlah; i++)
        {
            if (data[i].nim == cari)
            {
                cout << "\nData Ditemukan\n";

                cout << "NIM       : " << data[i].nim << endl;
                cout << "Nama      : " << data[i].nama << endl;
                cout << "Jurusan   : " << data[i].jurusan << endl;
                cout << "Semester  : " << data[i].semester << endl;
                cout << "IPK       : " << data[i].ipk << endl;

                ditemukan = true;
                break;
            }
        }
    }
    else if (pilihan == 2)
    {
        string cari;

        cout << "Masukkan Nama : ";
        getline(cin, cari);

        for (int i = 0; i < jumlah; i++)
        {
            if (data[i].nama == cari)
            {
                cout << "\nData Ditemukan\n";

                cout << "NIM       : " << data[i].nim << endl;
                cout << "Nama      : " << data[i].nama << endl;
                cout << "Jurusan   : " << data[i].jurusan << endl;
                cout << "Semester  : " << data[i].semester << endl;
                cout << "IPK       : " << data[i].ipk << endl;

                ditemukan = true;
                break;
            }
        }
    }
    else
    {
        cout << "\nPilihan tidak tersedia.\n";
        return;
    }

    if (!ditemukan)
    {
        cout << "\nData tidak ditemukan.\n";
    }
}
    //=====================================
// Edit Data
//=====================================
void editData()
{
    if (jumlah == 0)
    {
        cout << "\nBelum ada data.\n";
        return;
    }

    string cari;
    bool ditemukan = false;

    cin.ignore();

    cout << "\nMasukkan NIM yang akan diedit : ";
    getline(cin, cari);

    for (int i = 0; i < jumlah; i++)
    {
        if (data[i].nim == cari)
        {
            ditemukan = true;

            cout << "\n===== DATA LAMA =====\n";

            cout << "NIM       : " << data[i].nim << endl;
            cout << "Nama      : " << data[i].nama << endl;
            cout << "Jurusan   : " << data[i].jurusan << endl;
            cout << "Semester  : " << data[i].semester << endl;
            cout << "IPK       : " << data[i].ipk << endl;

            cout << "\n===== DATA BARU =====\n";

            cout << "Nama      : ";
            getline(cin, data[i].nama);

            cout << "Jurusan   : ";
            getline(cin, data[i].jurusan);

            cout << "Semester  : ";
            cin >> data[i].semester;

            cout << "IPK       : ";
            cin >> data[i].ipk;

            cout << "\nData berhasil diperbarui.\n";

            break;
        }
    }

    if (!ditemukan)
    {
        cout << "\nNIM tidak ditemukan.\n";
    }
}

    //=====================================
// Hapus Data
//=====================================
void hapusData()
{
    if (jumlah == 0)
    {
        cout << "\nBelum ada data.\n";
        return;
    }

    string cari;
    bool ditemukan = false;
    char konfirmasi;

    cin.ignore();

    cout << "\nMasukkan NIM yang akan dihapus : ";
    getline(cin, cari);

    for (int i = 0; i < jumlah; i++)
    {
        if (data[i].nim == cari)
        {
            ditemukan = true;

            cout << "\nData ditemukan.\n";

            cout << "Nama : " << data[i].nama << endl;

            cout << "Yakin ingin menghapus? (Y/T) : ";
            cin >> konfirmasi;

            if (konfirmasi == 'Y' || konfirmasi == 'y')
            {
                for (int j = i; j < jumlah - 1; j++)
                {
                    data[j] = data[j + 1];
                }

                jumlah--;

                cout << "\nData berhasil dihapus.\n";
            }
            else
            {
                cout << "\nPenghapusan dibatalkan.\n";
            }

            break;
        }
    }

    if (!ditemukan)
    {
        cout << "\nNIM tidak ditemukan.\n";
    }
}

    //=====================================
// Sorting Data (Bubble Sort)
//=====================================
void sortingData()
{
    if (jumlah == 0)
    {
        cout << "\nBelum ada data.\n";
        return;
    }

    int pilihan;

    cout << "\n========== SORTING DATA ==========\n";
    cout << "1. Urutkan berdasarkan NIM\n";
    cout << "2. Urutkan berdasarkan Nama\n";
    cout << "3. Urutkan berdasarkan IPK (Tertinggi)\n";
    cout << "Pilihan : ";
    cin >> pilihan;

    Mahasiswa sementara;

    switch (pilihan)
    {
    case 1:

        for (int i = 0; i < jumlah - 1; i++)
        {
            for (int j = 0; j < jumlah - i - 1; j++)
            {
                if (data[j].nim > data[j + 1].nim)
                {
                    sementara = data[j];
                    data[j] = data[j + 1];
                    data[j + 1] = sementara;
                }
            }
        }

        cout << "\nData berhasil diurutkan berdasarkan NIM.\n";
        break;

    case 2:

        for (int i = 0; i < jumlah - 1; i++)
        {
            for (int j = 0; j < jumlah - i - 1; j++)
            {
                if (data[j].nama > data[j + 1].nama)
                {
                    sementara = data[j];
                    data[j] = data[j + 1];
                    data[j + 1] = sementara;
                }
            }
        }

        cout << "\nData berhasil diurutkan berdasarkan Nama.\n";
        break;

    case 3:

        for (int i = 0; i < jumlah - 1; i++)
        {
            for (int j = 0; j < jumlah - i - 1; j++)
            {
                if (data[j].ipk < data[j + 1].ipk)
                {
                    sementara = data[j];
                    data[j] = data[j + 1];
                    data[j + 1] = sementara;
                }
            }
        }

        cout << "\nData berhasil diurutkan berdasarkan IPK.\n";
        break;

    default:
        cout << "\nPilihan tidak tersedia.\n";
    }
}

    //=====================================
// Statistik
//=====================================
void statistik()
{
    if (jumlah == 0)
    {
        cout << "\nBelum ada data.\n";
        return;
    }

    float total = 0;
    float ipkTertinggi = data[0].ipk;
    float ipkTerendah = data[0].ipk;

    string namaTertinggi = data[0].nama;
    string namaTerendah = data[0].nama;

    for (int i = 0; i < jumlah; i++)
    {
        total += data[i].ipk;

        if (data[i].ipk > ipkTertinggi)
        {
            ipkTertinggi = data[i].ipk;
            namaTertinggi = data[i].nama;
        }

        if (data[i].ipk < ipkTerendah)
        {
            ipkTerendah = data[i].ipk;
            namaTerendah = data[i].nama;
        }
    }

    float rata = total / jumlah;

    cout << "\n========== STATISTIK ==========\n";

    cout << "Jumlah Mahasiswa : " << jumlah << endl;

    cout << "IPK Tertinggi    : "
         << ipkTertinggi
         << " (" << namaTertinggi << ")" << endl;

    cout << "IPK Terendah     : "
         << ipkTerendah
         << " (" << namaTerendah << ")" << endl;

    cout << fixed << setprecision(2);

    cout << "Rata-rata IPK    : "
         << rata << endl;
}

    //=====================================
    // Menu
    //=====================================
    void menu()
    {
        int pilih;

        do
        {
            cout<<"\n";
            cout<<"=====================================================\n";
            cout<<"      SISTEM MANAJEMEN DATA MAHASISWA\n";
            cout<<"=====================================================\n";
            cout<<"1. Tambah Data\n";
            cout<<"2. Tampilkan Data\n";
            cout<<"3. Cari Data\n";
            cout<<"4. Edit Data\n";
            cout<<"5. Hapus Data\n";
            cout<<"6. Sorting Data\n";
            cout<<"7. Statistik\n";
            cout<<"0. Keluar\n";
            cout<<"=====================================================\n";
            cout<<"Pilihan : ";
            cin>>pilih;

            switch(pilih)
            {
                case 1:
                    tambahData();
                    break;

                case 2:
                    tampilData();
                    break;

                case 3:
                    cariData();
                    break;

                case 4:
                    editData();
                    break;

                case 5:
                    hapusData();
                    break;

                case 6:
                    sortingData();
                    break;

                case 7:
                    statistik();
                    break;

                case 0:
                    cout<<"\nTerima kasih.\n";
                    break;

                default:
                    cout<<"\nPilihan tidak tersedia.\n";
            }

        }while(pilih!=0);
    }

};

//=========================================
// Main Program
//=========================================
int main()
{
    SistemMahasiswa sistem;

    sistem.menu();

    return 0;
}