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

enum {
	ext = 0,
	add,
	change,
	delet,
	sort,
	search
};

int main() {
	setlocale(LC_ALL, "Russian");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	int command = 0, numSt = 0, quontitySt = 0;
	const int nameFileSize = 255;
	const char nameFile[nameFileSize]{ "C:\\Users\\edika\\Desktop\\БД.txt" };
	const char nameBinFile[nameFileSize]{ "C:\\Users\\edika\\Desktop\\БДбин.txt" };
	studentInformation* student = new studentInformation[maxQuontSt];
	fstream BD;

	cout << "Добро пожаловать!\n";
	Sleep(500);
	cout << "Эта база данныых содержит в себе информацию о студентах.\n";
	cout << "Для начала работы с базой данных нажмите ENTER.\n";
	cin.get();
	system("cls");
	BD.open(nameFile, ios_base::in);
	if (BD.peek() == EOF) {
		cout << "База данных пуста.\n";
		cout << "Заполните базу данных.\n";
		Sleep(1500);
		system("cls");
		quontitySt = addSt(student, quontitySt);
	}
	else {

	}
	BD.close();
	do {
		BD.open(nameFile, ios_base::trunc);
		BD.close();
		BD.open(nameFile, ios_base::out);
		write(student, quontitySt, BD);
		cout << "Введите номер команды:\n";
		cout << "0) Выход.\n" << "1) Добавить запись.\n" << "2) Изменить запись.\n" << "3) Удалить запись.\n" << "4) Сортировка.\n" << "5) Поиск.\n";
		cin >> command;
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
			Sleep(500);
			system("cls");
			break;
		case change:
			cout << "Вы ввели команду Изменить запись.\n";
			Sleep(1000);
			system("cls");
			changeSt(student);
			Sleep(500);
			system("cls");
			break;
		case delet:
			cout << "Вы ввели команду Удалить запись.\n";
			Sleep(1000);
			write(student, quontitySt, BD);
			quontitySt = deleteSt(student, quontitySt);
			Sleep(500);
			system("cls");
			break;
		case sort:
			cout << "Вы ввели команду Сортировка.\n";
			Sleep(1000);
			system("cls");
			sortSt(student, quontitySt);
			Sleep(500);
			system("cls");
			break;
		case search:
			cout << "Вы ввели команду Поиск.\n";
			Sleep(1000);
			write(student, quontitySt, BD);
			searchSt(student, quontitySt);
			system("cls");
			break;
		default:
			cout << "Введена неверная команда.\n";
			Sleep(1000);
			system("cls");
		}
		Sleep(1000);
		BD.close();
	} while (command != 0);

	delete[]student;
	cout << "До встречи!";
	
	return(0);
}
