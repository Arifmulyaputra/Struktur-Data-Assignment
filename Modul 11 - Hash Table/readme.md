# <h1 align="center">Laporan Praktikum Modul 11 Hash Table</h1>
<p align="center">2311110017 / Arif Mulya Putra / Sains Data</p>

## Dasar Teori

#### 1. Pengertian Hash Table

Hash table adalah sebuah struktur data yang digunakan untuk menyimpan data secara asosiatif, yang berarti data disimpan dalam format array di mana setiap data memiliki indeks uniknya sendiri. Akses ke data menjadi sangat cepat jika indeks data tersebut diketahui. Menurut Singh, S. dan rekan-rekannya (2022), hash table adalah struktur data yang efektif untuk penyimpanan dan pengambilan data dengan cepat. Hash table bekerja dengan memetakan kunci data ke indeks dalam array, dan indeks ini digunakan untuk menyimpan data dalam array. Pencarian data dalam hash table sangat efisien karena nilai hash dari kunci data dapat dihitung dengan cepat dan digunakan untuk menentukan indeks array tempat data disimpan [2].

#### 2. Fungsi Hash Table

- Penyimpanan Data Asosiatif: Hash table memungkinkan penyimpanan data dengan kunci unik dan pengambilan data dengan cepat berdasarkan kunci tersebut.

- Pencarian Data yang Cepat: Hash table menawarkan waktu pencarian yang sangat cepat, rata-rata O(1), dibandingkan dengan struktur data lain seperti pohon pencarian biner yang memiliki waktu pencarian rata-rata O(log n).

- Penghematan Memori: Hash table dapat menghemat memori dengan menyimpan data secara kompak, terutama jika kunci data pendek.

- Implementasi yang Mudah: Hash table relatif mudah diimplementasikan dan dipahami.

#### 3. Sistem Hash Table

Hash table adalah struktur data yang sangat efisien untuk menyimpan dan mengambil data, menggunakan fungsi hash untuk mengubah kunci menjadi indeks dalam array, yang memungkinkan akses cepat ke nilai terkait. Menurut Chen, J. dan rekan-rekannya (2019), hash table menawarkan waktu pencarian yang cepat dan dapat menyimpan data dalam jumlah besar secara efisien. Namun, hash table bisa mengalami tabrakan, yaitu ketika dua kunci yang berbeda dipetakan ke indeks yang sama dalam array, yang dapat memperlambat kinerja [3].

- Hashing (Menghitung Hash Code)

Fungsi hash mengubah kunci menjadi indeks dalam array. Fungsi hash harus mendistribusikan kunci secara merata untuk menghindari tabrakan.

- Inserting (Memasukkan Data)

Proses memasukkan data ke dalam hash table:
Hashing the Key: Gunakan fungsi hash untuk menghitung hash code dari kunci.
Index Calculation: Gunakan hash code untuk menentukan indeks dalam array.
Handling Collisions: Jika indeks sudah ditempati, gunakan metode penanganan tabrakan seperti chaining atau open addressing.

- Searching (Mencari Data)

Proses pencarian data pada hash table:
Hashing the Key: Hitung hash code dari kunci yang dicari.
Index Calculation: Tentukan indeks dari hash code.
Traversing (Jika Diperlukan): Jika terjadi tabrakan, telusuri entri yang bertabrakan hingga menemukan kunci yang sesuai atau memastikan bahwa kunci tidak ada.

- Deleting (Menghapus Data)

Proses penghapusan data pada hash table:
Hashing the Key: Hitung hash code dari kunci yang akan dihapus.
Index Calculation: Tentukan indeks dari hash code.
Traversing (Jika Diperlukan): Jika terjadi tabrakan, telusuri entri yang bertabrakan hingga menemukan kunci yang sesuai.
Removing Entry: Hapus entri tersebut, dan jika menggunakan open addressing, pastikan untuk menandai slot sebagai dihapus (tergantung pada implementasi).

- Handling Collisions (Menangani Tabrakan)

Metode umum untuk menangani tabrakan:
Chaining: Menggunakan linked list di setiap slot array untuk menyimpan beberapa elemen dengan hash code yang sama.
Open Addressing: Mencari slot kosong berikutnya di array menggunakan metode seperti linear probing, quadratic probing, atau double hashing.

- Resizing (Mengubah Ukuran)

