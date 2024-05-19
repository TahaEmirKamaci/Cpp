#include "PersonToEmployee.h"

int main()
{
	Employee employee1 = { "Ogun","Birinci","Software","Engineer",4500,5 };
	Employee employee2 = { "Ali","Ikinci","Software","Engineer",4500,5 };
	Employee employee3 = { "Burak","Ucuncu","IT","Programmer",4500,5 };
	Employee employee4 = { "Enes","Dorduncu","Accounting","Engineer",4500,5 };
	Manager manager1 = { "Duygu","Keydal","Software","President",8500,10 };
	Manager manager2 = { "Omer","Selvi","IT","Manager",15000,25 };

	Employee employeeList[] = { employee1,employee2,employee3,employee4 };
	manager1.extractEmployees(employeeList);
	manager2.extractEmployees(employeeList);
	manager1.print();
	manager2.print();
}
