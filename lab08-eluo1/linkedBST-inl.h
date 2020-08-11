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
#include <vector>

#include "adts/list.h"
#include "adts/queue.h"
#include "adts/stlList.h"
#include "adts/stlQueue.h"
#include "helpers.h" // list-to-vector helper function included

#include "linkedBSTNode.h"

using std::pair;
using std::runtime_error;
using std::vector;

template <typename K, typename V> LinkedBST<K, V>::LinkedBST() {
    this->size = 0;
    this->root = nullptr;
    // throw runtime_error("Not yet implemented: LinkedBST<K,V>::LinkedBST");
}

template <typename K, typename V> LinkedBST<K, V>::~LinkedBST() {
    // To do: implement the destructor
    this->deleteSubtree(this->root); // need to implement delete subtree
}

template <typename K, typename V> int LinkedBST<K, V>::getSize() {
    return this->size;
    // throw runtime_error("Not yet implemented: LinkedBST<K,V>::getSize");
}

template <typename K, typename V> bool LinkedBST<K, V>::isEmpty() {
    return (this->size == 0);
    // throw runtime_error("Not yet implemented: LinkedBST<K,V>::isEmpty");
}

template <typename K, typename V> void LinkedBST<K, V>::insert(K key, V value) {
    // throw runtime_error("Not yet implemented: LinkedBST<K,V>::insert");
    this->root = insertInSubtree(this->root, key, value);
    this->size++;
}

template <typename K, typename V> void LinkedBST<K, V>::update(K key, V value) {
    // throw runtime_error("Not yet implemented: LinkedBST<K,V>::update");
    this->updateInSubtree(this->root,key, value);
}

template <typename K, typename V> V LinkedBST<K, V>::get(K key) {
    return this->findInSubtree(this->root, key);
}

template <typename K, typename V> bool LinkedBST<K, V>::contains(K key) {
    // throw runtime_error("Not yet implemented: LinkedBST<K,V>::contains");
    return this->containsInSubtree(this->root, key);
}

template <typename K, typename V> void LinkedBST<K, V>::remove(K key) {
    // throw runtime_error("Not yet implemented: LinkedBST<K,V>::remove");
    this->root = this->removeFromSubtree(this->root, key);
    this->size--;
}

template <typename K, typename V> vector<K> LinkedBST<K, V>::getKeys() {
    // throw runtime_error("Not yet implemented: LinkedBST<K,V>::getKeys");
    vector<pair<K, V>> temp = this->traverseInOrder();
    vector<K> toReturn;
    for (int i=0; i<this->size; i++){
        toReturn.push_back(temp[i].first);
    }
    return toReturn;
}

template <typename K, typename V>
vector<pair<K, V>> LinkedBST<K, V>::getItems() {
    return this->traverseInOrder();
}

template <typename K, typename V> int LinkedBST<K, V>::getHeight() {
    return this->getHeightInSubtree(this->root);
}

template <typename K, typename V> K LinkedBST<K, V>::getMaxKey() {
    // throw runtime_error("Not yet implemented: LinkedBST<K,V>::getMax");
    return this->getMaxInSubtree(this->root).first;
}

template <typename K, typename V> K LinkedBST<K, V>::getMinKey() {
    // throw runtime_error("Not yet implemented: LinkedBST<K,V>::getMin");
    return this->getMinInSubtree(this->root).first;
}

template <typename K, typename V>
vector<pair<K, V>> LinkedBST<K, V>::traversePreOrder() {
    // throw runtime_error(
    //     "Not yet implemented: LinkedBST<K,V>::traversePreOrder");
    List<pair<K, V>>* list = new STLList<pair<K,V>>();
    this->buildPreOrderTraversal(this->root, list); // call private helper function
    vector<pair<K, V>> toReturn; //static declaration
    toReturn = dynamicListToStaticVector(list); //dynamic to static
    delete list; // free dynamic memory
    return toReturn;
}

template <typename K, typename V>
vector<pair<K, V>> LinkedBST<K, V>::traverseInOrder() {
    // throw runtime_error("Not yet implemented: LinkedBST<K,V>::traverseInOrder");
    List<pair<K, V>>* list = new STLList<pair<K,V>>();
    this->buildInOrderTraversal(this->root, list); // call private helper function
    vector<pair<K, V>> toReturn; //static declaration
    toReturn = dynamicListToStaticVector(list); //dynamic to static
    delete list; // free dynamic memory
    return toReturn;
}

template <typename K, typename V>
vector<pair<K, V>> LinkedBST<K, V>::traversePostOrder() {
    // throw runtime_error(
    //     "Not yet implemented: LinkedBST<K,V>::traversePostOrder");
    List<pair<K, V>>* list = new STLList<pair<K,V>>();
    this->buildPostOrderTraversal(this->root, list); // call private helper function
    vector<pair<K, V>> toReturn; //static declaration
    toReturn = dynamicListToStaticVector(list); //dynamic to static
    delete list; // free dynamic memory
    return toReturn;
}

template <typename K, typename V>
vector<pair<K, V>> LinkedBST<K, V>::traverseLevelOrder() {
    // Start BFS at root. As nodes are removed from queue, add pairs to vector.
    vector<pair<K,V>> level_traversal;

    // Note, there's no need to deal with finding neighbors or marking visited
    // here. A node's only neighbors that haven't already been visited will be
    // their children.
    if (this->root != nullptr) {
        STLQueue<LinkedBSTNode<K,V>*> search_queue;
        search_queue.enqueue(this->root);
        while (search_queue.getSize() > 0) {
            LinkedBSTNode<K,V>* current = search_queue.dequeue();
            // Add to traversal
            level_traversal.push_back(pair<K,V>(current->getKey(), current->getValue()));
            if (current->getLeft() != nullptr) {
                search_queue.enqueue(current->getLeft());
            }
            if (current->getRight() != nullptr) {
                search_queue.enqueue(current->getRight());
            }
        }
    }

    return level_traversal;
}

template <typename K, typename V> void LinkedBST<K, V>::checkInvariants() {
    if (this->countNodes(this->root) != this->size) {
        throw runtime_error(
            "Problem in BST: Node count doesn't match tree size");
    }
    if (this->root != nullptr) {
        // The bounds provided here are arbitrary because the false arguments
        // indicate that they do not apply.  But we need a value of type K to
        // fill this parameter since we don't have globally min/max K values
        // generically.
        this->verifyKeysBoundedBy(this->root, false, this->root->getKey(),
                                  false, this->root->getKey());
    }
}
