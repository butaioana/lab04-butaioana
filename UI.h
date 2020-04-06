#pragma once
#include "Service.h"
class UI {
private:
	Service service;
	void add();
	void print();
	void update_examen();
	void delete_examen();
	void all_exams_by_higher_note();
	void bonus();
public:
	void run();
};