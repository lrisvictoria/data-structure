#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

void PrintArray(int* a, int n);
void InsertSort(int* a, int n);
void ShellSort(int* a, int n);
void HeapSort(int* a, int n);
void SelectSort(int* a, int n);
void BubbleSort(int* a, int n);
void QuickSort(int* a, int begin, int end);
void QuickSortNorR(int* a, int begin, int end);
void MergeSort(int* a, int n);
void MergeSortNonR(int* a, int n);
void QuickSortT(int* a, int begin, int end);
void CountSort(int* a, int n);