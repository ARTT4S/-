#include "deleteSt.h"
#include "typeCheck.h"
#include "write.h"
#include <iostream>

enum {
	yes = 1,
	no
};

int deleteSt(studentInformation student[], int quont, fstream &BD) {
	int flag = 0, delstr = 0, copyi = 0;
	while (flag != no) {
		write(student, quont, BD);
		cout << "Какую по счёту запись вы хотите удалить?\n";
		delstr = typeCheck(delstr, 1, quont);
		system("cls");
		cout << "Вы точно хотите удалить запись?" << endl << "1) Да" << endl << "2) Нет\n";
		flag = typeCheck(flag, yes, no);
		system("cls");
		switch (flag) {
		case yes:
			delstr -= 1;
			for (int j = 0; j < quont; ++j) {
				if (j != delstr) {
					student[copyi] = student[j];
				}
				++copyi;
			}
			cout << "Запись удалена.\n";
			break;
		case no:
			cout << "Возвращаем вас к главному меню\n";
			system("pause");
			break;
		default:
			cout << "Введена неверная команда\n";
			break;
		}
		system("cls");
		cout << "Вы хотите удалить ещё одну запись?" << endl << "1) Да" << endl << "2) Нет\n";
		flag = typeCheck(flag, yes, no);
	}
	return (quont - 1);
}
