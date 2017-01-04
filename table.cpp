#include <stdio.h>  // printf() etc.
#include <string.h> // strcpy(), strlen() etc.
#include <math.h>
#include <iostream>
#include <fstream>
#include "table.hpp"
// #include "Enum_Columns.cpp"
using namespace std;

int table::add(int INDEX)
{
    //add values from Client
    string tempString;
    Row tempRow(INDEX);
    int NewIt = 0;
    int OldIt = 0;
    //get the row as a string
    getline(sCli, tempString, '\r');
    //parse the string
    for(int i = 0; i<D_Client_Location; i++){
        while(  tempString[NewIt] != ',' &&
                tempString[NewIt] != '\r' && 
                tempString[NewIt] != '\n' && 
                tempString[NewIt]  ){
                    NewIt++;
                }
        //add the entry to the row
        tempRow.add(i, tempString.substr(OldIt, NewIt-OldIt));
        OldIt = NewIt;
    }

    //Add details from Dynamic
    NewIt = 0;
    OldIt = 0;
    getline(sDyn, tempString, '\r');
    //parse the string
    for(int i = D_Client_Location; i<COLS_total; i++){
        while(  tempString[NewIt] != ',' &&
                tempString[NewIt] != '\r' && 
                tempString[NewIt] != '\n' && 
                tempString[NewIt]  ){
                    NewIt++;
                }
        //tempRow.col_list[i] = tempString.substr(OldIt, NewIt-OldIt);
        //add the entry to the row
        int test = tempRow.add(i, tempString.substr(OldIt, NewIt-OldIt))){
            
        if(test == 1){
            printf("issue adding col %i of row %j \n", i, INDEX);
        }
        OldIt = NewIt;
    }

    //Add the Row to the Table
    row_list.push_back(tempRow);

    return 1;
}

void table::print(){
    for(int i = 0; i<index; i++){
        for(int j = 0; j<COLS_total; j++){
            printf("%s ", ((row_list[i]).col_list[j]).c_str());
        }
    }

}

table::table(string Dynamic, string Client){
    index = 0;
    //open the file streams
    sCli.open(Client);
    sDyn.open(Dynamic);
    //check they opened correcly
    if(!sCli.is_open()){
        printf("Client Activity File did not open.\n");
        return;
    }
    if(!sDyn.is_open()){
        printf("Dynamic Transatic File did not open.\n");
        return;
    }
    //clear the useless content at the top of the file
    //(going to test input data first, will uncomment later - Richie)
    string temp;
    // for(int i = 0l i<1; i++){
    //     getline(sCli, temp '\r');
    // }
    // for(int i = 0; i<4; i++){
    //     getline(sDyn, temp '\r');
    // }

    temp = "";

    while(!sCli.eof() && !sDyn.eof()){
        printf("adding %i row\n",index);
        add(index);
        index++;
    }    
}

table::~table(){
    row_list.clear();
    sCli.close();
    sDyn.close();
}