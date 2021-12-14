#include "changest.h"
#include "write.h"
#include "typeCheck.h"
#include <iostream>
#include <Windows.h>

enum {
	yes = 1,
	no
};

enum {
	ext = 0,
	surname,
	name,
	patronymic,
	group,
	course,
	highProgr,
	teorInf,
	math,
	anGeom,
	eng,
	engGraph
};

void changeSt(studentInformation student[], int quont, fstream &BD) {
	int changeCommand = 0, numSt = 0, flag = 0;
	do { 
		write(student, quont, BD);
		cout << "Запись о каком студенте по номеру вы хотите поменять: ";
		numSt = typeCheck(numSt, 1, quont);
		system("cls");
		cout << "Вы точно хотите изменить запись?" << endl << "1) Да" << endl << "2) Нет\n";
		flag = typeCheck(flag, yes, no);
		system("cls");
		switch (flag) {
		case yes:
			numSt -= 1;
			cout << "Что вы хотите поменять?\n";
			cout << "0)  Возврат к меню." << endl << "1)  Изменить Фамилию." << endl << "2)  Изменить имя." << endl << "3)  Изменить отчество." << endl << "4)  Изменить группу." << endl << "5)  Изменить курс." << endl << "6)  Изменить оценку по высокоуровневому программированию." << endl << "7)  Изменить оценку по теоретической информатике." << endl << "8)  Изменить оценку по математическому анализу." << endl << "9)  Изменить оценку по аналитической геометрии." << endl << "10) Изменить оценку по английскому языку." << endl << "11) Изменить оценку по инженерной графике." << endl;
			changeCommand = typeCheck(changeCommand, ext, engGraph);
			system("cls");
			switch (changeCommand) {
			case ext:
				cout << "Возвращаем вас к меню сортировки.\n";
				break;
			case surname:
				cout << "Внесите изменения в поле Фамилия: ";
				cin >> student[numSt].surname;
				break;
			case name:
				cout << "Внесите изменения в поле Имя: ";
				cin >> student[numSt].name;
				break;
			case patronymic:
				cout << "Внесите изменения в поле Отчество: ";
				cin >> student[numSt].patronymic;
				break;
			case group:
				cout << "Внесите изменения в поле Группа: ";
				cin >> student[numSt].group;
				break;
			case course:
				cout << "Внесите изменения в поле Курс: ";
				student[numSt].course = typeCheck(student[numSt].course, minCourse, maxCourse);
				break;
			case highProgr:
				cout << "Внесите изменения в поле Выс. прог.: ";
				student[numSt].discipline.highProgr = typeCheck(student[numSt].discipline.highProgr, minGrade, maxGrade);
				break;
			case teorInf:
				cout << "Внесите изменения в поле Теор. инф.: ";
				student[numSt].discipline.teorInf = typeCheck(student[numSt].discipline.teorInf, minGrade, maxGrade);
				break;
			case math:
				cout << "Внесите изменения в поле Мат. анализ: ";
				student[numSt].discipline.math = typeCheck(student[numSt].discipline.math, minGrade, maxGrade);
				break;
			case anGeom:
				cout << "Внесите изменения в поле Аналит. геом.: ";
				student[numSt].discipline.anGeom = typeCheck(student[numSt].discipline.anGeom, minGrade, maxGrade);
				break;
			case eng:
				cout << "Внесите изменения в поле Английский: ";
				student[numSt].discipline.english = typeCheck(student[numSt].discipline.english, minGrade, maxGrade);
				break;
			case engGraph:
				cout << "Внесите изменения в поле Инж. граф.: ";
				student[numSt].discipline.engGraph = typeCheck(student[numSt].discipline.engGraph, minGrade, maxGrade);
				break;
			default:
				cout << "Введена неверная команда.\n";
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
		system("cls");
		cout << "Вы хотите продолжить изменения?" << endl << "1) Да" << endl << "2) Нет\n";
		flag = typeCheck(flag, yes, no);
	} while (flag != no);
} 
