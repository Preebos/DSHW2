// Authors: Evan Hafner, Robin Steyer
// Course Title: Data Structures
// Course Number: CS2028
// Instructor: Anca Ralescu
// TA: Suryadip Chakraborty
// Abstract: Assignment 2 (THe Element Uniqueness problem) implements three IsUnique algorithms
//	and three sorting algorithms. The results are displayed as a table.
// Preconditions: TODO
// Postconditions: TODO

#include <iostream>
#include <iomanip>
#include <time.h>
#include <cstdlib>

using namespace std;

// three sorting algorithms to test with isUnique3:
enum sort_type { BUBBLE, INSERTION, SELECTION };

// input: array A (passed by reference by nature), and the index of the last element
void bubbleSort(unsigned int A[], unsigned int last) {
	unsigned int temp;
	for (unsigned int n = 0; n < last; n++) {
		for (unsigned int k = 0; k < last; k++) {
			if (A[k] > A[k + 1]) {
				temp = A[k];
				A[k] = A[k + 1];
				A[k + 1] = temp;
			}
		}
	}
}

// input: array A (passed by reference by nature), and the index of the last element
void insertionSort(unsigned int A[], unsigned int last) {
	int n;
	unsigned int temp;
	for (unsigned int i = 1; i <= last; i++) {
		n = i;
		while (n > 0 && A[n] < A[n - 1]) {
			temp = A[n];
			A[n] = A[n - 1];
			A[n - 1] = temp;
			n--;
		}
	}
}

void selectionSort(unsigned int A[], unsigned int last) {

	unsigned int tmp;
	int minIndex;

	// Iterate through array
	for (unsigned int i = 0; i <= last; i++) {
		
		// Set initial current min
		minIndex = i;

		// Find the min in the unsorted portion of the array
		for (unsigned int j = i; j <= last; j++) {
			// Check next index for value lower than current min
			if (A[j] < A[minIndex]) {
				minIndex = j;
			}

		}

		// Swap the current index with the next min value
		tmp = A[minIndex];
		A[minIndex] = A[i];
		A[i] = tmp;

	}

}

// isUnique1 RECURSIVELY returns true if the array contains no repeated elements,
// false if the array contains repeated elements
bool isUnique1(unsigned int A[], unsigned int first, unsigned int last) {
	if (first >= last) { // true if there is only one element
		return true;
	}
	if (!isUnique1(A, first, last - 1)) {
		return false;
	}
	if (!isUnique1(A, first + 1, last)) {
		return false;
	}
	return(A[first] != A[last]);
}

//// isUnique2 ITERATIVELY returns true if the array contains no repeated elements,
//// false if the array contains repeated elements
bool isUnique2(unsigned int A[], unsigned int first, unsigned int last){
	if (first >= last) { // true if there is only one element
		return true;
	}
	for (unsigned int i = first; i < last; i++) {
		for (unsigned int j = i + 1; j <= last; j++) {
			if (A[i] == A[j]) {
				return false;
			}
		}
	}
	return true;
}

// isUnique2 SORTS the array then returns true if the array contains no repeated elements,
// false if the array contains repeated elements
bool isUnique3(unsigned int A[], unsigned int first, unsigned int last, sort_type st){
	if (first >= last) { // true if there is only one element
		return true;
	}
	if (st == BUBBLE) {
		bubbleSort(A, last);
	}
	else if (st == INSERTION) {
		insertionSort(A, last);
	}
	else {
		selectionSort(A, last);
	}
	for (unsigned int i = first; i < last; i++) {
		if (A[i] == A[i + 1]) {
			return false;
		}
	}
	return true;
}

