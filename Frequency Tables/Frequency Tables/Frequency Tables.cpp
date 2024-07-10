#include <iostream>
#include <vector>
#include <map>
#include <cmath>
#include <iomanip>
#include <sstream>

// Frekans hesaplama fonksiyonları
void frekans_hesapla_i32(const std::vector<int>& arr, std::map<int, int>& map) {
    for (int val : arr) {
        map[val]++;
    }
}

void frekans_hesapla_f64(const std::vector<double>& arr, int precision, std::map<std::string, int>& map) {
    for (double val : arr) {
        std::ostringstream key;
        key << std::fixed << std::setprecision(precision) << val;
        map[key.str()]++;
    }
}

// Frekans serisi fonksiyonları
void frekans_seri_i32(const std::vector<int>& arr) {
    std::map<int, int> map;
    frekans_hesapla_i32(arr, map);

    std::cout << "\nFrekans Serisi:\n";
    for (const auto& [key, value] : map) {
        std::cout << key << ": " << value << "\n";
    }
}

void frekans_seri_f64(const std::vector<double>& arr, int precision) {
    std::map<std::string, int> map;
    frekans_hesapla_f64(arr, precision, map);

    std::cout << "\nFrekans Serisi:\n";
    for (const auto& [key, value] : map) {
        std::cout << key << ": " << value << "\n";
    }
}

// Frekans tablosu fonksiyonları
void frekans_tablosu_i32(std::vector<int> arr) {
    int n = arr.size();
    std::cout << "\n\nn: " << n;
    int min = arr.front();
    int max = arr.back();
    int r = max - min;
    int k = static_cast<int>(std::ceil(std::sqrt(n)));
    int h = static_cast<int>(std::ceil(static_cast<double>(r) / k));
    std::cout << "\nn: " << n << ", r: " << r << ", k: " << k << ", h: " << h << "\n\n";

    std::cout << "Sınıf Limitleri\nAlt \t Üst \t SON\n";
    int value = arr.front();
    double son = (value + (value + h - 1)) / 2.0;
    for (int i = 0; i < k; i++) {
        std::cout << value << " \t " << value + h - 1 << " \t " << son << "\n";
        value += h;
        son = (value + (value + h - 1)) / 2.0;
    }

    std::cout << "Sınıf Sınırları\nAlt \t Üst \t Sınıf Frekansı\t Eklenik Frekans \t Oransal Frekans \t Oransal Eklenik Frekans\n";
    value = arr.front();
    double alt_sinir = value - 0.5;
    int toplam_frekans = 0;
    double toplam_oransal_frekans = 0.0;

    for (int i = 0; i < k; i++) {
        double ust_sinir = alt_sinir + h;
        int frekans = 0;
        for (int j : arr) {
            if (j >= static_cast<int>(alt_sinir) && j < static_cast<int>(ust_sinir)) {
                frekans++;
            }
        }
        toplam_frekans += frekans;
        toplam_oransal_frekans += static_cast<double>(frekans) / n;
        std::cout << std::fixed << std::setprecision(2) << alt_sinir << " \t " << ust_sinir << " \t " << frekans << " \t\t " << toplam_frekans << " \t\t\t " << static_cast<double>(frekans) / n << " \t\t\t " << toplam_oransal_frekans << "\n";
        alt_sinir += h;
    }
}

void frekans_tablosu_f64(std::vector<double> arr) {
    int n = arr.size();
    std::cout << "\n\nn: " << n;
    double min = arr.front();
    double max = arr.back();
    double r = max - min;
    int k = static_cast<int>(std::ceil(std::sqrt(n)));
    double h = std::ceil(r / k);
    std::cout << "\nn: " << n << ", r: " << r << ", k: " << k << ", h: " << h << "\n\n";

    std::cout << "Sınıf Limitleri\nAlt \t Üst \t SON\n";
    double value = min;
    double son = (value + (value + h - 0.1)) / 2.0;
    for (int i = 0; i < k; i++) {
        std::cout << value << " \t " << value + h - 0.1 << " \t " << son << "\n";
        value += h;
        son = (value + (value + h - 0.1)) / 2.0;
    }

    std::cout << "Sınıf Sınırları\nAlt \t Üst \t Sınıf frekansı \t Eklenik Frekans \t Oransal Frekans \t OEF\n";
    double alt_sinir = min - 0.05;
    int toplam_frekans = 0;
    double toplam_oransal_frekans = 0.0;

    for (int i = 0; i < k; i++) {
        double ust_sinir = alt_sinir + h;
        int frekans = 0;
        for (double j : arr) {
            if (j >= alt_sinir && j < ust_sinir) {
                frekans++;
            }
        }
        toplam_frekans += frekans;
        toplam_oransal_frekans += static_cast<double>(frekans) / n;
        std::cout << std::fixed << std::setprecision(2) << alt_sinir << " \t " << ust_sinir << " \t " << frekans << " \t\t " << toplam_frekans << " \t\t\t " << static_cast<double>(frekans) / n << " \t\t\t " << toplam_oransal_frekans << "\n";
        alt_sinir += h;
    }
}

int main() {
    std::vector<int> arr_i32 = { 1, 2, 2, 3, 3, 3, 4, 4, 4, 4 };
    std::vector<double> arr_f64 = { 1.1, 2.2, 2.2, 3.3, 3.3, 3.3, 4.4, 4.4, 4.4, 4.4 };

    std::cout << "Frekans Serisi (int):";
    frekans_seri_i32(arr_i32);

    std::cout << "Frekans Serisi (double):";
    frekans_seri_f64(arr_f64, 1);

    std::cout << "Frekans Tablosu (int):";
    frekans_tablosu_i32(arr_i32);

    std::cout << "Frekans Tablosu (double):";
    frekans_tablosu_f64(arr_f64);

    return 0;
}
