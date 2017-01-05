#include <stdio.h>  // printf() etc.
#include <string.h> // strcpy(), strlen() etc.
#include <math.h>
#include <iostream>
#include <fstream>
#include <vector>
#include "Row.hpp"
//#include "Enum_Columns.cpp"
using namespace std;

class table{
    public:
    vector<Row> row_list;
    int index;
    fstream sCli, sDyn;

    void test(int INDEX);

    int add(int INDEX);
    void print();
    table(int test, string Dynamic, string Client);
    table(string Dynamic, string Client);
    ~table();
};