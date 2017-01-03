#include <stdio.h>  // printf() etc.
#include <string.h> // strcpy(), strlen() etc.
#include <math.h>
#include <iostream>
#include <fstream>
#include "Enum_Columns.cpp"
using namespace std;

class Row{
    public:
    string* col_list;

    int hash_function(const char *key);
    int add(columns col_num, string value);
    Row();

    HashTable(int MAX_KEY_LENGTH, int HASH_TABLE_SIZE_M, int DOUBLE_HASHING);
    ~HashTable();
};