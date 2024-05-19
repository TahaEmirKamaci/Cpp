#include <iostream>
using namespace std;

bool asal_mi(int sayi) {
    if (sayi <= 1) return false;
    if (sayi <= 3) return true;
    if (sayi % 2 == 0 || sayi % 3 == 0) return false;

    for (int i = 5; i * i <= sayi; i += 6) {
        if (sayi % i == 0 || sayi % (i + 2) == 0) {
            return false;
        }
    }

    return true;
}

void asal_sayilari_bul(int deger) {
    cout << "Asal sayilar: ";
    for (int i = 2; i <= deger; i++) {
        if (asal_mi(i)) {
            cout << i << " ";
        }
    }
    cout << endl;
}

int main() {
    int ust_sinir;
    cout << "Ust sinir degerini girin: ";
    cin >> ust_sinir;

    asal_sayilari_bul(ust_sinir);

    return 0;
}
