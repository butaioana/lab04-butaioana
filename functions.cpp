#include "functions.h"
#include <iostream>
int* citire_vector(int& n)
{
	int i, * array = new int[0];
	std::cout << "Lungimea sirului: ";
	std::cin >> n;
	array = new int[n];
	std::cout << "Vectorul este: ";
	for (i = 1; i <= n; i++)
		std::cin >> array[i];
	return array;
}
void print_array(int* array, int start, int n)
{
	int i;
	std::cout << "Vectorul este: ";
	for (i = start; i <= n; i++)
		std::cout << array[i] << ' ';
	std::cout << std::endl;
}