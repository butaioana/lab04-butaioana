#include "Class_undo.h"


Undo::Undo() {

	this->index = 0;

}


Undo::Undo(int index, Examen shop) {

	this->index = index;
	this->examen = shop;
}


Undo::Undo(const Undo& object) {

	this->index = object.index;
	this->examen = object.examen;
}



Undo::~Undo() {

	this->index = 0;
}


int Undo::get_index() {
	return this->index;
}


Examen Undo::get_examen() {
	return this->examen;

}

void Undo::set_index(int new_index) {

	this->index = new_index;
}

Undo& Undo:: operator =(const Undo& undo) {

	this->index = undo.index;
	this->examen = undo.examen;
	return *this;
}