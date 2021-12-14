#include "addst.h"
#include "typeCheck.h"
#include <iostream>
#include <Windows.h>
using namespace std;

enum {
	yes = 1,
	no
};

int addSt(studentInformation student[], int quont) {
	int flag = 1;
	while (flag != no) {
		
		system("cls");
		switch (flag) {
		case yes:
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
				student[quont - 1].course = typeCheck(student[quont - 1].course, minCourse, maxCourse);
				cout << "Введите оценку по высокоуровневому программированию " << quont << "-го студента: ";
				student[quont - 1].discipline.highProgr = typeCheck(student[quont - 1].discipline.highProgr, minGrade, maxGrade);
				cout << "Введите оценку по теоретической информатике " << quont << "-го студента: ";
				student[quont - 1].discipline.teorInf = typeCheck(student[quont - 1].discipline.teorInf, minGrade, maxGrade);
				cout << "Введите оценку по математическому анализу " << quont << "-го студента: ";
				student[quont - 1].discipline.math = typeCheck(student[quont - 1].discipline.math, minGrade, maxGrade);
				cout << "Введите оценку по аналитической геометрии " << quont << "-го студента: ";
				student[quont - 1].discipline.anGeom = typeCheck(student[quont - 1].discipline.anGeom, minGrade, maxGrade);
				cout << "Введите оценку по английскому языку " << quont << "-го студента: ";
				student[quont - 1].discipline.english = typeCheck(student[quont - 1].discipline.english, minGrade, maxGrade);
				cout << "Введите оценку по инженерной графике " << quont << "-го студента: ";
				student[quont - 1].discipline.engGraph = typeCheck(student[quont - 1].discipline.engGraph, minGrade, maxGrade);
			}
			else {
				cout << "Достигнуто максимальное количество студентов.\n";
			}
			break;
		case no:
			cout << "Возвращаем вас к главному меню.\n";
			system("pause");
			break;
		default:
			cout << "Введена неверная команда.\n";
			break;
		}
		cout << "Вы хотите добавить ещё одну запись?" << endl << "1) Да" << endl << "2) Нет\n";
		flag = typeCheck(flag, yes, no);
	}

	return quont;
}
