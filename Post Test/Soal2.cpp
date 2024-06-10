#include <iostream>
using namespace std;

long long faktorial(int n) {
    if (n == 0) { 
        return 1;
    } else {  
        return n * faktorial(n - 1);
    }
}

int main() {
    int bilangan;

    cout << "Masukkan bilangan bulat positif: ";
    cin >> bilangan;
    long long hasil = faktorial(bilangan);
    cout << bilangan << " Faktorial dari " << bilangan << " adalah: " << hasil << endl;
    return 0;
}