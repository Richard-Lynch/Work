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
    string DynamicFile = "Dyn1.csv";
    string ClientFile = "Cli1.csv";

    table Dix(DynamicFile, ClientFile);
    Dix.print();



    //row values[Length];

    //char DynamicFile[Length] = "Dyn1.csv";
    // printf("Please enter file name: ");
    // cin.getline(inputFile, stringLength);
    // printf("\n");

    // std::ifstream Input;
    // Input.open(inputFile);

    // if(!Input.is_open()){
    //     printf("File did not open.\n");
    //     return 1;
    // }
    // int i = 0;
    // while(!Input.eof()){
    //     getline(Input, values[i].Row, '\r');
    //     values[i].index = i;
    //     i++;
    // }
    
    // for(int j = 0; j<i; j++){
    //     printf("%s \n", (values[j]).Row.c_str());
    // }

    // Input.close();

    return 0;
}