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

// input: array A (passed by reference by nature)
void bubbleSort(unsigned int A[], unsigned int last) {
	unsigned int temp;
	for (int n = 0; n < last; n++) {
		for (int k = 0; k < last; k++) {
			if (A[k] > A[k + 1]) {
				temp = A[k];
				A[k] = A[k + 1];
				A[k + 1] = temp;
			}
		}
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

// isUnique2 ITERATIVELY returns true if the array contains no repeated elements,
// false if the array contains repeated elements
bool isUnique2(unsigned int A[], unsigned int first, unsigned int last){
	if (first >= last) { // true if there is only one element
		return true;
	}
	for (int i = first; i < last; i++) {
		for (int j = i + 1; j <= last; j++) {
			if (A[i] == A[j]) {
				return false;
			}
		}
	}
	return true;
}

// isUnique2 SORTS the array then returns true if the array contains no repeated elements,
// false if the array contains repeated elements
bool isUnique3(unsigned int A[], unsigned int first, unsigned int last){
	if (first >= last) { // true if there is only one element
		return true;
	}
	//SORT(A, first, last); // TODO
	for (int i = first; i < last; i++) {
		if (A[i] == A[i + 1]) {
			return false;
		}
	}
	return true;
}

int main() {

	system("pause");
	return 0;
}