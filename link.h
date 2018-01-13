#ifndef _LINK_H_
#define _LINK_H_

#include <cstdlib>

/*
Class for a basic link in a singly linked list that is part of a chaining hash table.
Members are the key, value, and pointer to next link.
Methods for getting and setting member variables.
*/

class Link {
private:
    int key;
    int val;
    Link *next;
public:
    Link(int inKey, int inVal) {
        key = inKey;
        val = inVal;
        next = NULL;
    }
    Link *getNext() {
        return next;
    }
    void setNext(Link *tmp) {
        next = tmp;
    }
    int getKey() {
        return key;
    }
    void setKey(int inKey) {
        key = inKey;
    }
    int getVal() {
        return val;
    }
    void setVal(int inVal) {
        val = inVal;
    }
};

#endif