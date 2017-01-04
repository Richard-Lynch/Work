#include <stdio.h>  // printf() etc.
#include <string.h> // strcpy(), strlen() etc.
#include <math.h>
#include <iostream>
#include <fstream>
#include "Row.hpp"
using namespace std;

int Row::add(int col_num, string value){
    if(col_list[col_num][0] != '-'){
        col_list[col_num] = value;
        return 1;
    }
    else return 0;
}

Row::Row(int Index){
    //allocate memory for hash table
    col_list = new string[COLS_total];

    //empty the table
    for (int i = 0; i < COLS_total; i++){
        col_list[i] = '-';
    }
    index = Index;
    
}

Row::Row(){
    //allocate memory for hash table
    col_list = new string[COLS_total];

    //empty the table
    for (int i = 0; i < COLS_total; i++){
        col_list[i] = '-';
    }
}

Row::~Row(){
    //delete[] col_list;
}
