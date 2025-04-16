//Author: Lucius Karki
//Class : CSI 370-201
//Assignment : Final Project
//Date Assigned : Tuesday, December 10, 2024
//Due Date : 23:59 GMT, Tuesday, December 10, 2024
//Description : Uses six sorting algorithms and tests their speed. Outputs
// time taken to a text file. Three have a C++ version and an assembly version
//Certification of Authenticity :
//I certify that this is entirely my own work, except where I have given
//fully - documented references to the work of others.I understand the definition and
//consequences of plagiarism and acknowledge that the assessor of this assignment
//may, for the purpose of assessing this assignment :
//	-Reproduce this assignment and provide a copy to another member of academic staff;
//and /or
//-Communicate a copy of this assignment to a plagiarism checking service(which may
//	then retain a copy of this assignment on its database for the purpose of future
//	plagiarism checking)

#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include <ctime> 
#include <iomanip>

using namespace std;

const string RANDOM_DATA_FILE = "RandomNumbers.txt";
const string ASCENDING_DATA_FILE= "AscendingNumbers.txt";
const string DESCENDING_DATA_FILE = "DescendingNumbers.txt";

/*     Pre:  an array of unspecified datatype, size of array
*     Post:  List is sorted in ascending order
*  Purpose:  To sort an array with bubble sort
*********************************************************/
template <typename T>void bubbleSort(T list[], int size) {
	bool swapped = true;
	int i;
	while (swapped == true) {
		swapped = false;
		for (i = 0; i < size-1; i++) {
			if (list[i + 1] < list[i]) {
				swap(list[i + 1], list[i]);
				swapped = true;
			}
		}
	}
}

/*     Pre:  an array of unspecified datatype, size of array
*     Post:  List is sorted in ascending order
*  Purpose:  To sort an array with bubble sort
*********************************************************/
template <typename T>void bubbleSortAssembly(T list[], int size) {
	int large = size;
	__asm {
		mov ecx, 0				; i = 1
		
		outerloop :
			inc ecx				; i ++
			cmp ecx, large		; checks if everything has been sorted, jumps if so
			je finished
			mov esi, list		; resets esi to beginning of the list
			mov edx, ecx		; setting up inner counter

		innerloop :
			mov eax, [esi]		; value at i
			mov ebx, [esi + 4]	; value at i + 1
			cmp ebx, eax		; i <= i + 1
			jge noswap			; jumps if no swap is to be made

			mov[esi], ebx		; swaps
			mov[esi + 4], eax
			add esi, 4			; goes to next spot in memory
			inc edx				; j++
			cmp edx, large		; checks if the loop is over repeats if not
			jl innerloop
			jmp outerloop		; ends loop if j > large

		noswap:
			inc edx				; i++
			add esi, 4			; gets next thing in array
			cmp edx, large		; checks if the end of array has been reached
			jl innerloop		; loops to inner
			jmp outerloop		; ends innner loop and goes back to outer

		finished:

	};
}

/*     Pre:  an array of unspecified datatype, size of array
*     Post:  List is sorted in ascending order
*  Purpose:  To sort an array with insertion sort
*********************************************************/
template <typename T>void insertionSort(T list[], int size) {
	int i, j;
	T value;
	for (i = 1; i < size; i++) {
		value = list[i];
		j = i - 1;
		while (j >= 0 && list[j] > value) {
			list[j + 1] = list[j];
			j = j - 1;
		}
		list[j + 1] = value;
	}
}

