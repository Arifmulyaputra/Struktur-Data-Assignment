# <h1 align="center">Laporan Praktikum Modul 7 Stack</h1>
<p align="center">2311110017 / Arif Mulya Putra / Sains Data</p>

## Dasar Teori

#### 1. Pengertian Stack

Stack adalah kumpulan data yang disusun bertingkat di mana data bisa ditambah atau diambil dari ujung atas, yang disebut sebagai ujung atas tumpukan. Contoh sederhana adalah dua kotak ditumpuk, dengan kemampuan menambah dan mengambil kotak dari ujung atas. Stack kotak bisa terdiri dari N kotak, di mana setiap aksi dilakukan pada ujung atas tumpukan. Stack adalah struktur data dinamis yang memungkinkan penambahan dan penghapusan data [1].

#### 2. Karakteristik Stack

- LIFO (Last In First Out): Data yang terakhir dimasukkan ke dalam stack akan pertama keluar dari stack [2]. 
- Elemen Paling Atas untuk Operasi: Elemen yang teratas digunakan untuk operasi seperti push dan pop [2].
- Penyisipan dan Penghapusan di Satu Ujung: Penyisipan dan penghapusan elemen terjadi di satu ujung, yaitu dari atas tumpukan [2].
- Keterbatasan Ukuran Memori: Stack memiliki keterbatasan ukuran memori, yang dapat menyebabkan stack overflow jika terlalu banyak elemen ditambahkan [2].
- Akses Data Secara Akan Tidak Dimungkinkan: Stack tidak memungkinkan akses data secara acak, hanya data yang berada pada bagian atas yang dapat diakses [2].

#### 3. Kelebihan dan Kekurangan Stack

Kelebihan Stack:
- Manajemen data efisien [3].
- Manajemen fungsi efisien [3].	
- Kontrol atas pengalokasian memori [3].	
- Manajemen smart memory yang membersihkan objek secara otomatis [3].
- Lebih tahan lama, aman, dan tidak ada pengubahan ukuran variabel [3].

Kekurangan Stack:
- Ukuran memori terbatas [3].
- Banyaknya objek dan meningkatkan risiko Stack Overflow [3].
- Tidak memungkinkan adanya akses acak [3].
- Fungsi dan program tidak terdefinisi jika penyimpanan variabel ditimpa variabel lain [3].
- Potensi terjadinya hang atau penghentian yang tidak diinginkan ketika tumpukan berada di luar area memori [3].


## Guided

### 1.
```C++
#include <iostream>
using namespace std;

const int maksimal = 5;
string arrayBuku[maksimal];
int top = 0;

bool isFull() {
    return (top == maksimal);
}

bool isEmpty() {
    return (top == 0);
}

void pushArrayBuku(string data) {
    if (isFull()) {
        cout << "Data telah penuh" << endl;
    } else {
        arrayBuku[top++] = data;
    }
}

void popArrayBuku() {
    if (isEmpty()) {
        cout << "Tidak ada data yang dihapus" << endl;
    } else {
        arrayBuku[--top] = "";
    }
}

void peekArrayBuku(int posisi) {
    if (isEmpty()) {
        cout << "Tidak ada data yang bisa dilihat" << endl;
    } else if (posisi <= top) {
        cout << "Posisi ke " << posisi << " adalah " << arrayBuku[top - posisi] << endl;
    } else {
        cout << "Posisi melebihi data yang ada" << endl;
    }
}

int countStack() {
    return top;
}

void changeArrayBuku(int posisi, string data) {
    if (posisi <= top) {
        arrayBuku[top - posisi] = data;
    } else {
        cout << "Posisi melebihi data yang ada" << endl;
    }
}

void destroyArraybuku() {
    while (!isEmpty()) {
        popArrayBuku();
    }
}

void cetakArrayBuku() {
    if (isEmpty()) {
        cout << "Tidak ada data yang dicetak" << endl;
    } else {
        for (int i = top - 1; i >= 0; i--) {
            cout << arrayBuku[i] << endl;
        }
    }
}

int main() {
    pushArrayBuku("Kalkulus");
    pushArrayBuku("Struktur Data");
    pushArrayBuku("Matematika Diskrit");
    pushArrayBuku("Dasar Multimedia");
    pushArrayBuku("Inggris");

    cetakArrayBuku();
    cout << "\n";

    cout << "Apakah data stack penuh? " << isFull() << endl;
    cout << "Apakah data stack kosong? " << isEmpty() << endl;

    peekArrayBuku(2);
    popArrayBuku();

    cout << "Banyaknya data = " << countStack() << endl;

    changeArrayBuku(2, "Bahasa Jerman");
    cetakArrayBuku();

    cout << "\n";
    destroyArraybuku();
    cout << "Jumlah data setelah dihapus: " << top << endl;

    cetakArrayBuku();

    return 0;
}
```

