enum DynCols{
//dynamic trans
    D_Client_Location,
    D_Site_No,
    D_Deposit_Date,
    D_Collection_Date,
    //D_Emtpty1,
    D_Ref_Num_PIS,
    D_STC,
    D_Location_Total,
    D_Cheques,
    D_GBP,
    D_Empty2,
    D_Euro_Notes_Total,
    D_Euro_Coin_Total,
    D_Cash_Total,
    D_Bag,
    D_Inner_Bag,
    D_Difference,
    D_Comments,

    //total
    D_Cols_Total
};

//pennies
// enum penneyesDynCols{
// //dynamic trans
//     D_Client_Location,
//     D_Site_No,
//     D_Deposit_Date,
//     D_Emtpty1,
//     D_Ref_Num_PIS,
//     D_STC,
//     D_Location_Total,
//     D_Cheques,
//     D_GBP,
//     D_Empty2,
//     D_Euro_Notes_Total,
//     D_Euro_Coin_Total,
//     D_Cash_Total,
//     D_Bag,
//     D_Difference,
//     D_Comments,

//     //total
//     D_Cols_Total
// };

enum CliCols{
    //client detailed
    C_Customer_Name,
    C_Site_Name,
    C_Customer_Code,
    C_Date,
    C_Transaction_type,
    C_Process_type,
    C_Quantity,
    C_ID_Processed,
    C_Total_Notes,
    C_Total_Coins,
    C_Total_Cash,
    C_500,
    C_200,
    C_100,
    C_50,
    C_20,
    C_10,
    C_5,
    C_2,
    C_1,
    C_50c,
    C_20c,
    C_10c,
    C_5c,
    C_2c,
    C_1c,
    C_Mixed_Coin,
    C_BIC,
    C_IBAN,
    C_PAYDAY,
    
    //total
    C_Cols_Total
};

enum ComCols{
    //client detailed
    cC_Customer_Name,
    cC_Site_Name,
    cC_Customer_Code,
    cC_Date,
    cC_Transaction_type,
    cC_Process_type,
    cC_Quantity,
    cC_ID_Processed,
    cC_Total_Notes,
    cC_Total_Coins,
    cC_Total_Cash,
    cC_500,
    cC_200,
    cC_100,
    cC_50,
    cC_20,
    cC_10,
    cC_5,
    cC_2,
    cC_1,
    cC_50c,
    cC_20c,
    cC_10c,
    cC_5c,
    cC_2c,
    cC_1c,
    cC_Mixed_Coin,
    cC_BIC,
    cC_IBAN,
    cC_PAYDAY,
    
    //dynamic trans
    cD_Client_Location,
    cD_Site_No,
    cD_Deposit_Date,
    cD_Collection_Date,
    //cD_Emtpty1,
    cD_Ref_Num_PIS,
    cD_STC,
    cD_Location_Total,
    cD_Cheques,
    cD_GBP,
    cD_Empty2,
    cD_Euro_Notes_Total,
    cD_Euro_Coin_Total,
    cD_Cash_Total,
    cD_Bag,
    cD_Inner_Bag,
    cD_Difference,
    cD_Comments,
    cShort_bag_number,

    //total
    c_Cols_Total
};