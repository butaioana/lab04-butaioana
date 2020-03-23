#include "repo.h"

Repo::Repo()
{
	this->len = 0;
}
Repo::~Repo() {
	this->len = 0;
}
void Repo::insert(Student examinare) {
	this->v[this->len++] = examinare;
}
int Repo::get_len() {
	return this->len;
}
Student* Repo::get_all() {
	return this->v;
}
void Repo::update(Student student) {

	int n = this->get_len();
	Student* vector = this->get_all();

	for (int i = 0; i < n; i++) {
		if (strcmp(student.get_nume(), vector[i].get_nume()) == 0) {
			vector[i] = student;
		}
	}

}
void Repo::set_len(int new_len) {
		this->len = new_len;
}