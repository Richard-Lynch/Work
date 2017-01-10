#include <stdio.h>
#include <iostream>
#include <iomanip>
#include <stdlib.h>
#include <fstream>
#include <string.h>
#include <sstream>
#include "table.hpp"

int rows_to_ignore;
int num_cols;

int main(){
//-----------------------------------------------------------------
//ACTUAL 
    // string DynamicFile = "D_FINAL.csv";
    // string ClientFile = "C_FINAL.csv";

    // table Dix(1, DynamicFile, ClientFile);

//-----------------------------------------------------------------
    //string test
        // string temp = "Richard";
        // while(temp.size() > 0){
        //     printf("String: %s\n", temp.c_str());
        //     temp = temp.substr(0, temp.size()-1);
        // }

//-----------------------------------------------------------------

    // //parse test
    // string tempString = "Hey Its Me\n";    vector<string> result;
    // string substr;
    // tempString = tempString.substr(0, tempString.size()-1);//remove the newline
    // stringstream ss(tempString);
    // int count = 0;

    // while( ss.good() )//while the string has values
    // {
    //     string sub;
    //     getline( ss, sub, ' ' );//get the substring
    //     substr = sub;
    //     count++;
    //     result.push_back( substr );//push it to the vector
    // }

    // printf("Printing Parsed String\n");
    // for(int i = 0; i<count; i++){
    //     printf("%i: %s\n", i, result[i].c_str());
    // }
    // printf("Finished Printing Parsed String\n");

//-----------------------------------------------------------------
    //open the file streams
//     fstream sConfig;
//     sConfig.open("Config.txt");

//     //check they opened correcly
//     if(!sConfig.is_open()){
//         printf("Config File did not open.\n");
//         return 1;
//     }

//     //add each row from the client file
//     int end = 1;//set the end flag to 1
//     while(!sConfig.eof() && end == 1 ){    //while not at the end of the file && end is 1
//         printf("Reading Config Row %i\n",1);
//         //new
//             string tempS;
//             getline(sConfig, tempS, '\n'); //get a copy of the line(row)
//             //string tempString = "Hey Its Me\n"; 
//             string tempString = tempS;    
//             vector<string> result;
//             string substr;
//             tempString = tempString.substr(0, tempString.size()-1);//remove the newline
//             stringstream ss(tempString);
//             int count = 0;
            
//             while( ss.good() )//while the string has values
//             {
//                 string sub;
//                 getline( ss, sub, ' ' );//get the substring
//                 substr = sub;
//                 count++;
//                 result.push_back( substr );//push it to the vector
//             }

//             printf("Printing Parsed String\n");
//             for(int i = 0; i<count; i++){
//                 printf("%i: %s\n", i, result[i].c_str());
//             }
//             printf("Finished Printing Parsed String\n");
//             end = 0;
//         //eo new

//     }

// //-----------------------------------------------------------------
    return 0;
}