#include "addst.h"
#include <iostream>
using namespace std;

enum {
	yes = 1,
	no
};

int addSt(studentInformation student[], int quont) {
	int flag = 0;
	while (flag != no) {
		++quont;
		if (quont != maxQuontSt) {
			cout << "Добавьте запись.\n";
			cout << "Введите фамилию " << quont << "-го студента: ";
			cin >> student[quont - 1].surname;
			cout << "Введите имя " << quont << "- го студента: ";
			cin >> student[quont - 1].name;
			cout << "Введите отчество " << quont << "-го студента: ";
			cin >> student[quont - 1].patronymic;
			cout << "Введите группу " << quont << "-го студента: ";
			cin >> student[quont - 1].group;
			cout << "Введите курс " << quont << "-го студента: ";
			cin >> student[quont - 1].course;
			cout << "Введите оценку по высокоуровневому программированию " << quont << "-го студента: ";
			cin >> student[quont - 1].discipline.highProgr;
			cout << "Введите оценку по теоретической информатике " << quont << "-го студента: ";
			cin >> student[quont - 1].discipline.teorInf;
			cout << "Введите оценку по математическому анализу " << quont << "-го студента: ";
			cin >> student[quont - 1].discipline.math;
			cout << "Введите оценку по аналитической геометрии " << quont << "-го студента: ";
			cin >> student[quont - 1].discipline.anGeom;
			cout << "Введите оценку по английскому языку " << quont << "-го студента: ";
			cin >> student[quont - 1].discipline.english;
			cout << "Введите оценку по инженерной графике " << quont << "-го студента: ";
			cin >> student[quont - 1].discipline.engGraph;
			cout << "Хотите ли вы добавить ещё одну запись?" << endl << "1) Да" << endl << "2) Нет\n";
			cin >> flag;
		}
		else {
			cout << "Достигнуто максимальное количество студентов.\n";
		}
			system("cls");
	}
	cout << "Чтобы вернуться к главному меню нажмите ENTER.\n";
	cin.get();
	cin.get();

	return quont;
}
