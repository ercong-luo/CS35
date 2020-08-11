/*
  Copyright (c) 2020
  Swarthmore College Computer Science Department, Swarthmore PA
  J. Brody, A. Danner, M. Gagne, L. Meeden, Z. Palmer, A. Soni, M. Wehar
  Distributed as course material for Spring 2020
  CPSC 035: Data Structures and Algorithms
  https://tinyurl.com/vdxo2w8
*/

#include <stdexcept>
#include <utility>

#include "adts/list.h"
#include "adts/stlList.h"

using std::runtime_error;

template <typename K, typename V>
V LinkedBST<K, V>::findInSubtree(LinkedBSTNode<K, V>* current, K key) {
    //If key not found, throw an error
    if (current == nullptr) {
        throw runtime_error("Key not found: LinkedBST<K,V>::findInSubtree");
    }
    // Found it. Return value
    else if (key == current->getKey()) {
        return current->getValue();
    }
    // If key less, search left subtree
    else if (key < current->getKey()) {
        return this->findInSubtree(current->getLeft(), key);
    }
    // If key greater, search right subtree
    else { //key > current->getKey()
        return this->findInSubtree(current->getRight(), key);
    }
}

template <typename K, typename V>
bool LinkedBST<K, V>::containsInSubtree(LinkedBSTNode<K, V>* current, K key) {
    //If key not found, return false
    if (current == nullptr) {
        return false;
    }
    // Found it. Return true
    else if (key == current->getKey()) {
        return true;
    }
    // If key less, search left subtree
    else if (key < current->getKey()) {
        return this->containsInSubtree(current->getLeft(), key);
    }
    // If key greater, search right subtree
    else { //key > current->getKey()
        return this->containsInSubtree(current->getRight(), key);
    }
    // throw runtime_error("Not yet implemented: LinkedBST<K,V>::containsInSubtree");
}

template <typename K, typename V>
void LinkedBST<K, V>::updateInSubtree(LinkedBSTNode<K, V>* current, K key, V value) {
    //If key not found, return false
    if (current == nullptr) {
        throw runtime_error("Key not found: LinkedBST<K,V>::updateInSubtree");
    }
    // Found it. Update value
    else if (key == current->getKey()) {
        current->setValue(value);
        return;
    }
    // If key less, search and update in left subtree
    else if (key < current->getKey()) {
        this->updateInSubtree(current->getLeft(), key, value);
    }
    // If key greater, search and update in right subtree
    else { //key > current->getKey()
        this->updateInSubtree(current->getRight(), key, value);
    }
    // throw runtime_error("Not yet implemented: LinkedBST<K,V>::updateInSubtree");
}

template <typename K, typename V>
int LinkedBST<K, V>::getHeightInSubtree(LinkedBSTNode<K, V>* current) {
    if (current == nullptr) {
        return -1;
    }

    int left_height = this->getHeightInSubtree(current->getLeft());
    int right_height = this->getHeightInSubtree(current->getRight());

    if (left_height > right_height) {
        return left_height + 1;
    }
    else { //right_height >= left_height
        return right_height +  1;
    }
}

template <typename K, typename V>
pair<K, V> LinkedBST<K, V>::getMinInSubtree(LinkedBSTNode<K, V>* current) {
    // throw runtime_error("Not yet implemented: LinkedBST<K,V>::getMinInSubtree");
    K min = current->getKey();
    if(current->getLeft()==nullptr){              
        return pair<K,V> (current->getKey(), current->getValue());
    }
    else{
        return getMinInSubtree(current->getLeft());
    }
}

template <typename K, typename V>
pair<K, V> LinkedBST<K, V>::getMaxInSubtree(LinkedBSTNode<K, V>* current) {
    K max = current->getKey();
    if(current->getRight()==nullptr){              
        return pair<K,V> (current->getKey(), current->getValue());
    }
    else{
        return getMaxInSubtree(current->getRight());
    }
    // throw runtime_error("Not yet implemented: LinkedBST<K,V>::getMaxInSubtree");
}

template <typename K, typename V>
LinkedBSTNode<K, V>*
LinkedBST<K, V>::insertInSubtree(LinkedBSTNode<K, V>* current, K key, V value) {
    //If current is null, insert right here
    if (current == nullptr) {
        current = new LinkedBSTNode<K,V>(key, value);       
        return current;
    }
    //Key already exists, throw error
    else if (key == current->getKey()){
        throw runtime_error("Key already exists. LinkedBST<K, V>::insertInSubtree");
    }
    //If key less, go into left subtree
    else if(key < current->getKey()){
        current->setLeft(insertInSubtree(current->getLeft(), key, value));
        return current;   
    }
    // If key greater, go into right subtree
    else{ // (key > current->getKey()
        current->setRight(insertInSubtree(current->getRight(), key, value));
        return current;  
    }
    // throw runtime_error("Not yet implemented: LinkedBST<K,V>::insertInSubtree");
}

