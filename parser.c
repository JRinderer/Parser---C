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
             if(currentChar!='\t'){
                 build2dArry(token, intlArryi, intlArryj, currentChar, filePntr, chrType);
             }else{
                 filePntr=skipTabs(currentChar, filePntr);
                 currentChar=fgetc(filePntr);
                 chrType=charType(currentChar);
                 build2dArry(lexem, intlArryi, intlArryj, currentChar, filePntr, chrType);
             }
             //if(currentChar!='\t') {
                 //This will determine if we're at a \t char but I need to skip the chars here and move to the next
                 //char that's not a \t.
                 //build2dArry(token, intlArryi, intlArryj, currentChar, filePntr, chrType);

             //}else if(currentChar=='\t'){
               //  filePntr=skipTabs(currentChar, filePntr);
                // currentChar=fgetc(filePntr);
                 //chrType=charType(currentChar);
                 //build2dArry(lexem, intlArryi, intlArryj, currentChar, filePntr, chrType);
            // }
             //parseProg(token[intlArryi])
             printf("The token is %s\n",token[intlArryi]);
             if(lexem[intlArryi]!=NULL) {
                 printf("The lexem is %s\n", lexem[intlArryi]);
             }
             intlArryi++; intlArryj=0;
             fseek(filePntr, -1, SEEK_CUR);
             if((testChar(currentChar,'\n')==0)){
                 lineNo++;
             }
         }
     }
}

int skipTabs(char c, FILE *fp){
    do{
        c=fgetc(fp);
    }while (c=='\t');
    fseek(fp,-1,SEEK_CUR);
    return fp;
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