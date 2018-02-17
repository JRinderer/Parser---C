//
// Created by jrinder on 2/9/18.
//
#include "token.h"
#include <stdio.h>
#include <memory.h>
#include "parser.h"
#include "scanner.h"

void startParser(){
    FILE *filePntr;
    char currentChar;
    int intI;
    int intJ;
    int intA;
    int intB;
    int chrType;
    char token[LIMIT][MAX];
    char lexem[LIMIT][MAX];
    int lineNo=1;
    int totalI=0;


    //====================================OPEN THE .SCAN FILE==========================================================
    if ((filePntr = fopen("scnr.scan", "r"))==NULL){
        printf("Error unable to open .scan file.\n"); //if the file returns null this error is printed otherwise the
        //above statement sets the file pointer equal to the given file
    }
    //>>>>>>>>>>>>>>>>>>>>>>Before we can even begin parsing the TOKENS and LEXEME we have to build the chars into
    //>>>>>>>>>>>>>>>>>>>>>>words as we did in the scanner. Once we've built the words we can then begin parsing them
    //
     fseek(filePntr, 0, SEEK_END);
     if(isEmpty(filePntr)==1){
         printf("The .scan file is empty\n");
     }else {
         rewind(filePntr);
         reset:
         while((currentChar=fgetc(filePntr))!='.'){
             chrType = charType(currentChar);
             if(currentChar=='\n'){
                 currentChar=fgetc(filePntr);
                 fseek(filePntr, -1, SEEK_CUR);
                 goto reset;
             }
             if(currentChar!='\t'){
                 build2dArry(token, intI, intJ, currentChar, filePntr, chrType);
                 intI++; intJ=0;
             }else if(currentChar=='\t'){
                 filePntr=skipTabs(currentChar, filePntr);
                 currentChar=fgetc(filePntr);
                 chrType=charType(currentChar);
                 build2dArry(lexem, intA, intB, currentChar, filePntr, chrType);
                 intA++; intB=0;
             }
             totalI++;
             fseek(filePntr, -1, SEEK_CUR);
             if((testChar(currentChar,'\n')==0)){
                 lineNo++;
             }
         }
     }
    int a = 0;
    for(int i=0;i<(totalI/2);i++){
        printf("The TOKEN is %s\n",token[i]);
        printf("The LEXEME IS %s\n",lexem[i]);
    }

}
//=====================================Function to ignore tabs=========================================================
int skipTabs(char c, FILE *fp){
    do{
        c=fgetc(fp);
    }while (c=='\t');
    fseek(fp,-1,SEEK_CUR);
    return fp;
}
//=====================================================================================================================
//====================================Function to test if file is empty================================================
int isEmpty(FILE *fp){
    if(ftell(fp)==0){
        return 1; //1 is error
    }else{
        return 0; //0 is correct
    }
}
//=====================================================================================================================
