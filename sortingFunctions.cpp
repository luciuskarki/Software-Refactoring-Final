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
#include "timerSystem.h"
/*     Pre:  None
*     Post:  none
*  Purpose:  To run bubblesort
*********************************************************/
void runBubbleSort()
{
	TimerSystem timer;
	std::cout << std::fixed << std::setprecision(8);
	ifstream finRand;
	ifstream finAscending;
	ifstream finDescending;

	int size1 = 100;
	int size2 = 10000;
	int size3 = 1000000;
	int i;

	int* array100;
	int* array10K;
	int* array1M;

	array100 = new int[size1];
	array10K = new int[size2];
	array1M = new int[size3];

	ofstream fout;
	fout.open("data.txt", ios::app);
	fout << fixed << setprecision(8);
	//The whole testing for 100 size array
	for (int j = 0; j < 3; j++) {
		finRand.open(RANDOM_DATA_FILE);
		if (finRand.fail()) {
			fout << "failed to open " + RANDOM_DATA_FILE;
			exit(1);
		}

		finAscending.open(ASCENDING_DATA_FILE);
		if (finAscending.fail()) {
			fout << "failed to open " + ASCENDING_DATA_FILE;
			exit(2);
		}

		finDescending.open(DESCENDING_DATA_FILE);
		if (finDescending.fail()) {
			fout << "failed to open " + DESCENDING_DATA_FILE;
			exit(3);
		}

		for (i = 0; i < size1; i++) {//get random data for 100
			finRand >> array100[i];
		}

		timer.startClock();
		bubbleSort(array100, size1);
		fout << timer.getTime() << ", ";

		for (i = 0; i < size1; i++) {//get ascending data for 100
			finAscending >> array100[i];
		}

		timer.startClock();
		bubbleSort(array100, size1);
		fout << timer.getTime() << ", ";

		for (i = 0; i < size1; i++) {//get descending data for 100
			finDescending >> array100[i];
		}

		timer.startClock();
		bubbleSort(array100, size1);
		fout << timer.getTime() << endl;

		finRand.close();
		finAscending.close();
		finDescending.close();
		fout << endl;
	}

	//The whole testing for 10k size array
	for (int j = 0; j < 3; j++) {
		finRand.open(RANDOM_DATA_FILE);
		if (finRand.fail()) {
			fout << "failed to open " + RANDOM_DATA_FILE;
			exit(1);
		}

		finAscending.open(ASCENDING_DATA_FILE);
		if (finAscending.fail()) {
			fout << "failed to open " + ASCENDING_DATA_FILE;
			exit(2);
		}

		finDescending.open(DESCENDING_DATA_FILE);
		if (finDescending.fail()) {
			fout << "failed to open " + DESCENDING_DATA_FILE;
			exit(3);
		}

		for (i = 0; i < size2; i++) {//get random data for 10k
			finRand >> array10K[i];
		}

		timer.startClock();
		bubbleSort(array10K, size2);
		fout << timer.getTime() << ", ";

		for (i = 0; i < size2; i++) {//get ascending data for 10k
			finAscending >> array10K[i];
		}

		timer.startClock();
		bubbleSort(array10K, size2);
		fout << timer.getTime() << ", ";

		for (i = 0; i < size2; i++) {//get descending data for 10k
			finDescending >> array10K[i];
		}

		timer.startClock();
		bubbleSort(array10K, size2);
		fout << timer.getTime() << endl;

		finRand.close();
		finAscending.close();
		finDescending.close();
		fout << endl;
	}

	//The whole testing for 1M size array
	for (int j = 0; j < 3; j++) {
		finRand.open(RANDOM_DATA_FILE);
		if (finRand.fail()) {
			fout << "failed to open " + RANDOM_DATA_FILE;
			exit(1);
		}

		finAscending.open(ASCENDING_DATA_FILE);
		if (finAscending.fail()) {
			fout << "failed to open " + ASCENDING_DATA_FILE;
			exit(2);
		}

		finDescending.open(DESCENDING_DATA_FILE);
		if (finDescending.fail()) {
			fout << "failed to open " + DESCENDING_DATA_FILE;
			exit(3);
		}

		for (i = 0; i < size3; i++) {//get random data for 1M
			finRand >> array1M[i];
		}

		timer.startClock();
		bubbleSort(array1M, size3);
		fout << timer.getTime() << ", ";

		for (i = 0; i < size3; i++) {//get ascending data for 1M
			finAscending >> array1M[i];
		}

		timer.startClock();
		bubbleSort(array1M, size3);
		fout << timer.getTime() << ", ";

		for (i = 0; i < size3; i++) {//get descending data for 1M
			finDescending >> array1M[i];
		}

		timer.startClock();
		bubbleSort(array1M, size3);
		fout  << timer.getTime() << endl;

		finRand.close();
		finAscending.close();
		finDescending.close();
		fout << endl;
	}

	delete[] array100;
	delete[] array10K;
	delete[] array1M;
}

