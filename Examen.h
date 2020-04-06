#pragma once
#pragma once
#include <ostream>
class Examen {

private:

	char* data;
	double nota;
	char* nume;
	int bonus;

public:

	Examen();//constructor implicit
	Examen(char*, char*, double,int);//constructor de initializare
	Examen(const Examen&);//constructor de copiere
	~Examen();//destructor

	//Getters

	char* get_nume();
	char* get_data();
	double get_nota();
	int get_bonus();

	//Setters

	void set_nume(char*);
	void set_data(char*);
	void set_nota(double);
	void set_bonus(int);

	//Overwrite operators '=' , "==" and "<<"

	Examen& operator =(const Examen&);
	bool operator==(const Examen&);
	friend std::ostream& operator << (std::ostream&, const Examen&);
};