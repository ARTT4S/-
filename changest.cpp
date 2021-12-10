#include "changest.h"
#include "write.h"
#include <iostream>
#include <Windows.h>
using namespace std;

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

void changeSt(studentInformation student[]) {
	int changeCommand = 0, numSt = 0, flag = 0;
	do { 
		cout << "Запись о каком студенте по номеру вы хотите поменять?\n";
		cin >> numSt;
		numSt -= 1;
		cout << "Какую записть вы хотите поменять?\n";
		cout << "1)  Изменить Фамилию." << endl << "2)  Изменить имя." << endl << "3)  Изменить отчество." << endl << "4)  Изменить группу." << endl << "5)  Изменить курс." << endl << "6)  Изменить оценку по высокоуровневому программированию." << endl << "7)  Изменить оценку по теоретической информатике." << endl << "8)  Изменить оценку по математическому анализу." << endl << "9)  Изменить оценку по аналитической геометрии." << endl << "10) Изменить оценку по английскому языку." << endl << "11) Изменить оценку по инженерной графике." << endl << "0) Возврат к меню." << endl;;
		cin >> changeCommand;
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
			cin >> student[numSt].course;
			break;
		case highProgr:
			cout << "Внесите изменения в поле Выс. прог.: ";
			cin >> student[numSt].discipline.highProgr;
			break;
		case teorInf:
			cout << "Внесите изменения в поле Теор. инф.: ";
			cin >> student[numSt].discipline.teorInf;
			break;
		case math:
			cout << "Внесите изменения в поле Мат. анализ: ";
			cin >> student[numSt].discipline.math;
			break;
		case anGeom:
			cout << "Внесите изменения в поле Аналит. геом.: ";
			cin >> student[numSt].discipline.anGeom;
			break;
		case eng:
			cout << "Внесите изменения в поле Английский: ";
			cin >> student[numSt].discipline.english;
			break;
		case engGraph:
			cout << "Внесите изменения в поле Инж. граф.: ";
			cin >> student[numSt].discipline.engGraph;
			break;
		default:
			cout << "Введена неверная команда.\n";
		}
		cout << "Хотите ли вы ещё что-то изменить?" << endl << "1) Да" << endl << "2) Нет\n";
		cin >> flag;
		if (flag == no) {
			cout << "Чтобы вернуться к главному меню нажмите ENTER.\n";
			cin.get();
			cin.get();
			changeCommand = 0;
		}
	} while (changeCommand != 0);
} 
