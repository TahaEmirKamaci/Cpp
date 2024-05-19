#include "date.h"


int Main() {
	Date mainDate(02, 01, 2020);
	cout << "Day:" << mainDate.getDay() << endl;
	cout << "Day:" << mainDate.getMonth() << endl;
	cout << "Day:" << mainDate.getYear() << endl;
	mainDate.displayDate();

	Date mainDate2(01, 01, 2020);
	mainDate2.displayDate();



	mainDate.compareDate(mainDate2);

	cout << "------------------------------" << endl;
	for (int i = 0; i < 30; i++) {
		mainDate2.increaseDay();
		mainDate2.displayDate();
	}
}


