#include <fstream>
#include <iostream>
#include <string>
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
		cout << "ERROR: Unable to open file! " << endl;
		return 0; 
	}
	
	string s;
	while(getline(dataFile, s)){
		cout << s << endl;
	}

	dataFile.close(); 

	return 0;
}
