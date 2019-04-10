#include <iostream>
#include "sortari.h"

int main() {
	int n = 20;
	int *a = new int[n];
	for (int i = 0; i < n; ++i) {
		int no = rand() % 100;
		a[i] = no;
	}
	printArray(a, n);
	radixSort(a, n);
	printArray(a, n);
}