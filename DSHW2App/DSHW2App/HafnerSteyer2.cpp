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
#include <time.h>

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

void selectionSort() {

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

// isUnique2 ITERATIVELY returns true if the array contains no repeated elements,
// false if the array contains repeated elements
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
	if (st = BUBBLE) {
		bubbleSort(A, last);
	}
	else if (st = INSERTION) {
		insertionSort(A, last);
	}
	else {
		//selectionSort();
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

	// create three arrays of size 100
	unsigned int sortArray1[100], sortArray2[100], sortArray3[100];
	bool b1, b2, b3;
	double time1, time2, time3;

	// fill each array identically with random values
	for (int n = 0; n < 100; n++) {
		sortArray1[n] = rand() % 10000;
		sortArray2[n] = sortArray1[n];
		sortArray3[n] = sortArray1[n];
	}

	cout << "Running isUnique3 with three sorting algorithms..." << endl;
	clock_t start = clock();
	b1 = isUnique3(sortArray1, 0, 99, BUBBLE);
	clock_t end = clock();
	time1 = (float)(end - start) * 1000.0 / (float)CLOCKS_PER_SEC;

	start = clock();
	b2 = isUnique3(sortArray1, 0, 99, INSERTION);
	end = clock();
	time2 = (float)(end - start) * 1000.0 / (float)CLOCKS_PER_SEC;

	start = clock();
	b3 = isUnique3(sortArray1, 0, 99, SELECTION);
	end = clock();
	time3 = (float)(end - start) * 1000.0 / (float)CLOCKS_PER_SEC;

	cout << "Time taken to complete isUnique3 using various sorts:" << endl;
	cout << "\tBubble Sort: " << time1 << " ms" << endl;
	cout << "\tInsertion Sort: " << time2 << " ms" << endl;
	cout << "\tSelection Sort: " << time3 << " ms" << endl;



	system("pause");
	return 0;
}