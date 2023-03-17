#include <iostream>
#include <iomanip>
using namespace std;
void bangla(long long int n) {
    if (n >= 10000000) {
        bangla(n / 10000000);
        cout << " kuti";
        n %= 10000000;
    }

    if (n >= 100000) {
        bangla(n / 100000);
        cout << " lakh";
        n %= 100000;
    }

    if (n >= 1000) {
        bangla(n / 1000);
        cout << " hajar";
        n %= 1000;
    }

    if (n >= 100) {
        bangla(n / 100);
        cout << " shata";
        n %= 100;
    }

    if (n) {
        cout << " " << n;
    }
}
int main() {
    int count = 0;
    long long int num = 0;
    while (cin >> num) {
        count++;
        cout << setw(4) << count << ".";
        if (num != 0) {
            bangla(num);
        } else {
            cout << " 0";
        }
        cout << "\n";
    }
}