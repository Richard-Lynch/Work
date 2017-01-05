#include <stdio.h>  // printf() etc.
#include <string.h> // strcpy(), strlen() etc.
#include <math.h>
#include <iostream>
#include <fstream>
#include "table.hpp"
// #include "Enum_Columns.cpp"
using namespace std;

void table::test(int INDEX){
    //printf("Starting test.\n");
    string tempString;
    Row tempRow(INDEX);
    int NewIt;
    if(INDEX > 0){
        NewIt = 1;
    }else{
        NewIt = 0;
    }
    int OldIt = NewIt;
    //get the row as a string
    getline(sCli, tempString, '\r');
    // if(tempString.substr(0, 3)=="ISA"){
    //     return;
    // }

    //printf("Long Client string: %s\n", tempString.c_str());

    //parse the string
    for(int i = 0; i<D_Client_Location; i++){
        while(  tempString[NewIt] != ',' &&
                tempString[NewIt] != '\r' && 
                //tempString[NewIt] != '\n' && 
                tempString[NewIt]   ){
            if(NewIt > strlen(tempString.c_str())){
                break;
            }
            if(tempString[NewIt] == '"'){
                NewIt++;
                while(  tempString[NewIt] != '"'&&
                        tempString[NewIt] ){
                    NewIt++;
                }
                NewIt++;
            }
            else{
                NewIt++;
            }
        }
        if(NewIt > strlen(tempString.c_str())){
                break;
        }
        //add the entry to the row
        string tempSub = tempString.substr(OldIt, NewIt-OldIt);
        //remove endline
        // if(i == D_Client_Location-1){
        //     NewIt--;
        // }

        //printf("Adding Sub string: %s\n", tempSub.c_str());
        tempRow.add(i, tempSub);
        NewIt++;
        OldIt = NewIt;
    }

    // printf("Printing Cols Client from Row.\n");
    // for(int i = 0; i<D_Client_Location; i++){
    //     printf("Col %i: %s\n", i, tempRow.col_list[i].c_str());
    // }
    // printf("Finished Printing Cols from Row.\n");

    if(INDEX > 0){
        NewIt = 1;
    }else{
        NewIt = 0;
    }
    OldIt = NewIt;
    //get the row as a string
    getline(sDyn, tempString, '\r');

    //printf("Long Dynamic string: %s\n", tempString.c_str());

    //parse the string
    for(int i = D_Client_Location; i<COLS_total; i++){
        while(  tempString[NewIt] != ',' &&
                tempString[NewIt] != '\r' && 
                //tempString[NewIt] != '\n' && 
                tempString[NewIt]  ){
            if(tempString[NewIt] == '"'){
                NewIt++;
                while(tempString[NewIt] != '"'){
                    NewIt++;
                }
                NewIt++;
            }
            else{
                NewIt++;
            }
        }
        //add the entry to the row
        string tempSub = tempString.substr(OldIt, NewIt-OldIt);
        //remove endline
        // if(i == COLS_total-1){
        //     NewIt--;
        // }
        //printf("Adding Sub string: %s\n", tempSub.c_str());
        tempRow.add(i, tempSub);
        NewIt++;
        OldIt = NewIt;
    }

    // printf("Printing Dynamic Cols from Row.\n");
    // for(int i = D_Client_Location; i<COLS_total; i++){
    //     printf("Col %i: %s\n", i, tempRow.col_list[i].c_str());
    // }
    // printf("Finished Printing Cols from Row.\n");

    // printf("Printing ALL Cols from Row %i.\n", INDEX);
    // for(int i = 0; i<COLS_total; i++){
    //     printf("Col %i: %s\n", i, tempRow.col_list[i].c_str());
    // }

    //printf("Finished Printing Cols from Row %i.\n", INDEX);

     //printf("Adding Row to Table.\n");
    //Add the Row to the Table
    row_list.push_back(tempRow);
    printf("Testing Row: %s\n\n",(row_list[index]).col_list[8].c_str());
    //printf("Finished Adding Row.\n");


    //return 1;
    //printf("Ending test.\n");
}

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
        string tempSub = tempString.substr(OldIt, NewIt-OldIt);
        tempRow.add(i, tempSub);
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
        string tempSub = tempString.substr(OldIt, NewIt-OldIt);
        int test = tempRow.add(i, tempSub);
            
        if(test == 1){
            printf("issue adding col %i of row %i \n", i, INDEX);
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
            printf("%s [] ", ((row_list[i]).col_list[j]).c_str());
        }

    }

}
table::table(int T, string Dynamic, string Client){
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

    while(!sCli.eof() && !sDyn.eof()){
        printf("adding row %i\n",index);
        test(index);
        //test(index);
        index++;
    }

    printf("Testing Rows: \n");
    for(int i = 0; i<row_list.size();i++){
        printf("Testing Row %i: %s\n", i, (row_list[i]).col_list[8].c_str());
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
        //test(index);
        index++;
    }
}

table::~table(){
    row_list.clear();
    sCli.close();
    sDyn.close();
}