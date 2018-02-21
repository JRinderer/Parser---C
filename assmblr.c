//
// Created by jrinder on 2/20/18.
//

#include <bits/types/FILE.h>
#include <stdio.h>
#include <memory.h>
#include "assmblr.h"
#include "token.h"

FILE *filePntr;

//============Define constants that will not change throughout the code. These are standard assemlby pieces.===========

//=====================================================================================================================
//===============Since I'm working with file I/O I have to create a .asm file to append code to.=======================
void createNewAsmFle(char *path){

    filePntr= fopen(path,"w");
    fclose(filePntr);
}
//=====================================================================================================================
//write data to asm
/*void writeLnesAsm(char * txt1, char * txt2){
    FILE * flPntr;
    char stngHldr[LIMIT]="";
    strcat(stngHldr,txt1);
    strcat(stngHldr, "\t\t\t");
    strcat(stngHldr,txt2);
    strcat(stngHldr,"\n");
    flPntr = fopen("scnr.scan","a");
    fputs(stngHldr,flPntr);
    fclose(flPntr);
}*/

//=======================================generates a newLine \n========================================================
void nullLine(){
    FILE *fp;
    fp = fopen("assmblr.asm","a");
    fputs(" \n",fp);
    fclose(fp);
}
//=====================================================================================================================
//===========================This will generate a line of assemlby code================================================
void printLines(char *lbl, char *opCode, char *var, char *cmnts){
    FILE *fp;

    fp = fopen("assmblr.asm","a");

    char strnHlder[LIMIT]="";
    strcat(strnHlder,lbl);
    strcat(strnHlder,opCode);
    strcat(strnHlder,var);
    strcat(strnHlder,cmnts);
    strcat(strnHlder,"\n");
    fputs(strnHlder,fp);
    fclose(fp);
}
//==========================Print the beginning section for ASM file===================================================
void printBeginAsm(){
    nullLine();
    printLines(";TEXT SECTION","","","");
    nullLine();
    printLines("\t\t\t","section","\t\t\t.txt","");
    nullLine();
    printLines("\t\t\t","global","\t\t\tmain","");
    nullLine();
    printLines("main:","\t\tnop","\t\t\t\t\t\t","\t\t\t;main PROC");
    printLines("\t\t\t","push","\t\t\trbp","");
    printLines("\t\t\t","mov","\t\t\t\trbp,rsp","");

}

void printNums(char *num){
    printLines("\t\t\t","push\t\t\t",num,"\t\t\t\t\t\t;emit numbers");

}

void printIdentifs(char *ident){
    char strnHldr[LIMIT]="";
    strcat(strnHldr,"qword ");
    strcat(strnHldr,"[");
    strcat(strnHldr,ident);
    strcat(strnHldr,"]");

    printLines("\t\t\t","push\t\t\t",strnHldr,"\t\t\t\t;print identifiers");
}

void printAssngment(char *assng){
    char strnHldr[LIMIT]="";
    strcat(strnHldr,"qword ");
    strcat(strnHldr,"[");
    strcat(strnHldr,assng);
    strcat(strnHldr,"]");

    printLines("\t\t\t","pop\t\t\t\t",strnHldr,"\t\t\t\t;print assignments");
}

void printAdditionLines(char *ops){
    printLines("\t\t\t","pop\t\t\t\t","rbx","\t\t\t\t\t\t;print addition ops");
    printLines("\t\t\t","pop\t\t\t\t","rax","");
    //if(strcmp(tokn,"+")
    if(!strcmp(ops,"+")){
        printLines("\t\t\t","add\t\t\t\t","rax,rbx","\t\t\t\t\t;adds the contents of rax and rbx");
    }else{
        printLines("\t\t\t","sub\t\t\t\t","rax,rbx","\t\t\t\t\t;subtracts the contents of rax and rbx");
    }
    printLines("\t\t\t","push\t\t\t","rax","");
}

void printMultiLines(char *ops){
    printLines("\t\t\t","pop\t\t\t\t","rbx","\t\t\t\t\t;print multiplcation/division");
    printLines("\t\t\t","pop\t\t\t\t","rax","");
    printLines("\t\t\t","mov\t\t\t\t","rdx,0","move a 0 into rdx");
    if(!strcmp(ops,"*")){
        printLines("\t\t\t","imul\t\t\t\t","rax,rbx","\t\t\t\t\t;multiply the two register");
        printLines("\t\t\t","push\t\t\t\t","rax","");
    }else if(!strcmp(ops,"/")){
        printLines("\t\t\t","idiv\t\t\t\t","rbx","\t\t\t\t\t;multiply the two register");
        printLines("\t\t\t","push\t\t\t\t","rax","");
    }
}