template <typename K, typename V>
LinkedBSTNode<K, V>*
LinkedBST<K, V>::removeFromSubtree(LinkedBSTNode<K, V>* current, K key) {
    // throw runtime_error("Not yet implemented: LinkedBST<K,V>::removeFromSubtree");
    if(current == nullptr){ //key not found
        throw runtime_error("Given key not found.");
    }
    else if(key < current->getKey()){//key less 
        current->setLeft(this->removeFromSubtree(current->getLeft(), key));
        return current;
    }
    else if(key > current->getKey()){//key larger
        current->setRight(this->removeFromSubtree(current->getRight(), key));
        return current;
    }
    else{ // found the key to delete
        if (current->getLeft() == nullptr && current->getRight() == nullptr){ //current has no child
            delete current;
            return nullptr;
        }
        else if (current->getLeft() == nullptr){ // current has no left child, promote right
            LinkedBSTNode<K, V>* temp = current->getRight();
            delete current;
            return temp;
        }
        else if (current->getRight() == nullptr){ // current has no right child, promote left
            LinkedBSTNode<K, V>* temp = current->getLeft();
            delete current;
            return temp;
        }
        else{ // current has two children, just promote left child, taking advantage of the BTS property
            pair<K,V> temp_pair = this->getMaxInSubtree(current->getLeft());
            current->setKey(temp_pair.first);
            current->setValue(temp_pair.second);
            current->setLeft(this->removeFromSubtree(current->getLeft(),temp_pair.first));
            return current;
        }
    }

}

template <typename K, typename V>
void LinkedBST<K, V>::deleteSubtree(LinkedBSTNode<K, V>* current) {   
    if(current == nullptr){
        return;
    } else {
        deleteSubtree(current->getLeft());
        deleteSubtree(current->getRight());
        delete current;
    }
}

template <typename K, typename V>
void LinkedBST<K, V>::buildPreOrderTraversal(LinkedBSTNode<K, V>* current, List<pair<K, V>>* list) {
    // throw runtime_error("Not yet implemented: LinkedBST<K,V>::buildPreOrder");
    if (current == nullptr){
        return;
    }
    list->insertLast(pair<K,V>(current->getKey(), current->getValue()));
    this->buildPreOrderTraversal(current->getLeft(), list);
    this->buildPreOrderTraversal(current->getRight(), list);
}

template <typename K, typename V>
void LinkedBST<K, V>::buildInOrderTraversal(LinkedBSTNode<K, V>* current, List<pair<K, V>>* list) {
    // throw runtime_error("Not yet implemented: LinkedBST<K,V>::buildInOrder");
    if (current == nullptr){
        return;
    }
    this->buildInOrderTraversal(current->getLeft(), list);
    list->insertLast(pair<K,V>(current->getKey(), current->getValue()));
    this->buildInOrderTraversal(current->getRight(), list);
}

template <typename K, typename V>
void LinkedBST<K, V>::buildPostOrderTraversal(LinkedBSTNode<K, V>* current, List<pair<K, V>>* list) {
    // throw runtime_error("Not yet implemented: LinkedBST<K,V>::buildPostOrder");
    if (current == nullptr){
        return;
    }
    this->buildPostOrderTraversal(current->getLeft(), list);
    this->buildPostOrderTraversal(current->getRight(), list);
    list->insertLast(pair<K,V>(current->getKey(), current->getValue()));
}

template <typename K, typename V>
int LinkedBST<K, V>::countNodes(LinkedBSTNode<K, V>* current) {
    if (current == nullptr) {
        return 0;
    } else {
        return this->countNodes(current->getLeft()) +
               this->countNodes(current->getRight()) + 1;
    }
}

template <typename K, typename V>
void LinkedBST<K, V>::verifyKeysBoundedBy(LinkedBSTNode<K, V>* current,
                                          bool minApplies, K minBound,
                                          bool maxApplies, K maxBound) {
    if (minApplies && current->getKey() < minBound) {
        throw runtime_error("LinkedBST::verifyKeysBoundedBy: a node has a "
                            "right descendent with lesser key");
    }
    if (maxApplies && current->getKey() > maxBound) {
        throw runtime_error("LinkedBST::verifyKeysBoundedBy: a node has a left "
                            "descendent with greater key");
    }
    if (current->getLeft() != nullptr) {
        verifyKeysBoundedBy(current->getLeft(), minApplies, minBound, true,
                            current->getKey());
    }
    if (current->getRight() != nullptr) {
        verifyKeysBoundedBy(current->getRight(), true, current->getKey(),
                            maxApplies, maxBound);
    }
}
