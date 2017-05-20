#include <fstream>
#include <iostream>
#include <string>

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
	int i = 1;
	while(getline(dataFile, s)){
		if(i == 1){
			int data[s];		
		}
		cout << s << endl;
	}

	dataFile.close(); 

	return 0;
}
