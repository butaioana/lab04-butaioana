#pragma once
#include "Repo.h"
#include "Repo_undo.h"
class Service {
private:
	Repo repo;
	Repo_undo repo_undo;
public:
	Service() {}
	~Service() {}
	void insert_service(char*, char*, int);
	int get_len();
	Examen* get_all();
	void update_examen(char*, char*, int);
	void delete_examen(char*);
	void undo_examen();
	void add_to_repo_undo(char*, Examen);
	void reverse_add_exam(char*);
	Examen* all_exams_by_higher_note(double,int&);
	void bonus(char* name);
};