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
    int intlArryi;
    int intlArryj;
    int chrType;
    char token[LIMIT][MAX];
    char lexem[LIMIT][MAX];
    int lineNo=1;


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
         while((currentChar=fgetc(filePntr))!='.'){
             chrType = charType(currentChar);
             build2dArry(token,intlArryi,intlArryj, currentChar, filePntr, chrType);
             //parseProg(token[intlArryi]);
             intlArryi++; intlArryj=0;
             fseek(filePntr, -1, SEEK_CUR);
             if((testChar(currentChar,'\n')==0)){
                 lineNo++;
             }
         }
     }
}


/*void parseProg(char *strn){
    //First confirm that the declarations are made.
    if(!strcmp(strn,"DCL")){
        printf("You found a DCL!\n");
    }else if(!strcmp(strn, "IDENTIF")){
        printf("You found an IDENTIFIER\n");
    }else if(!strcmp(strn, "INT")){
        printf("You've found an INT\n");
    }

}*/

void parseDcls(char *token, char * lexeme){
    //if(strcmp(token,"DCL"){
}


int isEmpty(FILE *fp){
    if(ftell(fp)==0){
        return 1; //1 is error
    }else{
        return 0; //0 is correct
    }
}