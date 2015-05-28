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

// isUnique1 recursively returns true if the array contains no repeated elements,
// false if the array contains repeated elements
bool isUnique1(unsigned int A[], int first, int last) {
	if (first >= last) {
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


//bool isUnique2(A, first, last){
//Input: Array A, first, last
//Output :
//	true if the array contains no repeated elements
//		false if the array contains repeated elements
//		if (first >= last)
//			return true;
//	for (int i = first; i < last; i++)
//		for (int j = i + 1; j <= last; j++)
//			if (A[i] == A[j])
//				return false;
//	return true;
//}
//
//bool isUnique3(A, first, last){
//Input: Array A, first, last
//Output :
//	true if the array contains no repeated elements
//		false if the array contains repeated elements
//		if (first >= last)
//			return true;
//	SORT(A, first, last);
//	for (int i = first; i < last; i++)
//		if (A[i] == A[i + 1])
//			return false;
//	return true;
//}


int main() {

	system("pause");
	return 0;
}