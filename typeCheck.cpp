#include "typeCheck.h"
#include <iostream>
#include <Windows.h>
using namespace std;

int typeCheck(int n, int min, int max) {
	bool flag = true;
	while (flag) {
		cin >> n;
		cin.clear();
		cin.ignore(32767, '\n');
		if ((cin.fail()) or (n < min) or (n > max)) {
			cin.clear();
			cin.ignore(32767, '\n');
			cout << "Вы ввели некорректное значение! Введите другое значение.\n";
			system("pause");
			system("cls");
		}
		else {
			flag = false;
		}
	}
	return n;
}
