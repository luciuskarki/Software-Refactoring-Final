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
TimerSystem timer;

int* populate(int size, string file) {
	ifstream fin;
	int* arr;
	arr = new int[size];

	fin.open(file);
	if (fin.fail()) {
		cout << "failed to open " + file;
		exit(3);
	}

	for (int i = 0; i < size; i++) {
		fin >> arr[i];
	}
	fin.close();
	return arr;
}

void testSize(int size, ofstream& fout, void (*sort)(int*, int)) {
	for (int j = 0; j < 3; j++) {
		timer.startClock();
		sort(populate(size, RANDOM_DATA_FILE), size);
		fout << timer.getTime() << ", ";

		timer.startClock();
		sort(populate(size, ASCENDING_DATA_FILE), size);
		fout << timer.getTime() << ", ";

		timer.startClock();
		sort(populate(size, DESCENDING_DATA_FILE), size);
		fout << timer.getTime() << endl;
	}
}

/*     Pre:  Sorting Function and the name of the function passed in
*     Post:  none
*  Purpose:  To run the passed in sort and get the time it takes
*********************************************************/
void runSort(void (*sort)(int*, int), string funcName) {
	std::cout << std::fixed << std::setprecision(8);

	ofstream fout;
	fout.open("data.txt", ios::app);
	fout << fixed << setprecision(8);
	fout << funcName << endl;

	testSize(100, fout, sort);
	testSize(10000, fout, sort);
	testSize(1000000, fout, sort);

	fout.close();
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
