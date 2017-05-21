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
		int data[length];
		bool result = parse_data(s,data,length);

		Col input_data;
		input_data.size = length;
		input_data.data = fillArray(data,length);
		input_data.max = maximum(input_data.data, input_data.size);
		input_data.min = minimum(input_data.data, input_data.size);
		input_data.avg = average(input_data.data, input_data.size);

		arr[i] = input_data;

	}

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
	}



	dataFile.close();

	return 0;
}
