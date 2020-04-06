#pragma once
#include "Examen.h"
class Repo {

private:
	Examen array[101];
	int len;

public:

	Repo();
	~Repo();

	void insert(Examen);
	int get_len();
	Examen* get_all();
	void update(Examen);
	void delete_examen(int);
};