#include <stdio.h>
#include <iostream>
#include <iomanip>
#include <stdlib.h>
#include <fstream>
#include <string.h>
#include "table.hpp"

//#include "Row.hpp"

//const int Length = 1000;
int rows_to_ignore;
int num_cols;


// struct row{
//     std::string Row;
//     int index;
// };
int main(){
    string DynamicFile = "D_FINAL.csv";
    string ClientFile = "C_FINAL.csv";

    table Dix(1, DynamicFile, ClientFile);

    return 0;
}