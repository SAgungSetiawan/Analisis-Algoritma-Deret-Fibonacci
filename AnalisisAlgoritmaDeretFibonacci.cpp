#include <iostream>
#include <chrono>
#include <vector>

using namespace std;
using namespace std::chrono;

long long fibonacciRekursif(int n) {
    if (n <= 1) return n;
    return fibonacciRekursif(n - 1) + fibonacciRekursif(n - 2);
}

long long fibonacciDynamicProgramming(int n) {
    vector<long long> fib(n + 1, 0);
    fib[1] = 1;
    for (int i = 2; i <= n; ++i) {
        fib[i] = fib[i - 1] + fib[i - 2];
    }
    return fib[n];
}

void ukurWaktuEksekusiRekursif(int n) {
    auto mulai = high_resolution_clock::now();
    long long hasilRekursif = fibonacciRekursif(n);
    auto selesai = high_resolution_clock::now();
    auto durasiRekursif = duration_cast<microseconds>(selesai - mulai).count();
    cout << "Fibonacci (Rekursif) ke-" << n << " = " << hasilRekursif << " -> Waktu eksekusi: " << durasiRekursif << " mikrodetik" << endl;
}

void ukurWaktuEksekusiDP(int n) {
    auto mulai = high_resolution_clock::now();
    long long hasilDP = fibonacciDynamicProgramming(n);
    auto selesai = high_resolution_clock::now();
    auto durasiDP = duration_cast<microseconds>(selesai - mulai).count();
    cout << "Fibonacci (DP) ke-" << n << " = " << hasilDP << " -> Waktu eksekusi: " << durasiDP << " mikrodetik" << endl;
}

int main() {
    int nilaiUji[] = {10, 25, 30, 40, 50};

    cout << "Hasil Rekursif:" << endl;
    for (int n : nilaiUji) {
        ukurWaktuEksekusiRekursif(n);
    }

    cout << endl;

    cout << "Hasil Dynamic Programming:" << endl;
    for (int n : nilaiUji) {
        ukurWaktuEksekusiDP(n);
    }

    return 0;
}
