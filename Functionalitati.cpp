#include"Functionalitati.h"
#include<iostream>
void meniu() {
	std::cout << "1.Adaugare" << std::endl;
	std::cout << "2.Afisare" << std::endl;
	std::cout << "x.Iesire" << std::endl;
}
bool except_date(char* string) {

	int lista_zile[13]= { 0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	int nr_ok = 0, nr_zile, nr_luni, i;
	int nr_an = 0;

	if ('9' >= string[0] && string[0] >= '0' && '9' >= string[1] && string[1] >= '0' && string[2] == '.' && string[5] == '.')
	{
		nr_zile = (string[0] - '0') * 10 + (string[1] - '0');
		nr_luni = (string[3] - '0') * 10 + (string[4] - '0');
	}
	else
		return false;
	i = 6;
	while (i < strlen(string)) {
		if (string[i] == '.')
			return false;
		nr_an = nr_an * 10 + (string[i] - '0');
		i = i + 1;
	}
	if (0 < nr_luni && nr_luni <= 12 && lista_zile[nr_luni] >= nr_luni && nr_zile > 0 && (nr_an % 4 == 0 && nr_an % 400 == 0))
		nr_ok = nr_ok + 1;
	else
		if (0 < nr_luni && nr_luni <= 12 && lista_zile[nr_luni] > nr_luni && nr_luni > 0)
			nr_ok = nr_ok + 1;
	if (nr_ok == 1)
		return true;
	else
		return false;
}

bool except_note(int& nota)
{
	
	if (0 < nota < 11)
		return true;
	else
		return false;
	
}