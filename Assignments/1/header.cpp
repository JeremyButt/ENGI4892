//header.cpp
#include <fstream>
#include <iostream>
#include <string>
#include <sstream>
#include "header.h"
using namespace std;


int* fillArray(int data_input[], int size){
	int* data = new int[size];
	for(int i = 0; i<(size); i++){
		data[i] = data_input[i];
	}
	return data;
}

bool parse_data(string s, int data[], int size){

	istringstream iss(s);
  string str;
  int numb = 0;
	getline(iss,str,' ');
  for(int i=0; getline(iss,str,' ') && i<size; i++){

    istringstream(str) >> numb;
    data[i] = numb;
  }

	return true;
}

int getLengthRequired(string s){
	istringstream iss(s);
	string s_length;
	int i_length;
	getline( iss, s_length, ' ' );
	istringstream(s_length) >> i_length;
	return i_length;
}

int minimum(int* data, int size){
	int answer = data[0];
	for(int i=0; i<size; i++){
		if(data[i]<answer){
			answer = data[i];
		}
	}
	return answer;
}
int maximum(int* data, int size){
	int answer = data[0];
	for(int i=0; i<size; i++){
		if(data[i]>answer){
			answer = data[i];
		}
	}
	return answer;
}
double average(int* data, int size){
	int answer = 0;
	for(int i=0; i<size; i++){
		answer+=data[i];
	}
	return answer/size;
}
