// Header.h
#include <fstream>
#include <iostream>
#include <string>
#include <sstream>
using namespace std;


struct Col {
	int* data = nullptr;
	int size = 0;
	int min = 0;
	int max = 0;
  int avg = 0;
};

int* fillArray(int data_input[], int size);
bool parse_data(string s, int data[], int size);
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
