#include "bank.h"

int main()
{
	bankAccount acc1("Ali", "Kemal", 1500, "05054214507");
	cout << "Name:" << acc1.getPersonName() << endl;
	cout << "Surname:" << acc1.getPersonSurname() << endl;
	cout << "Phone:" << acc1.getPersonPhone() << endl;
	cout << "Balance:" << acc1.getPersonBalance() << endl;


	bankAccount acc2 = acc1;
	cout << "Name:" << acc2.getPersonName() << endl;
	cout << "Surname:" << acc2.getPersonSurname() << endl;
	cout << "Phone:" << acc2.getPersonPhone() << endl;
	cout << "Balance:" << acc2.getPersonBalance() << endl;

	acc1.credit(1500);
	acc1.displayProfile();
	acc1.withdraw(150);
	acc1.displayProfile();

	bankAccount acc3("Enes", "Uzun");
	acc3.displayProfile();
	acc1.sendMoney(acc3, 1500);
	acc3.displayProfile();
	acc1.displayProfile();
}
