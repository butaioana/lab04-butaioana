#pragma once
#include "Class_undo.h"

class Repo_undo {

private:
	Undo array[101];
	int len;

public:

	Repo_undo();
	~Repo_undo();
	void add_to_stack(Undo);
	void reduce_len();
	Undo end_element_of_array();

};
