#include <iostream>
using namespace std;

void toplam_olasilik();
void bayes_teoremi();

int main()
{
    cout << "Merhaba size bazi sorular sorup BAYES TEOREMI ya da TOPLAM OLASILIK probleminiz cozecegiz" << endl << endl;

    int a = 0;

    cout << "Eger bir olayın olasiligini bu olayın farkli senaryolar altinda gerceklesme olasiliklarinin toplami \nolarak hesaplamak istiyorsaniz 1'e basin" << endl << endl;
    cout << "Bir olasilik degerini bildigimiz olasilik degerleri ile hesaplamak istiyorsaniz 2'ye basin" << endl;
    cin >> a;

    if (a == 1) {
        cout << "Sorunuz cesidi TOPLAM OLASILIKTIR" << endl << endl;
        toplam_olasilik();
    }
    else if (a == 2) {
        cout << "Sorunuz cesidi BAYES TEOREMIDIR" << endl << endl;
        bayes_teoremi();
    }
    else {
        cout << "Yanlis deger girdiniz";
    }
}

void bayes_teoremi() {
    float P_A, P_B, P_A_kosul_B, P_B_kosul_A;

    cout << "P(A|B) = [ P(A) * P(B|A) ] / P(B)  Formulu kullanilacaktir, degerlerinizi giriniz" << endl << endl;

    cout << "A olasilik degerini giriniz ( P(A) )" << endl;
    cin >> P_A;

    cout << "B olasilik degerini giriniz ( P(B) )" << endl;
    cin >> P_B;

    cout << "B kosulu altinda A olasilik degerini giriniz ( P(A|B) )" << endl;
    cin >> P_A_kosul_B;

    P_B_kosul_A = (P_A_kosul_B * P_B) / P_A;

    cout << "A kosulu altinda B olasiliginin gerceklesme ihtimali" << endl << P_B_kosul_A << endl;
}

void toplam_olasilik() {
    int k;
    cout << "Kac farkli senaryo vardir (k degeri)" << endl;
    cin >> k;
    float* P_B = new float[k];
    float* P_A_kosul_B = new float[k];
    float P_A = 0;

    for (int i = 0; i < k; i++) {
        cout << i + 1 << ". senaryo degerlerini giriniz" << endl;
        cout << i + 1 << ". P(_) degerini giriniz" << endl;
        cin >> P_B[i];

        cout << i + 1 << ". P(_|_) degerini giriniz" << endl;
        cin >> P_A_kosul_B[i];
    }
    for (int i = 0; i < k; i++) {
        P_A = P_A + (P_B[i] * P_A_kosul_B[i]);
    }

    cout << "Toplam olasilik degeri " << endl << P_A << endl;
}
