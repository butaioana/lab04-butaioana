#include "Repo.h"

Repo::Repo() {

	this->len = 0;
}

Repo::~Repo() {
	this->len = 0;
}

void Repo::insert(Examen expence) {
	this->array[this->len++] = expence;
}

int Repo::get_len() {
	return this->len;
}

Examen* Repo::get_all() {
	return this->array;
}

//void Repo::set_len(int new_len) {
//	this->len= new_len;
//}

void Repo::update(Examen exam) {

	int n = this->get_len();
	Examen* vector = this->get_all();

	for (int i = 0; i < n; i++) {
		if (strcmp(exam.get_nume(), vector[i].get_nume()) == 0) {
			vector[i] = exam;
		}
	}

}

void Repo::delete_examen(int i) {

	while (i < this->len) {
		if (i + 1 < this->len)
			this->array[i] = this->array[i + 1];
		i++;
	}
	this->len--;
}