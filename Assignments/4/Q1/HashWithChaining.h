#ifndef __HASH_WITH_CHAINING_
#define __HASH_WITH_CHAINING_

#include <vector>
#include "HashTable.h"

/**
 * This class uses separate chaining as described in class, but instead
 * of using linked lists, it uses vectors.
 * The idea and complexity is the same, but you're probably more accustomed
 * to using vectors vs. linked lists.
 */

template<class K, class V>
class HashWithChaining : public HashTable<K,V>
{
  public:
    // c'tor (initializes hashcode lambda function and size)
    HashWithChaining(std::function<int(K)> hc) : hashcode(hc), size(0) { }

    // Add key/value pair to the hashtable by using 'key' to determine
    // the index for initial placement.
    // pre-condition:  a valid hashtable
    // post-condition: 'value' is added at position determined by 'key'
    bool insert(const K& key, const V& value) override
    {
      int loc = hashcode(key)%capacity; // get loc from key

      if(data[loc].empty()){
        size++; // if empty then new location in array being used
      }

      this->keys_examined++;// inc keys examined
      HTEntry temp = HTEntry(key, value);// new temp entry

      data[loc].push_back(temp);  // puch temp into vector


      return true;
    }

    // pre-condition:  a valid hashtable
    // post-condition: the value associated with 'key', else nullptr
    const V* find(const K& key) override
    {
      int loc = hashcode(key)%capacity;
      if(data[loc].empty()){
        return 0; // if vectpr at location is empty then no value found
      }
      else{
        for(auto const& temp : data[loc]){  // for all in vector comare to see if that is key/ value pair
          this->keys_examined++;// inc keys examined
          if(temp.key == key)
            return &temp.value; //return address to the value
        }
        return 0;
      }
    }

    // pre-condition:  a valid hashtable
    // post-condition: return the load factor; hashtable is not modified
    float loadFactor() const override
    {
      return size/capacity; // return the load factor
    }

    // pre-condition:  a valid hashtable
    // post-condition: return total keys examined so far;
    //                 hashtable is not modified
    int totalKeysExamined() const override
    {
      return keys_examined; //return most recent key examined count
    }

    // pre-condition:  a valid hashtable
    // post-condition: hashtable is not modified
    void print() const override
    {
      cout << "KEY" << " | " << "Value" << endl;
      cout << "______________________________________" << endl;
      //for all in array
      for(int i = 0; i < capacity; i++){
        //if not emplty
        if(!data[i].empty()){
          for(auto const& temp : data[i]){ // for every entry in vector
            cout << temp.key << " | " << temp.value << endl;  // cout the key and value
          }
        }
      }
    }

  private:
    static constexpr int capacity = 211;
    std::function<int(K)> hashcode;
    int keys_examined = 0;

    // Contains key/value pairs for the hashtable
    struct HTEntry {
      K key;
      V value;

      HTEntry(const K& k = K(), const V& v = V()) : key(k), value(v) { }
    };

    // A bucket array of vectors (each vector contains type 'HTEntry')
    vector<HTEntry> data[capacity];
    int size;
};

#endif
