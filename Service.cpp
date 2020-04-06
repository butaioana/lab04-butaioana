#include "Service.h"
#include "Repo_undo.h"
#include "Functions.h"

void Service::insert_service(char* nume, char* data, int nota) {

	Examen examen(nume, data, nota,0);
	Undo undo(4, examen);
	repo_undo.add_to_stack(undo);
	repo.insert(examen);

}

Examen* Service::get_all() {
	return this->repo.get_all();
}

int Service::get_len() {
	return this->repo.get_len();
}

void Service::update_examen(char* nume, char* data, int nota) {

	Examen current_examen(nume, data, nota,0);
	Examen* examen = this->repo.get_all();
	Undo undo;
	for (int i = 0; i < this->repo.get_len(); i++)
		if (strcmp(nume, examen[i].get_nume()) == 0) {
			undo = Undo(3, examen[i]);
			i = this->repo.get_len();
		}
	this->repo_undo.add_to_stack(undo);
	this->repo.update(current_examen);
}

void Service::delete_examen(char* name) {

	Examen* shop = this->repo.get_all();
	for (int i = 0; i < this->repo.get_len(); i++) {
		if (strcmp(name, shop[i].get_nume()) == 0) {
			Undo undo(1, shop[i]);
			repo_undo.add_to_stack(undo);
			this->repo.delete_examen(i);
		}
	}
}

void Service::reverse_add_exam(char* name) {
	Examen* examen = this->repo.get_all();
	for (int i = 0; i < this->repo.get_len(); i++) {
		if (strcmp(name, examen[i].get_nume()) == 0) {
			this->repo.delete_examen(i);
		}
	}
}


void Service::undo_examen() {

	Repo_undo repo_undo;

	Undo undo_end_element = repo_undo.end_element_of_array();
	if (undo_end_element.get_index() == 4) {
		this->reverse_add_exam(undo_end_element.get_examen().get_nume());
		repo_undo.reduce_len();
	}
	if (undo_end_element.get_index() == 3) {
		this->repo.update(undo_end_element.get_examen());
		repo_undo.reduce_len();
	}
	if (undo_end_element.get_index() == 1) {
		this->repo.insert(undo_end_element.get_examen());
		repo_undo.reduce_len();
	}
}

void Service::add_to_repo_undo(char* date, Examen exam) {

	Examen exam1(exam.get_nume(), date, exam.get_nota(),0);
	Undo undo(7, exam1);
	repo_undo.add_to_stack(undo);
}

Examen* Service::all_exams_by_higher_note(double note,int &n) {

	Examen* array_by_date = new Examen[101];
	n = 0;
	Examen* examen = this->repo.get_all();
	for (int i = 0; i < this->repo.get_len(); i++) {

		if (note<examen[i].get_nota()) {
			array_by_date[n++] = examen[i];
		}
	}
	return array_by_date;
}

void Service::bonus(char* name) {

	Examen* array = repo.get_all();
	for (int i = 0; i < repo.get_len(); i++) {

		if (strcmp(name, array[i].get_nume())==0) {

			array[i].set_bonus(array[i].get_bonus() + 1);
		}
	}

}