Ketika hash table terlalu penuh, performanya bisa menurun. Oleh karena itu, resizing diperlukan untuk membuat array baru yang lebih besar, menghitung ulang indeks untuk setiap elemen dalam hash table lama, dan memasukkan elemen-elemen tersebut ke dalam array baru.


#### 4. Kelebihan dan Kekuarangan Hash Table

Kelebihan Hash Table:

- Efisiensi Waktu: Hash table memungkinkan akses data yang cepat dan efisien [1].
- Penghematan Ruang Penyimpanan: Hash table menghemat ruang penyimpanan dengan mengubah data menjadi nilai hash yang lebih kecil [1].
- Pengurangan Waktu Pengembangan: Hash table mengurangi waktu pengembangan dengan menyederhanakan kompleksitas kode [1].

Kekurangan Hash Table:

- Collision: Hash table dapat mengalami tabrakan saat dua kunci memiliki nilai hash yang sama [1].
- Penurunan Performa: Hash table bisa mengalami penurunan performa jika tidak digunakan dengan benar [1].
- Pengurangan Keamanan: Hash table bisa mengurangi keamanan jika tidak diterapkan dengan tepat [1].

#### 5. Jenis-Jenis Hash Table:

- Hash Table Statis: Ukuran array pada hash table statis tidak dapat diubah setelah diciptakan.
- Hash Table Dinamis: Ukuran array pada hash table dinamis bisa berubah secara otomatis saat data ditambahkan atau dihapus.
- Hash Table Berantai: Hash table berantai digunakan untuk menangani tabrakan, yaitu ketika dua kunci berbeda dipetakan ke indeks yang sama dalam array.
- Pohon Hash: Pohon hash adalah struktur data gabungan yang mengombinasikan hash table dengan pohon pencarian biner.


## Guided

### 1.
```C++
#include <iostream>
using namespace std;
const int MAX_SIZE = 10;

// Fungsi hash sederhana
int hash_func(int key) {
    return key % MAX_SIZE;
}

// Struktur data untuk setiap node
struct Node {
    int key;
    int value;
    Node* next;
    Node(int key, int value) : key(key), value(value), next(nullptr) {}
};

// Class hash table
class HashTable {
private:
    Node** table;
public:
    HashTable() {
        table = new Node*[MAX_SIZE]();
    }
    ~HashTable() {
        for (int i = 0; i < MAX_SIZE; i++) {
            Node* current = table[i];
            while (current != nullptr) {
                Node* temp = current;
                current = current->next;
                delete temp;
            }
        }
        delete[] table;
    }

    // Insertion
    void insert(int key, int value) {
        int index = hash_func(key);
        Node* current = table[index];
        while (current != nullptr) {
            if (current->key == key) {
                current->value = value;
                return;
            }
            current = current->next;
        }
        Node* node = new Node(key, value);
        node->next = table[index];
        table[index] = node;
    }

    // Searching
    int get(int key) {
        int index = hash_func(key);
        Node* current = table[index];
        while (current != nullptr) {
            if (current->key == key) {
                return current->value;
            }
            current = current->next;
        }
        return -1;
    }

    // Deletion
    void remove(int key) {
        int index = hash_func(key);
        Node* current = table[index];
        Node* prev = nullptr;
        while (current != nullptr) {
            if (current->key == key) {
                if (prev == nullptr) {
                    table[index] = current->next;
                } else {
                    prev->next = current->next;
                }
                delete current;
                return;
            }
            prev = current;
            current = current->next;
        }
    }

    // Traversal
    void traverse() {
        for (int i = 0; i < MAX_SIZE; i++) {
            Node* current = table[i];
            while (current != nullptr) {
                cout << current->key << ": " << current->value << endl;
                current = current->next;
            }
        }
    }
};

int main() {
    HashTable ht;
    // Insertion
    ht.insert(1, 10);
    ht.insert(2, 20);
    ht.insert(3, 30);

    // Searching
    cout << "Get key 1: " << ht.get(1) << endl;
    cout << "Get key 4: " << ht.get(4) << endl;
   
    // Deletion
    ht.remove(4);
   
    // Traversal
    ht.traverse();
   
    return 0;
}
```

Penjelasan:

