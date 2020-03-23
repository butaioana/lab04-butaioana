#include <iostream>
#include "functions.h"
#include "ex3_dinamic.h"
#include "ex11_dinamic.h"
void menu()
{
    std::cout << std::endl;
    std::cout << "Menu " << std::endl;
    std::cout << "0.Exit" << std::endl;
    std::cout << "1.Citire " << std::endl;
    std::cout << "2.Afisare " << std::endl;
    std::cout << "3.Secventa doar cu numere prime " << std::endl;
    std::cout << "11.Cea mai lunga secventa sub forma de munte" << std::endl;
    std::cout << std::endl;
}
int main()
{
    int op = 1, * array = new int[0], n = 0;

    menu();
    while (op)
    {
        std::cout << "Optiunea este: ";
        std::cin >> op;
        if (op == 1)
            array = citire_vector(n);
        if (op == 2)
            print_array(array, 1, n);
        if (op == 3)
            array = ex3_dinamic(array, n);
        if (op == 11)
            ex11_dinamic(array, n);
        if (op != 0)
            menu();
        if (op == 0)
        {
            std::cout << "Paaaaa";
            delete[] array;
            break;
        }
    }
}

