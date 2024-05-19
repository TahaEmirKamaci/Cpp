#pragma once

#include <iostream>
using namespace std;

/*
	ERİŞİM BELİRLEYİCİLER

	private->sadece sınıfın içerisinden erişilebilir.(default varsayılan olarak private) Main kısımdan erişilemez.
	protected-> sadece class içerisinde ve miras alan classlarla erişilebilir.Main kısımdan erişilemez.
	public->her yerden erişilebilir.

*/



class Student {
private:
	string studentName, studentSurname, studentID;//üye değişkenleri(member variables)

public:	
	Student();
	Student(string, string, string);
	~Student();
	Student(const Student& oth);

	void displayInformation();//üye fonksiyonu(member function)
	void setName(string name) {studentName = name;}
	void setSurname(string surname) {studentSurname = surname;}
	void setID(string ID) {studentID = ID;}
	void setInformation(string name, string surname, string ID) {
		studentName = name;
		studentSurname = surname;
		studentID = ID;
	}
	string getName() {
		return studentName;
	};
	string getSurname(){
		return studentSurname;
	};
	string getID() {
		return studentID;
	};
};

Student::Student() {
	//cout << "Default constructed worked." << endl;
	studentName = "None";
	studentSurname = "None";
	studentID = "None";
}
Student::Student(string name, string surname,string ID) {
	cout << "Constructed worked." << endl;
	studentName = name;
	studentSurname = surname;
	studentID = ID;
}
Student::~Student() {
	cout << "Destructor worked." << endl;
}
Student::Student(const Student& oth) {
	cout << "copy constructor worked" << endl;
	studentName = oth.studentName;
	studentSurname = oth.studentSurname;
	studentID = oth.studentID;
}

void Student::displayInformation() {
	cout << "Name:" << studentName << " " << studentSurname << endl;
	cout << "ID:" << studentID << endl;
};