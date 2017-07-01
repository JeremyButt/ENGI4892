#ifndef __BSTMAP_H__
#define __BSTMAP_H__
#include "BSTNode.h"
#include "Map.h"
#include <iostream>
#include <string>
#include <fstream>
using namespace std;

template<class K, class V>
class BSTMap : public virtual Map<K, V>{
  public:
    //C'tor & D'tor
    BSTMap(){
      this->root_ = nullptr;//set root to null on construct
    }
    ~BSTMap(){
      this->DELETE_ALL(this->root_);  // use the protected recursive func to del all nodes inc root
    }

    // pre-condition:   a valid key/value pair
    // post-condition:  pair will be added to the BST, if not already present
    //                  Return true if insert succeeded, else false
    bool insert(const K& key, const V& value) override{
      return (insertAtNode(this->root_, key, value)); // call insertatnode to begin recursive insert
    }

    // pre-condition:   a valid key/value pair and node
    // post-condition:  pair will be added to the BST, if not already present
    //                  Return true if insert succeeded, else false
    bool  insertAtNode(BSTNode<K,V>*& node, const K& key, const V& value){
      if (node == nullptr){
        node = new BSTNode<K,V>(key, value);  //if null add node here
        return true;  // once added return true
      }else if (key < node->key_){
        insertAtNode(node->left, key, value);// if key is less insertatnode to the left (recursive)
      }else if (key > node->key_){
        insertAtNode(node->right, key, value);// if key is greater insertatnode to the right (recursive)
      }else{
        return false; // if node not able to be added return false
      }
    }

    // pre-condition:   a valid key
    // post-condition:  if key was present, key/value pair is removed
    //                  Return true if remove succeeded, else false
    bool remove(const K& key) override{
      BSTNode<K,V>* temp= this->root_, *prev = nullptr;  // set temp nodes
      while (temp!= nullptr) { // while not at end of tree
        if (temp->key_ == key)  // if key is key_ break while
          break;
        prev = temp;  //update prev
        //shift temp node along
        if (temp->key_ < key)
          temp= temp->right;
        else temp = temp->left;
      }
      // find which branch to delete and delete by merge
      if(temp != nullptr && temp->key_ == key){
        if(temp == this->root_){
          delete_by_merging(this->root_);
        }else if(prev->left == temp){
          delete_by_merging(prev->left) ;
        }else{
          delete_by_merging(prev->right);
        }
        // if key not found or tree is empty
      }else if(this->root_ != nullptr){
        cout << "key " << key << " is not in the tree\n" ;
      }else{
        cout << "the tree is empty\n" ;
      }
    }

    // pre-condition:   a valid node
    // post-condition:  if node was present, node is removed [works with remove for delete by merge]
    //                  Return true if delete_by_merging succeeded, else false
    bool delete_by_merging(BSTNode<K,V>*& node){
      BSTNode<K,V>* tmp = node; // set up temp
        if(node != nullptr) {
          if(node->right = nullptr){ // case 1: no right child
            node = node->left;
          }else if(node->left == nullptr){ // case 2: no left child
            node = node->right ; //
          }else{  //case 3 both right and left children
            tmp = node->left; // 1. move left
            while (tmp->right != nullptr) // 2. then right
              tmp = tmp->right;
              tmp->right = node->right; // 3. merge right subtree
              tmp = node; //update temp
              node = node->left; //update node
            }
            delete tmp; // delete temp node
          }
    }

    // pre-condition:   a valid key
    // post-condition:  return the corresponding value for key, else nullptr
    //                  the BST is not changed
    const V* search(const K& key) const override{
      BSTNode<K,V>* p = this->root_;  //set temp to root
      //while not at end of tree
      while (p != nullptr){
        if(key == p->key_){//if key found
          return &p->value_; //return value as pointer
        }else if(key < p->key_){//if key less go left in tree
          p = p->left;
        }else{  // if key greater go right in tree
          p = p->right;
        }
      }
      return 0 ; //not found in the tree
    }

    // pre-condition:   a valid BST
    // post-condition:  return whether or not BST contains any items
    //                  the BST is not changed
    bool isEmpty() const override{
      if (this->root_ == nullptr)//if root null tree empty
        return true;
      return false;
    }

    // pre-condition:   a valid BST
    // post-condition:  prints contents of BST in sorted order
    //                  the BST is not changed
    void print() const override{
      preorderprint(this->root_);//recursive call to print in preorder starting at root
    }

    // pre-condition:   a valid NODE
    // post-condition:  prints contents of BST in sorted order [works with print to print everything from root node]
    //                  the BST is not changed
    void preorderprint(BSTNode<K,V>* p) const{
      //while not at end
      if(p != nullptr){
        cout << "KEY: " << p->key_ << " VALUE: " << p->value_ << " " << endl; // output contents
        preorderprint(p->left); // recursive call to left
        preorderprint(p->right);// recursive call to right
      }
    }

  protected:
    BSTNode<K,V>* root_;

    // pre-condition:   a valid BSTMap
    // post-condition:  Deletes all contents
    //
    void DELETE_ALL(BSTNode<K,V>* p){
      //while not at end
      if(p != nullptr){
        DELETE_ALL(p->left);//recursive to left
        DELETE_ALL(p->right);//recursive to right
        delete p;// delete p
        p = nullptr;//null out p
      }
    }
};

#endif
