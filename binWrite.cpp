#include "binWrite.h"
#include <iostream>
#include <cstring>

void binWrite(int quont, fstream& BD, fstream &BDBin) {
	const int size = 150, sizeColumnNames = 115;
	char *string = new char[size];
	while (!BD.eof()) {
		BD.getline(string, size);
		BDBin.write(string, sizeof(string));
	}
}
