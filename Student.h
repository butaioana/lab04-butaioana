#pragma once
#include<ostream>
class Student
{
private:
	char* nume;
	char* date;
	int nota;
public:
	Student();
	Student(char*, char*, int);
	Student(const Student&);
	~Student();
	char* get_nume();
	char* get_date();
	int get_nota();
	
	void set_nume(char* new_nume);
	void set_date(char* new_date);
	void set_nota(int new_nota);
	// Suprascrierea operatorilor '=', "==" și "<<"Student& operator = (const Student& );
	Student& operator =(const Student&);
	bool operator == (const Student&);
	friend std::ostream& operator << (std::ostream&, const Student&);

};

