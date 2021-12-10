#include "deleteSt.h"
#include "write.h"
#include <iostream>
using namespace std;

enum {
	yes = 1,
	no
};

int deleteSt(studentInformation student[], int quont) {
	int flag = 0;
	while (flag != no) {
		int delstr = 0;
		cout << "Какую по счёту запись вы хотите удалить?\n";
		cin >> delstr;
		system("cls");
		delstr -= 1;
		int copyi = 0;
		for (int j = 0; j < quont; ++j) {
			if (j != delstr) {
				student[copyi] = student[j];
			}
			++copyi;
		}
		cout << "Запись удалена.\n";
		cout << "Хотите ли вы ещё что-то удалить?" << endl << "1) Да" << endl << "2) Нет\n";
		cin >> flag;
		system("cls");
	}
	cout << "Чтобы вернуться к главному меню нажмите ENTER.\n";
	cin.get();
	cin.get();
	return (quont - 1);
}