/*     Pre:  None
*     Post:  none
*  Purpose:  To run bubblesort (assembly)
*********************************************************/
void runBubbleSortAssembly() {
	TimerSystem timer;
	std::cout << std::fixed << std::setprecision(8);
	ifstream finRand;
	ifstream finAscending;
	ifstream finDescending;

	int size1 = 100;
	int size2 = 10000;
	int size3 = 1000000;
	int i;

	int* array100;
	int* array10K;
	int* array1M;

	array100 = new int[size1];
	array10K = new int[size2];
	array1M = new int[size3];

	ofstream fout;
	fout.open("data.txt", ios::app);
	fout << fixed << setprecision(8);
	fout << "Assembly bubble" << endl;
	//The whole testing for 100 size array
	for (int j = 0; j < 3; j++) {
		finRand.open(RANDOM_DATA_FILE);
		if (finRand.fail()) {
			fout << "failed to open " + RANDOM_DATA_FILE;
			exit(1);
		}

		finAscending.open(ASCENDING_DATA_FILE);
		if (finAscending.fail()) {
			fout << "failed to open " + ASCENDING_DATA_FILE;
			exit(2);
		}

		finDescending.open(DESCENDING_DATA_FILE);
		if (finDescending.fail()) {
			fout << "failed to open " + DESCENDING_DATA_FILE;
			exit(3);
		}

		

		for (i = 0; i < size1; i++) {//get random data for 100
			finRand >> array100[i];
		}

		timer.startClock();
		bubbleSortAssembly(array100, size1);
		fout << timer.getTime() << ", ";

		if (j == 0) {
			for (int i = 0; i < size1; i++) {
				cout << array100[i] << " ";
			}
		}

		for (i = 0; i < size1; i++) {//get ascending data for 100
			finAscending >> array100[i];
		}

		timer.startClock();
		bubbleSortAssembly(array100, size1);
		fout << timer.getTime() << ", ";



		for (i = 0; i < size1; i++) {//get descending data for 100
			finDescending >> array100[i];
		}

		timer.startClock();
		bubbleSortAssembly(array100, size1);
		fout << timer.getTime() << endl;
		
		finRand.close();
		finAscending.close();
		finDescending.close();
	}
	
	//The whole testing for 10k size array
	for (int j = 0; j < 3; j++) {
		finRand.open(RANDOM_DATA_FILE);
		if (finRand.fail()) {
			fout << "failed to open " + RANDOM_DATA_FILE;
			exit(1);
		}

		finAscending.open(ASCENDING_DATA_FILE);
		if (finAscending.fail()) {
			fout << "failed to open " + ASCENDING_DATA_FILE;
			exit(2);
		}

		finDescending.open(DESCENDING_DATA_FILE);
		if (finDescending.fail()) {
			fout << "failed to open " + DESCENDING_DATA_FILE;
			exit(3);
		}

		for (i = 0; i < size2; i++) {//get random data for 10k
			finRand >> array10K[i];
		}

		timer.startClock();
		bubbleSortAssembly(array10K, size2);
		fout << timer.getTime() << ", ";

		for (i = 0; i < size2; i++) {//get ascending data for 10k
			finAscending >> array10K[i];
		}

		timer.startClock();
		bubbleSortAssembly(array10K, size2);
		fout << timer.getTime() << ", ";

		for (i = 0; i < size2; i++) {//get descending data for 10k
			finDescending >> array10K[i];
		}

		timer.startClock();
		bubbleSortAssembly(array10K, size2);
		fout << timer.getTime() << endl;

		finRand.close();
		finAscending.close();
		finDescending.close();
	}

	//The whole testing for 1M size array
	for (int j = 0; j < 3; j++) {
		finRand.open(RANDOM_DATA_FILE);
		if (finRand.fail()) {
			fout << "failed to open " + RANDOM_DATA_FILE;
			exit(1);
		}

		finAscending.open(ASCENDING_DATA_FILE);
		if (finAscending.fail()) {
			fout << "failed to open " + ASCENDING_DATA_FILE;
			exit(2);
		}

		finDescending.open(DESCENDING_DATA_FILE);
		if (finDescending.fail()) {
			fout << "failed to open " + DESCENDING_DATA_FILE;
			exit(3);
		}

		for (i = 0; i < size3; i++) {//get random data for 1M
			finRand >> array1M[i];
		}

		timer.startClock();
		bubbleSortAssembly(array1M, size3);
		fout << timer.getTime() << ", ";

		for (i = 0; i < size3; i++) {//get ascending data for 1M
			finAscending >> array1M[i];
		}

		timer.startClock();
		bubbleSortAssembly(array1M, size3);
		fout << timer.getTime() << ", ";

		for (i = 0; i < size3; i++) {//get descending data for 1M
			finDescending >> array1M[i];
		}

		timer.startClock();
		bubbleSortAssembly(array1M, size3);
		fout << timer.getTime() << endl;

		finRand.close();
		finAscending.close();
		finDescending.close();
	}
	delete[] array100;
	delete[] array10K;
	delete[] array1M;
}

