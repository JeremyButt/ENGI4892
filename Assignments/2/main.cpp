#include <iostream>
#include "Node.h"
#include "SortedBags.h"



using namespace std;


int main(int argc, char const *argv[]) {

  SortedBags<int> bag;
  bag.insert(2);

  cout << "*********************************" <<
  endl << " This is after adding 2 " << endl;
  cout << endl << "*********************************" << endl;

  bag.display();

  cout <<  endl << "*********************************" << endl;

  bag.insert(3);

  cout << "*********************************" <<
  endl << " This is after adding 3 " << endl;
  cout << endl << "*********************************" << endl;

  bag.display();

  cout << endl << "*********************************" << endl;

  bag.insert(2);

  cout << "*********************************" <<
  endl << " This is after adding 2nd 2 " << endl;
  cout << endl << "*********************************" << endl;

  bag.display();

  cout << endl << "*********************************" << endl;

  bag.insert(5);

  cout << "*********************************" <<
  endl << " This is after adding 5 " << endl;
  cout << endl << "*********************************" << endl;

  bag.display();

  cout << endl << "*********************************" << endl;

  bag.insert(6);

  cout << "*********************************" <<
  endl << " This is after adding 6 " << endl;
  cout << endl << "*********************************" << endl;

  bag.display();

  cout << endl << "*********************************" << endl;

  bag.insert(4);

  cout << "*********************************" <<
  endl << " This is after adding 4 " << endl;
  cout << endl << "*********************************" << endl;

  bag.display();

  cout << endl << "*********************************" << endl;

  return 0;
}
