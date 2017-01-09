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
        printf("added.\n");
        return 1;
    }
    else
    printf("failed.\n"); return 0;
}

void Row::short_bag(){
    string temp = col_list[cD_Bag];
    if(strlen(temp.c_str())>4){
        string temp2 = temp.substr(7, 6);
        temp2.insert(4, "-");

        col_list[cShort_bag_number] = temp2;
        max_size++;
    }
    
    fill();
}

void Row::fill(){
    col_list.resize(max_size+1, "0");
}

void Row::empty(){
    for(int i = 0; i < max_size; i++){
        col_list[i] = "";
    }
}

void Row::filter(int pass[]){
    for(int i = 0; i < max_size; i++){
        if(i != pass[i]){
            col_list[i] = "";
        }
    }
}

void Row::append(Row rhs){
    col_list.reserve( col_list.size() + rhs.col_list.size() ); // preallocate memory
    col_list.insert( col_list.end()-1, rhs.col_list.begin(), rhs.col_list.end() );
    max_size  += rhs.max_size+1;
}

void Row::swap(Row rhs){
    Row temp;
    temp.col_list = col_list;
    temp.index = index;
    temp.max_size = max_size;

    col_list = rhs.col_list;
    index = rhs.index;
    max_size = rhs.max_size;

    rhs.col_list = temp.col_list;
    rhs.index = temp.index;
    rhs.max_size = temp.max_size;
}

void Row::operator=(Row rhs){
    col_list = rhs.col_list;
    index = rhs.index;
    max_size = rhs.max_size;
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
    col_list.push_back("-");
}

Row::~Row(){
    col_list.clear();
    //delete[] col_list;
}
