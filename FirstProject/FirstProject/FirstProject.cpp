#include "studentClass.h"
#include "Triangle.h"

int main()
{
    /*
    Student student1("ali kemal","calak","1");
    Student student2;
    Student student3(student1);

    student3.displayInformation();

    /*
    student1.studentName = "ali kemal";
    student1.studentSurname = "calak";
    student1.studentID = "1";
    student1.displayInformation();

    student2.studentName = "enes";
    student2.studentSurname = "uzun";
    student2.studentID = "2";
    student2.displayInformation();
    */
    /*
    student1.setName("ali kemal");
    student1.setSurname("calak");
    student1.setID("1");
    student1.displayInformation();
    *//*
    string name = student1.getName();
    string surname = student1.getSurname();
    string ID = student1.getID();


    cout << name << endl;
    cout << surname << endl;
    cout << ID << endl;


    student2.setInformation("arif", "sahin", "2");
    student2.displayInformation();

    if (true) {
        Student student5;
    }
    */
    float a, b, c;
    cout << "please enter the sides(a-b-c):" << endl;
    cin >> a >> b >> c;
    Triangle triangle1(a, b, c);//constructor
    Triangle triangle1={a, b, c};//constructor
    Triangle triangle1{ a,b,c };//constructor


    Triangle triangle2 = triangle1;//copy constructor
    Triangle triangle3(triangle1);//copy constructor

    cout << "-Triangle1-" << endl;
    cout << "Side A:" << triangle1.getSideA() << endl;
    cout << "Side B:" << triangle1.getSideB() << endl;
    cout << "Side C:" << triangle1.getSideC() << endl;
    cout << "Area:" << triangle1.calculateArea() << endl;
    
    triangle2.setValue(12, 16, 20);
    cout << "-Triangle2-" << endl;
    cout << "Side A:" << triangle2.getSideA() << endl;
    cout << "Side B:" << triangle2.getSideB() << endl;
    cout << "Side C:" << triangle2.getSideC() << endl;
    cout << "Area:" << triangle2.calculateArea() << endl;
    
    triangle1.triangleType();
    
    
    return 0;
}