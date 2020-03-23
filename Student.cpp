#include "Student.h"
#include <cstring>
Student::Student() {

	this->nume = NULL;
	this->nota = 0;
	this->date = NULL;
}

Student::Student(char* name, char* date, int price) {

	this->nume = new char[strlen(name) + 1];
	strcpy_s(this->nume, 1 + strlen(name), name);
	this->date = new char[strlen(date) + 1];
	strcpy_s(this->date, 1 + strlen(date), date);
	this->nota = price;
}

Student::Student(const Student& expence) {

	this->nume = new char[strlen(expence.nume) + 1];
	strcpy_s(this->nume, 1 + strlen(expence.nume), expence.nume);
	this->date = new char[strlen(expence.date) + 1];
	strcpy_s(this->date, 1 + strlen(expence.date), expence.date);
	this->nota = expence.nota;
}

Student::~Student() {

	if (this->date) {

		delete[] this->date;
		this->date = NULL;
		delete[] this->nume;
		this->nume = NULL;
	}
}

//Getters

char* Student::get_nume() {
	return this->nume;
}

int Student::get_nota() {
	return this->nota;
}

char* Student::get_date() {
	return this->date;
}

//Setters

void Student::set_nume(char* new_name) {

	this->nume = new char[strlen(new_name) + 1];
	strcpy_s(this->nume, 1 + strlen(new_name), new_name);
}

void Student::set_date(char* new_date) {
	this->date = new char[strlen(new_date) + 1];
	strcpy_s(this->date, 1 + strlen(new_date), new_date);
}

void Student::set_nota(int new_price) {
	this->nota = new_price;
}

Student& Student:: operator =(const Student& expence) {
	this->set_nume(expence.nume);
	this->set_nota(expence.nota);
	this->set_date(expence.date);
	return *this;
}

bool Student:: operator==(const Student& s) {
	return strcmp(this->date, s.date) == 0 and this->nota == s.nota and strcmp(this->nume, s.nume) == 0;
}

std::ostream& operator <<(std::ostream& os, const Student& expence) {
	os << std::endl << "Name: " << expence.nume << " Date: " << expence.date << " Nota: " << expence.nota << std::endl;
	return os;
}