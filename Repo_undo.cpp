#include "Repo_undo.h"

Repo_undo::Repo_undo() {

	this->len = 0;

}

Repo_undo::~Repo_undo() {

	this->len = 0;

}


void Repo_undo::add_to_stack(Undo undo) {

	this->array[this->len++] = undo;

}

void Repo_undo::reduce_len() {

	if (this->len > 0)
		this->len--;

}

Undo Repo_undo::end_element_of_array() {

	if (this->len > 0)
		return this->array[this->len - 1];
	else
		return this->array[0];
}