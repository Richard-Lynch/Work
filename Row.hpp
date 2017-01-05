#include <stdio.h>  // printf() etc.
#include <string.h> // strcpy(), strlen() etc.
#include <math.h>
#include <iostream>
#include <fstream>
#include "Enum_Columns.cpp"
using namespace std;

class Row{
    public:
    string col_list[COLS_total];
    int index;

    int add(int col_num, string value);
    Row(int Index);
    Row();
    ~Row();
};