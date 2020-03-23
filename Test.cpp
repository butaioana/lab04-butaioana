
#include"Test.h"
#include"repo.h"
#include "UI.h"
#include<assert.h>
void teste() {

	char* date1 = new char[101], * persoana1 = new char[100];
	char* date2 = new char[101], * persoana2 = new char[100];
	char* date3 = new char[101], * persoana3 = new char[100];
	char* name = new char[20];

	strcpy_s(date1, sizeof"20.03.2020", "20.03.2020");
	strcpy_s(persoana1, sizeof"Ioana", "Ioana");
	Student s1(persoana1, date1, 9);
	strcpy_s(persoana2, sizeof"Ana", "Ana");
	Student s2(persoana2, date2, 7);
	strcpy_s(date3, sizeof"24.10.2020", "24.10.2020");
	strcpy_s(persoana3, sizeof"Ioana", "Ioana");
	Student s3(persoana3, date3, 8);

	Repo repo;
	Student examinare[2];
	examinare[0] = s1;
	examinare[1] = s2;
	repo.insert(s1);
	repo.insert(s2);

	assert(repo.get_len() == 2);
	for (int i = 0; i < repo.get_len(); i++) {
		assert(repo.get_all()[i] == examinare[i]);
	}

	repo.update(s3);

	examinare[0] = s3;
	assert(repo.get_len() == 2);
	for (int i = 0; i < repo.get_len(); i++) {
		assert(repo.get_all()[i] == examinare[i]);
	}

	Service service;
	name = new char[1+strlen("Ana")];
	strcpy_s(name, 1 + strlen("Ana"), "Ana");
	service.delete_student(name);
	for (int i = 0; i < repo.get_len(); i++) {
		assert(repo.get_all()[i] == examinare[i]);
	}
}
