//header.cpp
#include <fstream>
#include <iostream>
#include <string>
#include <sstream>
#include "header.h"
using namespace std;


struct Col {
	int **data = new int*[];
	int size = 0;
	int min = 0;
	int max = 0;
};

void fillArray(int **data, int data_input[]){
	for(int i = 0; i<(sizeof(data_input)/sizeof(data_input[0])); i++){
		data[i] = data_input[i];
	}
}

bool parse_data(string s, int data[]){
	istringstream iss(s);
  string str;
  int i=0;
  int numb = 0;
	getline(iss,str,' ');
  while(getline(iss,str,' ')){

    istringstream(str) >> numb;
		//cout << numb << endl;
    data[i] = numb;
    i++;
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
