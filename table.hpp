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
    vector<Row> cli_row_list;
    vector<Row> dyn_row_list;
    vector<Row> combined_row_list;
    //int index;
    int cli_rows;
    int dyn_rows;
    int max_rows;
    int combined_rows;
    fstream sCli, sDyn;

    //void test(int INDEX);
    int add_cli(int INDEX);
    int add_dyn(int INDEX);

    int align();
    //int align2();
    int combine();

    void test_print();
    void print(int cliCol, int dynCol);
    void print(int* cols_to_print, int* from_file, int number_cols);
    void print_combined_row(int* cols_to_print, int number_cols);
    void output(int cols_to_print[], int number_cols, string file, int t, int t_pass[]);
    void output_dixons();
    void output_pen();
    table(int test, string Dynamic, string Client);
    //table(string Dynamic, string Client);
    ~table();
};