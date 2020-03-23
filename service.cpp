#include "Service.h"
void Service::insert_sevice(char* nume, char* date, int nota) {
	Student student(nume, date, nota);
	repo.insert(student);
}
Student* Service::get_all() {
	return this->repo.get_all();
}
int Service::get_len() {
	return this->repo.get_len();
}
void Service::update_shop(char* name, char* date, int nota) {
	Student student(name, date, nota);
	this->repo.update(student);
}

void Service::set_len(int new_len) {
	this->repo.set_len(new_len);
}

void Service::delete_student(char* student) {

	for (int i = 0; i < repo.get_len(); i++) {
		if (strcmp(student, repo.get_all()[i].get_nume()) == 0) {
			while (i < repo.get_len()) {
				if (i + 1 < repo.get_len())
					repo.get_all()[i] = repo.get_all()[i + 1];
				i++;
			}
			this->set_len(repo.get_len() - 1);
		}
	}
}