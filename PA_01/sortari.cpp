#include <iostream>
#include <queue>
#include "sortari.h"

void swapArray(int &a, int &b) {
	int temp = a;
	a = b;
	b = temp;
}

void printArray(int *a, int n) {
	for (int i = 0; i < n; ++i) {
		std::cout << a[i] << " ";
	}
	std::cout << std::endl;
}

void merge(int *arr, int s, int mij, int d) {
	int *temp = new int[d];
	int i = s; 
	int j = mij + 1;
	int k = 0;
	while (i <= mij and j <= d) {
		if (arr[i] < arr[j]) {
			temp[k++] = arr[i++];
		} else {
			temp[k++] = arr[j++];
		}
	}
	while (i <= mij) {
		temp[k++] = arr[i++];
	}
	while (j <= d) {
		temp[k++] = arr[j++];
	}

	for (int i = 0; i < k; ++i) {
		arr[s+i] = temp[i];
	}

}

void mergeSort(int * arr, int s, int d) {
	if (s < d) {
		int m = (s + d) / 2;
		mergeSort(arr, s, m);
		mergeSort(arr, m + 1, d);
		merge(arr, s, m, d);
	}
}

void quickSort1(int * arr, int low, int high) {
	if (low < high) {
		int pi = partition(arr, low, high);
		quickSort1(arr, low, pi - 1);
		quickSort1(arr, pi + 1, high);
	}
}

void quickSort2(int * arr, int low, int high) {
	while (low < high) {
		int pi = partition(arr, low, high);
		if (pi - low > high - pi) {
			quickSort2(arr, pi + 1, high);
			high = pi - 1;
		} else {
			quickSort2(arr, low, pi - 1);
			low = pi + 1;
		}
	}
}

int partition(int * arr, int low, int high) {
	int pi = arr[low];
	int i = low + 1;
	int j = high;
	while (i <= j) {
		if (arr[i] <= pi)
			++i;
		if (arr[j] >= pi)
			--j;
		if (i < j) {
			if (arr[i] > pi and arr[j] < pi) {
				swap(arr[i], arr[j]);
				++i; --j;
			}
		}
	}
	swap(arr[low], arr[i - 1]);
	return (i-1);
}

void radixSort(int * arr, int n) {
	int no = getMaxLength(arr, n);
	int pos = 1;
	while (no) {
		queueRadix(arr, n, pos);
		no /= 10;
		pos *= 10;
	}
}

void queueRadix(int * arr, int n, int pos) {
	std::queue<int> coada[10];

	for (int i = 0; i < n; ++i) {
		coada[(arr[i] / pos) % 10].push(arr[i]);
	}

	int k = 0;
	int i = 0;
	while (k < 10) {
		if (coada[k].empty()) {
			k++;
			continue;
		}
		arr[i++] = coada[k].front();
		coada[k].pop();
	}
}

void insertionSort(int arr[], int n) {

	for (int i = 1; i < n; ++i) {
		int key = arr[i];
		int j = i-1;

		while (j >= 0 and arr[j] > key) {
			arr[j + 1] = arr[j];
			--j;
		}
		arr[j + 1] = key;
	}
}

void shellSort(int arr[], int n) {
	int mid = n / 2;
	while (mid > 0) {
		for (int j = mid; j < n; j++) {
			for (int i = j - mid; i >= 0; i -= mid) {
				if (arr[i] > arr[i + mid]) {
					swap(arr[i], arr[i + mid]);
				}
			}
		}
		mid /= 2;
	}
}

unsigned long long int mulBigNo(unsigned long long int x, unsigned long long y) {
	if (x < 10 and y < 10) {
		return x * y;
	}
	unsigned long long int k, k1=1, k2=1;
	if (x > y) {
		k = numberOfDigit(x);
	} else {
		k = numberOfDigit(y);
	}
	for (int i = 0; i < k; ++i) {
		k2 *= 10;
	}
	for (int i = 0; i < k / 2; ++i) {
		k1 *= 10;
	}
	unsigned long long int xs = x / k1;
	unsigned long long int xd = x % k1;
	unsigned long long int ys = x / k1;
	unsigned long long int yd = x % k1;
	return mulBigNo(xs, ys) * k2 + (mulBigNo(xs, yd) + mulBigNo(xd, ys))*k1 + mulBigNo(xd, yd);
}

unsigned long long int mulBigNoOptimized(unsigned long long int x, unsigned long long y) {
	unsigned long long int k, k1 = 1, k2 = 1;
	if (x < 10 and y < 10) {
		return x * y;
	}

	if (x > y) {
		k = numberOfDigit(x);
	} else {
		k = numberOfDigit(y);
	}

	for (int i = 0; i < k; ++i) {
		k2 *= 10;
	}
	for (int i = 0; i < k / 2; ++i) {
		k1 *= 10;
	}

	unsigned long long int xs = x / k1;
	unsigned long long int xd = x % k1;
	unsigned long long int ys = x / k1;
	unsigned long long int yd = x % k1;
	unsigned long long int temp1 = mulBigNo(xs, ys);
	unsigned long long int temp2 = mulBigNo(xd, yd);
	return temp1 * k2 + k1 * (mulBigNo(xs - xd, ys - yd) + temp1 +temp2) + temp2;
}

int max(int a, int b) {
	return a > b ? a : b;
}

void swap(int &a, int &b) {
	int temp = a;
	a = b;
	b = temp;
}

int getMaxLength(int arr[], int n) {
	int mx = arr[0];
	for (int i = 1; i < n; i++)
		if (arr[i] > mx)
			mx = arr[i];
	return mx;
}

int numberOfDigit(int no) {
	int n = 0;
	while (no) {
		n++;
		no /= 10;
	}
	return n;
}
