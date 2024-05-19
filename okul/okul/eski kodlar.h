/*
    rasyonel sayi1(3, 5), sayi2(7, 8);
    rasyonel sonuc = sayi1.carp(sayi2);
    cout << sayi1.getPay() << "/" << sayi1.getPayda();
    cout << "*" << sayi2.getPay() << "/" << sayi2.getPayda() << endl;
    cout << "=" << sonuc.getPay() << "/" << sonuc.getPayda() << endl;
    */
    /*
    int no;
    string isim;
    kisi bir;
    kisi iki(250, "serhat");
    cout << "no gir" << endl;
    cin >> no;
    cout << "isim gir" << endl;
    cin >> isim;
    bir.setno(no);
    bir.setisim(isim);
    bir.yaz();
    iki.yaz();
    */
    /*
    sekermakina makinam;
    cout << "toplam seker sayisi: " << makinam.mevcutseker() << endl;
    cout << "bir seker ucreti: " << makinam.sekerucret() << " TL" << endl;
    makinam.satis();
    cout << "seker sayisi: " << makinam.mevcutseker() << endl;
    */
    /*
    Dizi d(5);
    d.oku();
    d.goster();
    cout << "-------------------------" << endl;
    d.sirala();
    d.goster();
    cout << "-------------------------" << endl;
    d.degistir(3, 42);
    d.goster();
    */
    /*
    proje yapayzeka("tanima sistemi");
    tasarimek bir("ahmet",100);
    yazilimek iki("nihal",200);
    yazilimek uc("derya", 300);
    testek dort("veli", 400);
    testek bes("canan", 500);
    yapayzeka.ekle(&bir);
    yapayzeka.ekle(&iki);
    yapayzeka.ekle(&uc);
    yapayzeka.ekle(&dort);
    yapayzeka.ekle(&bes);
    */

class rasyonel {
private:
    int pay;
    int payda;

public:
    rasyonel(int p, int pd) : pay(p), payda(pd) {}

    int getPay() const {
        return pay;
    }

    int getPayda() const {
        return payda;
    }

    rasyonel carp(const rasyonel& other) const {
        int yeni_pay = pay * other.pay;
        int yeni_payda = payda * other.payda;
        return rasyonel(yeni_pay, yeni_payda);
    }
};

class kisi {
private:
    int no;
    string isim;

public:
    kisi() {
        no = 0;
        isim = "";
    }

    kisi(int no, const string& isim) {
        this->no = no;
        this->isim = isim;
    }

    void setno(int no) {
        this->no = no;
    }

    void setisim(const string& isim) {
        this->isim = isim;
    }

    void yaz() {
        cout << "No: " << no << " Isim: " << isim << endl;
    }
};

class sekermakina {
public:
    int mevcutseker() {
        return sekersayi;
    }
    int sekerucret() {
        return ucret;
    }
    void satis() {
        if (sekersayi > 0) {
            cout << "bir seker satildi" << endl;
            sekersayi--;
        }
        else {
            cout << "uzgunuz seker kalmadi" << endl;
        }
    }
    sekermakina(int sekersayi = 50, int sekerucret = 50) {
        this->sekersayi = sekersayi;
        this->ucret = sekerucret;
    }
private:
    int sekersayi;
    int ucret;
};

class Dizi {
private:
    int* dizi;
    int boyut;

public:
    Dizi(int boyut) {
        this->boyut = boyut;
        dizi = new int[boyut];
    }

    ~Dizi() {
        delete[] dizi;
    }

    void oku() {
        for (int i = 0; i < boyut; i++) {
            cout << "Dizi elemani " << i + 1 << ": ";
            cin >> dizi[i];
        }
    }

    void goster() {
        for (int i = 0; i < boyut; i++) {
            cout << dizi[i] << endl;
        }
    }

    int degistir(int sira, int num) {
        if (sira >= 1 && sira <= boyut) {
            dizi[sira - 1] = num;
            return 1;
        }
        else {
            return -1;
        }
    }

    void sirala() {
        int temp;
        for (int i = 0; i < boyut; i++) {
            for (int j = i + 1; j < boyut; j++) {
                if (dizi[i] > dizi[j]) {
                    temp = dizi[i];
                    dizi[i] = dizi[j];
                    dizi[j] = temp;
                }
            }
        }
    }
};

class kisi {
public:
    int sicilno;
protected:
    string isim;
public:
    kisi(string x, int y) :isim(x), sicilno(y) {}
    void gorev();
};

class proje {
    kisi* calisan[5];
    string pa;
    static int say;
public:
    void ekle(kisi* x);
    void baslat() {}


};
void proje::ekle(kisi* x) {
    calisan[say] = x;
    say++;
}
void proje::baslat() {
    for (int i = 0; i < say; i++) {
        calisan[i]->gorev();
    }
}
int proje::say = 0;
class testek {
    int ekipNo;
    string ekipAD;
public:
    testek(int ekipNo, string ekipAD) {
        this->ekipNo = ekipNo;
        this->ekipAD = ekipAD;
    }

};


class tasarimek :public kisi {
public:
    tasarimek(string x, int y) :kisi(x, y) {}
    void gorev() { cout << "tasarim islemi baslatildi" << endl; };
};

class yazilimek :public kisi {
public:
    yazilimek(string x, int y) :kisi(x, y) {}
    void gorev();
};