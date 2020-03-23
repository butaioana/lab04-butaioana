#include"UI.h"
#include"Test.h"
#include"Functionalitati.h"
#include<iostream>
using namespace std;

char* allocate_memory()
{
	char* name = new char[0];
	string string_name;
	cin >> string_name;
	name = new char[string_name.size() + 1];
	strcpy_s(name, 1 + string_name.size(), string_name.c_str());

	return name;
}

void UI::add(){

	char nume[100];
	char* date = new char[0];
	string aux_date;
	int nota;
	cout << "Nume: ";
	cin >> nume;
	cout << endl;
	int ok = 1;
	while (ok == 1)
	{
		while (ok == 1) {
			cout << "Data: ";
			date = allocate_memory();
			if (except_date(date))
				ok = 0;
			else
				cout << "Invalid date! ";
		}
		cout << endl;
		cout << "nota: ";
		do {
			cin >> nota;
			if(!(nota >= 1 and nota <= 10))
				cout << "Nota trebuie sa fie cuprinsa intre 1 si 10: ";
		} while (!(nota >= 0 and nota <= 10));

		this->service.insert_sevice(nume, date, nota);
	}
}
void UI::print()
{
	for (int i = 0; i < this->service.get_len(); i++)
		cout << this->service.get_all()[i] << endl;
}
void UI::update_shop() {

	char* date = new char[0], * name = new char[0];
	int price;

	cout << "Give a name: ";
	name = allocate_memory();

	int ok = 1;
	while (ok == 1) {
		cout << "Give a date: ";
		date = allocate_memory();
		if (except_date(date))
			ok = 0;
		else
			cout << "Invalid date! ";
	}

	cout << "Give a mark: ";
	cin >> price;
	cout << endl;
	this->service.update_shop(name, date, price);
}

void UI::delete_shop()
{
	cout << "Give a name for deleting: ";
	char* name = allocate_memory();
	this->service.delete_student(name);
}
void UI::run() {
	int op = 1;
	while (op) 
	{
		cout << "Alege o obtiune" << endl;
		meniu();
		cout << "Obtiunea ta este" << endl;
		cin >> op;
		if (op == 1) {
			this->add();
		}
		if (op == 2) {
			this->print();
		}
		if (op == 3) {
			this->update_shop();
		}
		if (op == 4)
			this->delete_shop();
	}
}