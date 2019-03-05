#include "HashTable.h"
#include "WordEntry.h"
#include <cmath>

/* HashTable constructor
*  input s is the size of the array
*  set s to be size
*  initialize array of lists of WordEntry
*/
HashTable::HashTable (int s) {
    size = s;
    hashTable = new list<WordEntry>[s];
}


/* computeHash
*  return an integer based on the input string
*  used for index into the array in hash table
*  be sure to use the size of the array to 
*  ensure array index doesn't go out of bounds
*/
int HashTable::computeHash(const string &s) {
    int val = 0;
    for (unsigned i = 0; i < s.size(); i++) {
        val += (val << 2) * s[i];
    }
    return abs(val) % size;
}


/* put
*  input: string word and int score to be inserted
*  First, look to see if word already exists in hash table
*   if so, addNewAppearence with the score to the WordEntry
*   if not, create a new Entry and push it on the list at the
*   appropriate array index
*/
void HashTable::put(const string &s, int score) {
    int indexerino = computeHash(s);
    for (list<WordEntry>::iterator i = hashTable[indexerino].begin(); i != hashTable[indexerino].end(); i++) {
        if (s == i->getWord()) {
            i->addNewAppearance(score);
            return;
        }
    }
    WordEntry word = WordEntry(s, score);
    hashTable[indexerino].push_back(word);
}

/* getAverage
*  input: string word 
*  output: the result of a call to getAverage()
*          from the WordEntry
*  Must first find the WordEntry in the hash table
*  then return the average
*  If not found, return the value 2.0 (neutral result)
*/

double HashTable::getAverage(const string &s) {
    int indexerino = computeHash(s);
    for (list<WordEntry>::iterator i = hashTable[indexerino].begin(); i != hashTable[indexerino].end(); i++) {
        if (s == i->getWord()) {
            return i->getAverage();
        }
    }
    return 2.0;
}

/* contains
* input: string word
* output: true if word is in the hash table
*         false if word is not in the hash table
*/
bool HashTable::contains(const string &s) {
    int indexerino = computeHash(s);
    for (list<WordEntry>::iterator i = hashTable[indexerino].begin(); i != hashTable[indexerino].end(); i++) {
        if (s == i->getWord()) {
            return true;
        }
    }
    return false;
}

