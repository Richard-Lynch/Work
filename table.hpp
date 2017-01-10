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
    //variables
    vector<Row> cli_row_list;
    vector<Row> dyn_row_list;
    vector<Row> combined_row_list;
    int cli_rows;
    int dyn_rows;
    int max_rows;
    int combined_rows;
    fstream sCli, sDyn;
    //variables

    //read files
    int add_cli(int INDEX);
    int add_dyn(int INDEX);
    int align();
    //int align2();
    int combine();

    //config
    int readConfig(string configFile);
    void readSkipHeaders(vector<string> result);
    void readSkipCells(vector<string> result);
    void readSkipFirstLine(vector<string> result);
    void readColumnsToPrint(vector<string> result);
    void readCommandToPrint(vector<string> result);
    //config

    //print
    void test_print();
    void print(int cliCol, int dynCol);
    void print(int* cols_to_print, int* from_file, int number_cols);
    void print_combined_row(int* cols_to_print, int number_cols);
    //print

    //output
    void output(int cols_to_print[], int number_cols, string file, int t, int t_pass[]);
    void output_dixons();
    void output_pen();
    //output

    //Constuctor and Destructor
    table(int test, string Dynamic, string Client);
    ~table();
    //Constuctor and Destructor
};