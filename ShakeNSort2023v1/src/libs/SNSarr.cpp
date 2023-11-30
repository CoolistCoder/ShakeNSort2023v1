/*
 * SNSarr.cpp
 *
 *  Created on: Nov 29, 2023
 *      Author: alec
 */

#include "SNSarr.h"

void SNSarr::insertionSort(){
	//perform a standard insertion sort on the stored array
	unsigned int cursor;
	for (unsigned int pos=1; pos<this->arrSize; ++pos){
		//The cursor is the point that the swap occurs
		//Update cursor to the position in the array
		cursor = pos;

		if (this->storedOrder == ORDER_GTL){ //Greater to Least
			while (cursor > 0 && this->arr[cursor-1] < this->arr[pos]){
				this->swp(&this->arr[cursor], &this->arr[cursor-1]);
				cursor = cursor - 1;
				//When the spot to the left of the cursor is greater than
				//the cursor's position, just swap the two elements and
				//move the cursor to the left by 1.  Repeat until
				//the element to the left is always less than the
				//element at the cursor's position.
			}
		}
		else{ //default behavior is least to greatest
			while (cursor > 0 && this->arr[cursor-1] > this->arr[pos]){
				this->swp(&this->arr[cursor], &this->arr[cursor-1]);
				cursor = cursor - 1;
			}
		}
	}
}

void SNSarr::bubbleSort(){
	//perform a standard bubble sort on the stored array
	while (this->sorted){
		this->sorted = true;
		for (unsigned int arr1=0; arr1<this->arrSize; ++arr1){
			for (unsigned int arr2=0; arr2<this->arrSize; ++arr2){
				if (this->storedOrder == ORDER_GTL){ //sort greatest to least
					if (this->arr[arr1] > this->arr[arr2]){
						this->swp(&this->arr[arr1], &this->arr[arr2]);
						this->sorted = false;
					}
				}//if
				else{ //default is to sort least to greatest
					if (this->arr[arr1] < this->arr[arr2]){
						this->swp(&this->arr[arr1], &this->arr[arr2]);
						this->sorted = false;
					}
				}//else
			}//for
		}//for
	}//while
	this->sorted = true; //reset the sorted flag
}//insertionSort

void SNSarr::cleanup(){
	//anything that uses the new keyword
	//must be cleaned up!!!
	if (this->arr)
		delete[] this->arr;
}

void SNSarr::swp(unsigned int* elem1, unsigned int* elem2){
	//use a simple arithmetic swap
	*elem2 = *elem1 + *elem2;
	*elem1 = *elem2 - *elem1;
	*elem2 = *elem2 - *elem1;
}

void SNSarr::addRandomElements(const unsigned int elems){
	//simply loop (elems) time and add random elements
	//as needed.
	//Reset random seed (note for new programmers:
	//If you use srand() in a loop, it'll update the
	//seed based on the clock.  This is not usually
	//desirable...
	srand(time(nullptr));
	//delete array first if present
	this->cleanup();
	//redefine array
	this->arr = new unsigned int[elems];
	//Now add random elements from 0 to 100
	for (unsigned int i=0; i<elems; ++i){
		*(this->arr+i) = rand()%100;
		//I like accessing arrays the "old school way"
		//to keep the practice alive.
		//Please note: This might not be desirable
		//in business applications.  This is to be used
		//if for some reason your compiler doesn't like
		//the []'s.
	}
	//if all went well, we can update the array size
	this->arrSize = elems;
}

void SNSarr::shuffleElements(unsigned int loopTimes){
	//loop through array (loopTimes) times and pick random
	//elements to swap.
	if (this->arr){
		for (unsigned int loopTimes=0; loopTimes<this->arrSize; ++loopTimes){
			this->swp(&(*(this->arr+(rand()%this->arrSize))),
				      &(*(this->arr+(rand()%this->arrSize))));
		}
		//This isnt fun to read, so here's the breakdown:
		/* Swap (Array element[x], Array element[y])
		 * Where x and y = random value
		 */
	}
}

void SNSarr::pickSortMethod(sortType stype){
	//Use a simple switch to determine the user's preference
	switch(stype){
	case (TYPE_INSERTSORT):
		this->storedStype = stype;
		break;
	case (TYPE_BUBBLESORT):
		this->storedStype = stype;
		break;
	default:
		//In the event that a type is not determined
		//correctly by the user, the default type is
		//set to TYPE_DEFAULT, which in this case
		//would be TYPE_INSERTSORT under a different
		//name.  This can be used for reporting errors.
		this->storedStype = TYPE_DEFAULT;
		break;
	}
}

void SNSarr::pickSortOrder(sortOrder otype){
	//use a simple switch to determine the user's preference
	switch(otype){
	case (ORDER_LTG):
		this->storedOrder = ORDER_LTG;
		break;
	case (ORDER_GTL):
		this->storedOrder = ORDER_GTL;
		break;
	default:
		//Not terribly keen on reporting a small error
		//Like the user's preference in least to greatest
		//or greatest to least, so just set the sort order
		//to LTG in case the input is wrong
		this->storedOrder = ORDER_LTG;
		break;
	}
}

void SNSarr::sort(){
	//use switch to determine what sort func to call
	switch(this->storedStype){
	case TYPE_INSERTSORT:
		this->insertionSort();
		break;

	case TYPE_BUBBLESORT:
		this->bubbleSort();
		break;

	default:	//default is insert sort
		this->insertionSort();
		break;
	}
}

void SNSarr::print(){
	//simply print each element in the array in a clean way
	for (unsigned int i=0; i<this->arrSize; ++i){
		std::cout << "The value of element " << i << " is " << this->arr[i] << std::endl;
	}
}

void SNSarr::printSimple(){
	//Simpler format for printing: {0: val0, 1: val1, etc}
	std::cout << "(POSITION: VALUE)" << std::endl;
	std::cout << "{" << std::endl;
	for (unsigned int i=0; i<this->arrSize; ++i){
		std::cout << "(" << i << ": " << this->arr[i] << ")" << std::endl;
	}
	std::cout << "}" << std::endl;
}

SNSarr::SNSarr() {
	// TODO Auto-generated constructor stub
	this->arr = nullptr; //needs to be set as nullptr
	this->sorted = true;
	this->arrSize = 0;
	this->storedStype = TYPE_DEFAULT;
	this->storedOrder = ORDER_LTG;
}

SNSarr::~SNSarr() {
	// TODO Auto-generated destructor stub
	this->cleanup();
}

