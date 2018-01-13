#include "anagramhash.h"

/*
public methods for hash table of integer keys to integer values,
which allows duplicate (key, value) entries to be stored, 
and allows specified (key,value) entries to be removed 
from the hash table.
Used to solve the anagram mapping problem where the list of 
integers can have duplicates.
*/

/* 
add a key-value entry to the hash table. The (key-value) entry
may already exist in the table 
*/
void AnagramHash::put(int key, int val) {
    //address to array
    int addr = hash_function(key);
    //entry to be added
    Link *tmp = new Link(key, val);
    if (hash_table[addr] == NULL) {
        //first entry at this location
        hash_table[addr] = tmp;
    } else {
        //already chaining, go to end of list
        Link *chain = hash_table[addr];
        while (chain->getNext() != NULL) {
            chain = chain->getNext();
        }
        chain->setNext(tmp);
    }   
};

/*
return true if the key exists in the table.
find() should be called before get(), and get() should only 
be called if find() returns true.
*/
bool AnagramHash::find(int key) {
    int addr = hash_function(key);
    if (hash_table[addr] == NULL) {
        //no entries at this address
        return false;
    } else {
        //search list for entry
        Link *chain = hash_table[addr];
        while (chain != NULL && chain->getKey() != key ) {
            chain = chain->getNext();
        }
        if (chain == NULL) {
            //reached end of list, no entry
            return false;
        } else {
            //found it
            return true;
        }
    }
};

/*
get the value for the given key. If there are duplicate key-value entries,
the first one is returned.
find() should be called before get(), and get() should only 
be called if find() returns true.
*/
int AnagramHash::get(int key){
    //address to array
    int addr = hash_function(key);  
    //if get() was called without first checking with find(), have to 
    //return something. Set to NO_VAL
    int val = NO_VAL;    
    int tmpval;
    //search list at array location
    if (hash_table[addr] != NULL) {
        Link *chain = hash_table[addr];
        tmpval = chain->getVal();
        while (chain != NULL && chain->getKey() != key ) {
            chain = chain->getNext();
            tmpval = chain->getVal();
        }
        if (chain != NULL) {
            //found value before getting to end of list
            val = tmpval;
        } 
    }
    //return value if it was found, otherwise return NO_VAL
    return val;
};

/*
remove a specified key-value pair from the table. If there is more 
than one, the first is removed. 
*/
void AnagramHash::remove(int key, int val){
    //address into array
    int addr = hash_function(key);
    //if NULL, nothing to remove
    if (hash_table[addr] == NULL) {
        return;
    }
    //search list for key-value entry
    //first check the first entry, and remove it if it matches
    Link *chain = hash_table[addr];
    if (chain->getKey() == key && chain->getVal() == val) {
        hash_table[addr] = chain->getNext();
        delete chain;
        return;
    }
    //not the first entry, traverse the list
    Link *prev = chain;
    chain = chain->getNext();
    while (chain != NULL && !(chain->getKey() == key && chain->getVal() == val)) {
        chain = chain->getNext();
        prev = prev->getNext();
    }
    if (chain != NULL) {
        //found entry before getting to end of list, remove it
        prev->setNext(chain->getNext());
        delete chain;
    }
};