// main function
int main() {
	using std::cout;
	using std::endl;

	const int arraySize = 50000;
	clock_t start, end;
	srand(time(NULL));

	// create three arrays of size 100
	unsigned int sortArray1[arraySize], array1[arraySize], array2[arraySize]; //sortArray2[arraySize], sortArray3[arraySize];
	bool b1, b2, b3;
	double time1, time2, time3; //, sortTime2, sortTime3;

	// fill each array identically with random values
	for (int n = 0; n < arraySize; n++) {
		sortArray1[n] = rand() % 10000000;
		//sortArray2[n] = sortArray1[n];
		//sortArray3[n] = sortArray1[n];
		//array1[n] = sortArray1[n];
		array2[n] = sortArray1[n];
	}



	//cout << "**** PART 1 ****" << endl << endl;

	//start = clock();
	//sortb1 = isUnique3(sortArray1, 0, arraySize - 1, BUBBLE);
	//end = clock();
	//sortTime1 = (float)(end - start) * 1000.0 / (float)CLOCKS_PER_SEC;

	//start = clock();
	//sortb2 = isUnique3(sortArray2, 0, arraySize - 1, INSERTION);
	//end = clock();
	//sortTime2 = (float)(end - start) * 1000.0 / (float)CLOCKS_PER_SEC;f

	//start = clock();
	//sortb3 = isUnique3(sortArray3, 0, arraySize - 1, SELECTION);
	//end = clock();
	//sortTime3 = (float)(end - start) * 1000.0 / (float)CLOCKS_PER_SEC;

	//cout << "\nTime taken to complete isUnique3 using various sorts, on array size " << arraySize << endl;
	//cout << "\tBubble Sort: returned " << sortb1 << " in " << sortTime1 << " ms" << endl;
	//cout << "\tInsertion Sort: returned " << sortb2 << " in " << sortTime2 << " ms" << endl;
	//cout << "\tSelection Sort: returned " << sortb3 << " in " << sortTime3 << " ms" << endl << endl;

	//system("pause");

	
	// Part 2
	/*
	cout << endl << "**** PART 2 ****" << endl << endl;

	start = clock();
	//b1 = isUnique1(array1, 0, arraySize - 1);
	b1 = false;
	end = clock();
	time1 = (float)(end - start) * 1000.0 / (float)CLOCKS_PER_SEC;

	start = clock();
	b2 = isUnique2(array2, 0, arraySize - 1);
	end = clock();
	time2 = (float)(end - start) * 1000.0 / (float)CLOCKS_PER_SEC;

	start = clock();
	b3 = isUnique3(sortArray1, 0, arraySize - 1, INSERTION);
	end = clock();
	time3 = (float)(end - start) * 1000.0 / (float)CLOCKS_PER_SEC;

	//start = clock();
	//b1 = isUnique2(sortArray1, 0, arraySize - 1);
	//end = clock();
	//time1 = (float)(end - start) * 1000.0 / (float)CLOCKS_PER_SEC;

	cout << "\tisUnique1 returned " << b1 << " in " << time1 << " ms" << endl;
	cout << "\tisUnique2 returned " << b2 << " in " << time2 << " ms" << endl;
	cout << "\tisUnique3 returned " << b3 << " in " << time3 << " ms" << endl << endl;

	system("pause");
	*/

	// PART 3
	/*cout << endl << "**** PART 3 ****" << endl << endl;

	insertionSort(array2, arraySize - 1);
	insertionSort(sortArray1, arraySize - 1);
	
	

	start = clock();
	//b1 = isUnique1(array1, 0, arraySize - 1);
	b1 = false;
	end = clock();
	time1 = (float)(end - start) * 1000.0 / (float)CLOCKS_PER_SEC;

	start = clock();
	b2 = isUnique2(array2, 0, arraySize - 1);
	end = clock();
	time2 = (float)(end - start) * 1000.0 / (float)CLOCKS_PER_SEC;

	start = clock();
	b3 = isUnique3(sortArray1, 0, arraySize - 1, INSERTION);
	end = clock();
	time3 = (float)(end - start) * 1000.0 / (float)CLOCKS_PER_SEC;

	//start = clock();
	//b1 = isUnique2(sortArray1, 0, arraySize - 1);
	//end = clock();
	//time1 = (float)(end - start) * 1000.0 / (float)CLOCKS_PER_SEC;

	cout << "\tisUnique1 returned " << b1 << " in " << time1 << " ms" << endl;
	cout << "\tisUnique2 returned " << b2 << " in " << time2 << " ms" << endl;
	cout << "\tisUnique3 returned " << b3 << " in " << time3 << " ms" << endl << endl;

	system("pause");
	*/


	// PART 4

	unsigned int arr[5000];
	double times[3][11];
	int c = 0;


	unsigned arrSize = 100;

	// Generate array
	for (unsigned int i = 0; i < arrSize; i++)
		arr[i] = rand() % 10000000;


	start = clock();
	//b1 = isUnique1(arr, 0, arrSize - 1);
	b1 = false;
	end = clock();
	times[0][c] = (float)(end - start) * 1000.0 / (float)CLOCKS_PER_SEC;

	// Generate array
	for (unsigned int i = 0; i < arrSize; i++)
		arr[i] = rand() % 10000000;

	// Time algorithm two
	start = clock();
	b2 = isUnique2(arr, 0, arrSize - 1);
	end = clock();
	times[1][c] = (float)(end - start) * 1000.0 / (float)CLOCKS_PER_SEC;

	// Generate array
	for (unsigned int i = 0; i < arrSize; i++)
		arr[i] = rand() % 10000000;

	// Time algorithm three
	start = clock();
	b3 = isUnique3(arr, 0, arrSize - 1, INSERTION);
	end = clock();
	times[2][c] = (float)(end - start) * 1000.0 / (float)CLOCKS_PER_SEC;

	c++;

	for (unsigned int arrSize = 500; arrSize <= 5000; arrSize += 500, c++) {

		// Generate array
		for (unsigned int i = 0; i < arrSize; i++)
			arr[i] = rand() % 10000000;

		
		start = clock();
		//b1 = isUnique1(arr, 0, arrSize - 1);
		b1 = false;
		end = clock();
		times[0][c] = (float)(end - start) * 1000.0 / (float)CLOCKS_PER_SEC;

		// Generate array
		for (unsigned int i = 0; i < arrSize; i++)
			arr[i] = rand() % 10000000;

		// Time algorithm two
		start = clock();
		b2 = isUnique2(arr, 0, arrSize - 1);
		end = clock();
		times[1][c] = (float)(end - start) * 1000.0 / (float)CLOCKS_PER_SEC;
		
		// Generate array
		for (unsigned int i = 0; i < arrSize; i++)
			arr[i] = rand() % 10000000;

		// Time algorithm three
		start = clock();
		b3 = isUnique3(arr, 0, arrSize - 1, INSERTION);
		end = clock();
		times[2][c] = (float)(end - start) * 1000.0 / (float)CLOCKS_PER_SEC;
		

		

	}
	// Output table of times
	cout << "Times:\t100\t500\t1000\t1500\t2000\t2500\t3000\t3500\t4000\t4500\t5000" << endl;

	for (int i = 0; i < 3; i++) {
		cout << "Alg" << i+1 << "\t";
		for (int j = 0; j < 11; j++) {
			cout << times[i][j] << "\t";
		}
		cout << endl;
	}

	system("pause");
	

	
	


	// PART 5
	/*
	cout << endl << "**** Part 5 ****" << endl << endl;
	const unsigned ARR_SIZE = 180000;
	unsigned int *arr = new unsigned int[ARR_SIZE];


	for (int i = 0; i < ARR_SIZE; i++)
		arr[i] = rand() % 10000000;
	




	start = clock();
	b1 = isUnique1(arr, 0, ARR_SIZE - 1);
	b1 = false;
	end = clock();
	time1 = (float)(end - start) * 1000.0 / (float)CLOCKS_PER_SEC;

	for (int i = 0; i < ARR_SIZE; i++)
		arr[i] = i;//rand() % 10000000;

	start = clock();
	b2 = isUnique2(arr, 0, ARR_SIZE - 1);
	end = clock();
	time2 = (float)(end - start) * 1000.0 / (float)CLOCKS_PER_SEC;

	for (int i = 0; i < ARR_SIZE; i++)
		arr[i] = rand() % 10000000;

	start = clock();
	b3 = isUnique3(arr, 0, ARR_SIZE - 1, INSERTION);
	end = clock();
	time3 = (float)(end - start) * 1000.0 / (float)CLOCKS_PER_SEC;

	delete[] arr;

	//cout << "Alg1\t" << time1 << endl;
	cout << "Alg2\t" << "time:\t" << time2 << "\tresult:\t" << b2 << endl;
	//cout << "Alg3\t" << "time:\t" << time3 << "\tresult:\t" << b3 << endl;

	system("pause");
	*/


	return 0;
}