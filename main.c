#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <ctype.h>
#include <windows.h>


void displayColumnSummary(int);
void calcStDev(int);
void handleMissingValues(int);
int variableType(int);




int main() {

    char path[200];
    char data[100][100];
    int rowNum, colNum, nullNum;
    int r,c=0;



    printf("---------Command Line Data Cleaner---------");

    //take file path as an input
    printf("\n\n");
    printf("Enter the path of the csv file: ");
    gets(path);

    //open the file from the file path
    FILE *fptr ;
    
    fptr = fopen(path,"r");
 
    if(fptr == NULL){
        printf("Invalid File Type! Cannot read the file .");
        exit(0);
    }

    char row[1500];


        
        while(fgets(row, 500, fptr)!=NULL){
            char *token = strtok(row, ",");
            while(token!=NULL){
                data[r][c] = val;
                c++;
                token = strtok(NULL, ",");
            }
            r++;
        }



    fclose(fptr);
    return 0;
}

void displayColumnSummary(int colIndex){

}

void calcStDev(int colIndex){

}

void handleMissingValues(int colIndex){

}

int variableType(int colIndex){

}