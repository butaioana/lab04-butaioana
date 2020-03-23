#include <iostream>
#include "functions.h"


void ex11_dinamic(int* x, int& n)
{
	int s = 0, k = -1, ok1 = 1;
	int i = 1, ok = 0,ok2=0,maxx=0,ii=0,jj=0,aux;
	int* y = new int[100];

	while (i < n) {
		ok1 = 1;
		aux = i;
		while (x[i] <= x[i+1] and i+1<=n) {

			i++;
			ok1 += 1;
		}
		ok2 = 0;
		while (x[i] >= x[i + 1] and i + 1 <= n) {

			i++;
			ok2 += 1;
		}
		if (maxx < (ok2 + ok1)) {
			maxx =  (ok2 + ok1);
			ii = aux;
			jj = i;
		}
		//i++;
	}
	print_array(x, ii, jj);
	//return y[ok1];
}
