#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <ctype.h>
#include <windows.h>


int main() {

    char path[20];
    char val[30];

    printf("---------Command Line Data Cleaner---------");

    //take file path as an input
    printf("\n\n");
    printf("Enter the path of the csv file: ");
    gets(path);

    //open the file from the file path
    FILE * fptr;
    fptr = fopen (path,"w+");

    if(fptr == NULL){
        printf(“File type invalid!”);
        exit(1);
    }
    else{
        
    }


    fclose(fptr);
    printf("\n ---------Chalyo---------");
    
    return 0;
}
