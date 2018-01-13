#ifndef _ANAGRAM_HASH_H_
#define _ANAGRAM_HASH_H_
#include "link.h"

/*
Hash table of integer keys to integer values, which allows 
duplicate (key, value) entries to be stored, and allows specified
(key,value) entries to be removed from the hash table.
Used to solve the anagram mapping problem where the list of 
integers can have duplicates.
*/

class AnagramHash {
    private: 
        static const int MAX_SIZE = 100;    //size of table
        static const int NO_VAL = -99999;   //value returned if not found
        Link *hash_table[MAX_SIZE];         //table
        int hash_function(int key) {        //hash function, 
            return key % MAX_SIZE;          //      for integers just do mod
        }
    
    public: 
        //constructor: initialize array elements to NULL
        AnagramHash() {
            for (int i= 0; i < MAX_SIZE; i++) {
                hash_table[i] = NULL;
            }
        }
       
        //destructor: free any elements that are not NULL
        ~AnagramHash(){
            for (int i= 0; i < MAX_SIZE; i++) {
                if (hash_table[i] != NULL) {
                    delete hash_table[i];
                    hash_table[i] = NULL;
                }                    
            }
        }
        void put(int key, int val);       //add (key,value) to hash
        bool find(int key);               //determine if key is in table
        int get(int key);                 //get the value for the key
        void remove(int key, int val);    //remove the (key,value) entry
}; 

#endif