#include "sortst.h"
#include "typeCheck.h"
#include <iostream>
#include <Windows.h>
using namespace std;

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

enum {
	increase = 1,
	waning
};

static int lesser = 0;

bool recSort(char str1[], char str2[], int sym);
void sorting(int quont, int order[], studentInformation student[]);

void sortSt(studentInformation student[], int quont) {
	int sortCommand = 0, symbol = 0, buffer = 0;
	int *dispOrder = new int[quont] {0};
	cout << "По какому параметру вы хотите отсортировать массив?" << endl << "0) Возврат к меню." << endl << "1) По фамилии." << endl << "2) По имени." << endl << "3) По отчеству." << endl << "4) По группе." << endl << "5) По курсу." << endl << "6) По оценке по высокоуровневому программированию." << endl << "7) По оценке теоретической информатики." << endl << "8) По оценке по математическому анализу." << endl << "9) По оценке по аналитической геометрии." << endl << "10) По оценке по английскому языку." << endl << "11) По оценке по инженерной графике." << endl;
	sortCommand = typeCheck(sortCommand, ext, engGraph);
	system("cls");
	switch (sortCommand) {
	case ext:
		cout << "Возвращаем вас к главному меню\n";
		break;
	case surname:
		cout << "Вы выбрали сортировку по фималии.\n";
		Sleep(1000);
		system("cls");
		for (int i = 0; i < quont; ++i) {
			for (int j = i + 1; j < quont; ++j) {
				symbol = 0;
				if (strlen(student[i].surname) >= strlen(student[j].surname)) {
					lesser = strlen(student[j].surname);
				}
				else {
					lesser = strlen(student[i].surname);
				}
				if (recSort(student[i].surname, student[j].surname, symbol)) {
					dispOrder[i] += 1;
				}
				else {
					dispOrder[j] += 1;
				}
			}
		}
		sorting(quont, dispOrder, student);
		cout << "Сортировка закончена.";
		break;
	case name:
		cout << "Вы выбрали сортировку по имени.\n";
		Sleep(1000);
		system("cls");
		for (int i = 0; i < quont; ++i) {

			for (int j = i + 1; j < quont; ++j) {
				symbol = 0;
				if (strlen(student[i].name) >= strlen(student[j].name)) {
					lesser = strlen(student[i].name);
				}
				else {
					lesser = strlen(student[j].name);
				}
				if (recSort(student[i].name, student[j].name, symbol)) {
					dispOrder[i] += 1;
				}
				else {
					dispOrder[j] += 1;
				}
			}
		}
		sorting(quont, dispOrder, student);
		cout << "Сортировка закончена.";
		break;
	case patronymic:
		cout << "Вы выбрали сортировку по отчеству.\n";
		Sleep(1000);
		system("cls");
		for (int i = 0; i < quont; ++i) {
			for (int j = i + 1; j < quont; ++j) {
				symbol = 0;
				if (strlen(student[i].patronymic) >= strlen(student[j].patronymic)) {
					lesser = strlen(student[i].patronymic);
				}
				else {
					lesser = strlen(student[j].patronymic);
				}
				if (recSort(student[i].patronymic, student[j].patronymic, symbol)) {
					dispOrder[i] += 1;
				}
				else {
					dispOrder[j] += 1;
				}
			}
		}
		sorting(quont, dispOrder, student);
		cout << "Сортировка закончена.";
		break;
	case group:
		cout << "Вы выбрали сортировку по группе.\n";
		Sleep(1000);
		system("cls");
		for (int i = 0; i < quont; ++i) {
			for (int j = i + 1; j < quont; ++j) {
				symbol = 0;
				if (strlen(student[i].group) >= strlen(student[j].group)) {
					lesser = strlen(student[i].group);
				}
				else {
					lesser = strlen(student[j].group);
				}
				if (recSort(student[i].group, student[j].group, symbol)) {
					dispOrder[i] += 1;
				}
				else {
					dispOrder[j] += 1;
				}
			}
		}
		sorting(quont, dispOrder, student);
		cout << "Сортировка закончена.";
		break;
	case course:
		cout << "Вы выбрали сортировку по курсу.\n";
		Sleep(1000);
		system("cls");
		for (int i = 0; i < quont; ++i) {
			for (int j = i + 1; j < quont; ++j) {
				if (student[i].course > student[j].course) {
					dispOrder[i] += 1;
				}
				else {
					dispOrder[j] += 1;
				}
			}
		}
		sorting(quont, dispOrder, student);
		cout << "Сортировка закончена.";
		break;
	case highProgr:
		cout << "Вы выбрали сортировку по оценке по высокоуровневому программированию.\n";
		Sleep(1000);
		system("cls");
		for (int i = 0; i < quont; ++i) {
			for (int j = i + 1; j < quont; ++j) {
				if (student[i].discipline.highProgr > student[j].discipline.highProgr) {
					dispOrder[i] += 1;
				}
				else {
					dispOrder[j] += 1;
				}
			}
		}
		sorting(quont, dispOrder, student);
		cout << "Сортировка закончена.";
		break;
	case teorInf:
		cout << "Вы выбрали сортировку по оценке по теоретической информатике.\n";
		Sleep(1000);
		system("cls");
		for (int i = 0; i < quont; ++i) {
			for (int j = i + 1; j < quont; ++j) {
				if (student[i].discipline.teorInf > student[j].discipline.teorInf) {
					dispOrder[i] += 1;
				}
				else {
					dispOrder[j] += 1;
				}
			}
		}
		sorting(quont, dispOrder, student);
		cout << "Сортировка закончена.";
		break;
	case math:
		cout << "Вы выбрали сортировку по оценке по математическому анализу.\n";
		Sleep(1000);
		system("cls");
		for (int i = 0; i < quont; ++i) {
			for (int j = i + 1; j < quont; ++j) {
				if (student[i].discipline.math > student[j].discipline.math) {
					dispOrder[i] += 1;
				}
				else {
					dispOrder[j] += 1;
				}
			}
		}
		sorting(quont, dispOrder, student);
		cout << "Сортировка закончена.";
		break;
	case anGeom:
		cout << "Вы выбрали сортировку по оценке по аналитической геометрии.\n";
		Sleep(1000);
		system("cls");
		for (int i = 0; i < quont; ++i) {
			for (int j = i + 1; j < quont; ++j) {
				if (student[i].discipline.anGeom > student[j].discipline.anGeom) {
					dispOrder[i] += 1;
				}
				else {
					dispOrder[j] += 1;
				}
			}
		}
		sorting(quont, dispOrder, student);
		cout << "Сортировка закончена.";
		break;
	case eng:
		cout << "Вы выбрали сортировку по оценке по английскому языку.\n";
		Sleep(1000);
		system("cls");
		for (int i = 0; i < quont; ++i) {
			for (int j = i + 1; j < quont; ++j) {
				if (student[i].discipline.english > student[j].discipline.english) {
					dispOrder[i] += 1;
				}
				else {
					dispOrder[j] += 1;
				}
			}
		}
		sorting(quont, dispOrder, student);
		cout << "Сортировка закончена.";
		break;
	case engGraph:
		cout << "Вы выбрали сортировку по оценке по инженерной графике.\n";
		Sleep(1000);
		system("cls");
		for (int i = 0; i < quont; ++i) {
			for (int j = i + 1; j < quont; ++j) {
				if (student[i].discipline.engGraph > student[j].discipline.engGraph) {
					dispOrder[i] += 1;
				}
				else {
					dispOrder[j] += 1;
				}
			}
		}
		sorting(quont, dispOrder, student);
		cout << "Сортировка закончена.";
		break;
	}
	system("pause");
}

