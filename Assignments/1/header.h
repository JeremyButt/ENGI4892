// Header.h
#include <fstream>
#include <iostream>
#include <string>
#include <sstream>
using namespace std;

//Struct Col
// To store various data about the columns within the row array
struct Col {
	int* data = nullptr;	//the ints that are within the row
	int size = 0;	// Size of the data array
	int min = 0;	// min value to be calculated using the minimum() function
	int max = 0;	// max value to be calculated using the maximum() function
  int avg = 0;	// avg value to be calculated using the average() function
};

// pre-condition: int array input_data which has all data to be put into the struct Col data array, and int size the size of the array.
// post-condition: returns an array to be put in the struct Col.
int* fillArray(int data_input[], int size);

// pre-condition: string s that is only numbers separated by a single space, int array data that is
// 		an empty array to return the numbers parsed from the string, and int size the size of the array.
// post-condition: Returns true on a successful parse.
bool parse_data(string s, int data[], int size);

// pre-condition: string that is only numbers separated by a single space.
// post-condition: Finds the first number in the string and converts it to an int to be returned.
int getLengthRequired(string s);

// pre-condition: Pointer to an array of ‘n’ integers
// post-condition: Calculates the minimum element in the array (array is unchanged) … minimum( … )
int minimum(int* data, int size);

// pre-condition: Pointer to an array of ‘n’ integers
// post-condition: Calculates the maximum element in the array (array is unchanged) … maximum ( … )
int maximum(int* data, int size);

// pre-condition: Pointer to an array of ‘n’ integers
// post-condition: Calculates the average of the elements in the array (array is unchanged) … average ( … )
double average(int* data, int size);

void deallocate(int* data[], int size);
