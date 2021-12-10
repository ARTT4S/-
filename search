#include "search.h"
#include "write.h"
#include <iostream>
#include <iomanip>
#include <cstring>
#include <Windows.h>
using namespace std;

static const int threshold = 8;

void smartWrite(char studInf[]);

void searchSt(studentInformation student[], int quont) {
	int numOfPoor = 0;
	cout << "Студенты, у которых хотя бы по одному предмету стоит 2 (вариант №2)\n";
	for (int i = 0; i < quont; ++i) {
		if ((student[i].discipline.highProgr == 2) or (student[i].discipline.teorInf == 2) or (student[i].discipline.math == 2) or (student[i].discipline.anGeom == 2) or (student[i].discipline.english == 2) or (student[i].discipline.engGraph == 2)) {
			++numOfPoor;
			cout << "====================================================================================================================================================\n";
			cout << '|' << i + 1 << '\t' << '|';
			smartWrite(student[i].surname);
			smartWrite(student[i].name);
			smartWrite(student[i].patronymic);
			smartWrite(student[i].group);
			cout << student[i].course << setw(4) << '|' << student[i].discipline.highProgr << setw(10) << '|' << student[i].discipline.teorInf << setw(10) << '|' << student[i].discipline.math << setw(11) << '|' << student[i].discipline.anGeom << setw(13) << '|' << student[i].discipline.english << setw(10) << '|' << student[i].discipline.engGraph << setw(10) << '|' << endl;
			if (quont - i == 1) {
				cout << "====================================================================================================================================================\n";
			}
		}
		if (numOfPoor == 0) {
			cout << "Таких студентов нет в базе данных.\n";
		}
	}
	cout << "Чтобы вернуться к главному меню нажмите ENTER.\n";
	cin.get();
	cin.get();
	Sleep(500);
}

void smartWrite(char studInf[]) {
	if (strlen(studInf) < threshold) {
		cout << studInf << '\t' << '\t' << '|';
	}
	else {
		cout << studInf << '\t' << '|';
	}
}
