#include <iostream>
using namespace std;
#include <vector>

class Object {        
public:
	string ad, soyad; 
	string kullaniciAd; 
	int pass;          // Şifre 
	Object() {}       
	Object(string x, int y) : ad(x), pass(y) {} 
};

int main()
{
	
	vector <int> v; // int türünde elemanlar içeren vektör oluşturur
	v.reserve(10); // Vektöre en az 10 eleman kapasitesi ayırır
	cout << v.size() << endl; // Vektörün içindeki eleman sayısını yazdırır
	cout << v.capacity(); // Vektörün kapasitesini yazdırır

	vector <int> V; 
	V.resize(10); // Vektörü 10 elemanlı hale getirir
	V[9] = 35; 
	V.resize(9); // Vektörü tekrar 9 elemanlı hale getirir
	V.clear(); // Vektörü temizle, yedeklenen elemanları kaldırır
	bool e = V.empty(); // Vektörün boş olup olmadığını kontrol eder
	cout << V[8] << endl; // 9. elemanı yazdır (ancak vektörün boyutu 9 olduğundan geçersiz)
	V.~vector(); // Vektör nesnesini bellekten sil (destructor çalışması)

	vector <int> V; 
	V.push_back(1); // Vektörün sonuna 1 ekle
	V.push_back(2); // Vektörün sonuna 2 ekle
	V.push_back(3); // Vektörün sonuna 3 ekle
	V.insert(V.begin(), 20); // Vektörün başına 20 ekle
	V.insert(V.begin() + 2, 30); // Vektörün 2. elemanının öncesine 30 ekle
	V.insert(V.end(), 40); // Vektörün sonuna 40 ekle
	for (int i = 0; i < 6; i++) { // Vektörü baştan sona yazdır
		cout << V[i] << endl;
	}
	

	vector<Object> V;  // Object sınıfından oluşan bir vektör tanımlanıyor

	int x = 0;       
	Object kisi;       

	while (true) {     
		cout << "1-Yeni bir Kullanici Olustur" << endl << "2-Kullanici Girisi" << endl; 
		cout << "Seciminizi girin: "; 
		cin >> x;        

		switch (x) {      
		case 1:          
			cout << "Kullanici ad:" << endl; // Kullanıcı adını iste
			cin >> kisi.kullaniciAd; // Kullanıcı adını al
			cout << "Sifre:" << endl; // Şifreyi iste
			cin >> kisi.pass;          // Şifreyi al
			V.push_back(kisi);         // Vektöre kullanıcıyı ekle
			cout << "Basari ile tamamlandi" << endl; 
			break;                    // Switch-case'den çık
		case 2:          
			cout << "Kullanici adinizi giriniz" << endl; // Kullanıcı adını iste
			cin >> kisi.kullaniciAd; // Kullanıcı adını al
			break; 
		}
	}
}




