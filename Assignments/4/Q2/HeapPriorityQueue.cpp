#include <vector>
#include <iostream>
#include <sstream>
#include <fstream>
#include "HeapPriorityQueue.h"

using namespace std;


// Adds the key/value pair to the internal heap
// precond: valid HeapPriorityQueue
//postcond: HeapPriorityQueue with new element in correct sorted location
template<class K, class V>
void HeapPriorityQueue<K,V>::enqueue(const K& key, const V& value) {
  PQEntry temp = PQEntry(key, value); // create temp PQEntry to place in vector
  heap.push_back(temp); // push into vector
  trickleUp(heap.size()-1); // trickleup to fill and balance the heap
}

// Removes the best key from the heap and returns associated value
// precond: valid HeapPriorityQueue
//postcond: HeapPriorityQueue with root element removed and all elements in correct sorted locations
template<class K, class V>
V HeapPriorityQueue<K,V>::dequeue() {
  PQEntry temp = heap.at(0);// place the PQEntry being removed into temp var to return value later
  //case one - more than 3 or more elements
  if(heap.size() > 2){
    heap.erase(heap.begin());//erase element 0
    heap.insert(heap.begin(), heap[heap.size()-1]); // copy last element to begining
    heap.pop_back();// delete last element
    trickleDown(0); // rebalance
  // case two - 2 elements
  }else if(heap.size() > 1){
    heap.erase(heap.begin()); //remove top element (last is now first by elimination)
  //case three - 1 element
  }else if(heap.size() == 1){
    heap.pop_back();  // remove last element
  }
  return temp.value; // return the value of the temp value from before
}

// Test for empty
// precond: valid HeapPriorityQueue
//postcond: HeapPriorityQueue is empty or not ?
template<class K, class V>
bool HeapPriorityQueue<K,V>::isEmpty() const {
  return heap.empty(); // return the bool from vector empty method
}

// Prints contents of queue (key/value pairs) using level-order traversal
// precond: valid HeapPriorityQueue
//postcond:  prints all HeapPriorityQueue elements in correct sorted order
template<class K, class V>
void HeapPriorityQueue<K,V>::print() const {
  cout << "KEY " << " | " << " VALUE " << endl;
  cout << "---------------------------" << endl;
  //for every element in heap, cout
  for (auto const temp : heap){
    cout << temp.key << " | " << temp.value << endl;
  }
}


// Auxiliary methods to re-heapify the heap
// precond: valid HeapPriorityQueue
//postcond:  puts elements in correct sorted order starting from last element going to root
template<class K, class V>
void HeapPriorityQueue<K,V>::trickleUp(int idx){
  int parent = (idx-1) / 2; // get parent index
  //if not beond element 0 and idx greater than parent
  if (idx >= 0 && heap[idx].key > heap[parent].key){
    //swap PQentrys
    PQEntry temp = heap[idx];
    heap[idx] = heap[parent];
    heap[parent] = temp;
    trickleUp(parent); // preform recursive call on trickleUp to continue trickling until root it hit
  }
}

// precond: valid HeapPriorityQueue
//postcond:  puts elements in correct sorted order starting from root going to last element
template<class K, class V>
void HeapPriorityQueue<K,V>::trickleDown(int idx){
  int child1 = (idx*2) + 1;// get child 1 index
  int child2 = (idx*2) + 2;//get child 2 index
  // if not beond the last element and the idx < child1
  if (idx < heap.size() && heap[idx].key < heap[child1].key){
    //swap child and parent
    PQEntry temp = heap[idx];
    heap[idx] = heap[child1];
    heap[child1] = temp;
    trickleDown(child1); // preform recursive call on trickleDown to continue trickling until last elemente hit
  // else if not beond the last element and the idx < child2
  }else if (idx < heap.size() && heap[idx].key < heap[child2].key){
    //swap child and parent
    PQEntry temp = heap[idx];
    heap[idx] = heap[child2];
    heap[child2] = temp;
    trickleDown(child2); // preform recursive call on trickleDown to continue trickling until last elemente hit
  }
}



int main(int argc, char const *argv[]) {
  HeapPriorityQueue<int, string> PQ1 = HeapPriorityQueue<int, string>();

  string filename = "tickets.txt";

  cout << "LOADING Tickets into PQ1" << endl;
  // open file
	ifstream dataFile1(filename);

	//error handle if file not found
	if(!dataFile1){
		cout << "ERROR: Unable to open file \'" << filename << "\'!"  << endl;
		return 0;
	}

  string s;

  while(getline(dataFile1, s)){
    istringstream iss(s);	// create string stream object

    string key;// for key
    string value;//for value
    int key_int;//for int of key
    //parse line for key and value
    getline(iss,key,' ');
    getline(iss,value,' ');

    istringstream(key) >> key_int; // convert to int

    PQ1.enqueue(key_int, value); // insert
    PQ1.print();
  }

    //Close File
  	dataFile1.close();


    cout << "REMOVED: " << PQ1.dequeue() << endl; //remove biggest ticket
    PQ1.print(); // print out HeapPriorityQueue
    cout << "REMOVED: " << PQ1.dequeue() << endl; //remove biggest ticket
    PQ1.print(); // print out HeapPriorityQueue
    cout << "REMOVED: " << PQ1.dequeue() << endl; //remove biggest ticket
    PQ1.print(); // print out HeapPriorityQueue
    cout << "REMOVED: " << PQ1.dequeue() << endl; //remove biggest ticket
    PQ1.print(); // print out HeapPriorityQueue
    cout << "REMOVED: " << PQ1.dequeue() << endl; //remove biggest ticket
    PQ1.print(); // print out HeapPriorityQueue


  return 0;
}
