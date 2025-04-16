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
#include "sortingFunctions.h"

int main() {
	
	//runBubbleSort();
	//runInsertionSort();
	/*
	runSelectionSort();
	runShellSort();
	runMergeSort();
	runQuickSort();
	*/
	runBubbleSortAssembly();
	runInsertionSortAssembly();
	runSelectionSortAssembly();
	return 0;
}