Program ini adalah sebuah hash table sederhana dengan ukuran maksimum 10 yang menggunakan teknik chaining untuk menangani collision. Fungsi hash `hash_func` digunakan untuk menghitung indeks kunci dengan operasi modulo. Setiap entri dalam hash table merupakan sebuah linked list yang terdiri dari node-node dengan pasangan kunci-nilai. Kelas `HashTable` menyediakan metode untuk menyisipkan (insert) pasangan kunci-nilai, mencari nilai berdasarkan kunci (get), menghapus pasangan kunci-nilai (remove), dan menelusuri seluruh isi hash table (traverse). Pada fungsi `main`, dilakukan beberapa operasi seperti penyisipan tiga pasangan kunci-nilai, pencarian nilai berdasarkan kunci, penghapusan, dan penelusuran untuk menampilkan semua pasangan kunci-nilai yang ada di hash table.

### 2.
```C++
#include <iostream>
#include <string>
#include <vector>

using namespace std;
const int TABLE_SIZE = 11;

string name;
string phone_number;

class HashNode {
public:
    string name;
    string phone_number;

    HashNode(string name, string phone_number) {
        this->name = name;
        this->phone_number = phone_number;
    }
};

class HashMap {
private:
    vector<HashNode*> table[TABLE_SIZE];
public:
    int hashFunc(string key) {
        int hash_val = 0;
        for (char c : key) {
            hash_val += c;
        }
        return hash_val % TABLE_SIZE;
    }

    void insert(string name, string phone_number) {
        int hash_val = hashFunc(name);

        for (auto node : table[hash_val]) {
            if (node->name == name) {
                node->phone_number = phone_number;
                return;
            }
        }
        table[hash_val].push_back(new HashNode(name, phone_number));
    }

    void remove(string name) {
        int hash_val = hashFunc(name);

        for (auto it = table[hash_val].begin(); it != table[hash_val].end(); it++) {
            if ((*it)->name == name) {
                table[hash_val].erase(it);
                return;
            }
        }
    }

    string searchByName(string name) {
        int hash_val = hashFunc(name);
        for (auto node : table[hash_val]) {
            if (node->name == name) {
                return node->phone_number;
            }
        }
        return "";
    }

    void print() {
        for (int i = 0; i < TABLE_SIZE; i++) {
            cout << i << ": ";
            for (auto pair : table[i]) {
                if (pair != nullptr) {
                    cout << "[" << pair->name << ", " << pair->phone_number << "]";
                }
            }
            cout << endl;
        }
    }
};

int main() {
    HashMap employee_map;

    employee_map.insert("Mistah", "1234");
    employee_map.insert("Pastah", "5678");
    employee_map.insert("Ghana", "91011");

    cout << "Nomer Hp Mistah : " << employee_map.searchByName("Mistah") << endl;
    cout << "Phone Hp Pastah : " << employee_map.searchByName("Pastah") << endl;

    employee_map.remove("Mistah");

    cout << "Nomer Hp Mistah setelah dihapus : " << employee_map.searchByName("Mistah") << endl << endl;

    cout << "Hash Table : " << endl;

    employee_map.print();

    return 0;
}
```

Penjelasan:

Kode ini mendefinisikan sebuah hash table sederhana dengan ukuran tabel 11 untuk menyimpan pasangan nama dan nomor telepon menggunakan teknik chaining untuk mengatasi collision. Setiap entri dalam tabel merupakan sebuah vektor yang menyimpan objek `HashNode`, masing-masing berisi nama dan nomor telepon. Kelas `HashMap` menyediakan metode `hashFunc` untuk menghitung indeks menggunakan jumlah karakter ASCII dari nama, `insert` untuk menambah atau memperbarui data, remove untuk menghapus data berdasarkan nama, `searchByName` untuk mencari nomor telepon dari nama. Pada fungsi `main`, beberapa operasi dilakukan seperti menambahkan tiga karyawan, mencari nomor telepon, menghapus data karyawan, dan mencetak isi hash table. 

## Unguided 

#### 1. Buatlah sebuah program Rekursif Langsung (Direct Recursion) yang menghitung nilai faktorial dari sebuah inputan bilangan bulat positif!

