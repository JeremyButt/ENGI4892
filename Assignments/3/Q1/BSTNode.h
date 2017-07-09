//BSTNode.cpp
//Author: Jeremy Butt
//				jeremybutt@mun.ca
//				201527710

template<class K, class V>
class BSTNode {
public:
    BSTNode() {
    left = right = nullptr; //initialize left and right to nullptr
    }
    BSTNode(const K& key, const V& value, BSTNode* l=nullptr, BSTNode* r=nullptr) {
      key_ = key; value_ = value; left = l; right = r;  // initialize all member vars
    }
    K key_; // to store keys
    V value_;// to store values
    BSTNode<K,V> *left , *right; // to store child nodes
};