/*     Pre:  an array of unspecified datatype, size of array
*     Post:  List is sorted in ascending order
*  Purpose:  To sort an array with insertion sort in assembly
*********************************************************/
template <typename T>void insertionSortAssembly(T list[], int size) {
	int count = size;
	int tmp = 0;
	__asm {
		xor ecx, ecx
		mov ecx, 1						; initialize outer loop counter, i = 1 
		mov esi, list					; put array pointer in esi

		outerloop :
			cmp ecx, count				; checks if every value has been checked
			jge finished				; jumps if everything has finished

			mov edx						, ecx; initializes inner loop counter, j = i
			dec edx						; decrements by 1 to set it to one below j = i-1

		innerloop :
			cmp edx, -1					; makes sure inner loop counter doesn't go past 0
			jle noinsert				; jumps if it is past 0

			mov edi, edx				; j
			inc edi						; j + 1

			mov ebx, [esi + edx * 4]	; gets values
			mov eax, [esi + edi * 4]

			cmp eax, ebx				; compares values, if j > j + 1 it swaps
			jl doinsert

			cmp eax, ebx				; compares values if j <= j+1 it doesnt swap
			jge noinsert

		doinsert :
			mov tmp, eax				; swaps
			mov[esi + edx * 4], eax
			mov[esi + (edx + 4) * 4], ebx

			cmp edx, 0					; checks if edx is 0, if it is then the sort is over
			je noinsert

			dec edx						; j--
			jmp innerloop				; keeps going in the inner loop

		noinsert:
			inc ecx						; i++
			jmp outerloop				; starts outer loop again and moves to the next in the array
		finished:
		xor ecx, ecx
	};
}

/*     Pre:  an array of unspecified datatype, upperbound, lowerbound, and middle of what is passed in from mergesort
*     Post:  List is sorted in ascending order
*  Purpose:  To do the work of the mergesort algorithm
*********************************************************/
template <typename T> void merge(T list[], int lowerBound, int mid, int upperBound) {
	int size1 = mid - lowerBound + 1;
	int size2 = upperBound - mid;
	int i, j, k;

	T* tmp1 = new T[size1];
	T* tmp2 = new T[size2];

	for (i = 0; i < size1; i++) {
		tmp1[i] = list[lowerBound + i];
	}
	for (j = 0; j < size2; j++) {
		tmp2[j] = list[mid + j+1];
	}

	i = 0;
	j = i;
	
	for (k = lowerBound; (k < upperBound) && (i < size1) && (j < size2); k++) {
		if (tmp1[i] <= tmp2[j]) {
			list[k] = tmp1[i];
			i = i + 1;
		}
		else {
			list[k] = tmp2[j];
			j = j + 1;
		}
	}
	while (i < size1) {
		list[k] = tmp1[i];
		i = i + 1;
		k = k + 1;
	}
	while (j < size2) {
		list[k] = tmp2[j];
		j = j + 1;
		k = k + 1;
	}
	delete[] tmp1;
	delete[] tmp2;
}

/*     Pre:  an array of unspecified datatype, lowerbound of the array, upperbound of the array
*     Post:  List is sorted in ascending order
*  Purpose:  To sort an array with merge sort
*********************************************************/
template <typename T> void mergeSort(T list[], int lowerBound, int upperBound) {
	if (lowerBound < upperBound) {
		int mid;
		mid = ((lowerBound + upperBound) / 2);
		mergeSort(list, lowerBound, mid);
		mergeSort(list, mid + 1, upperBound);
		merge(list, lowerBound, mid, upperBound);
	}
}

