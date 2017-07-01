/****************************************************
*  ASSIGNMENT #2
*   Main.h
*    Location for Main of the SortedBag program
*
*
*   Author: Jeremy Butt (201527710)
*           jeremybutt@mun.ca
****************************************************/


#include <iostream>
#include "Node.h"
#include "SortedBags.h"



using namespace std;


int main(int argc, char const *argv[]) {

  SortedBags<int> bag;  // new sorted bag object
  int array[5] = {3,1,5,1,4}; // array of data to put in bag /list
  for(int i=0; i<5; i++){
    bag.insert(array[i]); //insert data in sorted manner
  }
  bag.display();  //display content
  cout << endl << endl;
  bag.RM_spec(1); //remove one entry
  bag.display();//display conten t
  cout << endl << endl;
  bag.insert(5);//insert data in sorted manner
  bag.insert(5);//insert data in sorted manner
  bag.insert(5);//insert data in sorted manner
  bag.insert(5);//insert data in sorted manner
  bag.insert(5);//insert data in sorted manner
  bag.insert(5);//insert data in sorted manner
  bag.display();//display content
  cout << endl << endl;
  bag.RM_all(5);//remove all entries
  bag.display();//display content
  cout << endl << endl;

  return 0;
}