/*     Pre:  None
*     Post:  None
*  Purpose:  To run insertionsort
*********************************************************/
void runInsertionSort(){
	TimerSystem timer;
	std::cout << std::fixed << std::setprecision(8);
	ifstream finRand;
	ifstream finAscending;
	ifstream finDescending;

	int size1 = 100;
	int size2 = 10000;
	int size3 = 1000000;
	int i;

	int* array100;
	int* array10K;
	int* array1M;

	array100 = new int[size1];
	array10K = new int[size2];
	array1M = new int[size3];

	ofstream fout;
	fout.open("data.txt", ios::app);
	fout << fixed << setprecision(8);
	fout << "Assembly insertion" << endl;
	//The whole testing for 100 size array
	for (int j = 0; j < 3; j++) {
		finRand.open(RANDOM_DATA_FILE);
		if (finRand.fail()) {
			fout << "failed to open " + RANDOM_DATA_FILE;
			exit(1);
		}

		finAscending.open(ASCENDING_DATA_FILE);
		if (finAscending.fail()) {
			fout << "failed to open " + ASCENDING_DATA_FILE;
			exit(2);
		}

		finDescending.open(DESCENDING_DATA_FILE);
		if (finDescending.fail()) {
			fout << "failed to open " + DESCENDING_DATA_FILE;
			exit(3);
		}



		for (i = 0; i < size1; i++) {//get random data for 100
			finRand >> array100[i];
		}

		timer.startClock();
		insertionSort(array100, size1);
		fout << timer.getTime() << ", ";


		for (i = 0; i < size1; i++) {//get ascending data for 100
			finAscending >> array100[i];
		}

		timer.startClock();
		insertionSort(array100, size1);
		fout << timer.getTime() << ", ";


		for (i = 0; i < size1; i++) {//get descending data for 100
			finDescending >> array100[i];
		}

		timer.startClock();
		insertionSort(array100, size1);
		fout << timer.getTime() << endl;

		finRand.close();
		finAscending.close();
		finDescending.close();
	}

	//The whole testing for 10k size array
	for (int j = 0; j < 3; j++) {
		finRand.open(RANDOM_DATA_FILE);
		if (finRand.fail()) {
			fout << "failed to open " + RANDOM_DATA_FILE;
			exit(1);
		}

		finAscending.open(ASCENDING_DATA_FILE);
		if (finAscending.fail()) {
			fout << "failed to open " + ASCENDING_DATA_FILE;
			exit(2);
		}

		finDescending.open(DESCENDING_DATA_FILE);
		if (finDescending.fail()) {
			fout << "failed to open " + DESCENDING_DATA_FILE;
			exit(3);
		}

		for (i = 0; i < size2; i++) {//get random data for 10k
			finRand >> array10K[i];
		}

		timer.startClock();
		insertionSort(array10K, size2);
		fout << timer.getTime() << ", ";

		for (i = 0; i < size2; i++) {//get ascending data for 10k
			finAscending >> array10K[i];
		}

		timer.startClock();
		insertionSort(array10K, size2);
		fout << timer.getTime() << ", ";

		for (i = 0; i < size2; i++) {//get descending data for 10k
			finDescending >> array10K[i];
		}

		timer.startClock();
		insertionSort(array10K, size2);
		fout << timer.getTime() << endl;

		finRand.close();
		finAscending.close();
		finDescending.close();
	}

	//The whole testing for 1M size array
	for (int j = 0; j < 3; j++) {
		finRand.open(RANDOM_DATA_FILE);
		if (finRand.fail()) {
			fout << "failed to open " + RANDOM_DATA_FILE;
			exit(1);
		}

		finAscending.open(ASCENDING_DATA_FILE);
		if (finAscending.fail()) {
			fout << "failed to open " + ASCENDING_DATA_FILE;
			exit(2);
		}

		finDescending.open(DESCENDING_DATA_FILE);
		if (finDescending.fail()) {
			fout << "failed to open " + DESCENDING_DATA_FILE;
			exit(3);
		}

		for (i = 0; i < size3; i++) {//get random data for 1M
			finRand >> array1M[i];
		}

		timer.startClock();
		insertionSort(array1M, size3);
		fout << timer.getTime() << ", ";

		for (i = 0; i < size3; i++) {//get ascending data for 1M
			finAscending >> array1M[i];
		}

		timer.startClock();
		insertionSort(array1M, size3);
		fout << timer.getTime() << ", ";

		for (i = 0; i < size3; i++) {//get descending data for 1M
			finDescending >> array1M[i];
		}

		timer.startClock();
		insertionSort(array1M, size3);
		fout << timer.getTime() << endl;

		finRand.close();
		finAscending.close();
		finDescending.close();
	}
	delete[] array100;
	delete[] array10K;
	delete[] array1M;
}

