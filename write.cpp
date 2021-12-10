#include "write.h"
#include <iostream>
#include <cstring>
#include <iomanip>

static const int threshold = 7;

void smartWrite(char studInf[], fstream &wBD);

void write(studentInformation student[], int quont, fstream &BD) {
	cout << "База данных:\n";
	cout << "====================================================================================================================================================\n";
	BD << "====================================================================================================================================================\n";
	cout << "|№" << '\t' << "|Фамилия\t" << "|Имя\t" << '\t' << "|Отчество\t" << "|Группа\t" << '\t' << "|Курс" << "|Выс. прог." << "|Теор. инф." << "|Мат. анализ" << "|Аналит. геом." << "|Английский" << "|Инж. граф.|\n";
	BD << "|№" << '\t' << "|Фамилия\t" << "|Имя\t" << '\t' << "|Отчество\t" << "|Группа\t" << '\t' << "|Курс" << "|Выс. прог." << "|Теор. инф." << "|Мат. анализ" << "|Аналит. геом." << "|Английский" << "|Инж. граф.|\n";
	cout << "====================================================================================================================================================\n";
	BD << "====================================================================================================================================================\n";
	for (int i = 0; i < quont; ++i) {
		cout << '|' << i + 1 << '\t' << '|';
		BD << '|' << i + 1 << '\t' << '|';
		smartWrite(student[i].surname, BD);
		smartWrite(student[i].name, BD);
		smartWrite(student[i].patronymic, BD);
		smartWrite(student[i].group, BD);
		cout << student[i].course << setw(4) << '|' << student[i].discipline.highProgr << setw(10) << '|' << student[i].discipline.teorInf << setw(10) << '|' << student[i].discipline.math << setw(11) << '|' << student[i].discipline.anGeom << setw(13) << '|' << student[i].discipline.english << setw(10) << '|' << student[i].discipline.engGraph << setw(10) << '|' << endl;
		BD << student[i].course << setw(4) << '|' << student[i].discipline.highProgr << setw(10) << '|' << student[i].discipline.teorInf << setw(10) << '|' << student[i].discipline.math << setw(11) << '|' << student[i].discipline.anGeom << setw(13) << '|' << student[i].discipline.english << setw(10) << '|' << student[i].discipline.engGraph << setw(10) << '|' << endl;
		cout << "====================================================================================================================================================\n";
		BD << "====================================================================================================================================================\n";
	}
}

void smartWrite(char studInf[], fstream &wBD) {
	if (strlen(studInf) < threshold) {
		cout << studInf << '\t' << '\t' << '|';
		wBD << studInf << '\t' << '\t' << '|';
	}
	else {
		cout << studInf << '\t' << '|';
		wBD << studInf << '\t' << '|';
	}
}
