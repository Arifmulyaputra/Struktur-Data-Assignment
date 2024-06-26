#include <iostream>

using namespace std;

// Mendefinisikan struktur buku
struct buku {
    string judulBuku[5];
    string pengarang[5];
    string penerbit[5];
    int tebalHalaman[5];
    int hargaBuku[5];
};

int main() {
    // Mendeklarasikan variabel favorit dengan tipe buku
    buku favorit;

    // Mengisi data ke dalam variabel favorit
    favorit.judulBuku[0] = "Home Sweet Loan";
    favorit.pengarang[0] = "Almira Bartari";
    favorit.penerbit[0] = "Gramedia";
    favorit.tebalHalaman[0] = 312;
    favorit.hargaBuku[0] = 71000;

    favorit.judulBuku[1] = "Bumi";
    favorit.pengarang[1] = "Tere Liye";
    favorit.penerbit[1] = "Gramedia";
    favorit.tebalHalaman[1] = 440;
    favorit.hargaBuku[1] = 103000;

    favorit.judulBuku[2] = "Tentang Kamu";
    favorit.pengarang[2] = "Tere Liye";
    favorit.penerbit[2] = "Republika";
    favorit.tebalHalaman[2] = 524;
    favorit.hargaBuku[2] = 75650;

    favorit.judulBuku[3] = "Laut Bercerita";
    favorit.pengarang[3] = "Leila S. Chudori";
    favorit.penerbit[3] = "Gramedia";
    favorit.tebalHalaman[3] = 220;
    favorit.hargaBuku[3] = 80000;

    favorit.judulBuku[4] = "Lima Sentimeter";
    favorit.pengarang[4] = "Donny Dhirgantoro";
    favorit.penerbit[4] = "Grasindo";
    favorit.tebalHalaman[4] = 81;
    favorit.hargaBuku[4] = 100000;

    // Menampilkan informasi buku favorit
    cout << "\t>> Buku Favorit Saya <<" << endl;
    cout << endl;
    for (int i = 0; i < 5; i++) {
        cout << "\t>> Buku ke-" << i + 1 << endl;
        cout << "\tJudul Buku       : " << favorit.judulBuku[i] << endl;
        cout << "\tPengarang        : " << favorit.pengarang[i] << endl;
        cout << "\tPenerbit         : " << favorit.penerbit[i] << endl;
        cout << "\tTebal Halaman    : " << favorit.tebalHalaman[i] << " halaman" << endl;
        cout << "\tHarga Buku       : Rp " << favorit.hargaBuku[i] << endl;
        cout << endl;
    }

    return 0;
}