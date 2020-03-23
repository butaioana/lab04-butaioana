#pragma once
#include "Student.h"
class Repo
{
public:
	Repo();
	~Repo();
	void insert(Student);
	int get_len();
	Student* get_all();
	void update(Student );
	void set_len(int);

private:
	Student v[101];

	int len;
};