Penjelasan:

Program ini menggunakan array untuk menyimpan data buku dengan ukuran maksimal sebanyak 5 elemen. Fungsi-fungsi yang disediakan termasuk: `isFull()` yang mengembalikan true jika tumpukan penuh, `isEmpty()` yang mengembalikan true jika tumpukan kosong, `pushArrayBuku()` untuk menambahkan data ke tumpukan, `popArrayBuku()` untuk menghapus data dari tumpukan, `peekArrayBuku()` untuk melihat data pada posisi tertentu dalam tumpukan, `countStack()` untuk menghitung jumlah data dalam tumpukan, `changeArrayBuku()` untuk mengubah data pada posisi tertentu dalam tumpukan, `destroyArrayBuku()` untuk menghapus semua data dari tumpukan, dan `cetakArrayBuku()` untuk mencetak semua data dalam tumpukan. Dalam `main()`, beberapa data buku ditambahkan ke tumpukan, kemudian tumpukan dicetak dan beberapa operasi seperti pengecekan tumpukan penuh, penghapusan data, penghitungan jumlah data, perubahan data, dan penghapusan semua data dilakukan, diikuti dengan pencetakan kembali tumpukan.

## Unguided 

#### 1.	Buatlah program untuk menentukan apakah kalimat tersebut yang diinputkan dalam program stack adalah palindrom/tidak. Palindrom kalimat yang dibaca dari depan dan belakang sama. Jelaskan bagaimana cara kerja programnya.

