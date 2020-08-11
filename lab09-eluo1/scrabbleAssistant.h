#pragma once
/*
  Copyright (c) 2020
  Swarthmore College Computer Science Department, Swarthmore PA
  J. Brody, A. Danner, M. Gagne, L. Meeden, Z. Palmer, A. Soni, M. Wehar
  Distributed as course material for Spring 2020
  CPSC 035: Data Structures and Algorithms
  https://tinyurl.com/vdxo2w8
*/

#include <string>
#include <vector>

#include "hashFunctions.h"
#include "hashTable.h"

using std::string;
using std::vector;

/**
 * This method produces the power set of combination from the provided
 * letters.  That is, it returns the set of all subsets of letters
 * @param letters The original set for which we want to find all subsets of
 * @return A vector of all subets.  Each subset is a string of the
 *          characters in that set.
 */
vector<string> stringPowerSet(string letters);


class ScrabbleAssistant {
  public:
    /**
     * Creates a ScrabbleAssistant object.  The provided vector contains all
     * legal words to be recognized by the assistant.
     */
    ScrabbleAssistant(vector<string> words);

    ~ScrabbleAssistant();

    /**
     * Checks to determine if the provided word is spelled correctly.  This
     * operation is performed in CONSTANT time.
     * @param word The word in question.
     * @return true if this is a valid word; false if it is not.
     */
    bool spellCheck(string word);

    /**
     * Finds all anagrams of the provided letters.  This function finds all
     * permutations of the provided letters which form valid words.  This
     * operation is performed in CONSTANT time (with respect to the number of
     * legal words).
     * @param letters The letters to check.  These letters are not necessarily
     *                in any particular order.
     * @return The words which can be spelled by permuting those letters.
     */
    vector<string> anagramsOf(string letters);

    /**
     * This method produces a vector of the words that could be spelled given
     * the provided series of letters.
     * @param letters The sequence of letters for which we want to find a word.
     *                These letters are not necessarily in any particular order.
     * @return A vector of all words that the player could spell with these
     *         letters.
     */
    vector<string> findWords(string letters);
    

  private:

    // TODO: put any member variables and private methods here
    Dictionary<string, string>* dictionary;
    string sortLetters(string s); 
};