/*     Pre:  None
*     Post:  none
*  Purpose:  To run insertionsort (assembly)
*********************************************************/
void runInsertionSortAssembly() {
	TimerSystem timer;
	std::cout << std::fixed << std::setprecision(8);
	ifstream finRand;
	ifstream finAscending;
	ifstream finDescending;

	int size1 = 100;
	int size2 = 10000;
	int size3 = 1000000;
	int i;

	int* array100;
	int* array10K;
	int* array1M;

	array100 = new int[size1];
	array10K = new int[size2];
	array1M = new int[size3];

	ofstream fout;
	fout.open("data.txt", ios::app);
	fout << fixed << setprecision(8);
	fout << "Assembly insertion" << endl;
	//The whole testing for 100 size array
	for (int j = 0; j < 3; j++) {
		finRand.open(RANDOM_DATA_FILE);
		if (finRand.fail()) {
			fout << "failed to open " + RANDOM_DATA_FILE;
			exit(1);
		}

		finAscending.open(ASCENDING_DATA_FILE);
		if (finAscending.fail()) {
			fout << "failed to open " + ASCENDING_DATA_FILE;
			exit(2);
		}

		finDescending.open(DESCENDING_DATA_FILE);
		if (finDescending.fail()) {
			fout << "failed to open " + DESCENDING_DATA_FILE;
			exit(3);
		}



		for (i = 0; i < size1; i++) {//get random data for 100
			finRand >> array100[i];
		}
		
		timer.startClock();
		insertionSortAssembly(array100, size1);
		fout << timer.getTime() << ", ";

		for (i = 0; i < size1; i++) {//get ascending data for 100
			finAscending >> array100[i];
		}

		timer.startClock();
		insertionSortAssembly(array100, size1);
		fout << timer.getTime() << ", ";


		for (i = 0; i < size1; i++) {//get descending data for 100
			finDescending >> array100[i];
		}

		timer.startClock();
		insertionSortAssembly(array100, size1);
		fout << timer.getTime() << endl;

		finRand.close();
		finAscending.close();
		finDescending.close();
	}

	//The whole testing for 10k size array
	for (int j = 0; j < 3; j++) {
		finRand.open(RANDOM_DATA_FILE);
		if (finRand.fail()) {
			fout << "failed to open " + RANDOM_DATA_FILE;
			exit(1);
		}

		finAscending.open(ASCENDING_DATA_FILE);
		if (finAscending.fail()) {
			fout << "failed to open " + ASCENDING_DATA_FILE;
			exit(2);
		}

		finDescending.open(DESCENDING_DATA_FILE);
		if (finDescending.fail()) {
			fout << "failed to open " + DESCENDING_DATA_FILE;
			exit(3);
		}

		for (i = 0; i < size2; i++) {//get random data for 10k
			finRand >> array10K[i];
		}

		timer.startClock();
		insertionSortAssembly(array10K, size2);
		fout << timer.getTime() << ", ";

		for (i = 0; i < size2; i++) {//get ascending data for 10k
			finAscending >> array10K[i];
		}

		timer.startClock();
		insertionSortAssembly(array10K, size2);
		fout << timer.getTime() << ", ";

		for (i = 0; i < size2; i++) {//get descending data for 10k
			finDescending >> array10K[i];
		}

		timer.startClock();
		insertionSortAssembly(array10K, size2);
		fout << timer.getTime() << endl;

		finRand.close();
		finAscending.close();
		finDescending.close();
	}

	//The whole testing for 1M size array
	for (int j = 0; j < 3; j++) {
		finRand.open(RANDOM_DATA_FILE);
		if (finRand.fail()) {
			fout << "failed to open " + RANDOM_DATA_FILE;
			exit(1);
		}

		finAscending.open(ASCENDING_DATA_FILE);
		if (finAscending.fail()) {
			fout << "failed to open " + ASCENDING_DATA_FILE;
			exit(2);
		}

		finDescending.open(DESCENDING_DATA_FILE);
		if (finDescending.fail()) {
			fout << "failed to open " + DESCENDING_DATA_FILE;
			exit(3);
		}

		for (i = 0; i < size3; i++) {//get random data for 1M
			finRand >> array1M[i];
		}

		timer.startClock();
		insertionSortAssembly(array1M, size3);
		fout << timer.getTime() << ", ";

		for (i = 0; i < size3; i++) {//get ascending data for 1M
			finAscending >> array1M[i];
		}

		timer.startClock();
		insertionSortAssembly(array1M, size3);
		fout << timer.getTime() << ", ";

		for (i = 0; i < size3; i++) {//get descending data for 1M
			finDescending >> array1M[i];
		}

		timer.startClock();
		insertionSortAssembly(array1M, size3);
		fout << timer.getTime() << endl;

		finRand.close();
		finAscending.close();
		finDescending.close();
	}
	delete[] array100;
	delete[] array10K;
	delete[] array1M;
}

