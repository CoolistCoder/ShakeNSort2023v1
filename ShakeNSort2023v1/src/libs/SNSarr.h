/*
 * SNSarr.h
 *
 *  Created on: Nov 29, 2023
 *      Author: alec
 */

#ifndef LIBS_SNSARR_H_
#define LIBS_SNSARR_H_
#include <iostream>
#include <random>

//allows user to choose what sort they want
typedef enum sortType{
	TYPE_INSERTSORT,
	TYPE_BUBBLESORT,
	TYPE_DEFAULT //insert sort
}sortType;

//allows the user to choose the order of the sort
typedef enum sortOrder{
	ORDER_LTG,	//least to greatest (default)
	ORDER_GTL	//greatest to least
}sortOrder;

class SNSarr {
private:
	unsigned int* arr; //array of variable size
	unsigned int arrSize; //array's stored size
	sortType storedStype;
	sortOrder storedOrder;

	//variables/functions for insertion sort
	bool sorted;
	//insertionSort()
	//Private function for insertion sorting an array
	//of unsigned ints.
	void insertionSort();

	//bubbleSort()
	//Private function for bubble sorting an array
	//of unsigned ints
	void bubbleSort();

	//functions for cleanup
	void cleanup();

	//Additional functions
	//swp(unsigned int, unsigned int)
	//Swaps two elements in an unsigned int array
	//NOTE: THIS METHOD OF SWAP ONLY WORKS WITH THIS KIND OF ARR
	void swp(unsigned int* elem1, unsigned int* elem2);
public:

	//addRandomElements(unsigned int)
	//Adds a quantity of elements to the private arr array.
	//Quantity of elements specified by the unsigned int.
	void addRandomElements(const unsigned int);

	//shuffleElements()
	//Shuffles around all elements of the stored array
	void shuffleElements(unsigned int);

	//pickSortMethod(sortType)
	//Allows user to define what sort they want to use
	//Default is insertion sort
	void pickSortMethod(sortType);

	//pickSortOrder(sortOrder)
	//Allows user to define what sort order they want to use
	//Default is least to greatest
	void pickSortOrder(sortOrder);

	//sort()
	//Sorts the array based on defined sort method
	void sort();

	//print()
	//prints the array out in the terminal
	void print();

	//printSimple()
	//prints the array out in a simpler format
	void printSimple();

	SNSarr();
	virtual ~SNSarr();
};

#endif /* LIBS_SNSARR_H_ */
