#pragma once
#include "repo.h"
class Service {
private:
	Repo repo;

public:

	void insert_sevice(char*, char*, int);
	int get_len();
	Student* get_all();
	void update_shop(char*, char*, int);
	void set_len(int);
	void delete_student(char*);
};