/*     Pre:  None
*     Post:  None
*  Purpose:  To run Mergesort
*********************************************************/
void runMergeSort()
{
	TimerSystem timer;
	std::cout << std::fixed << std::setprecision(8);
	ifstream finRand;
	ifstream finAscending;
	ifstream finDescending;
	ofstream fout;

	int size1 = 100;
	int size2 = 10000;
	int size3 = 1000000;
	int i;

	int* array100;
	int* array10K;
	int* array1M;

	array100 = new int[size1];
	array10K = new int[size2];
	array1M = new int[size3];

	fout.open("data.txt", ios::app);
	fout << fixed << setprecision(8);

	//The whole testing for 100 size array
	for (int j = 0; j < 3; j++) {
		finRand.open(RANDOM_DATA_FILE);
		if (finRand.fail()) {
			fout << "failed to open " + RANDOM_DATA_FILE;
			exit(1);
		}

		finAscending.open(ASCENDING_DATA_FILE);
		if (finAscending.fail()) {
			fout << "failed to open " + ASCENDING_DATA_FILE;
			exit(2);
		}

		finDescending.open(DESCENDING_DATA_FILE);
		if (finDescending.fail()) {
			fout << "failed to open " + DESCENDING_DATA_FILE;
			exit(3);
		}

		for (i = 0; i < size1; i++) {//get random data for 100
			finRand >> array100[i];
		}



		timer.startClock();
		mergeSort(array100, 0, size1 - 1);
		fout << timer.getTime() << ", ";

		for (i = 0; i < size1; i++) {//get ascending data for 100
			finAscending >> array100[i];
		}

		timer.startClock();
		mergeSort(array100, 0, size1 - 1);
		fout << timer.getTime() << ", ";

		for (i = 0; i < size1; i++) {//get descending data for 100
			finDescending >> array100[i];
		}

		timer.startClock();
		mergeSort(array100, 0, size1 - 1);
		fout << timer.getTime() << endl;

		finRand.close();
		finAscending.close();
		finDescending.close();
		fout << endl;
	}

	//The whole testing for 10k size array
	for (int j = 0; j < 3; j++) {
		finRand.open(RANDOM_DATA_FILE);
		if (finRand.fail()) {
			fout << "failed to open " + RANDOM_DATA_FILE;
			exit(1);
		}

		finAscending.open(ASCENDING_DATA_FILE);
		if (finAscending.fail()) {
			fout << "failed to open " + ASCENDING_DATA_FILE;
			exit(2);
		}

		finDescending.open(DESCENDING_DATA_FILE);
		if (finDescending.fail()) {
			fout << "failed to open " + DESCENDING_DATA_FILE;
			exit(3);
		}

		for (i = 0; i < size2; i++) {//get random data for 10k
			finRand >> array10K[i];
		}

		timer.startClock();
		mergeSort(array10K, 0, size2 - 1);
		fout << timer.getTime() << ", ";

		for (i = 0; i < size2; i++) {//get ascending data for 10k
			finAscending >> array10K[i];
		}

		timer.startClock();
		mergeSort(array10K, 0, size2 - 1);
		fout << timer.getTime() << ", ";

		for (i = 0; i < size2; i++) {//get descending data for 10k
			finDescending >> array10K[i];
		}

		timer.startClock();
		mergeSort(array10K, 0, size2 - 1);
		fout << timer.getTime() << endl;

		finRand.close();
		finAscending.close();
		finDescending.close();
		fout << endl;
	}

	//The whole testing for 1M size array
	for (int j = 0; j < 3; j++) {
		finRand.open(RANDOM_DATA_FILE);
		if (finRand.fail()) {
			fout << "failed to open " + RANDOM_DATA_FILE;
			exit(1);
		}

		finAscending.open(ASCENDING_DATA_FILE);
		if (finAscending.fail()) {
			fout << "failed to open " + ASCENDING_DATA_FILE;
			exit(2);
		}

		finDescending.open(DESCENDING_DATA_FILE);
		if (finDescending.fail()) {
			fout << "failed to open " + DESCENDING_DATA_FILE;
			exit(3);
		}

		for (i = 0; i < size3; i++) {//get random data for 1M
			finRand >> array1M[i];
		}

		timer.startClock();
		mergeSort(array1M, 0, size3 - 1);
		fout << timer.getTime() << ", ";

		for (i = 0; i < size3; i++) {//get ascending data for 1M
			finAscending >> array1M[i];
		}

		timer.startClock();
		mergeSort(array1M, 0, size3 - 1);
		fout << timer.getTime() << ", ";

		for (i = 0; i < size3; i++) {//get descending data for 1M
			finDescending >> array1M[i];
		}

		timer.startClock();
		mergeSort(array1M, 0, size3 - 1);
		fout << timer.getTime() << endl;

		finRand.close();
		finAscending.close();
		finDescending.close();
		fout << endl;
	}

	delete[] array100;
	delete[] array10K;
	delete[] array1M;
}

/*     Pre:  None
*     Post:  None
*  Purpose:  To run quicksort
*********************************************************/
void runQuickSort()
{
	TimerSystem timer;
	std::cout << std::fixed << std::setprecision(8);
	ifstream finRand;
	ifstream finAscending;
	ifstream finDescending;

	int size1 = 100;
	int size2 = 10000;
	int size3 = 1000000;
	int i;

	int* array100;
	int* array10K;
	int* array1M;

	array100 = new int[size1];
	array10K = new int[size2];
	array1M = new int[size3];

	ofstream fout;
	fout.open("data.txt", ios::app);
	fout << fixed << setprecision(8);
	//The whole testing for 100 size array
	for (int j = 0; j < 3; j++) {
		finRand.open(RANDOM_DATA_FILE);
		if (finRand.fail()) {
			fout << "failed to open " + RANDOM_DATA_FILE;
			exit(1);
		}

		finAscending.open(ASCENDING_DATA_FILE);
		if (finAscending.fail()) {
			fout << "failed to open " + ASCENDING_DATA_FILE;
			exit(2);
		}

		finDescending.open(DESCENDING_DATA_FILE);
		if (finDescending.fail()) {
			fout << "failed to open " + DESCENDING_DATA_FILE;
			exit(3);
		}

		for (i = 0; i < size1; i++) {//get random data for 100
			finRand >> array100[i];
		}



		timer.startClock();
		quickSort(array100, 0, size1-1);
		fout << timer.getTime() << ", ";

		for (i = 0; i < size1; i++) {//get ascending data for 100
			finAscending >> array100[i];
		}

		timer.startClock();
		quickSort(array100, 0, size1-1);
		fout << timer.getTime() << ", ";

		for (i = 0; i < size1; i++) {//get descending data for 100
			finDescending >> array100[i];
		}

		timer.startClock();
		quickSort(array100, 0, size1-1);
		fout << timer.getTime() << endl;

		finRand.close();
		finAscending.close();
		finDescending.close();
		fout << endl;
	}

	//The whole testing for 10k size array
	for (int j = 0; j < 3; j++) {
		finRand.open(RANDOM_DATA_FILE);
		if (finRand.fail()) {
			fout << "failed to open " + RANDOM_DATA_FILE;
			exit(1);
		}

		finAscending.open(ASCENDING_DATA_FILE);
		if (finAscending.fail()) {
			fout << "failed to open " + ASCENDING_DATA_FILE;
			exit(2);
		}

		finDescending.open(DESCENDING_DATA_FILE);
		if (finDescending.fail()) {
			fout << "failed to open " + DESCENDING_DATA_FILE;
			exit(3);
		}

		for (i = 0; i < size2; i++) {//get random data for 10k
			finRand >> array10K[i];
		}

		timer.startClock();
		quickSort(array10K, 0, size2-1);
		fout << timer.getTime() << ", ";

		for (i = 0; i < size2; i++) {//get ascending data for 10k
			finAscending >> array10K[i];
		}

		timer.startClock();
		quickSort(array10K, 0, size2-1);
		fout << timer.getTime() << ", ";

		for (i = 0; i < size2; i++) {//get descending data for 10k
			finDescending >> array10K[i];
		}

		timer.startClock();
		quickSort(array10K, 0, size2-1);
		fout << timer.getTime() << endl;

		finRand.close();
		finAscending.close();
		finDescending.close();
		fout << endl;
	}

	//The whole testing for 1M size array
	for (int j = 0; j < 3; j++) {
		finRand.open(RANDOM_DATA_FILE);
		if (finRand.fail()) {
			fout << "failed to open " + RANDOM_DATA_FILE;
			exit(1);
		}

		finAscending.open(ASCENDING_DATA_FILE);
		if (finAscending.fail()) {
			fout << "failed to open " + ASCENDING_DATA_FILE;
			exit(2);
		}

		finDescending.open(DESCENDING_DATA_FILE);
		if (finDescending.fail()) {
			fout << "failed to open " + DESCENDING_DATA_FILE;
			exit(3);
		}

		for (i = 0; i < size3; i++) {//get random data for 1M
			finRand >> array1M[i];
		}

		timer.startClock();
		quickSort(array1M, 0, size3-1);
		fout << timer.getTime() << ", ";

		for (i = 0; i < size3; i++) {//get ascending data for 1M
			finAscending >> array1M[i];
		}

		timer.startClock();
		quickSort(array1M, 0, size3-1);
		fout << timer.getTime() << ", ";

		for (i = 0; i < size3; i++) {//get descending data for 1M
			finDescending >> array1M[i];
		}

		timer.startClock();
		quickSort(array1M, 0, size3-1);
		fout << timer.getTime() << endl;

		finRand.close();
		finAscending.close();
		finDescending.close();
		fout << endl;
	}

	delete[] array100;
	delete[] array10K;
	delete[] array1M;
}

