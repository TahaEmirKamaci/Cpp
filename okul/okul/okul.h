#include <iostream>
#include <string>
using namespace std;




class nokta {
private:
    int x;
	int y;
public:
    nokta() {}
    nokta(int x, int y) {
		this->x = x;
		this->y = y;
	}
    nokta operator+(const nokta& other) const {
		return nokta(x + other.x, y + other.y);
	}
    void yaz();
};
void nokta::yaz() {
    cout << "x: " << x << " y: " << y << endl;
};