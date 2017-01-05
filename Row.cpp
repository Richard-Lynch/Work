#include <stdio.h>  // printf() etc.
#include <string.h> // strcpy(), strlen() etc.
#include <math.h>
#include <iostream>
#include <fstream>
#include "Row.hpp"
using namespace std;

int Row::add(string value){
    if(col_list.size() < max_size){
        col_list.push_back(value);
        return 1;
    }
    else
    printf("DAZ TOO BIG\n"); return 0;
}

void Row::fill(){
    col_list.resize(max_size, "-");
}

Row::Row(int Index, int size){
    //empty the table
    // for (int i = 0; i < COLS_total; i++){
    //     col_list[i] = '-';
    // }
    max_size = size;
    index = Index;
    
}

Row::Row(){
    //empty the table
    col_list.resize(100, "-");
}

Row::~Row(){
    col_list.clear();
    //delete[] col_list;
}
