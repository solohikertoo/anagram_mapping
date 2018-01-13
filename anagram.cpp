#include <iostream>
#include <vector>
#include "anagramhash.h"

using namespace std;

/*
given two vectors of integers, a and b, find the mapping of indices of
elements of a to indices of corresponding elements of b.
Returns a vector of integers that gives the mapping
*/
vector<int> findAnagramMap(vector<int> &a, vector<int> &b) {
    int i;
    int n = a.size();
    
    vector<int> p;
    p.reserve(n);
    
    //store elements of b in hash table that allows duplicates. 
    //element of b is the key, its index in b is the value
    AnagramHash m;
    for (i=0; i<n; i++) {
        m.put(b[i],i);
    }
    
    //for each a, get the index from the hash table, which is the 
    //index to b and so is the mapping
    //to account for duplicates, remove the entry from the hash table 
    //after done with it
    for (i=0; i<n; i++) {
        p[i]=m.get(a[i]);
        m.remove(a[i],p[i]);
    }
    return p;
}

//driver for testing function to find anagram mapping
int main(int argc, char **argv) {
    //set some array and a true mapping, make sure it has duplicates
    vector<int> a = {51,22,67,36,10,48,22};
    vector<int> ptrue = {5,1,6,3,0,4,2};
    int i;
    int n = a.size();
    vector<int> b;
    b.reserve(n);

    //set the b vector according to the true mapping
    for (i=0; i<n; i++) {
        b[ptrue[i]]= a[i];
    }
    
    //print values, call function to get mapping, and print result
    cout << "a = "; for (i=0; i<n; i++) {cout << a[i] << " ";} cout << endl;
    cout << "b = ";for (i=0; i<n; i++) {cout << b[i] << " ";} cout << endl;
    cout << "true map  = "; for (i=0; i<n; i++) {cout << ptrue[i] << " ";} cout << endl;
   
    vector <int> p = findAnagramMap(a,b);
    cout << "found map = "; for (i=0; i<n; i++) {cout << p[i] << " ";} cout << endl;
    return 0;
}