//main.cpp
//Author: Jeremy Butt
//				jeremybutt@mun.ca
//				201527710

#include <fstream>
#include <iostream>
#include <string>
#include <sstream>

#include "header.h"

using namespace std;

int main(int argc,char *argv[]){

	// get filename if not passed as arg
	string filename= "";
	if(argc == 2){
		filename = argv[1];
	}else{
		cout << "Input filename: ";
		cin >> filename;
	}

	// open file
	ifstream dataFile(filename);

	//error handle if file not found
	if(!dataFile){
		cout << "ERROR: Unable to open file \'" << filename << "\'!"  << endl;
		return 0;
	}

	string s;
	int x = 0;
	getline(dataFile, s); //get first line to find row array length
	istringstream(s)>> x; // convert to int
	Col arr[x];	// create array of Col structs

	//loop for every line in the file
	for(int i=0; getline(dataFile, s) && i<x; i++){

		int length = getLengthRequired(s);	// get the length require for the data array
		int data[length];	// create middle man data array
		bool result = parse_data(s,data,length);	// parse rest of string to find the remaining numbers to be put in array

		//creat and fill struct
		Col input_data;
		input_data.size = length;
		input_data.data = fillArray(data,length);
		input_data.max = maximum(input_data.data, input_data.size);
		input_data.min = minimum(input_data.data, input_data.size);
		input_data.avg = average(input_data.data, input_data.size);

		//place struct Col into row array
		arr[i] = input_data;

	}

	//PRINT OUT DATA
	for(int n=0; n<(sizeof(arr)/sizeof(arr[0])); n++){
		cout << "Row #" << n+1 << ": (size: " << arr[n].size << ") [";
		for(int j=0; j<arr[n].size; j++){
			if(j==arr[n].size-1){
				cout << arr[n].data[j] << "";
			}else{
				cout << arr[n].data[j] << " ";
			}
		}
		cout << "] Min: " << minimum(arr[n].data, arr[n].size) << " Max: "  << maximum(arr[n].data, arr[n].size) << " Avg: " << average(arr[n].data, arr[n].size) << endl;
		//Deallocate and zero out heap allocated memory locations.
		delete[] arr[n].data;
		arr[n].data = nullptr;
	}


	//Close File
	dataFile.close();

	return 0;
}
