#include <stdio.h>  // printf() etc.
#include <string.h> // strcpy(), strlen() etc.
#include <math.h>
#include <iostream>
#include <fstream>
#include "table.hpp"
using namespace std;

int table::add_cli(int INDEX){
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
    //if(INDEX >66){printf("String: %s",tempString.c_str());}

    //check if we're at the end of the report
    if(tempString.substr(1, 13)=="End of Report"){
        printf("Reached end of report\n");
        return 0;
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
    return 1;
    //printf("Testing Client Row: %s\n\n",(cli_row_list[index]).col_list[8].c_str());
}
//-----------------------------------------------------------------

int table::add_dyn(int INDEX){
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
    //if(INDEX >100){printf("String: %s",tempString.c_str());}

     //check if we're at the end of the report
    if(tempString.substr(1, 13)=="End of Report"){
        printf("Reached end of report\n");
        return 0;
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
    return 1;
    //printf("Testing Dyn Row: %s\n\n",(dyn_row_list[index]).col_list[5].c_str());

}
//-----------------------------------------------------------------

int table::align(){
    int swapped = 0;
    for(int i = 0; i < cli_rows; i++){
        //check if the rows match
        if( cli_row_list[i].col_list[C_ID_Processed].compare(dyn_row_list[i].col_list[D_Bag]) != 0||
            cli_row_list[i].col_list[C_Total_Notes].compare(dyn_row_list[i].col_list[D_Euro_Notes_Total]) != 0||
            cli_row_list[i].col_list[C_Total_Coins].compare(dyn_row_list[i].col_list[D_Euro_Coin_Total]) != 0||
            cli_row_list[i].col_list[C_Total_Cash].compare(dyn_row_list[i].col_list[D_Cash_Total])!= 0    ){   
                //if they dont
                int j = i;
                while ( j<dyn_rows-1 && ( 
                        cli_row_list[i].col_list[C_ID_Processed].compare(dyn_row_list[j].col_list[D_Bag]) != 0||
                        cli_row_list[i].col_list[C_Total_Notes].compare(dyn_row_list[j].col_list[D_Euro_Notes_Total]) != 0||
                        cli_row_list[i].col_list[C_Total_Coins].compare(dyn_row_list[j].col_list[D_Euro_Coin_Total]) != 0||
                        cli_row_list[i].col_list[C_Total_Cash].compare(dyn_row_list[j].col_list[D_Cash_Total])!= 0    )){
                            //if(j < dyn_rows-1){
                                j++;
                            //}
                            //else{
                              //  printf("AHHHHHHHH\n");
                               // break;
                                //}
                        }
                if(j < dyn_rows-1){
                    swapped = 1;
                    dyn_row_list[i].swap(dyn_row_list[j]);
                    dyn_row_list[i].index = i;
                    printf("Swapped %i with %i\n", i, j);
                }
                else{
                    printf("Couldnt Swap %i, reached end of dyn\n", i);
                }
            }
    }
    if(swapped == 0){
        printf("Nothing Swapped\n");
    }
    return swapped;
}

//-----------------------------------------------------------------

void table::test_print(){
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

void table::print(int cliCol, int dynCol){
    printf("Printing Rows: \n");
    printf("Index  Client               Dynamic \n");
    for(int i = 0; i<cli_rows;i++){
        printf("%i:     (%s)         (%s)\n", i+1, cli_row_list[i].col_list[cliCol].c_str(), dyn_row_list[i].col_list[dynCol].c_str());
    }    
    printf("\n");
}
//-----------------------------------------------------------------

void table::print(int* cols_to_print, int* from_file, int number_cols){
    printf("Printing Rows: \n");
    string temp;
    for(int i = 0; i<max_rows;i++){
        printf("%i: ", i+1);
        for(int j = 0; j<number_cols; j++){
            if(from_file[j] == 0){
                temp =  cli_row_list[i].col_list[cols_to_print[j]];
            }else if(from_file[j] == 1){
                temp = dyn_row_list[i].col_list[cols_to_print[j]];
            }else{
                printf("ERROR!!!\n");
            }
            printf("%s ", temp.c_str());
        }
        printf("\n");
    }    
    printf("Finished Printing Rows\n");
}

//-----------------------------------------------------------------
// void table::output(int* cols_to_print, int* from_file, int number_cols){
//     printf("Printing Rows: \n");
//     string temp;
//     for(int i = 0; i<max_rows;i++){
//         printf("%i: ", i+1);
//         for(int j = 0; j<number_cols; j++){
//             if(from_file[j] == 0){
//                 temp =  cli_row_list[i].col_list[cols_to_print[j]];
//             }else if(from_file[j] == 1){
//                 temp = dyn_row_list[i].col_list[cols_to_print[j]];
//             }else{
//                 printf("ERROR!!!\n");
//             }
//             printf("%s ", temp.c_str());
//         }
//         printf("\n");
//     }    
//     printf("Finished Printing Rows\n");
// }

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
    int end = 1;
    while(!sCli.eof()&& end == 1 ){
        printf("adding client row %i\n",cli_rows);
        end = add_cli(cli_rows);
        cli_rows += end;
    }

    end = 1;
    while(!sDyn.eof()&& end == 1){
        printf("adding dynamic row %i\n",dyn_rows);
        end = add_dyn(dyn_rows);
        dyn_rows += end;
    }

    if(cli_rows < dyn_rows){
        max_rows = cli_rows;
    }else{
        max_rows = dyn_rows;
    }

    print(C_ID_Processed, D_Bag);
    align();
    print(C_ID_Processed, D_Bag);
    align();
    print(C_ID_Processed, D_Bag);

    int print_cols[] = {C_Customer_Code, D_Site_No, D_Client_Location, D_Deposit_Date, D_Ref_Num_PIS,D_STC, D_Euro_Notes_Total, D_Euro_Coin_Total, D_Cash_Total,D_Difference,D_GBP,D_Cols_Total,
    C_200, C_100, C_50, C_20, C_10, C_5, C_2, C_1, C_50c, C_20c, C_10c, C_5c, C_2c, C_1c};
    int cols_file[] = {0, 1, 1, 1, 1,1, 1, 1, 1, 1,1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};

    print(print_cols, cols_file, 26);

}
//-----------------------------------------------------------------

table::~table(){
    cli_row_list.clear();
    dyn_row_list.clear();
    sCli.close();
    sDyn.close();
}