/*     Pre:  an array of unspecified datatype, upper bound of the array, and lower bound of the array
*     Post:  List is sorted in ascending order
*  Purpose:  To sort an array with quicksort
*********************************************************/
//template <typename T> void quickSort(T list[], int lowerBound, int upperBound) {
//	if (lowerBound<upperBound) {
//		int i = lowerBound;
//		int j = upperBound;
//
//		T pivot = list[(lowerBound + upperBound) / 2];
//
//		while (i <= j) {
//			while (list[i] < pivot) {
//				i++;
//			}
//			while (list[j] > pivot) {
//				j--;
//			}
//			if (i <= j) {
//				swap(list[i], list[j]);
//				i = i++;
//				j = j--;
//			}
//			if (lowerBound < j) {
//				quickSort(list, lowerBound, j);
//			}
//			if (i < upperBound) {
//				quickSort(list, i, upperBound);
//			}
//		}
//	}
//}
template <typename T>
void quickSort(T list[], int lowerBound, int upperBound) {
	if (lowerBound < upperBound) {
		int i = lowerBound;
		int j = upperBound;
		T pivot = list[(lowerBound + upperBound) / 2];

		while (i <= j) {
			while (list[i] < pivot) {
				i++;
			}
			while (list[j] > pivot) {
				j--;
			}
			if (i <= j) {
				swap(list[i], list[j]);
				i++;
				j--;
			}
		}

		// Recursively sort the two subarrays
		quickSort(list, lowerBound, j);
		quickSort(list, i, upperBound);
	}
}

void runBubbleSort();
void runBubbleSortAssembly();
void runInsertionSort();
void runInsertionSortAssembly();
void runMergeSort();
void runQuickSort();
void runSelectionSort();
void runSelectionSortAssembly();
void runShellSort();


/*     Pre:  an array of unspecified datatype, size of array
*     Post:  List is sorted in ascending order
*  Purpose:  To sort an array with selection sort
*********************************************************/
template <typename T>void selectionSort(T list[], int size) {
	int i, j, minIndex;
	for (i = 0; i < size-1; i++) {
		minIndex = i;
		for (j = i + 1; j < size; j++) {
			if (list[j] < list[minIndex]) {
				minIndex = j;
			}
		}
		if (minIndex != i) {
			swap(list[i], list[minIndex]);
		}
	}
}

/*     Pre:  an array of unspecified datatype, size of array
*     Post:  List is sorted in ascending order
*  Purpose:  To sort an array with selection sort in assembly
*********************************************************/
template <typename T>void selectionSortAssembly(T list[], int size) {
	int count = size;
	int tmp = 0;
	__asm {
		xor ecx, ecx
		mov ecx, 0						; i = 0
		mov esi, list					; puts pointer into esi

		outerloop :
			cmp ecx, count				; checks if list has been sorted
			jge finished

			mov edx, ecx				; setting counter, i = j

			mov eax, edx				; place for the inital low value
			mov ebx, [esi + edx * 4]	; data for the initial low value

		innerloop:
			inc edx						; j++
			cmp edx, count				; checks to make sure the loop isnt over
			jge swapitem				; if it is then swap is called

			mov edi, [esi + edx * 4]	; puts value at j into esi
			cmp ebx, edi				; compares low value to value at j
			jg newMin					; jumps if a lower value is found

			jmp innerloop				; starts the loop over again

		swapitem :
			mov edi, [esi + ecx * 4]	; swaps the item
			mov[esi + ecx * 4], ebx
			mov[esi + eax * 4], edi

			inc ecx						; i++
			jmp outerloop				; starts loop again

		newMin:
			mov eax, edx				; changes data of the low value
			mov ebx, [esi + edx * 4]
			jmp innerloop

		finished :
			xor ecx, ecx
	};
}


/*     Pre:  an array of unspecified datatype, size of array
*     Post:  List is sorted in ascending order
*  Purpose:  To sort an array with shell sort
*********************************************************/
template <typename T> void shellSort(T list[], int size) {
	int gap = size / 2;
	int i;
	while (gap > 0) {
		for (i = 0; i < size - gap; i++) {
			if (list[i] > list[i + gap]) {
				swap(list[i], list[(i + gap)]);
			}
		}
		gap /= 2;
	}
	bubbleSort(list, size);
}

/*     Pre:  memory location of two variables of unpecified datatype
*     Post:  Two swapped items
*  Purpose:  To swap the two variables around
*********************************************************/
template <typename T>void swap(T &lhs, T &rhs) {
	T temp;
	temp = lhs;
	lhs = rhs;
	rhs = temp;
}