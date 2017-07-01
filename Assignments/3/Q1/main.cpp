#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include "BSTMap.h"

using namespace std;
int main(int argc, char const *argv[]) {

  // get filename if not passed as arg
	string filename= "";
	if(argc == 2){
		filename = argv[1];
	}else{
		cout << "Input filename: ";
		cin >> filename;
	}


//
//
//  NUMBER TO NAME
//
//
	// open file
	ifstream dataFile(filename);

	//error handle if file not found
	if(!dataFile){
		cout << "ERROR: Unable to open file \'" << filename << "\'!"  << endl;
		return 0;
	}

  BSTMap<int, string>* map = new BSTMap<int, string>;

  string s;
  bool completed;
  while(getline(dataFile, s)){
    istringstream iss(s);	// create string stream object
    string key;// for key
    string value;//for value
    int key_int;//for int of key
    //parse line for key and value
    getline(iss,value,' ');
    getline(iss,key,' ');
    istringstream(key) >> key_int; // convert to int

    completed = map->insert(key_int, value); // insert
    // check if valid insert
    if(completed)
      cout << "successfull added " << value << endl;
    else
      cout << "failed to add " << value << endl;

    }
    //Close File
  	dataFile.close();

    map->print();//print contents
    //do a search
    if(map->search(7857474))
      cout << "SEARCHING FOR VALUE OF '7857474'! ........... VALUE: " << *map->search(7857474) << endl;



  delete map;// deallocate map


  //
  //
  //  NAME TO NUMBER
  //
  //

  // open file
  ifstream dataFile2(filename);

  //error handle if file not found
  if(!dataFile2){
    cout << "ERROR: Unable to open file \'" << filename << "\'!"  << endl;
    return 0;
  }

  BSTMap<string, int>* map2 = new BSTMap<string, int>;

  string s2;
  bool completed2;
  while(getline(dataFile2, s2)){
    istringstream iss2(s2);	// create string stream object
    string key2;// for key
    string value2;//for value
    int value_int;// for value int
    // parse line to get key and value
    getline(iss2,key2,' ');
    getline(iss2,value2,' ');
    istringstream(value2) >> value_int;// convert value to int

    completed2 = map2->insert(key2, value_int);// insert
    //check for valid insert
    if(completed2)
      cout << "successfull added " << value2 << endl;
    else
      cout << "failed to add " << value2 << endl;

    }
    //Close File
    dataFile2.close();

    map2->print();//print map2

    //search for value
    if(map2->search("Moira_Cooper"))
      cout << "SEARCHING FOR VALUE OF 'Moira_Cooper'! ........... VALUE: " << *map2->search("Moira_Cooper") << endl;



  delete map2;//deallocate map2




  return 0;
}
