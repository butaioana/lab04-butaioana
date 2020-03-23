#include "functions.h"
#include <iostream>

bool prim(int n)
{
    if (n < 2)
        return false;
    if (n % 2 == 0 && n != 2)
        return 0;
    for (int i = 3; i * i <= n; i = i + 2)
        if (n % i == 0)
            return false;
    return true;

}
int* ex3_dinamic(int* vector, int& n)
{
    int inceput = 0, sf = 0, max = 0, start = 0, end = 0;
    for (int i = 1; i <= n; i++)
    {
        if (prim(vector[i]))
        {
            inceput = i;
            while (prim(vector[i]))
            {
                sf = i;
                i++;
            }
        }
        if (sf - inceput >= max)
        {
            max = sf - inceput;
            start = inceput;
            end = sf;
        }
    }
    if (start == 0 && end == 0)
    {
        int* newvector = new int[0];
        return newvector;
    }
    else
    {
        int* newvector, k = 0;
        n = end - start + 1;
        newvector = new int[end - start + 1];
        for (int i = start; i <= end; i++)
            newvector[++k] = vector[i];
        return newvector;
    }
}