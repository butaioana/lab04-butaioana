#include "Examen.h"
#include <cstring>
Examen::Examen() {

	this->nume = NULL;
	this->nota = 0;
	this->data = NULL;
	this->bonus = 0;
}

Examen::Examen(char* nume, char* data, double nota, int bonus) {

	this->nume = new char[strlen(nume) + 1];
	strcpy_s(this->nume, 1 + strlen(nume), nume);
	this->data = new char[strlen(data) + 1];
	strcpy_s(this->data, 1 + strlen(data), data);
	this->nota = nota;
	this->bonus = bonus;
}

Examen::Examen(const Examen& expence) {

	this->nume = new char[strlen(expence.nume) + 1];
	strcpy_s(this->nume, 1 + strlen(expence.nume), expence.nume);
	this->data = new char[strlen(expence.data) + 1];
	strcpy_s(this->data, 1 + strlen(expence.data), expence.data);
	this->nota = expence.nota;
}

Examen::~Examen() {

	if (this->data) {

		delete[] this->data;
		this->data = NULL;
	}
	if (this->nume)
	{
		delete[] this->nume;
		this->nume = NULL;
	}
}

//Getters

char* Examen::get_nume() {
	return this->nume;
}

double Examen::get_nota() {
	return this->nota;
}

char* Examen::get_data() {
	return this->data;
}

int Examen::get_bonus() {
	return this->bonus;
}

//Setters

void Examen::set_nume(char* new_nume) {

	if (this->nume)
	{
		delete[] this->nume;
		this->nume = NULL;
	}
	this->nume = new char[strlen(new_nume) + 1];
	strcpy_s(this->nume, 1 + strlen(new_nume), new_nume);
}

void Examen::set_bonus(int bonus) {

	this->bonus = bonus;
}

void Examen::set_data(char* new_data) {
	if (this->data)
	{
		delete[] this->data;
		this->data = NULL;
	}
	this->data = new char[strlen(new_data) + 1];
	strcpy_s(this->data, 1 + strlen(new_data), new_data);
}

void Examen::set_nota(double new_nota) {
	this->nota = new_nota;
}

Examen& Examen:: operator =(const Examen& expence) {
	this->set_nume(expence.nume);
	this->set_nota(expence.nota);
	this->set_data(expence.data);
	return *this;
}

bool Examen:: operator==(const Examen& s) {
	return strcmp(this->data, s.data) == 0 and this->nota == s.nota and strcmp(this->nume, s.nume) == 0;
}

std::ostream& operator <<(std::ostream& os, const Examen& expence) {
	os << std::endl << "Nume: " << expence.nume << " Data: " << expence.data << " Nume: " << expence.nota << " Bonus: "<<expence.bonus<<std::endl;
	return os;
}