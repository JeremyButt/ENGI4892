//header.cpp
#include <fstream>
#include <iostream>
#include <string>
#include <sstream>
#include "header.h"
using namespace std;


int* fillArray(int data_input[], int size){
	int* data = new int[size];	//new allocated mem for array
	for(int i = 0; i<(size); i++){
		data[i] = data_input[i];	// push data_input into newly allocated array
	}
	return data;
}

bool parse_data(string s, int data[], int size){
	istringstream iss(s);	// create string stream object
  string str;
  int numb = 0;
	getline(iss,str,' '); // Find first number to ignore
	//loop through string finding all elements separated by a space
  for(int i=0; getline(iss,str,' ') && i<size; i++){
    istringstream(str) >> numb; //convert string to int
    data[i] = numb;	// store int in data array
  }
	return true;
}

int getLengthRequired(string s){
	istringstream iss(s);	// create string stream object
	string s_length;
	int i_length;
	getline( iss, s_length, ' ' ); // Find first number
	istringstream(s_length) >> i_length; //convert string to int
	return i_length;
}

int minimum(int* data, int size){
	int answer = data[0];	//set 0th element to smallest
	// Loop through array
	for(int i=0; i<size; i++){
		//if current element is smaller than the current answer
		if(data[i]<answer){
			answer = data[i];	// set the current element to the answer
		}
	}
	return answer;
}

int maximum(int* data, int size){
	int answer = data[0];	//set 0th element to largest
	// Loop through array
	for(int i=0; i<size; i++){
		//if current element is larger than the current answer
		if(data[i]>answer){
			answer = data[i];	// set the current element to the answer
		}
	}
	return answer;
}

double average(int* data, int size){
	int answer = 0;
	for(int i=0; i<size; i++){
		answer+=data[i];	// sum all ints in data array
	}
	return answer/size;	//return average
}
