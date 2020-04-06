#include "UI.h"
#include "Test.h"
#include "Functions.h"
#include <iostream>
#include <string>
#include <ctime>

using namespace std;

char* allocate_memory()
{
    char* name = new char[0];
    string string_name;

    cin >> string_name;
    name = new char[string_name.size() + 1];
    strcpy_s(name, 1 + string_name.size(), string_name.c_str());

    return name;
}

int macarena() {

    return rand() % 5;
}

void UI::add() {

    char* date = new char[0], * name = new char[0];
    int nota;
    do {
        cout << "nume: ";
        name = allocate_memory();

        int ok = 1;
        while (ok == 1) {
            cout << "data: ";
            date = allocate_memory();
            if (except_date(date))
                ok = 0;
            else
                cout << "(._.)( ZZ.LL.AAAA )(._.)Data incorecta! ";
        }
        cout << "Nota: ";
        do {
            cin >> nota;
            if (!(nota >= 0 and nota <= 10))
                cout << "(X_X) Nota trebuie sa fie cuprinsa intre 1 si 10: ";
        } while (!(nota >= 0 and nota <= 10));
        if (macarena() == 0)

            cout << "STAI ACASA! " << endl;

    } while (macarena() == 0);
    this->service.insert_service(name, date, nota);
}

void UI::print() {

    int n = this->service.get_len();
    Examen* array = this->service.get_all();
    for (int i = 0; i < n; i++)
        cout << array[i] << endl;
}

void UI::all_exams_by_higher_note() {

    double note;
    cout << "Dati o nota: ";
    cin >> note;
    int n;
    Examen* array = this->service.all_exams_by_higher_note(note,n);

    for (int i = 0; i < n; i++)
        cout << array[i] << endl;
}

void UI::bonus() {
    char* name = new char[0];
    cout << "nume: ";
    name = allocate_memory();
    this->service.bonus(name);
}

void UI::update_examen() {

    char* date = new char[0], * name = new char[0];
    int nota;

    cout << " nume: ";
    name = allocate_memory();

    int ok = 1;
    while (ok == 1) {
        cout << "data: ";
        date = allocate_memory();
        if (except_date(date))
            ok = 0;
        else
            cout << "(._.)( ZZ.LL.AAAA )(._.)Data incorecta! ";
    }
    cout << endl;
    cout << "Nota: ";
    do {
        cin >> nota;
        if (!(nota >= 1 and nota <= 10))
            cout << "(X_X) Nota trebuie sa fie cuprinsa intre 1 si 10: ";
    } while (!(nota >= 0 and nota <= 10));
    this->service.update_examen(name, date, nota);
}

void UI::delete_examen()
{
    cout << "sterge un examen dupa nume: ";
    char* name = allocate_memory();
    this->service.delete_examen(name);
}

void UI::run() {

    string opt;
    bool ok = true;
    Examen* undo_array = new Examen[0];

    do {
        cout << "(^_^) " << endl;
        cout << "Alege o obtiune" << endl;
        menu();
        cout << "Obtiunea ta este" << endl;
        cin >> opt;

        if (opt.size() == 1)
        {
            if (opt[0] == '1') {
                this->add();
            }
            else
                if (opt[0] == '2') {
                    this->print();
                }
                else
                    if (opt[0] == '3') {
                        this->update_examen();
                    }
                    else
                        if (opt[0] == '4') {
                            this->delete_examen();
                        }
                        else
                            if (opt[0] == '5')
                            {
                                this->service.undo_examen();
                            }
                            else
                                if (opt[0] == '6')
                                {
                                    this->all_exams_by_higher_note();
                                }
                                else
                                    if (opt[0] == '7')
                                    {
                                        this->bonus();
                                    }
                                    else
                                        if (opt[0] == 'x') {
                                            ok = false;
                                        }
                                        else
                                            cout << endl << "(X_X)" << endl;
        }
        else
            cout << endl << "(X_X)" << endl;
    } while (ok);
}