#include <iostream>
#include <iomanip>
#include <ctime>
#include <Windows.h>
#include <fstream>
using namespace std;
#include "struct.h"
#include "write.h"
#include "addst.h"
#include "changest.h"
#include "deletest.h"
#include "sortst.h"
#include "search.h"
#include "typeCheck.h"

enum {
	ext = 0,
	add,
	change,
	delet,
	sort,
	search
};

static const int err = 48;

void strRead(char str[], int size, fstream& BD);
void intRead(int *integer, int size, fstream& BD);
void strBinRead(char str[], fstream& BDB);
void intBinRead(int* integer, fstream& BDB);

int main() {
	setlocale(LC_ALL, "Russian");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	int command = 1, numSt = 0, quontitySt = 0, count = 0;
	const int nameFileSize = 255, sizeColumnNames = 115, size = 150;
	char read = NULL;
	const char nameFile[nameFileSize]{ "C:\\Users\\edika\\Desktop\\БД.txt" };
	const char nameBinFile[nameFileSize]{ "C:\\Users\\edika\\Desktop\\БДбин.bin" };
	char* string = new char[size];
	studentInformation* student = new studentInformation[maxQuontSt];
	fstream BD;
	fstream BDBin;
	cout << "Добро пожаловать!\n";
	Sleep(500);
	cout << "Эта база данныых содержит в себе информацию о студентах.\n";
	system("pause");
	system("cls");
	BD.open(nameFile, ios_base::in);
	BDBin.open(nameBinFile, ios_base::in);
	if (BD.is_open() and BDBin.is_open()) {
		if ((BD.peek() == EOF) and (BDBin.peek() == EOF)) {
			cout << "База данных пуста.\n";
			cout << "Заполните базу данных.\n";
			Sleep(1500);
			system("cls");
			quontitySt = addSt(student, quontitySt);
		}
		else if (BD.peek() != EOF) {
			if (BD.is_open()) {
				BD.seekg(0, ios_base::end);
				BD.seekg(-size, ios_base::end);
				BD.seekg(-2, ios_base::cur);
				while (read != '\n') {
					BD.seekg(-2, ios_base::cur);
					BD.get(read);
				}
				BD.get(read);
				while (read != '\t') {
					BD.get(read);
					if (read != '\t') {
						quontitySt *= 10;
						quontitySt += (int)read - err;
					}
				}
				BD.seekg(size * 2 + sizeColumnNames, ios_base::beg);
				for (int i = 0; i < quontitySt; ++i) {
					BD.getline(string, size, '\t');
					BD.get();
					strRead(student[i].surname, surnameSize, BD);
					strRead(student[i].name, nameSize, BD);
					strRead(student[i].patronymic, patronymicSize, BD);
					strRead(student[i].group, groupSize, BD);
					intRead(&student[i].course, size, BD);
					intRead(&student[i].discipline.highProgr, size, BD);
					intRead(&student[i].discipline.teorInf, size, BD);
					intRead(&student[i].discipline.math, size, BD);
					intRead(&student[i].discipline.anGeom, size, BD);
					intRead(&student[i].discipline.english, size, BD);
					intRead(&student[i].discipline.engGraph, size, BD);
					BD.get();
					BD.getline(string, size);
				}
			}
		}
		else if (BDBin.peek() != EOF) {
			BDBin.close();
			BDBin.open(nameBinFile, ios_base::in | ios_base::binary);
			BDBin.seekg(0, ios_base::end);
			BDBin.seekg(-size, ios_base::end);
			BDBin.seekg(-1, ios_base::cur);
			while (count != 13) {
				BDBin.seekg(-2, ios_base::cur);
				BDBin.read((char*)&read, sizeof(read));
				if (read == '|') {
					++count;
				}
			}
			while (read != '\t') {
				BDBin.read((char*)&read, sizeof(read));
				if (read != '\t') {
					quontitySt *= 10;
					quontitySt += (int)read - err;
				}
			}
			BDBin.seekg(size * 3, ios_base::beg);
			BDBin.read((char*)&read, sizeof(read));
			for (int i = 0; i < quontitySt; ++i) {
				while (read != '\t') {
					BDBin.read((char*)&read, sizeof(read));
				}
				BDBin.read((char*)&read, sizeof(read));
				strBinRead(student[i].surname, BDBin);
				strBinRead(student[i].name, BDBin);
				strBinRead(student[i].patronymic, BDBin);
				strBinRead(student[i].group, BDBin);
				intBinRead(&student[i].course, BDBin);
				intBinRead(&student[i].discipline.highProgr, BDBin);
				intBinRead(&student[i].discipline.teorInf, BDBin);
				intBinRead(&student[i].discipline.math, BDBin);
				intBinRead(&student[i].discipline.anGeom, BDBin);
				intBinRead(&student[i].discipline.english, BDBin);
				intBinRead(&student[i].discipline.engGraph, BDBin);
				BDBin.read((char*)&read, sizeof(read));
			}
		}
	}
	else {
		cout << "Проблемы с запуском файла, содержащего базу данных. Возможно, файла не существует.\n";
		command = 0;
	}
	BD.close();
	BDBin.close();
	while (command != 0) {
		BD.open(nameFile, ios_base::trunc);
		BD.close();
		BD.open(nameFile, ios_base::out);
		write(student, quontitySt, BD);
		cout << "Введите номер команды:\n";
		cout << "0) Выход.\n" << "1) Добавить запись.\n" << "2) Изменить запись.\n" << "3) Удалить запись.\n" << "4) Сортировка.\n" << "5) Поиск.\n";
		command = typeCheck(command, ext, search);
		system("cls");
		switch (command) {
		case ext:
			cout << "Вы ввели команду Выход.\n";
			break;
		case add:
			cout << "Вы ввели команду Добавить запись.\n";
			Sleep(1000);
			system("cls");
			quontitySt = addSt(student, quontitySt);
			break;
		case change:
			cout << "Вы ввели команду Изменить запись.\n";
			Sleep(1000);
			system("cls");
			changeSt(student, quontitySt, BD);
			break;
		case delet:
			cout << "Вы ввели команду Удалить запись.\n";
			Sleep(1000);
			system("cls");
			quontitySt = deleteSt(student, quontitySt, BD);
			break;
		case sort:
			cout << "Вы ввели команду Сортировка.\n";
			Sleep(1000);
			system("cls");
			sortSt(student, quontitySt);
			break;
		case search:
			cout << "Вы ввели команду Поиск.\n";
			Sleep(1000);
			system("cls");
			write(student, quontitySt, BD);
			searchSt(student, quontitySt);
			break;
		default:
			cout << "Введена неверная команда.\n";
		}
		Sleep(1000);
		system("cls");
		BD.close();
		BD.open(nameFile, ios_base::in);
		BDBin.open(nameBinFile, ios_base::trunc | ios_base::binary | ios_base::out | ios_base::in);
		while (!BD.eof()) {
			BD.getline(string, size);
			BDBin.write((char*)string, size);
		}
		BD.close();
		BDBin.close();
	}
	delete[]student;
	delete[]string;
	cout << "До встречи!";

	return(0);
}

void strRead(char str[], int size, fstream& BD) {
	char sym = NULL;
	BD.getline(str, size, '\t');
	BD.get(sym);
	if (sym == '\t') {
		BD.get();
	}
}
void intRead(int *integer, int size, fstream& BD) {
	char str = NULL;
	char* string = new char[size];
	BD.get(str);
	*integer = (int)str - err;
	BD.getline(string, size, '|');
}

void strBinRead(char str[], fstream& BDB) {
	char read = NULL;
	int i = 0;
	for (i; read != '|'; ++i) {
		BDB.read((char*)&read, sizeof(read));
		if (read != '\t') {
			str[i] = read;
		}
		else {
			BDB.read((char*)&read, sizeof(read));
		}
		if (read == '\t') {
			BDB.read((char*)&read, sizeof(read));
		}
	}
	i -= 1;
	for (i; i < strlen(str); ++i) {
		str[i] = NULL;
	}
}

void intBinRead(int* integer, fstream& BDB) {
	char read = NULL;
	BDB.read((char*)&read, sizeof(read));
	*integer = (int)read - err;
	for (int i = 0; read != '|'; ++i) {
		BDB.read((char*)&read, sizeof(read));
	}
}
