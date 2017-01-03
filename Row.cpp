#include <stdio.h>  // printf() etc.
#include <string.h> // strcpy(), strlen() etc.
#include <math.h>
#include <iostream>
#include <fstream>
#include "Enum_Columns.cpp"
#include "Row.hpp"
using namespace std;

int Row::add(columns col_num, string value);
{
    if(col_list[col_num][0] != '-'){
        col_list[col_num] = value;
        return 1;
    }
    else return 0;
}

Row::Row(){
    //allocate memory for hash table
    col_list = new string[COLS_total];

    //empty the table
    for (int i = 0; i < table_size; i++){
        hash_table[i] = '-';
        }
}

Row::~Row(){
    delete[] col_list;
}
