#include "Functions.h"
#include <iostream>
void menu() {

    std::cout << "x.Exit" << std::endl;
    std::cout << "1.Add" << std::endl;
    std::cout << "2.Print" << std::endl;
    std::cout << "3.Update" << std::endl;
    std::cout << "4.Delete" << std::endl;
    std::cout << "5.Undo" << std::endl;
    std::cout << "6.Afisare examene mai mari decat o nota" << std::endl;
    std::cout << "7. Adauga un bonus de un punct pentru examenele sustinute" << std::endl;

}

bool except_date(char* string) {

    int list_of_days[13] = { 0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
    int nrok = 0, nrzile, nrluni, i;
    int nran = 0;

    if ('9' >= string[0] and string[0] >= '0' and '9' >= string[1] and string[1] >= '0' and string[2] == '.' and string[5] == '.') {
        nrzile = (string[0] - '0') * 10 + (string[1] - '0');
        nrluni = (string[3] - '0') * 10 + (string[4] - '0');
    }
    else
        return false;

    i = 6;

    while (i < strlen(string)) {
        if (string[i] == '.')
            return false;
        nran = nran * 10 + (string[i] - '0');
        i = i + 1;
    }

    if (0 < nrluni and nrluni <= 12 and list_of_days[nrluni] >= nrzile and nrzile > 0 and (nran % 4 == 0 or nran % 400 == 0))
        nrok = nrok + 1;
    else
        if (0 < nrluni and nrluni <= 12 and list_of_days[nrluni] > nrzile and nrzile > 0)
            nrok = nrok + 1;
    if (nrok == 1)
        return true;
    else
        return false;
}

void convert_char_to_int(char* date1, int& day, int& month, int& year) {
    int i = 0;
    while (date1[i] != '.') {

        day = day * 10 + (date1[i] - '0');
        i++;
    }
    i++;
    while (date1[i] != '.') {

        month = month * 10 + (date1[i] - '0');
        i++;
    }
    i++;
    while (date1[i] != '.' and i < strlen(date1)) {

        year = year * 10 + (date1[i] - '0');
        i++;
    }

}

bool verify_dates(char* date1, char* date2) {

    int day1 = 0, month1 = 0, year1 = 0, day2 = 0, month2 = 0, year2 = 0;
    convert_char_to_int(date1, day1, month1, year1);
    convert_char_to_int(date2, day2, month2, year2);
    if (year1 > year2)
        return true;
    else {
        if (year1 == year2) {
            if (month1 > month2) {
                return true;
            }
            else {
                if (month1 == month2) {
                    if (day1 > day2) {
                        return true;
                    }
                    else
                        return false;
                }
                else
                    return false;
            }

        }
        else
            return false;
    }
}

bool except_note(int& nota)
{

    if (0 < nota < 11)
        return true;
    else
        return false;

}