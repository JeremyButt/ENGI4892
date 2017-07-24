#ifndef __HASH_WITH_QUADRATIC_
#define __HASH_WITH_QUADRATIC_

#include "HashTable.h"

/**
 * This class uses open-addressing, specifically quadratic probing to
 * resolve collisions.
 */

template<class K, class V>
class HashWithQuadratic : public HashTable<K,V>
{
  public:
    HashWithQuadratic<K,V>(std::function<int(K)> hc)
      : hashcode(hc), size(0) {
        //init array to null ptr
        for(int i = 0; i < capacity; i++){
          data[i] = nullptr;
        }
      }

    // Add key/value pair to the hashtable by using 'key' to determine
    // the index for initial placement.
    // pre-condition:  a valid hashtable
    // post-condition: 'value' is added at position determined by 'key'
    bool insert(const K& key, const V& value) override
    {
      if(size == capacity){
        return false;// return false if the array is full 
      }
      int loc = hashcode(key)%capacity; // get loc index

      // for the quad steps and while data is not null
      for(int step = 1; data[loc] != nullptr; step++){
        this->keys_examined++; // inc keys examined
        loc = (loc + (step * step - step) / 2) % capacity; // update loc if the data is not null using the quadratic probeing
      }
      this->keys_examined++; // inc keys examined
      HTEntry* temp = new HTEntry(key, value);  // new temp ht entry
      data[loc] = temp; // input temp into array
      size++; // inc size

      return true;
    }

    // pre-condition:  a valid hashtable
    // post-condition: the value associated with 'key', else nullptr
    const V* find(const K& key) override
    {
      int loc = hashcode(key)%capacity;// get loc from key

      // for the quad steps and while data is not null
      for(int step = 1;  data[loc] != nullptr; step++){
        this->keys_examined++;// inc keys examined
        if(data[loc]->key == key){
          return &data[loc]->value; // when found return
        }
        loc = (loc + (step * step - step) / 2) % capacity;// update loc if the data is not null using the quadratic probeing
      }
      return 0; // hit null then not found
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
      return keys_examined; // retunr the current key examined count
    }

    // pre-condition:  a valid hashtable
    // post-condition: hashtable is not modified
    void print() const override
    {
      cout << "KEY" << " | " << "Value" << endl;
      cout << "______________________________________" << endl;
      for(int i = 0; i < capacity; i++){// for every array element
        if(data[i] != nullptr)
          cout << data[i]->key << " | " << data[i]->value << endl;  // output the val and key
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

    // An array of type 'HTEntry'
    HTEntry* data[capacity];
    int size;
};

#endif
