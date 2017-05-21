// Header.h
#include <fstream>
#include <iostream>
#include <string>
#include <sstream>
using namespace std;

struct Col;

void fillArray(int **data, int data_input[]);
bool parse_data(string s, int data[]);
int getLengthRequired(string s);
