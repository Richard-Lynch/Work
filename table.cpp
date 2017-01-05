#include <stdio.h>  // printf() etc.
#include <string.h> // strcpy(), strlen() etc.
#include <math.h>
#include <iostream>
#include <fstream>
#include "table.hpp"
// #include "Enum_Columns.cpp"
using namespace std;

void table::add_cli(int INDEX){
    //create temp vars
    string tempString;
    Row tempCliRow(INDEX, C_Cols_Total);

    //set the starting values for the string iterator
    int NewIt;
    if(INDEX > 0){
        NewIt = 1;
    }else{
        NewIt = 0;
    }
    int OldIt = NewIt;

    //get the row as a string
    getline(sCli, tempString, '\r');
    if(INDEX >66){printf("String: %s",tempString.c_str());}

    //check if we're at the end of the report
    if(tempString.substr(0, 12)=="End of Report"){
        return;
    }

    //parse the string
    for(int i = 0; i<C_Cols_Total; i++){
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

        //printf("Adding Sub string: %s\n", tempSub.c_str());
        tempCliRow.add(tempSub);
        NewIt++;
        OldIt = NewIt;
    }

    tempCliRow.fill();

    cli_row_list.push_back(tempCliRow);
    //printf("Testing Client Row: %s\n\n",(cli_row_list[index]).col_list[8].c_str());
}
//-----------------------------------------------------------------

void table::add_dyn(int INDEX){
    //create temp vars
    string tempString;
    Row tempDynRow(INDEX, D_Cols_Total);

    //set the starting values for the string iterator
    int NewIt;
    if(INDEX > 0){
        NewIt = 1;
    }else{
        NewIt = 0;
    }
    int OldIt = NewIt;

    //get the row as a string
    getline(sDyn, tempString, '\r');
    if(INDEX >100){printf("String: %s",tempString.c_str());}

     //check if we're at the end of the report
    if(tempString.substr(1, 13)=="End of Report"){
        return;
    }

    //parse the string
    for(int i = 0; i<D_Cols_Total; i++){
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
        //printf("Adding Sub string %i: %s\n", i, tempSub.c_str());
        tempDynRow.add(tempSub);
        //printf("Testing Sub string %i: %s\n", i, tempDynRow.col_list[i].c_str());
        
        NewIt++;
        OldIt = NewIt;
    }

    tempDynRow.fill();
    dyn_row_list.push_back(tempDynRow);
    //printf("Testing Dyn Row: %s\n\n",(dyn_row_list[index]).col_list[5].c_str());

}
//-----------------------------------------------------------------



//-----------------------------------------------------------------


int table::add(int INDEX)
{return 0;}
// int table::add(int INDEX)
// {
//     //add values from Client
//     string tempString;
//     Row tempRow(INDEX);
//     int NewIt = 0;
//     int OldIt = 0;
//     //get the row as a string
//     getline(sCli, tempString, '\r');
//     //parse the string
//     for(int i = 0; i<D_Client_Location; i++){
//         while(  tempString[NewIt] != ',' &&
//                 tempString[NewIt] != '\r' && 
//                 tempString[NewIt] != '\n' && 
//                 tempString[NewIt]  ){
//                     NewIt++;
//                 }
//         //add the entry to the row
//         string tempSub = tempString.substr(OldIt, NewIt-OldIt);
//         tempRow.add(i, tempSub);
//         OldIt = NewIt;
//     }

//     //Add details from Dynamic
//     NewIt = 0;
//     OldIt = 0;
//     getline(sDyn, tempString, '\r');
//     //parse the string
//     for(int i = D_Client_Location; i<COLS_total; i++){
//         while(  tempString[NewIt] != ',' &&
//                 tempString[NewIt] != '\r' && 
//                 tempString[NewIt] != '\n' && 
//                 tempString[NewIt]  ){
//                     NewIt++;
//                 }
//         //tempRow.col_list[i] = tempString.substr(OldIt, NewIt-OldIt);
//         //add the entry to the row
//         string tempSub = tempString.substr(OldIt, NewIt-OldIt);
//         int test = tempRow.add(i, tempSub);
            
//         if(test == 1){
//             printf("issue adding col %i of row %i \n", i, INDEX);
//         }
//         OldIt = NewIt;
//     }

//     //Add the Row to the Table
//     row_list.push_back(tempRow);

//     return 1;
// }

//-----------------------------------------------------------------


void table::print(){
    for(int i = 0; i<cli_rows; i++){
        for(int j = 0; j<C_Cols_Total; j++){
            printf("%s [] ", ((cli_row_list[i]).col_list[j]).c_str());
        } 
    }
    for(int i = 0; i<dyn_rows; i++){
        for(int j = 0; j<D_Cols_Total; j++){
            printf("%s [] ", ((dyn_row_list[i]).col_list[j]).c_str());
        }
    } 
}

//-----------------------------------------------------------------

table::table(int T, string Dynamic, string Client){
    cli_rows = dyn_rows = 0;

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

    while(!sCli.eof()){
        printf("adding client row %i\n",cli_rows);
        add_cli(cli_rows);
        cli_rows++;
    }

    while(!sDyn.eof()){
        printf("adding dynamic row %i\n",dyn_rows);
        add_dyn(dyn_rows);
        dyn_rows++;
    }

    printf("Testing Rows: \n");
    for(int i = 0; i<cli_row_list.size();i++){
        printf("Testing Client Row %i: %s\n", i, (cli_row_list[i]).col_list[8].c_str());
    }    
    printf("\n");
    for(int i = 0; i<dyn_row_list.size(); i++){
        printf("Testing Dyn Row %i: %s\n", i, (dyn_row_list[i]).col_list[5].c_str());
    } 
    printf("\n");
}
//-----------------------------------------------------------------


// table::table(string Dynamic, string Client){
//     //index = 0;
//     //open the file streams
//     sCli.open(Client);
//     sDyn.open(Dynamic);
//     //check they opened correcly
//     if(!sCli.is_open()){
//         printf("Client Activity File did not open.\n");
//         return;
//     }
//     if(!sDyn.is_open()){
//         printf("Dynamic Transatic File did not open.\n");
//         return;
//     }
//     //clear the useless content at the top of the file
//     //(going to test input data first, will uncomment later - Richie)
//     string temp;
//     // for(int i = 0l i<1; i++){
//     //     getline(sCli, temp '\r');
//     // }
//     // for(int i = 0; i<4; i++){
//     //     getline(sDyn, temp '\r');
//     // }

//     temp = "";

//     while(!sCli.eof() && !sDyn.eof()){
//         printf("adding %i row\n",index);
//         add(index);
//         //test(index);
//         index++;
//     }
// }
//-----------------------------------------------------------------


table::~table(){
    cli_row_list.clear();
    dyn_row_list.clear();
    sCli.close();
    sDyn.close();
}