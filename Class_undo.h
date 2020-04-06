#pragma once
#include "Examen.h"

class Undo {

private:

	int index;
	Examen examen;
public:

	Undo();
	Undo(int, Examen);
	Undo(const Undo&);
	~Undo();
	int get_index();
	void set_index(int);
	Examen get_examen();
	Undo& operator =(const Undo&);

};