```C++
#include <iostream>
#include <stack>
#include <string>
#include <algorithm>

using namespace std;

string preprocessString(const string& str) {
    string processedStr;
    for (char ch : str) {
        if (isalpha(ch)) {
            processedStr.push_back(toupper(ch));
        }
    }
    return processedStr;
}

bool isPalindrome(const string& str) {
    stack<char> charStack;
    int length = str.length();
    int i, mid = length / 2;

    for (i = 0; i < mid; ++i) {
        charStack.push(str[i]);
    }

    if (length % 2 != 0) {
        ++i;
    }

    while (i < length) {
        if (charStack.top() != str[i]) {
            return false;
        }
        charStack.pop();
        ++i;
    }

    return true;
}

int main() {
    string input;

    cout << "Masukkan kalimat: ";
    getline(cin, input);

    string processedInput = preprocessString(input);

    if (isPalindrome(processedInput)) {
        cout << "Kalimat tersebut adalah palindrom.\n";
    } else {
        cout << "Kalimat tersebut bukan palindrom.\n";
    }

    return 0;
}


```
#### Output:
![image](https://github.com/Arifmulyaputra/Struktur-Data-Assignment/assets/161549884/c20cb464-574b-43a6-8230-58f1180ffe7a)


Penjelasan:

Program pada unguided 1 ini berfungsi untuk memeriksa apakah kalimat yang dimasukkan pengguna adalah palindrom. Untuk melakukan hal ini, langkah-langkah yang diambil termasuk menghapus spasi dan mengonversi huruf menjadi huruf kecil agar pengecekan tidak dipengaruhi oleh spasi atau huruf besar kecil. Kemudian, setiap karakter dari kalimat dimasukkan ke dalam tumpukan, kemudian dikeluarkan satu per satu untuk membentuk kalimat yang terbalik. Hasilnya dibandingkan dengan kalimat asli. Jika keduanya sama, maka kalimat tersebut adalah palindrom, dan pesan yang sesuai akan ditampilkan. Jika tidak, pesan yang menunjukkan kalimat bukan palindrom akan ditampilkan.


#### 2.	Buatlah program untuk melakukan pembalikan terhadap kalimat menggunakan stack dengan minimal 3 kata. Jelaskan output program dan source codenya beserta operasi/fungsi yang dibuat?

```C++
#include <iostream>
#include <stack>
#include <string>

using namespace std;

// Fungsi untuk membalikkan urutan kata dalam sebuah kalimat
string reverseSentence(const string& sentence) {
    string reversedSentence;
    stack<string> wordStack;

    // Memisahkan kata-kata dalam kalimat dan memasukkan ke dalam stack
    size_t start = 0, end;
    while ((end = sentence.find(' ', start)) != string::npos) {
        wordStack.push(sentence.substr(start, end - start));
        start = end + 1;
    }
    wordStack.push(sentence.substr(start)); // Memasukkan kata terakhir

    // Membuat kalimat baru dengan urutan kata yang dibalik
    while (!wordStack.empty()) {
        reversedSentence += wordStack.top() + " ";
        wordStack.pop();
    }

    return reversedSentence;
}

int main() {
    string inputSentence;

    cout << "Masukkan kalimat minimal 3 kata: ";
    getline(cin, inputSentence);

    string reversedSentence = reverseSentence(inputSentence);

    cout << "Kalimat setelah dibalik: " << reversedSentence << endl;

    return 0;
}

```
Output:
![image](https://github.com/Arifmulyaputra/Struktur-Data-Assignment/assets/161549884/ce1484a8-d50f-4b36-a71d-5e99882ad703)


Penjelasan:
Program pada unguided 2 ini dirancang untuk melakukan pembalikan kalimat yang diinputkan oleh pengguna menggunakan struktur data tumpukan (stack). Setelah pengguna memasukkan sebuah kalimat, program menampilkan kembali kalimat tersebut. Fungsi `reverseSentence` kemudian dipanggil dengan parameter kalimat yang dimasukkan, di mana setiap karakter dari kalimat tersebut dimasukkan ke dalam tumpukan. Setelah semua karakter dimasukkan, karakter-karakter tersebut dikeluarkan satu per satu dari tumpukan untuk membentuk kalimat yang terbalik. Hasil akhirnya ditampilkan ke layar. Dengan demikian, pengguna dapat melihat kedua versi kalimat, yaitu kalimat asli dan kalimat yang telah dibalikkan.


## Kesimpulan

Stack adalah struktur data bertingkat yang mengikuti prinsip LIFO (Last In First Out), di mana data terakhir yang dimasukkan akan pertama kali diambil. Operasi pada stack melibatkan elemen paling atas tumpukan, dengan penyisipan dan penghapusan data terjadi di satu ujung. Meskipun stack efisien dalam manajemen data dan fungsi, serta memberikan kontrol atas pengalokasian memori, namun memiliki keterbatasan ukuran memori yang dapat mengakibatkan stack overflow. Akses data acak tidak dimungkinkan dalam stack, dan penggunaan yang berlebihan bisa mengakibatkan hang atau penghentian program jika tumpukan berada di luar area memori.

## Referensi

[1] Wanra Tarigan. *Algoritma Pemrograman dan Struktur Data*. Eureka Media Aksara. 2022

[2] Trivusi. *Struktur Data Stack: Pengertian, Karakteristik, dan Kegunaannya*. 2022. Available: https://www.trivusi.web.id/2022/07/struktur-data-stack.html?m=1

[3] Algonz D.B. Raharja. *Stack: Definisi, Kelebihan, Kekurangan, Jenis Operasi, dan Implementasi*. 2022. Available: https://www.ekrut.com/media/stack-adalah 

