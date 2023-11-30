/* Background: Every once in a while, I like to see how long it takes
 * for me to code a simple program that sorts an array.  shakeNSort
 * is a simple program that creates a jumbled array, then sorts
 * the jumbled array.
 *
 * Project created NOV 29, 2023 at 3:22.
 * Project started NOV 29, 2023 at 3:23.
 * Project paused NOV 29, 2023 at 4:05 (food)
 * Project restarted NOV 29, 2023 at 4:14
 * Project paused NOV 29, 2023 at 4:38 (sleep)
 * Project restarted NOV 29, 2023 at 18:09
 * Project paused NOV 29, 2023 at 19:50 (groceries)
 * Project restarted NOV 29, 2023 at 21:19
 * Project finished NOV 29, 21:40 (v1.0)
 *
 * Written by Alec
 *
 */
#include "libs/SNSarr.h"
#include <iostream>
using namespace std;

int main() {
	//Create a new array, then add random elements to it
	SNSarr newarr;
	cout << "Adding random elements to array: " << endl;
	newarr.addRandomElements(25);
	cout << "Elements added." << endl;

	//print out the array so we know the elements are random
	cout << "Printing array:" << endl;
	newarr.printSimple();

	//Sort the array from least to greatest using insertion
	//sort and print
	cout << "Sorting array with insertion sort (LTG):" << endl;
	newarr.pickSortMethod(TYPE_INSERTSORT);
	newarr.pickSortOrder(ORDER_LTG);
	newarr.sort();
	cout << "Array sorted." << endl;
	cout << "Printing array:" << endl;
	newarr.printSimple();

	//Shuffle the array around (10,000 iterations)
	//Print the array after shuffling
	cout << "Shuffling array:" << endl;
	newarr.shuffleElements(10000);
	cout << "Array shuffled." << endl;
	cout << "Printing array:" << endl;
	newarr.printSimple();

	//Sort array from greatest to least and print it
	cout << "Sorting array with insertion sort (GTL): " << endl;
	newarr.pickSortOrder(ORDER_GTL);
	newarr.sort();
	cout << "Array sorted." << endl;
	cout << "Printing array:" << endl;
	newarr.printSimple();


	//reuse the existing array for bubble sorting
	cout << "Adding random elements to array: " << endl;
	newarr.addRandomElements(10);
	cout << "Elements added." << endl;

	//print out the array so we know the elements are random
	cout << "Printing array:" << endl;
	newarr.printSimple();

	//Sort the array using bubble sort and print
	cout << "Sorting array with bubble sort (LTG):" << endl;
	newarr.pickSortMethod(TYPE_BUBBLESORT);
	newarr.pickSortOrder(ORDER_LTG);
	newarr.sort();
	cout << "Array sorted." << endl;
	cout << "Printing array:" << endl;
	newarr.printSimple();

	//Shuffle the array around (10,000 iterations)
	//Print the array after shuffling
	cout << "Shuffling array:" << endl;
	newarr.shuffleElements(10000);
	cout << "Array shuffled." << endl;
	cout << "Printing array:" << endl;
	newarr.printSimple();

	//Sort array from greatest to least and print it
	cout << "Sorting array greatest to least: " << endl;
	newarr.pickSortOrder(ORDER_GTL);
	newarr.sort();
	cout << "Array sorted." << endl;
	cout << "Printing array:" << endl;
	newarr.printSimple();

	cout << "End of program, have a nice day." << endl;
	return 0;
}
