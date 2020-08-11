/*
  Copyright (c) 2020
  Swarthmore College Computer Science Department, Swarthmore PA
  J. Brody, A. Danner, M. Gagne, L. Meeden, Z. Palmer, A. Soni, M. Wehar
  Distributed as course material for Spring 2020
  CPSC 035: Data Structures and Algorithms
  https://tinyurl.com/vdxo2w8
*/

#include "scrabbleAssistant.h"
#include <algorithm>
#include <stdexcept>

using namespace std;

ScrabbleAssistant::ScrabbleAssistant(vector<string> words) {
    // throw runtime_error("Not yet implemented: ScrabbleAssistant constructor");
    this->dictionary = new HashTable<string,string>();
    for(int i=0; i < words.size(); i++){
      dictionary->insert(words[i], words[i]); // key and value are identical for each key-value pair
    }
}

ScrabbleAssistant::~ScrabbleAssistant() {
    // TODO: implement destructor
    delete this->dictionary;
    this->dictionary = nullptr;
}

bool ScrabbleAssistant::spellCheck(string word) {
    // throw runtime_error("Not yet implemented: ScrabbleAssistant::spellCheck");
    return dictionary->contains(word);
}

vector<string> ScrabbleAssistant::anagramsOf(string letters) {
  // throw runtime_error("Not yet implemented: ScrabbleAssistant::anagramsOf");
  vector<string> anagrams; // to be returned
  vector<pair<string,string>> allWords; // all the words from loaded dictionary
  allWords = dictionary->getItems();

  //helperDictionary
  Dictionary<string,string>* helperDictionary = new HashTable<string,string>();
  string letterKey = this->sortLetters(letters);
  helperDictionary->insert(letterKey, letters);

  //getting anagrams
  for(int i=0; i < allWords.size(); i++){ //check each word in loaded dictionary
    string key = this->sortLetters(allWords[i].first); // key is the given letters after sorting
    if(helperDictionary->contains(key)){ // if this word in loaded dictionary is composed of the same letters as the given word
      anagrams.push_back(allWords[i].second);
    }
  }

  //free memory
  delete helperDictionary;
  helperDictionary = nullptr;

  return anagrams;
}

vector<string> ScrabbleAssistant::findWords(string letters) {
  //superset contains the superset defined on the input string
  //answers is eventually returned
  vector<string> superset, anagrams, answers;

  //anagramHelper is to help determine if a word in the dictionary is indeed an anagram of an element in a superset
  //checkRepeat is to help determine if an answer is a duplicate
  Dictionary<string,string>* checkRepeat = new HashTable<string,string>();
  Dictionary<string,string>* anagramHelper = new HashTable<string,string>();

  //allWords are all the words in the loaded dictionary
  vector<pair<string,string>> allWords;

  superset = stringPowerSet(letters);
  allWords = dictionary->getItems();
  
  //set up anagram helper dictionary
  for (int i=0; i<superset.size(); i++){ //get anagrams of every element in the superset
    string letterKey = this->sortLetters(superset[i]);
    if(anagramHelper->contains(letterKey) == false){
      anagramHelper->insert(letterKey, superset[i]);
    }
  }
  
  //get words that we want, duplicates not accounted for yet
  for(int j=0; j < allWords.size(); j++){ //check each word in loaded dictionary
    string key = this->sortLetters(allWords[j].first); // key is the given letters after sorting
    if(anagramHelper->contains(key)){
      anagrams.push_back(allWords[j].first);
    }
  }
  
  // account for duplicates
  for(int k=0; k < anagrams.size(); k++){
    if(!checkRepeat->contains(anagrams[k])){
      checkRepeat->insert(anagrams[k],anagrams[k]);
    }
  }

  // get answers without duplicates into a vector
  allWords = checkRepeat->getItems();
  for(int k=0; k<allWords.size(); k++){
    answers.push_back(allWords[k].first);
  }

  //free up memory
  delete checkRepeat;
  checkRepeat = nullptr;
  delete anagramHelper;
  anagramHelper = nullptr;

  return answers;
}


vector<string> stringPowerSet(string letters){
  vector<string> result;
  //base case: return empty set if letters is empty
  if(letters == ""){
    result.push_back("");
    return result;
  }

  char firstChar = letters[0];
  string sub = letters.substr(1);

  //recursive case: find subset of last n-1 elements in set
  vector<string> smallerResult = stringPowerSet(sub);

  for(int i = 0; i < smallerResult.size(); i++){
      result.push_back(smallerResult[i]); // recursive results
      result.push_back(firstChar+smallerResult[i]); // append first element
  }
  return result;
}

// TODO: implement here any other methods that you choose to declare
string ScrabbleAssistant::sortLetters(string s){
  sort(s.begin(), s.end());
  return s;
}
