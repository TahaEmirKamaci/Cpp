#include <iostream>
using namespace std;

int main()
{
    cout << "Dağılım Ölçüleri Bulma" << endl<<endl;
    int a = -1;
    int b = -1;
    int c = 0;
    cout << "Tum sonuclarinizin degeri esit mi? Esit ise 1 basin" << endl;
    cout << "Sonlu sayida N ogeli bir evrende tekrar yerine koymaksizin rastgele secilen n birimden \nolusan bir orneklem uzerinde mi calisiyorsunuz? Evet ise 2'ye basin" << endl;
    cout << "Bir zaman araligi, alan ya da hacim uzerinde mi calisiyorsunuz? Evet ise 3'e basin" << endl;
    cout << "Sadece 2 sonucu olan deneyler uzerinde mi calisiyorsunuz? Cevap evet ise 4'e basin" << endl;

    cin >> a;
    
    switch (a)
    {
    case 1:
        cout << "Sectiginiz kesikli orneklem cesidi DUZGUN (UNIFORM) DAGILIM'dir"<<endl;
        break;
    case 2:
        cout << "Sectiginiz kesikli orneklem cesidi HIPERGEOMETRIK DAGILIM'dir" << endl;
        break;
    case 3:
        cout << "Sectiginiz kesikli orneklem cesidi POISSON DAGILIM'dir" << endl;
        break;
    case 4:
        cout << "Tek bir deney uzerinde mi calisiyorsunuz? Evet ise 1'e basin" << endl;
        cout << "Birbirinden bagimsiz birden fazla deney uzerinde mi calisiyorsunuz? Evet ise 2'ye basin" << endl;
        cin >> b;
        switch (b)
        {
        case 1:
            cout << "Sectiginiz kesikli orneklem cesidi BERNOLLI DAGILIM'dir" << endl;
            break;
        case 2:
            cout << "Ilk basari gerceklesene kadar denemeye devam mi ediyorsunuz? Evet ise 1'e basin" << endl;
            cout << "Birden fazla basarinin X denemede gerceklesme ihtimalini mi ariyorsunuz? Evet ise 2'ye basin" << endl;
            cout << "Iki secenekte degil ise rastgele bir tusa basiniz " << endl;
            cin >> c;
            if (c == 1) {
                cout << "Sectiginiz kesikli orneklem cesidi GEOMETRIK DAGILIM'dir" << endl;
            }
            else if (c == 2) {
                cout << "Sectiginiz kesikli orneklem cesidi NEGATIF BINOM DAGILIM'dir" << endl;
            }
            else {
                cout << "Sectiginiz kesikli orneklem cesidi BINOM DAGILIM'dir" << endl;
            }
            break;
        default:
            break;
        }
        break;
    default:
        break;
    }
}
