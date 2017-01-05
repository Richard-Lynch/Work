#include <stdio.h>  // printf() etc.
#include <string.h> // strcpy(), strlen() etc.
#include <math.h>
#include <iostream>
#include <fstream>
#include <vector>
#include "Enum_Columns.cpp"
using namespace std;

class Row{
    public:
    vector <string> col_list;
    int index;
    int max_size;

    void fill();
    int add(string value);
    Row(int Index, int size);
    Row();
    ~Row();
};