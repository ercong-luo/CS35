/*
  Copyright (c) 2020
  Swarthmore College Computer Science Department, Swarthmore PA
  J. Brody, A. Danner, M. Gagne, L. Meeden, Z. Palmer, A. Soni, M. Wehar
  Distributed as course material for Spring 2020
  CPSC 035: Data Structures and Algorithms
  https://tinyurl.com/vdxo2w8
*/

#include <stdexcept>
#include <iostream> // for std::cout/endl I used


#include "hashFunctions.h"

using std::pair;
using std::runtime_error;
using std::vector;
using std::exception; //for the try-catch blocks

template <typename K, typename V> HashTable<K, V>::HashTable() {
    // throw runtime_error("Not yet implemented: HashTable<K,V>::HashTable");
    this->capacity = 5;
    this->size = 0;
    this->table = new LinearDictionary<K,V>[this->capacity];
    this->maxLoadFactor = 0.75; //defailt maxLoadFactor
}

template <typename K, typename V>
HashTable<K, V>::HashTable(float maxLoadFactor) {
    // throw runtime_error("Not yet implemented: HashTable<K,V>::HashTable(float)");
    this->capacity = 5;
    this->size = 0;
    this->table = new LinearDictionary<K,V>[this->capacity];
    this->maxLoadFactor = maxLoadFactor;
}

template <typename K, typename V> HashTable<K, V>::~HashTable() {
    delete[] table;
    table = nullptr;
}

template <typename K, typename V> int HashTable<K, V>::getSize() {
    return this->size;
}

template <typename K, typename V> bool HashTable<K, V>::isEmpty() {
    return (this->size == 0);
}

template <typename K, typename V> void HashTable<K, V>::insert(K key, V value) { 
    int hashNum;
    //generate hash key
    hashNum = hash(key, this->capacity); 
    
    //insertion
    if(this->table[hashNum].contains(key) == true){//check duplicate key
        throw runtime_error("Error: duplicate key. HashTable<K, V>::insert");
    } else{
        this->table[hashNum].insert(key, value);
        this->size++;
    }

    // expand capacity if load factor exceeds maxLoadFactor
    if((this->size / this->capacity) > this->maxLoadFactor){
            this->expandCapacity();
    }
}

template <typename K, typename V> void HashTable<K, V>::update(K key, V value) { 
    // throw runtime_error("Not yet implemented: HashTable<K,V>::update");
    int hashNum;
    //generate hash key
    try{ //our hash functions are only defined on key types int and string
        hashNum = hash(key, this->capacity); 
    } catch(exception& e){
        std::cout << e.what() << std::endl;
        return;
    }
    hashNum = hash(key, this->capacity); 
    //update
    if(this->table[hashNum].contains(key) == false){//check if key doesn't exist
        throw runtime_error("Error: key not found. HashTable<K, V>::insert");
    } else{
            this->table[hashNum].update(key, value);
            return;
    }

}

template <typename K, typename V> V HashTable<K, V>::get(K key) { 
    // throw runtime_error("Not yet implemented: HashTable<K,V>::get");
    int hashNum;
    //generate hash key
    try{ //our hash functions are only defined on key types int and string
        hashNum = hash(key, this->capacity); 
    } catch(exception& e){
        std::cout << e.what() << std::endl;
    }

    hashNum = hash(key, this->capacity); 

    //get value
    if(this->table[hashNum].contains(key) == false){//check if key doesn't exist
        throw runtime_error("Error: key not found. HashTable<K, V>::insert");
    } else{
            return this->table[hashNum].get(key);  
    }
}

template <typename K, typename V> bool HashTable<K, V>::contains(K key) {
    // throw runtime_error("Not yet implemented: HashTable<K,V>::contains");
    int hashNum;
    //generate hash key
    try{ //our hash functions are only defined on key types int and string
        hashNum = hash(key, this->capacity); 
    } catch(exception& e){
        std::cout << e.what() << std::endl;
    }

    hashNum = hash(key, this->capacity); 
    return this->table[hashNum].contains(key);
}

template <typename K, typename V> void HashTable<K, V>::remove(K key) {
    // throw runtime_error("Not yet implemented: HashTable<K,V>::remove");
    int hashNum;
    //generate hash key
    try{ //our hash functions are only defined on key types int and string
        hashNum = hash(key, this->capacity); 
    } catch(exception& e){
        std::cout << e.what() << std::endl;
    }

    hashNum = hash(key, this->capacity); 

    //remove key-value pair
    if(this->table[hashNum].contains(key) == false){//check if key doesn't exist
        throw runtime_error("Error: key not found. HashTable<K, V>::insert");
    } else{
        this->table[hashNum].remove(key);  
        this->size = this->size - 1;
        return;
    }
}

template <typename K, typename V> vector<K> HashTable<K, V>::getKeys() {
    // throw runtime_error("Not yet implemented: HashTable<K,V>::getKeys");
    vector<K> toReturn, temp;
    for(int i=0; i < this->capacity; i++){ // check pointers in table
        temp = this->table[i].getKeys();
        for(int j=0; j < temp.size(); j++){ // get keys referred to by each pointer in table
            toReturn.push_back(temp[j]);
        }
    }
    return toReturn;
}

template <typename K, typename V>
vector<pair<K, V>> HashTable<K, V>::getItems() { 
    // throw runtime_error("Not yet implemented: HashTable<K,V>::getItems");
    vector<pair<K, V>> toReturn, temp;

    for(int i=0; i < this->capacity; i++){ // check each linear dictionary in table
        if(!this->table[i].isEmpty()){ //not necessary but I'll keep this if statement here for now
            temp = this->table[i].getItems();
            for(int j=0; j < temp.size(); j++){ // get key-value pairs referred to by each pointer in table
                toReturn.push_back(temp[j]);
            }
        }
    }
    return toReturn;
}

template <typename K, typename V> void HashTable<K, V>::expandCapacity() {
    // throw runtime_error("Not yet implemented: HashTable<K,V>::expandCapacity");
    vector<pair<K, V>> temp;

    temp = this->getItems(); // grab everything from old table
    delete[] this->table; // delete the old dynamic array
    this->table = nullptr;
    this->capacity = this->capacity * 2;
    this->table = new LinearDictionary<K,V>[this->capacity]; //double capacity
    this->size = 0;//reset size for the insert method

    // now copy over all the elements
    for(int i=0; i < temp.size(); i++){
        this->insert(temp[i].first,temp[i].second);
    }
    return;
}