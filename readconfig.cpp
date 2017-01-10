//-----------------------------------------------------------------

int table::readConfig(string configFile){
//-----------------------------------------------------------------
    //open the file streams
    fstream sConfig;
    sConfig.open("Config.txt");

    //check they opened correcly
    if(!sConfig.is_open()){
        printf("Config File did not open.\n");
        return 1;
    }

    //add each row from the client file
    int end = 1;//set the end flag to 1
    int row_index = 1;
    while(!sConfig.eof() && end == 1 ){    //while not at the end of the file && end is 1
        printf("Reading Config Row %i\n",row_index;
        //get a copy of the line(row)
        string tempS;
        getline(sConfig, tempS, '\n');
        string tempString = tempS;
        vector<string> result;
        string substr;
        tempString = tempString.substr(0, tempString.size()-1);//remove the newline
        stringstream ss(tempString);

        //Parse the String
        int count = 0;
        while( ss.good() )//while the string has values
        {
            string sub;
            getline( ss, sub, ' ' );//get the substring
            substr = sub;
            count++;
            result.push_back( substr );//push it to the vector
        }

        //call the appropriate function
        if(result[0].compare("Skip") == 0){
            if(result[1].compare("Headers") == 0){
                readSkipHeaders(result);
            }
            else if(result[1].compare("Cells") == 0){
                readSkipCells(result);
            }
            else if(result[1].compare("FirstLine") == 0)
                readSkipFirstLine(result);
        }
        else if{(result[0].compare("ColumnsToPrint") == 0)
            readColumnsToPrint(result);
        }
        else if(result[0].compare("Command") == 0){
            readCommandToPrint(result);
        }
        else{
            printf("Config File not in correct format\n");
        }

        //print the string to troubleshoot
        printf("Printing Parsed String\n");
        for(int i = 0; i<count; i++){
            printf("%i: %s\n", i, result[i].c_str());
        }
        printf("Finished Printing Parsed String\n");
        end = 0;
    }
}
//-----------------------------------------------------------------
//         //temp vars
//         string tempString;
//         vector<string> result;
//         string substr;
//         stringstream ss(tempString);

//         getline(sConfig, tempString, '\r'); //get a copy of the line(row)
//         tempString = temp.substr(NewLine, tempString.size()-1);//remove the return carrage
//         while( ss.good() )//while the string has values
//         {
//             getline( ss, substr, ',' );//get the substring
//             result.push_back( substr );//push it to the vector
//         }

//         if(result[0].compare("Skip") == 0){
//             if(result[1].compare("Headers") == 0){

//             }
//             else if(result[1].compare("Cells") == 0){

//             }
//             else if(result[1].compare("FirstLine") == 0)

//         }
//         else if{(result[0].compare("ColumnsToPrint") == 0)

//         }
//         else if(result[0].compare("Command") == 0){

//         }
//         else{
//             printf("Config File not in correct format\n");
//         }

//         end = add_cli(cli_rows);    
//         cli_rows += end;                //add 1 to the client rows for each row we add
//     }

//     //create temp vars
//     string tempString;
//     Row tempDynRow(0, D_Cols_Total);

//     //set the starting values for the string iterator
//     int NewIt;
//     if(INDEX > 0){
//         NewIt = 1;
//     }else{
//         NewIt = 0;
//     }
//     int OldIt = NewIt;

//     //get the row as a string
//     getline(sysconf, tempString, '\r');
//     //if(INDEX >100){printf("String: %s",tempString.c_str());}

//      //check if we're at the end of the report
//     if(tempString.substr(1, 13)=="End of Report"){
//         //printf("failed.\n");
//         printf("Reached end of report\n");
//         return 0;
//     }

//     //parse the string
//     for(int i = 0; i<D_Cols_Total; i++){
//         while(  tempString[NewIt] != ',' &&
//                 tempString[NewIt] != '\r' && 
//                 //tempString[NewIt] != '\n' && 
//                 tempString[NewIt]  ){
//             if(tempString[NewIt] == '"'){
//                 NewIt++;
//                 while(tempString[NewIt] != '"'){
//                     NewIt++;
//                 }
//                 NewIt++;
//             }
//             else{
//                 NewIt++;
//             }
//         }
//         //add the entry to the row
//         string tempSub = tempString.substr(OldIt, NewIt-OldIt);
//         //printf("Adding Sub string %i: %s\n", i, tempSub.c_str());
//         tempDynRow.add(tempSub);
        
//         //printf("Testing Sub string %i: %s\n", i, tempDynRow.col_list[i].c_str());
        
//         NewIt++;
//         OldIt = NewIt;
//     }

//     tempDynRow.fill();
//     dyn_row_list.push_back(tempDynRow);
//     printf("added.\n");
//     return 1;
//     //printf("Testing Dyn Row: %s\n\n",(dyn_row_list[index]).col_list[5].c_str());

// }
// //-----------------------------------------------------------------