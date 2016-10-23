#include "antet.h"

void antet(char *fnc, char *fnh)
{
    FILE *fph, *fpc;
    time_t curtime;

    const char search[3] = ".h";

    time(&curtime);

    if((fph = fopen(fnh, "w"))==NULL) {
        printf("Cannot open filename: %s.\n", fnh);
        exit(1);
    }
    fprintf(fph,"/**======================================================\n");
    fprintf(fph,"  File\t: %s\n", fnh);
    fprintf(fph,"  Author: Mihai Cornel\tmhcrnl@gmail.com\t0722270796\n");
    fprintf(fph,"  System: Ubuntu 16.04\tCode::Blocks 13.10\tgcc\n");
    fprintf(fph,"  System: Fedora 23   \tCode::Blocks 16.01\tgcc\n");
    fprintf(fph,"  Date\t: %s", ctime(&curtime));
    fprintf(fph,"  Util\t: \n");
    fprintf(fph,"=========================================================*/\n\n");

    //token = strtok(fnh, search);
//    while(token != NULL){
//        printf("Return first token: %s\n", token);
//        token = strtok(NULL, search);
//    }

    char upperCase[21];
    strcpy(upperCase, fnh);
    convertToUpperCase(&upperCase);

    char *token = strtok(upperCase, ".H");

    while(token){
        printf("TOKEN: %s\n", token);
        //upperCase = token;
        //putchar( toupper(token[i]));
        //strcat(upperCase, toupper(token[i]));
        token=strtok(NULL, " .H");
    }


    printf("UPPER_CASE: %s.\n", upperCase);

    fprintf(fph,"#ifndef %s_H_INCLUDED\n", upperCase);
    fprintf(fph,"#define %s_H_INCLUDED\n\n", upperCase);

    fprintf(fph, "#include <errno.h>\n");
    fprintf(fph, "#include <stdio.h>\n");
    fprintf(fph, "#include <stdlib.h>\n");
    fprintf(fph, "#include <string.h>\n\n");



    fprintf(fph, "#endf\n");
    fclose(fph);

    if((fpc = fopen(fnc, "w"))==NULL) {
        printf("Cannot open filename: %s.\n", fnc);
        exit(1);
    }
    fprintf(fpc,"/**=====================================================\n");
    fprintf(fpc,"  File\t: %s\n", fnc);
    fprintf(fpc,"  Author: Mihai Cornel \tmhcrnl@gmail.com  \t0722270796\n");
    fprintf(fpc,"  System: Ubuntu 16.04 \tCode::Blocks 13.10\tgcc\n");
    fprintf(fpc,"  System: Fedora 23    \tCode::Blocks 16.01\tgcc\n");
    fprintf(fpc,"  Date\t: %s", ctime(&curtime));
    fprintf(fpc,"  Util\t: \n");
    fprintf(fpc,"=========================================================*/\n\n");

    fprintf(fph, "#include \"%s\" \n", fnh);

    fclose(fpc);
}

void convertToUpperCase(char *sPtr)
{
    while(*sPtr != '\0'){
        *sPtr = toupper((unsigned char) *sPtr);
        ++sPtr;
    }
}

int makefile(void)
{
    char fmake[21] = "Makefile";
    FILE *fp;

    if((fp=fopen(fmake, "w")) == NULL){
        printf("File: %s.\n", fmake);
        return EXIT_FAILURE;
    }
    fprintf(fp,"runantet: main.c antet.c \n");
    fprintf(fp,"\tgcc -o runantet main.c antet.c -I.");

    printf("SUCCESS: file %s create.\n", fmake);
    fclose(fp);
    return EXIT_SUCCESS;
}

int readme(void)
{
    FILE *fp;
    char fn[] = "README.md";

    if((fp = fopen(fn, "w")) == NULL){
        printf("Cannot open filename: %s.\n", fn);
        return EXIT_FAILURE;
    }
    fprintf(fp, "# Project title \n");
    fprintf(fp, "One Paragraph of project description goes here. \n");

    fprintf(fp, "##Getting started \n");
    fprintf(fp, "These instructions will get you a copy of the project up and\
      running on your local machine for development and testing purposes. See\
      deployment for notes on how to deploy the project on a live system.\n");

    fprintf(fp,"###Prerequisites \n");
    fprintf(fp,"What things you need to install the software and how to install them.\n");
    fprintf(fp, "``` Give Example ```\n");

    fprintf(fp, "###Instalation \n");
    fprintf(fp, "A step by step series of examples that tell you have to get a development env running.\n");
    fprintf(fp, " ``` \n");
    fprintf(fp, " Give example \n");
    fprintf(fp, " ``` \n");

    fprintf(fp, "##Code Example \n");
    fprintf(fp, " ```C \n");
    fprintf(fp, " Give example \n");
    fprintf(fp, " ``` \n");

    fprintf(fp, "##Build Width \n");
    fprintf(fp, "* [Code::Blocks](http://www.codeblocks.org/) - The framework used.\n");

    fprintf(fp, "##API Referance \n");

    fprintf(fp, "##Tests \n");

    fprintf(fp, "##Contributors \n");
    fprintf(fp, "* [Mihai Cornel](https://github.com/mhcrnl)  \n");

    fprintf(fp, "##Licence \n");
    fprintf(fp, "Copyright (c) 2016 [Mihai Cornel](https://github.com/mhcrnl). \n");
    fprintf(fp, "Permission is hereby granted, free of charge, to any person obtaining\
     a copy of this software and associated documentation files (the \"Software\"), to\
     deal in the Software without restriction, including without limitation the rights\
     to use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of\
     the Software.\n");

    fclose(fp);
    printf("Create file name %s width SUCCESS.\n", fn);
    return EXIT_SUCCESS;
}

int run(void)
{
    int optiune;
    char fnc[20];
    char fnh[20];

    puts("Salut!, from automation_file_cration.");
    do{
        puts("\t\t\t MENIU ");
        puts("\t1.\tCreate filename.c and filename.h.");
        puts("\t2.\tCreate file README.md.");
        puts("\t3.\tCreate file Makefile.");

        puts("\t5.\tEXIT.");
        puts("Insert your option:");
        scanf("%d", &optiune);
        switch(optiune){
            case 1:
                puts("Introduce-ti numele fisierului cu extensia c(filename.c): ");
                scanf("%s", fnc);
                puts("Introduce-ti numele fisierului cu extensia h(filename.h): ");
                scanf("%s", fnh);
                antet(fnc, fnh);
                break;
            case 2:
                readme();
                break;
            case 3:
                makefile();
                break;

            case 5:
                printf("Number of line code writen in program: %d", __LINE__);
                exit(0);
        }
    }while(1);
    return(EXIT_SUCCESS);
}
