#include <fstream>
#include <iostream>
#include <string>
#include <sstream>

#include "header.h"

using namespace std;

int main(int argc,char *argv[]){
	string filename= "";
	if(argc == 2){
		filename = argv[1];
	}else{
		cout << "Input filename: ";
		cin >> filename;
	}

	ifstream dataFile(filename);

	if(!dataFile){
		cout << "ERROR: Unable to open file \'" << filename << "\'!"  << endl;
		return 0;
	}

	string s;
	int x = 0;
	getline(dataFile, s);
	istringstream(s)>> x;
	Col arr[x];

	for(int i=0; getline(dataFile, s) && i<x; i++){

		int length = getLengthRequired(s);
		cout << "Lenght: " << length << endl;
		int data[length];
		bool result = parse_data(s,data);
		Col input_data;
		input_data.size = length;
		fillArray(input_data.data, data);
		arr[i] = input_data;

		cout << "DATA: " << endl;
		for(int x=0; x<(sizeof(data)/sizeof(data[0])); x++){
				cout << data[x] << endl;
		}
	}



/*
	while(getline(dataFile, s)){
		if(i == 1){
			int data[s];
		}
		cout << s << endl;
	}
*/
	dataFile.close();

	return 0;
}
