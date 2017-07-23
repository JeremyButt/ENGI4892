#include "HashWithChaining.h"
#include "HashWithQuadratic.h"
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
using namespace std;


int main(int ac, char* av[])
{
  // Key is an integer for student ID
  // Value is a string representing the students' entire name

  // Create a lamdba function that takes an int (the key) and returns
  // an int by taking every even-positioned digit in the key and
  // concatenating it to form the hash code, ie:
  //   key  = 123456789
  //   code = 13579
  std::function<int(int)> concatEven = [](int key){
    int hash_key = 0;
    int num = 0;
    // get length of key
    int length = 1;
    int x = key;
    while ( x /= 10 )
      length++;

    num = key % 10;
    hash_key += num;

    int factor = 100;
    int build_factor = 10;
    for(int i = 0; length > i; i++){
      num = (key/factor) % 10;
      hash_key += (num*(build_factor));
      factor *= 100;
      build_factor *= 10;
    }

    return hash_key;
  };

  // Create a lamdba function that takes an int (the key) and returns
  // an int by taking every even-positioned digit in the key and
  // concatenating it to form the hash code, ie:
  //   key  = 123456789
  //   code = 2468
  std::function<int(int)> concatOdd = [](int key){
    int hash_key = 0;
    int num = 0;
    // get length of key
    int length = 1;
    int x = key;
    while ( x /= 10 )
      length++;

    num = (key/10) % 10;
    hash_key += num;

    int factor = 1000;
    int build_factor = 10;
    for(int i = 0; length > i; i++){
      num = (key/factor) % 10;
      hash_key += (num*(build_factor));
      factor *= 100;
      build_factor *= 10;
    }

    return hash_key;
  };

  // concat even digits, chaining
  HashWithChaining<int,string> h1(concatEven);

  // concat even digits, quadratic probing
  HashWithQuadratic<int,string> h2(concatEven);

  // concat odd digits, chaining
  HashWithChaining<int,string> h3(concatOdd);

  // concat odd digits, quadratic probing
  HashWithQuadratic<int,string> h4(concatOdd);

  // Read data from input file, and do inserts's and find's,
  // and gather statistics ...
  // FIXME

  string filename = "students.txt";

  cout << "LOADING H1" << endl;
  // open file
	ifstream dataFile1(filename);

	//error handle if file not found
	if(!dataFile1){
		cout << "ERROR: Unable to open file \'" << filename << "\'!"  << endl;
		return 0;
	}

  string s;
  bool completed;

  while(getline(dataFile1, s)){
    istringstream iss(s);	// create string stream object

    string key;// for key
    string value;//for value
    int key_int;//for int of key
    //parse line for key and value
    getline(iss,key,' ');
    getline(iss,value,' ');

    istringstream(key) >> key_int; // convert to int

    completed = h1.insert(key_int, value); // insert
    cout << "Total Keys Examined:" << h1.totalKeysExamined() << endl;

    // check if valid insert
    if(completed)
      cout << "Successfull added " << value << endl;
    else
      cout << "Failed to add " << value << endl;

    }
    //Close File
  	dataFile1.close();




cout << "LOADING H2" << endl;

    // open file
  	ifstream dataFile2(filename);

  	//error handle if file not found
  	if(!dataFile2){
  		cout << "ERROR: Unable to open file \'" << filename << "\'!"  << endl;
  		return 0;
  	}

    while(getline(dataFile2, s)){
      istringstream iss(s);	// create string stream object
      string key;// for key
      string value;//for value
      int key_int;//for int of key
      //parse line for key and value
      getline(iss,key,' ');
      getline(iss,value,' ');
      istringstream(key) >> key_int; // convert to int

      completed = h2.insert(key_int, value); // insert
      cout << "Total Keys Examined:" << h2.totalKeysExamined() << endl;
      // check if valid insert
      if(completed)
        cout << "Successfull added " << value << endl;
      else
        cout << "Failed to add " << value << endl;

      }
      //Close File
    	dataFile2.close();



cout << "LOADING H3" << endl;

      // open file
    	ifstream dataFile3(filename);

    	//error handle if file not found
    	if(!dataFile3){
    		cout << "ERROR: Unable to open file \'" << filename << "\'!"  << endl;
    		return 0;
    	}


      while(getline(dataFile3, s)){
        istringstream iss(s);	// create string stream object
        string key;// for key
        string value;//for value
        int key_int;//for int of key
        //parse line for key and value
        getline(iss,key,' ');
        getline(iss,value,' ');
        istringstream(key) >> key_int; // convert to int

        completed = h3.insert(key_int, value); // insert
        cout << "Total Keys Examined:" << h3.totalKeysExamined() << endl;
        // check if valid insert
        if(completed)
          cout << "Successfull added " << value << endl;
        else
          cout << "Failed to add " << value << endl;

        }
        //Close File
      	dataFile3.close();

cout << "LOADING H4" << endl;
        // open file
      	ifstream dataFile4(filename);

      	//error handle if file not found
      	if(!dataFile4){
      		cout << "ERROR: Unable to open file \'" << filename << "\'!"  << endl;
      		return 0;
      	}


        while(getline(dataFile4, s)){
          istringstream iss(s);	// create string stream object
          string key;// for key
          string value;//for value
          int key_int;//for int of key
          //parse line for key and value
          getline(iss,key,' ');
          getline(iss,value,' ');
          istringstream(key) >> key_int; // convert to int

          completed = h4.insert(key_int, value); // insert
          cout << "Total Keys Examined:" << h4.totalKeysExamined() << endl;
          // check if valid insert
          if(completed)
            cout << "Successfull added " << value << endl;
          else
            cout << "Failed to add " << value << endl;

          }
          //Close File
        	dataFile4.close();

          cout << "PRINTING H1" << endl;
          h1.print();//print h1
          cout << "PRINTING H2" << endl;
          h2.print();//print h2
          cout << "PRINTING H3" << endl;
          h3.print();//print h3
          cout << "PRINTING H4" << endl;
          h4.print();//print h4

          // get a key to search for
          int key_to_find = 0 ;
          cout << "Key to find: " ;
          cin >> key_to_find;

          //search and output from h1
          if(h1.find(key_to_find))
            cout << "[H1] Key 200093421 matches " << *h1.find(key_to_find) << endl;
            cout << "Total Keys Examined:" << h1.totalKeysExamined() << endl; // output the total key examined count

            //search and output from h1
          if(h2.find(key_to_find))
            cout << "[H2] Key 200093421 matches " << *h2.find(key_to_find) << endl;
            cout << "Total Keys Examined:" << h2.totalKeysExamined() << endl;// output the total key examined count
            //search and output from h1
          if(h3.find(key_to_find))
            cout << "[H3] Key 200093421 matches " << *h3.find(key_to_find) << endl;
            cout << "Total Keys Examined:" << h3.totalKeysExamined() << endl;// output the total key examined count
            //search and output from h1
          if(h4.find(key_to_find))
            cout << "[H4] Key 200093421 matches " << *h4.find(key_to_find) << endl;
            cout << "Total Keys Examined:" << h4.totalKeysExamined() << endl;// output the total key examined count

}
