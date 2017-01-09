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

    void append(Row rhs);
    void swap(Row rhs);
    void fill();
    void empty();
    void filter(int pass[]);
    int add(string value);
    void operator=(Row rhs);
    void short_bag();
    Row(int Index, int size);
    Row();
    ~Row();
};