#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;


double aritmetikOrtalama(double dizi[], int boyut) {
    double toplam = 0;
    for (int i = 0; i < boyut; i++) {
        toplam += dizi[i];
    }
    return toplam / boyut;
}

double geometrikOrtalama(double dizi[], int boyut) {
    double carpim = 1;
    double ortalama;
    for (int i = 0; i < boyut; i++) {
        carpim *= dizi[i];
    }
    ortalama = pow(carpim, 1.0 / boyut);
    return ortalama;
}

double harmonikOrtalama(double dizi[], int boyut) {
    double toplam = 0;
    double ortalama;
    for (int i = 0; i < boyut; i++) {
        toplam += 1.0 / dizi[i];
    }
    ortalama = boyut / toplam;
    return ortalama;
}

double orneklemVaryansi(double dizi[], int boyut) {
    double varyans = 0;
    double ortalama = aritmetikOrtalama(dizi, boyut);
    for (int i = 0; i < boyut; i++) {
        varyans += pow(dizi[i] - ortalama, 2);
    }
    varyans = varyans / (boyut - 1);
    return varyans;
}

double standartSapma(double dizi[], int boyut) {
    double sapma = sqrt(orneklemVaryansi(dizi, boyut));
    return sapma;
}

double ortalamaMutlakSapma(double dizi[], int boyut) {
    double toplam = 0;
    double ortalama = aritmetikOrtalama(dizi, boyut);
    for (int i = 0; i < boyut; i++) {
        toplam += abs(dizi[i] - ortalama);
    }
    double ortalamaMutlakSapma = toplam / boyut;
    return ortalamaMutlakSapma;
}

double carpiklikOlcutu(double dizi[], int boyut) {
    double carpiklik = 0;
    double ortalama = aritmetikOrtalama(dizi, boyut);
    double standartSapma = sqrt(orneklemVaryansi(dizi, boyut));
    for (int i = 0; i < boyut; i++) {
        carpiklik += pow((dizi[i] - ortalama) / standartSapma, 3);
    }
    carpiklik = carpiklik / boyut;
    return carpiklik;
}

double basiklikOlcutu(double dizi[], int boyut) {
    double basiklik = 0;
    double ortalama = aritmetikOrtalama(dizi, boyut);
    double standartSapma = sqrt(orneklemVaryansi(dizi, boyut));
    for (int i = 0; i < boyut; i++) {
        basiklik += pow((dizi[i] - ortalama) / standartSapma, 4);
    }
    basiklik = basiklik / boyut;
    return basiklik;
}

double varyasyonKatsayisi(double dizi[], int boyut) {
    double varyasyon = standartSapma(dizi, boyut) / aritmetikOrtalama(dizi, boyut);
    return varyasyon;
}

static void diziSirala(double dizi[], int boyut) {
    double temp;
    static int cagirma = 0;
    for (int i = 0; i < boyut; i++) {
        for (int j = 0; j < boyut; j++) {
            if (dizi[i] < dizi[j]) {
                temp = dizi[i];
                dizi[i] = dizi[j];
                dizi[j] = temp;
            }
        }
    }
    if ((cagirma % 2) == 0) {
        for (int a = 0; a < boyut; a++) {
            cout << dizi[a] << " ";
        }
        cout << endl;
    }
    cagirma++;
}

void medyanBul(double dizi[], int boyut) {
    double medyan;
    if (!(boyut % 2 == 0)) {
        medyan = dizi[boyut / 2];
    }
    else {
        medyan = (dizi[boyut / 2 - 1] + dizi[boyut / 2]) / 2.0;
    }
    std::cout << "Medyan: " << medyan << std::endl;
}

void modBul(double dizi[], int boyut) {
    double mod = 0;
    double modDeger = 0;
    int sayac = 0;
    for (int i = 0; i < boyut; i++) {
        for (int j = 0; j < boyut; j++) {
            if (dizi[i] == dizi[j]) {
                sayac++;
            }
        }
        if (sayac > mod) {
            mod = sayac;
            modDeger = dizi[i];
        }
        sayac = 0;
    }
    cout << endl << "Mod: " << modDeger << std::endl;
}

void tabloOlustur(double dizi[], double frekans[], int boyut) {
    cout << endl << "Degerler\tFrekanslar" << endl;
    for (int i = 0; i < boyut; i++) {
        bool yazdir = true;
        for (int j = i - 1; j >= 0; j--) {
            if (dizi[i] == dizi[j]) {
                yazdir = false;
                break;
            }
        }
        if (yazdir) {
            cout << dizi[i] << "\t\t" << frekans[i] << endl;
        }
    }
}

static void frekansHesapla(double dizi[], double frekans[], int boyut) {
    for (int i = 0; i < boyut; i++) {
        frekans[i] = 1;
        for (int j = i + 1; j < boyut; j++) {
            if (dizi[i] == dizi[j]) {
                frekans[i]++;
            }
        }
    }
}

void frekansTablosuOlusturma(double dizi[], int boyut) {
    double frekans[100];
    cout << endl << "Frekans Tablosu :";
    frekansHesapla(dizi, frekans, boyut);
    tabloOlustur(dizi, frekans, boyut);
}

int main() {


    int boyut;
    double dizi[100];
    static double frekans[100];
    cout << "Dizi boyutu giriniz = ";
    cin >> boyut;

    for (int i = 0; i < boyut; i++) {
        cout << endl << i + 1 << ". elemani giriniz = ";
        cin >> dizi[i];
    }
    diziSirala(dizi, boyut);

    // Frekans tablosu oluştur
    frekansTablosuOlusturma(dizi, boyut);

    modBul(dizi, boyut);
    cout << "Aritmetik ortalama: " << fixed << setprecision(2) << aritmetikOrtalama(dizi, boyut) << endl;
    medyanBul(dizi, boyut);
    cout << "Geometrik ortalama: " << geometrikOrtalama(dizi, boyut) << endl;
    cout << "Harmonik ortalama: " << harmonikOrtalama(dizi, boyut) << endl;
    cout << "Standart Sapma: " << standartSapma(dizi, boyut) << endl;
    cout << "Orneklem Varyansi: " << orneklemVaryansi(dizi, boyut) << endl;
    cout << "Ortalama Mutlak Sapma: " << ortalamaMutlakSapma(dizi, boyut) << endl;
    cout << "Carpiklik Olcutu: " << carpiklikOlcutu(dizi, boyut) << endl;
    cout << "Basiklik Olcutu: " << basiklikOlcutu(dizi, boyut) << endl;
    cout << "Varyasyon Katsayisi: " << varyasyonKatsayisi(dizi, boyut) << endl;

    return 0;
}