bool recSort(char str1[], char str2[], int sym) {
	if (str1[sym] > str2[sym]) {
		return 1;
	}
	else if (str1[sym] < str2[sym]) {
		return 0;
	}
	else {
		if (sym + 1 <= lesser) {
			recSort(str1, str2, sym + 1);
		}
	}

}

void sorting(int quont, int order[], studentInformation student[]) {
	studentInformation buffer;
	int condition = 0;
	cout << "Как вы хотите отсортировать массив?" << endl << "1) По возрастанию" << endl << "2) По убыванию\n";
	condition = typeCheck(condition, increase, waning);
	system("cls");
	switch (condition) {
	case increase:
		cout << "Вы выбрали сортировку по возрастанию.\n";
		Sleep(1000);
		system("cls");
		for (int i = 0; i < quont - 1; ++i) {
			for (int j = 0; j < quont - i - 1; ++j) {
				if (order[j] < order[j + 1]) {
					buffer = student[j];
					student[j] = student[j + 1];
					student[j + 1] = buffer;
				}
			}
		}
		break;
	case waning:
		cout << "Вы выбрали сортировку по убыванию.\n";
		Sleep(1000);
		system("cls");
		for (int i = 0; i < quont - 1; ++i) {
			for (int j = 0; j < quont - i - 1; ++j) {
				if (order[j] > order[j + 1]) {
					buffer = student[j];
					student[j] = student[j + 1];
					student[j + 1] = buffer;
				}
			}
		}
		break;
	default:
		cout << "Введена неверная команда.";
		break;
	}
}
