#include <stdio.h>  // printf() etc.
#include <string.h> // strcpy(), strlen() etc.
#include <math.h>
#include <iostream>
#include <fstream>
using namespace std;

class HashTable{
    public:
    int max_key_length;    //Max Length of a Key
    int table_size;    //Size of the hash table
    int double_hashing; //is double used
    int filled_cells;   //number of filled cells
    int collisions; //number of collisions
    int* Collisions_Index;  //pointer to the collisions array
    int* Filled;            //pointer to the filled array
    int* Collisions_Filled; //colliosn vs filled
    string* hash_table;     //the string array that stores the hashs

    int hash_function(const char *key);
    double table_load();
    HashTable(int MAX_KEY_LENGTH, int HASH_TABLE_SIZE_M, int DOUBLE_HASHING);
    ~HashTable();
};