/*     Pre:  None
*     Post:  None
*  Purpose:  To run selectionsort
*********************************************************/
void runSelectionSort()
{
	TimerSystem timer;
	std::cout << std::fixed << std::setprecision(8);
	ifstream finRand;
	ifstream finAscending;
	ifstream finDescending;

	int size1 = 100;
	int size2 = 10000;
	int size3 = 1000000;
	int i;

	int* array100;
	int* array10K;
	int* array1M;

	array100 = new int[size1];
	array10K = new int[size2];
	array1M = new int[size3];

	ofstream fout;
	fout.open("data.txt", ios::app);
	fout << fixed << setprecision(8);
	//The whole testing for 100 size array
	for (int j = 0; j < 3; j++) {
		finRand.open(RANDOM_DATA_FILE);
		if (finRand.fail()) {
			fout << "failed to open " + RANDOM_DATA_FILE;
			exit(1);
		}

		finAscending.open(ASCENDING_DATA_FILE);
		if (finAscending.fail()) {
			fout << "failed to open " + ASCENDING_DATA_FILE;
			exit(2);
		}

		finDescending.open(DESCENDING_DATA_FILE);
		if (finDescending.fail()) {
			fout << "failed to open " + DESCENDING_DATA_FILE;
			exit(3);
		}

		for (i = 0; i < size1; i++) {//get random data for 100
			finRand >> array100[i];
		}

		timer.startClock();
		selectionSort(array100, size1);
		fout << timer.getTime() << ", ";

		for (i = 0; i < size1; i++) {//get ascending data for 100
			finAscending >> array100[i];
		}

		timer.startClock();
		selectionSort(array100, size1);
		fout << timer.getTime() << ", ";

		for (i = 0; i < size1; i++) {//get descending data for 100
			finDescending >> array100[i];
		}

		timer.startClock();
		selectionSort(array100, size1);
		fout << timer.getTime() << endl;

		finRand.close();
		finAscending.close();
		finDescending.close();
		fout << endl;
	}

	//The whole testing for 10k size array
	for (int j = 0; j < 3; j++) {
		finRand.open(RANDOM_DATA_FILE);
		if (finRand.fail()) {
			fout << "failed to open " + RANDOM_DATA_FILE;
			exit(1);
		}

		finAscending.open(ASCENDING_DATA_FILE);
		if (finAscending.fail()) {
			fout << "failed to open " + ASCENDING_DATA_FILE;
			exit(2);
		}

		finDescending.open(DESCENDING_DATA_FILE);
		if (finDescending.fail()) {
			fout << "failed to open " + DESCENDING_DATA_FILE;
			exit(3);
		}

		for (i = 0; i < size2; i++) {//get random data for 10k
			finRand >> array10K[i];
		}

		timer.startClock();
		selectionSort(array10K, size2);
		fout << timer.getTime() << ", ";

		for (i = 0; i < size2; i++) {//get ascending data for 10k
			finAscending >> array10K[i];
		}

		timer.startClock();
		selectionSort(array10K, size2);
		fout << timer.getTime() << ", ";

		for (i = 0; i < size2; i++) {//get descending data for 10k
			finDescending >> array10K[i];
		}

		timer.startClock();
		selectionSort(array10K, size2);
		fout << timer.getTime() << endl;

		finRand.close();
		finAscending.close();
		finDescending.close();
		fout << endl;
	}

	//The whole testing for 1M size array
	for (int j = 0; j < 3; j++) {
		finRand.open(RANDOM_DATA_FILE);
		if (finRand.fail()) {
			fout << "failed to open " + RANDOM_DATA_FILE;
			exit(1);
		}

		finAscending.open(ASCENDING_DATA_FILE);
		if (finAscending.fail()) {
			fout << "failed to open " + ASCENDING_DATA_FILE;
			exit(2);
		}

		finDescending.open(DESCENDING_DATA_FILE);
		if (finDescending.fail()) {
			fout << "failed to open " + DESCENDING_DATA_FILE;
			exit(3);
		}

		for (i = 0; i < size3; i++) {//get random data for 1M
			finRand >> array1M[i];
		}

		timer.startClock();
		selectionSort(array1M, size3);
		fout << timer.getTime() << ", ";

		for (i = 0; i < size3; i++) {//get ascending data for 1M
			finAscending >> array1M[i];
		}

		timer.startClock();
		selectionSort(array1M, size3);
		fout << timer.getTime() << ", ";

		for (i = 0; i < size3; i++) {//get descending data for 1M
			finDescending >> array1M[i];
		}

		timer.startClock();
		selectionSort(array1M, size3);
		fout << timer.getTime() << endl;

		finRand.close();
		finAscending.close();
		finDescending.close();
		fout << endl;
	}

	delete[] array100;
	delete[] array10K;
	delete[] array1M;
}

