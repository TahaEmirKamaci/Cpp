#include "Array.h"

int main()
{
	Array mainArray(10);
	Array mainArray2(mainArray);
	cout << "Capacity" << mainArray.getCapacity() << endl;
	cout << "Size:" << mainArray.getSize() << endl;
	
	cout << "Capacity" << mainArray2.getCapacity() << endl;
	cout << "Size:" << mainArray2.getSize() << endl;

	mainArray.AddItem(5);
	mainArray.AddItem(12);
	mainArray.AddItem(3);
	mainArray.AddItem(8);
	mainArray.AddItem(7);
	mainArray.AddItem(41);
	mainArray.AddItem(4);
	mainArray.AddItem(3);
	mainArray.AddItem(1);
	mainArray.AddItem(3);
	mainArray.AddItem(21);
	mainArray.printItems();
	mainArray.AddItem(71);
	mainArray.printItems();


	Array mainArray3 = mainArray;
	mainArray3.printItems();
	mainArray3.AddItem(15);
	mainArray3.AddItem(18);

	mainArray.printItems();
	mainArray3.printItems();

	mainArray3.removeIndexItem(3);
	mainArray3.printItems();

	mainArray3.removeItem(3);
	mainArray3.printItems();

	mainArray3.findElement(12);
	mainArray3.printItems();

	mainArray3.findElement(155);


}
