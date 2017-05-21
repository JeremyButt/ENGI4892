#include <fstream>
#include <iostream>
#include <string>
#include <sstream>
using namespace std;

int main ( int argc, char *argv[] )
{
  istringstream iss("4 3 2 1");
  string s;
  int array[4];
  int i=0;
  int numb = 0;
  while ( getline( iss, s, ' ' ) ) {

    //cout << s << endl;
    istringstream(s) >> numb;
    //cout << numb << endl;
    array[i] = numb;
    i++;
  }

  for(int x=0; x<(sizeof(array)/sizeof(array[0])); x++){
      cout << array[x] << endl;
  }

}
