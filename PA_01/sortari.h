#pragma once

void swapArray(int &a, int &b);
void printArray(int *a, int n);

void merge(int *arr, int s, int mij, int d);
void mergeSort(int *arr, int s, int d);

void quickSort1(int *arr, int low, int high);
void quickSort2(int *arr, int low, int high);
int partition(int *arr, int low, int high);

void radixSort(int *arr, int n);
void queueRadix(int *arr, int n, int pos);

void insertionSort(int arr[], int n);

void shellSort(int arr[], int n);

unsigned long long int mulBigNo(unsigned long long int x, unsigned long long y);
unsigned long long int mulBigNoOptimized(unsigned long long int x, unsigned long long y);

int max(int a, int b);
void swap(int &a, int &b);
int getMaxLength(int arr[], int n);
int numberOfDigit(int no);
