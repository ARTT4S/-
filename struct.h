#ifndef STRUCT_H_INCLUDED
#define STRUCT_H_INCLUDED

extern enum {
	nameSize = 50,
	surnameSize = 50,
	patronymicSize = 50,
	groupSize = 15,
	maxQuontSt = 100
};

extern struct studentInformation {
	char name[nameSize]{ "Нет имени" };
	char surname[surnameSize]{ "Нет фамилии" };
	char patronymic[patronymicSize]{ "Нет отчества" };
	char group[groupSize]{ "Нет группы" };
	int course{ 0 };
	struct {
		int highProgr{ 0 };
		int teorInf{ 0 };
		int math{ 0 };
		int anGeom{ 0 };
		int english{ 0 };
		int engGraph{ 0 };
	} discipline{};
};

#endif