/*     Pre:  None
*     Post:  None
*  Purpose:  To run selectionsort in assembly
*********************************************************/
void runSelectionSortAssembly() {
	TimerSystem timer;
	std::cout << std::fixed << std::setprecision(8);
	ifstream finRand;
	ifstream finAscending;
	ifstream finDescending;

	int size1 = 100;
	int size2 = 10000;
	int size3 = 1000000;
	int i;

	int* array100;
	int* array10K;
	int* array1M;

	array100 = new int[size1];
	array10K = new int[size2];
	array1M = new int[size3];

	ofstream fout;
	fout.open("data.txt", ios::app);
	fout << fixed << setprecision(8);
	fout << "Assembly selection" << endl;
	//The whole testing for 100 size array
	for (int j = 0; j < 3; j++) {
		finRand.open(RANDOM_DATA_FILE);
		if (finRand.fail()) {
			fout << "failed to open " + RANDOM_DATA_FILE;
			exit(1);
		}

		finAscending.open(ASCENDING_DATA_FILE);
		if (finAscending.fail()) {
			fout << "failed to open " + ASCENDING_DATA_FILE;
			exit(2);
		}

		finDescending.open(DESCENDING_DATA_FILE);
		if (finDescending.fail()) {
			fout << "failed to open " + DESCENDING_DATA_FILE;
			exit(3);
		}



		for (i = 0; i < size1; i++) {//get random data for 100
			finRand >> array100[i];
		}

		timer.startClock();
		selectionSortAssembly(array100, size1);
		fout << timer.getTime() << ", ";

		for (int i = 0; i < size1; i++) {
			cout << array100[i] << " ";
		}

		for (int i = 0; i < size1; i++) {
			cout << array100[i] << " ";
		}


		for (i = 0; i < size1; i++) {//get ascending data for 100
			finAscending >> array100[i];
		}

		timer.startClock();
		selectionSortAssembly(array100, size1);
		fout << timer.getTime() << ", ";


		for (i = 0; i < size1; i++) {//get descending data for 100
			finDescending >> array100[i];
		}

		timer.startClock();
		selectionSortAssembly(array100, size1);
		fout << timer.getTime() << endl;

		finRand.close();
		finAscending.close();
		finDescending.close();
	}

	//The whole testing for 10k size array
	for (int j = 0; j < 3; j++) {
		finRand.open(RANDOM_DATA_FILE);
		if (finRand.fail()) {
			fout << "failed to open " + RANDOM_DATA_FILE;
			exit(1);
		}

		finAscending.open(ASCENDING_DATA_FILE);
		if (finAscending.fail()) {
			fout << "failed to open " + ASCENDING_DATA_FILE;
			exit(2);
		}

		finDescending.open(DESCENDING_DATA_FILE);
		if (finDescending.fail()) {
			fout << "failed to open " + DESCENDING_DATA_FILE;
			exit(3);
		}

		for (i = 0; i < size2; i++) {//get random data for 10k
			finRand >> array10K[i];
		}

		timer.startClock();
		selectionSortAssembly(array10K, size2);
		fout << timer.getTime() << ", ";

		for (i = 0; i < size2; i++) {//get ascending data for 10k
			finAscending >> array10K[i];
		}

		timer.startClock();
		selectionSortAssembly(array10K, size2);
		fout << timer.getTime() << ", ";

		for (i = 0; i < size2; i++) {//get descending data for 10k
			finDescending >> array10K[i];
		}

		timer.startClock();
		selectionSortAssembly(array10K, size2);
		fout << timer.getTime() << endl;

		finRand.close();
		finAscending.close();
		finDescending.close();
	}

	//The whole testing for 1M size array
	for (int j = 0; j < 3; j++) {
		finRand.open(RANDOM_DATA_FILE);
		if (finRand.fail()) {
			fout << "failed to open " + RANDOM_DATA_FILE;
			exit(1);
		}

		finAscending.open(ASCENDING_DATA_FILE);
		if (finAscending.fail()) {
			fout << "failed to open " + ASCENDING_DATA_FILE;
			exit(2);
		}

		finDescending.open(DESCENDING_DATA_FILE);
		if (finDescending.fail()) {
			fout << "failed to open " + DESCENDING_DATA_FILE;
			exit(3);
		}

		for (i = 0; i < size3; i++) {//get random data for 1M
			finRand >> array1M[i];
		}

		timer.startClock();
		selectionSortAssembly(array1M, size3);
		fout << timer.getTime() << ", ";

		for (i = 0; i < size3; i++) {//get ascending data for 1M
			finAscending >> array1M[i];
		}

		timer.startClock();
		selectionSortAssembly(array1M, size3);
		fout << timer.getTime() << ", ";

		for (i = 0; i < size3; i++) {//get descending data for 1M
			finDescending >> array1M[i];
		}

		timer.startClock();
		selectionSortAssembly(array1M, size3);
		fout << timer.getTime() << endl;

		finRand.close();
		finAscending.close();
		finDescending.close();
	}
	delete[] array100;
	delete[] array10K;
	delete[] array1M;
}
/*     Pre:  None
*     Post:  None
*  Purpose:  To run shellsort
*********************************************************/
void runShellSort()
{
	TimerSystem timer;
	std::cout << std::fixed << std::setprecision(8);
	ifstream finRand;
	ifstream finAscending;
	ifstream finDescending;

	int size1 = 100;
	int size2 = 10000;
	int size3 = 1000000;
	int i;

	int* array100;
	int* array10K;
	int* array1M;

	array100 = new int[size1];
	array10K = new int[size2];
	array1M = new int[size3];

	ofstream fout;
	fout.open("data.txt", ios::app);
	fout << fixed << setprecision(8);
	//The whole testing for 100 size array
	for (int j = 0; j < 3; j++) {
		finRand.open(RANDOM_DATA_FILE);
		if (finRand.fail()) {
			fout << "failed to open " + RANDOM_DATA_FILE;
			exit(1);
		}

		finAscending.open(ASCENDING_DATA_FILE);
		if (finAscending.fail()) {
			fout << "failed to open " + ASCENDING_DATA_FILE;
			exit(2);
		}

		finDescending.open(DESCENDING_DATA_FILE);
		if (finDescending.fail()) {
			fout << "failed to open " + DESCENDING_DATA_FILE;
			exit(3);
		}

		for (i = 0; i < size1; i++) {//get random data for 100
			finRand >> array100[i];
		}

		timer.startClock();
		shellSort(array100, size1);
		fout << timer.getTime() << ", ";

		for (i = 0; i < size1; i++) {//get ascending data for 100
			finAscending >> array100[i];
		}

		timer.startClock();
		shellSort(array100, size1);
		fout << timer.getTime() << ", ";

		for (i = 0; i < size1; i++) {//get descending data for 100
			finDescending >> array100[i];
		}

		timer.startClock();
		shellSort(array100, size1);
		fout << timer.getTime() << endl;

		finRand.close();
		finAscending.close();
		finDescending.close();
		fout << endl;
	}

	//The whole testing for 10k size array
	for (int j = 0; j < 3; j++) {
		finRand.open(RANDOM_DATA_FILE);
		if (finRand.fail()) {
			fout << "failed to open " + RANDOM_DATA_FILE;
			exit(1);
		}

		finAscending.open(ASCENDING_DATA_FILE);
		if (finAscending.fail()) {
			fout << "failed to open " + ASCENDING_DATA_FILE;
			exit(2);
		}

		finDescending.open(DESCENDING_DATA_FILE);
		if (finDescending.fail()) {
			fout << "failed to open " + DESCENDING_DATA_FILE;
			exit(3);
		}

		for (i = 0; i < size2; i++) {//get random data for 10k
			finRand >> array10K[i];
		}

		timer.startClock();
		shellSort(array10K, size2);
		fout << timer.getTime() << ", ";

		for (i = 0; i < size2; i++) {//get ascending data for 10k
			finAscending >> array10K[i];
		}

		timer.startClock();
		shellSort(array10K, size2);
		fout << timer.getTime() << ", ";

		for (i = 0; i < size2; i++) {//get descending data for 10k
			finDescending >> array10K[i];
		}

		timer.startClock();
		shellSort(array10K, size2);
		fout << timer.getTime() << endl;

		finRand.close();
		finAscending.close();
		finDescending.close();
		fout << endl;
	}

	//The whole testing for 1M size array
	for (int j = 0; j < 3; j++) {
		finRand.open(RANDOM_DATA_FILE);
		if (finRand.fail()) {
			fout << "failed to open " + RANDOM_DATA_FILE;
			exit(1);
		}

		finAscending.open(ASCENDING_DATA_FILE);
		if (finAscending.fail()) {
			fout << "failed to open " + ASCENDING_DATA_FILE;
			exit(2);
		}

		finDescending.open(DESCENDING_DATA_FILE);
		if (finDescending.fail()) {
			fout << "failed to open " + DESCENDING_DATA_FILE;
			exit(3);
		}

		for (i = 0; i < size3; i++) {//get random data for 1M
			finRand >> array1M[i];
		}

		timer.startClock();
		shellSort(array1M, size3);
		fout << timer.getTime() << ", ";

		for (i = 0; i < size3; i++) {//get ascending data for 1M
			finAscending >> array1M[i];
		}

		timer.startClock();
		shellSort(array1M, size3);
		fout << timer.getTime() << ", ";

		for (i = 0; i < size3; i++) {//get descending data for 1M
			finDescending >> array1M[i];
		}

		timer.startClock();
		shellSort(array1M, size3);
		fout << timer.getTime() << endl;

		finRand.close();
		finAscending.close();
		finDescending.close();
		fout << endl;
	}

	delete[] array100;
	delete[] array10K;
	delete[] array1M;
}
