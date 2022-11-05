#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <windows.h>
#include "strsep.h"


void displayColumnSummary(int col[100][100]);
int nullFinder(int col[100][100], int colNum);
void handleMissingValues(int col[100][100], int colNum, int avg);
void calcStDev(int);
int variableType(int);




int main() {

    char path[200];
    int data[100][100];

    char *token;
    int val, rowNum, colNum, nullNum;
    int r=0;
    int c=0;



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



    while (!feof(fptr))
    {
        fgets(row, 1500, fptr);
        char * cpy = strdup(row);
         
        while( (token = strsep(&cpy, ",")) != NULL)
        {
            val = atoi(token);
            data[r][c] = val;
            c++;
        }
        c=0;
        r++;        
    }

// displays the data in the array
    // for(int i=0; i<100; i++){
    //     for(int j=0; j<15; j++){
    //         printf("%d\t", data[i][j]);
    // }
    // printf("\n");
    // }

displayColumnSummary(data);







//close the file
    fclose(fptr);
    return 0;
}

void displayColumnSummary(int col[100][100]){
    int i,j;
    int sum=0;
    int avg=0;
    char opt;
    int indexCount;

    printf("Please Eenter a method to fil the missing values:\nA.) Mean\nB.) Median\n\n =>");
    scanf("%c", &opt);

    switch(opt){

    case 'A':
        for(i=0; i<15; i++){
        nullFinder(col,i);
            for(j=0; j<100; j++){
                sum = sum + col[j][i];
            }
        avg = sum / (j-indexCount);
        printf("The average of colum %d is %d\n\n", i+1, avg);
        handleMissingValues(col, i, avg);
        sum=0;
        avg=0;
        }
            for(int i=0; i<100; i++){
        for(int j=0; j<15; j++){
            printf("%d\t", col[i][j]);
    }
    printf("\n");
    }
        break;

    case 'B':

        break;

    case 'C':
        break;

    }
}

int nullFinder(int col[100][100], int colNum){
    int indexCount = 0;

    for(int i=0; i<100; i++){
        if(col[i][colNum]==0){
            indexCount++;
        }
    }

    return indexCount;
}

void handleMissingValues(int col[100][100], int colNum, int avg){
    for(int i=0; i<100; i++){
        if(col[i][colNum]==0){
            col[i][colNum] = avg;
    }
}

}


void calcStDev(int data){

}



int variableType(int data){

}