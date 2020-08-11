/*
  Copyright (c) 2020
  Swarthmore College Computer Science Department, Swarthmore PA
  J. Brody, A. Danner, M. Gagne, L. Meeden, Z. Palmer, A. Soni, M. Wehar
  Distributed as course material for Spring 2020
  CPSC 035: Data Structures and Algorithms
  https://tinyurl.com/vdxo2w8
*/

#include <stdexcept>
using std::pair;
using std::runtime_error;
using std::vector;

template <typename K, typename V> LinearDictionary<K, V>::LinearDictionary() {
    // throw runtime_error(
    //     "Not yet implemented: LinearDictionary<K,V>::LinearDictionary");
    this->size = 0;
}

template <typename K, typename V> LinearDictionary<K, V>::~LinearDictionary() {
    // TODO: implement destructor
  
}

template <typename K, typename V> int LinearDictionary<K, V>::getSize() {
    // throw runtime_error(
    //     "Not yet implemented: LinearDictionary<K,V>::getSize");
    return this->size;
}

template <typename K, typename V> bool LinearDictionary<K, V>::isEmpty() {
    // throw runtime_error(
    //     "Not yet implemented: LinearDictionary<K,V>::isEmpty");
    return (this->size == 0);
}

template <typename K, typename V>
void LinearDictionary<K, V>::insert(K key, V value) {
    // throw runtime_error(
    //     "Not yet implemented: LinearDictionary<K,V>::insert");
    int i;
    if(this->size!=0){ // check if key already exists if list isn't empty
        for (i=0; i<this->size; i++){
            if(this->collisionList[i].first == key){ // key already exists
                throw runtime_error("Error: key already exists. LinearDictionary<K, V>::insert");
            }
        }
    }
    this->collisionList.push_back(pair<K,V> (key,value));
    this->size ++;
}

template <typename K, typename V>
void LinearDictionary<K, V>::update(K key, V value) {
    // throw runtime_error(
    //     "Not yet implemented: LinearDictionary<K,V>::update");
    int i;
    for (i=0; i<this->size; i++){
        if(this->collisionList[i].first == key){ // key found
            this->collisionList[i].second = value;
            return;
        }
    }
    throw runtime_error("Error: key not found. LinearDictionary<K, V>::update");
}

template <typename K, typename V> V LinearDictionary<K, V>::get(K key) {
    // throw runtime_error("Not yet implemented: LinearDictionary<K,V>::get");
    int i;
    for (i=0; i<this->size; i++){
        if(this->collisionList[i].first == key){ // key found
            return this->collisionList[i].second;
        }
    }
    throw runtime_error("Error: key not found. LinearDictionary<K, V>::update");
}

template <typename K, typename V> bool LinearDictionary<K, V>::contains(K key) {
    // throw runtime_error(
    //     "Not yet implemented: LinearDictionary<K,V>::contains");
    for (int i=0; i<this->size; i++){
        if(this->collisionList[i].first == key){ // key found
            return true;
        }
    }
    return false;
}

template <typename K, typename V> void LinearDictionary<K, V>::remove(K key) {
    // throw runtime_error(
    //     "Not yet implemented: LinearDictionary<K,V>::remove");
    vector<pair<K,V>> temp;
    if(this->size == 0){
        throw runtime_error("Error: list is empty, so there's nothing to remove. LinearDictionary<K, V>::remove");
    }
    for (int i=0; i<this->size; i++){
        if(collisionList[i].first == key){ // key found
            this->collisionList.erase(this->collisionList.begin()+i); // documentation on 'erase' method: https://en.cppreference.com/w/cpp/container/vector/erase
            this->size --;
            return;
        }
    }
}

template <typename K, typename V> vector<K> LinearDictionary<K, V>::getKeys() {
    // throw runtime_error(
    //     "Not yet implemented: LinearDictionary<K,V>::getKeys");
    vector<K> toReturn;
    for (int i=0;i<this->size;i++){
        toReturn.push_back(this->collisionList[i].first);
    }
    return toReturn;
}

template <typename K, typename V>
vector<pair<K, V>> LinearDictionary<K, V>::getItems() {
    // throw runtime_error(
    //     "Not yet implemented: LinearDictionary<K,V>::getItems");
    return this->collisionList;
}

template <typename T> void removeFromVector(vector<T> &list, int index){
  if(index < 0 || index >= list.size()){
    throw runtime_error("index out of range in removeFromVector");
  }
  list.erase(list.begin()+index, list.begin()+index+1);
}

// TODO: put any other definitions here