```C++
#include <iostream>
#include <iomanip>
using namespace std;

const int MAX_SIZE = 10;

struct Mahasiswa
{
    string nama;
    long long NIM;
    int nilai;
    Mahasiswa *next; 

    Mahasiswa(string nama, long long NIM, int nilai) : nama(nama), NIM(NIM), nilai(nilai), next(nullptr) {}
};

class HashTable
{
private:
    Mahasiswa **table; 
    int hash_func(long long key)
    {
        return key % MAX_SIZE;
    }

public:
    HashTable()
    {
        table = new Mahasiswa *[MAX_SIZE](); 
    }

    ~HashTable()
    {
        for (int i = 0; i < MAX_SIZE; ++i)
        {
            Mahasiswa *current = table[i];
            while (current != nullptr)
            {
                Mahasiswa *temp = current;
                current = current->next;
                delete temp;
            }
        }
        delete[] table;
    }

    
    void insert(string nama, long long NIM, int nilai)
    {
        int index = hash_func(NIM);                                 
        Mahasiswa *new_mahasiswa = new Mahasiswa(nama, NIM, nilai); 
        new_mahasiswa->next = table[index];                         
        table[index] = new_mahasiswa;
    }

    void remove(long long NIM)
    {
        int index = hash_func(NIM);        
        Mahasiswa *current = table[index]; 
        Mahasiswa *prev = nullptr;         
        while (current != nullptr)
        {
            if (current->NIM == NIM)
            {
                if (prev == nullptr)
                {
                    table[index] = current->next; 
                }
                else
                {
                    prev->next = current->next; 
                }
                delete current; 
                cout << "Mahasiswa dengan NIM " << NIM << " telah dihapus." << endl;
                return;
            }
            prev = current;
            current = current->next;
        }
        cout << "Mahasiswa dengan NIM " << NIM << " tidak ditemukan." << endl;
    }

    Mahasiswa *cari_NIM(long long NIM)
    {
        int index = hash_func(NIM); 
        Mahasiswa *current = table[index]; 
        while (current != nullptr)
        {
            if (current->NIM == NIM)
            {
                return current; 
            }
            current = current->next;
        }
        return nullptr;
    }

    void cari_nilai(int awal, int akhir)
    {
        cout << "+---------------------+-----------------+---------------+" << endl;
        cout << "|       Nama          |       NIM       |     Nilai     |" << endl;
        cout << "+---------------------+-----------------+---------------+" << endl;
        for (int i = 0; i < MAX_SIZE; ++i)
        {
            Mahasiswa *current = table[i]; 
            while (current != nullptr)
            {
              
                if (current->nilai >= awal && current->nilai <= akhir)
                {
                    cout << "| " << setw(19) << left << current->nama
                         << "| " << setw(15) << current->NIM
                         << "| " << setw(13) << current->nilai << " |" << endl;
                }
                current = current->next;
            }
        }
        cout << "+---------------------+-----------------+---------------+" << endl;
    }

    // fungsi untuk menampilkan semua data mahasiswa
    void traverse()
    {
        // mencetak header tabel
        cout << "+---------------------+-----------------+---------------+" << endl;
        cout << "|       Nama          |       NIM       |     Nilai     |" << endl;
        cout << "+---------------------+-----------------+---------------+" << endl;
        // traverse semua bucket pada tabel hash
        for (int i = 0; i < MAX_SIZE; ++i)
        {
            Mahasiswa *current = table[i]; // mengambil node pertama di indeks yang tepat
            while (current != nullptr)
            {

                cout << "| " << setw(19) << left << current->nama
                     << "| " << setw(15) << current->NIM
                     << "| " << setw(13) << current->nilai << " |" << endl;
                current = current->next;
            }
        }
        cout << "+---------------------+-----------------+---------------+" << endl;
    }
};

int main()
{
    HashTable ht;

    int pilih, nilai, awal, akhir;
    string nama;
    long long NIM;

    do
    {
        cout << "\nMenu:" << endl;
        cout << "1. Tambah Data Mahasiswa" << endl;
        cout << "2. Hapus Data Mahasiswa" << endl;
        cout << "3. Cari berdasarkan NIM" << endl;
        cout << "4. Cari berdasarkan Rentang Nilai" << endl;
        cout << "5. Tampilkan Semua Data" << endl;
        cout << "6. Keluar" << endl;
        cout << "Pilih menu : ";
        cin >> pilih;

        switch (pilih)
        {
        case 1:
            cout << "Masukkan nama : ";
            cin.ignore();
            getline(cin, nama);
            cout << "Masukkan NIM : ";
            cin >> NIM;
            cout << "Masukkan nilai : ";
            cin >> nilai;
            ht.insert(nama, NIM, nilai);
            cout << "Data berhasil ditambahkan" << endl;
            break;
        case 2:
            cout << "Masukkan NIM yang ingin dihapus : ";
            cin >> NIM;
            ht.remove(NIM);
            break;
        case 3:
            cout << "Masukkan NIM yang ingin dicari : ";
            cin >> NIM;
            {
                Mahasiswa *mahasiswa_ptr = ht.cari_NIM(NIM);
                if (mahasiswa_ptr)
                {
                    cout << "Ditemukan mahasiswa dengan NIM " << NIM << " bernama " << mahasiswa_ptr->nama << " dan memiliki nilai " << mahasiswa_ptr->nilai << endl;
                }
                else
                {
                    cout << "Mahasiswa dengan NIM " << NIM << " tidak ditemukan" << endl;
                }
            }
            break;
        case 4:
            cout << "Masukkan nilai awal : ";
            cin >> awal;
            cout << "Masukkan nilai akhir : ";
            cin >> akhir;
            ht.cari_nilai(awal, akhir);
            break;
        case 5:
            ht.traverse();
            break;
        default:
            cout << "Pilihan tidak valid!" << endl;
        }
    } while (pilih != 6);

    return 0;
}
```
Output :
![image](https://github.com/Arifmulyaputra/Struktur-Data-Assignment/assets/161549884/d84ab46e-1494-4803-aed6-3af698c580d7)
![image](https://github.com/Arifmulyaputra/Struktur-Data-Assignment/assets/161549884/7f4dcd2f-eb38-4046-986a-04554b0a7038)
![image](https://github.com/Arifmulyaputra/Struktur-Data-Assignment/assets/161549884/daae0e8b-9cf8-4e63-b20d-dc6293b76f68)
![image](https://github.com/Arifmulyaputra/Struktur-Data-Assignment/assets/161549884/5b678619-0501-4740-9dd6-529bbd865e6c)

Penjelasan:

Kode ini membuat sebuah hash table untuk mengelola data mahasiswa dengan atribut nama, NIM, dan nilai. Struktur data hash table menggunakan linked list pada setiap slot tabel untuk menangani collision. Kelas HashTable menyediakan fungsi-fungsi untuk menambah, menghapus, mencari mahasiswa berdasarkan NIM, mencari mahasiswa dalam rentang nilai tertentu, dan menampilkan seluruh data mahasiswa. Program utama menyediakan antarmuka menu bagi pengguna untuk melakukan operasi-operasi tersebut secara interaktif. Fungsi hash didasarkan pada nilai NIM yang dibagi dengan ukuran tabel, dan data mahasiswa disimpan dalam linked list di slot yang sesuai. Program ini memastikan bahwa data dapat dikelola secara efisien dan memudahkan pencarian serta pengelolaan informasi mahasiswa.

## Kesimpulan

Hash table adalah struktur data yang efisien untuk menyimpan dan mengakses data dengan cepat, memetakan kunci ke indeks dalam array. Dengan menggunakan fungsi hash, hash table dapat memberikan pencarian data yang cepat dengan kompleksitas waktu rata-rata O(1). Namun, penggunaan yang tidak tepat dapat menghasilkan tabrakan, yang berpotensi merugikan performa dan keamanan hash table. Meskipun demikian, hash table tetap menjadi pilihan populer dalam pengembangan aplikasi karena keunggulan seperti efisiensi waktu, penghematan ruang penyimpanan, dan kemudahan pengembangan. Berbagai jenis hash table, seperti statis, dinamis, berantai, dan pohon hash, memberikan fleksibilitas dalam memproses data sesuai dengan kebutuhan dan kompleksitas aplikasi. Oleh karena itu, hash table merupakan alat yang sangat berguna dalam mengelola dan mengakses data dalam berbagai konteks komputasi.

## Referensi

[1] Joseph Teguh Santoso. *Struktur Data dan Algoritma*. Yayasan Primaagus Teknik. Semarang. 2021

[2] Singh, S., & Kumar, R. *Efficient Hash Table Based Data Structure for IoT Applications*. IEEE Access, 2022.

[3] Chen, J., & Li, Y. *Improved Hash Table Based Data Structure for Network Applications*. IEEE Transactions on Network and Information Systems Management, 2019.
