#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <windows.h>
#include "strsep.h"


void replaceEmptyFields(int col[100][100]);
int nullFinder(int indexes[100], int col[100][100], int colNum);
void handleMissingValues(int col[100][100], int colNum, int avg);
void sortValues(int col[100]);
int calcMedian(int col[100], int n);


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

replaceEmptyFields(data);
for(int i=0; i<100; i++){
        for(int j=0; j<15; j++){
            printf("%d\t", data[i][j]);
    }
    printf("\n");
}

//close the file
    fclose(fptr);
    return 0;
}

void replaceEmptyFields(int col[100][100]){
    int i,j;
    int z=0;
    int sum=0;
    int avg=0;
    int median;
    char opt;
    int indexes[100]={};
    int indexCount;
    int colcpy[100];

    printf("Please Eenter a method to fil the missing values:\nA.) Mean\nB.) Median\n\n =>");
    scanf("%c", &opt);

    switch(opt){

    case 'A':
        for(i=0; i<15; i++){
        indexCount = nullFinder(indexes, col,i);
            for(j=0; j<100; j++){
                sum = sum + col[j][i];
            }
        
        avg = sum / (j-indexCount);
        handleMissingValues(col, i, avg);
        sum=0;
        avg=0;
        }
        break;

    case 'B':
        for(int i=0; i<15; i++){
            indexCount = nullFinder(indexes, col,i);
            for(j=0; j<100; j++){
                if (col[j][i]!=0){
                    colcpy[z]= col[j][i];
                    z++;
                }
            }

            sortValues(colcpy);
            median = calcMedian(colcpy, z);
            handleMissingValues(col,i,median);
            z=0;

        }
        break;
    }
}

int nullFinder(int indexes[100], int col[100][100], int colNum){
    int indexCount = -1;

    for(int i=0; i<100; i++){
        if(col[i][colNum]==0){
            indexCount++;
            indexes[indexCount] = i;
        }
    }

    return indexCount;
}

void handleMissingValues(int col[100][100], int colNum, int replace){
    for(int i=0; i<100; i++){
        if(col[i][colNum]==0){
            col[i][colNum] = replace;
    }
}

}

void sortValues(int col[100]){ 
    int temp=0;

    for(int i=0 ; i<100 ; i++)
    {
        for(int j=0 ; j<100-1 ; j++)
        {
            if(col[j]>col[j+1])
            {
                temp = col[j];
                col[j] = col[j+1];
                col[j+1] = temp;
            }
        }
    }
}

int calcMedian(int col[100], int n)
{
    int median=0;

    if(n%2 == 0)
        median = (col[(n-1)/2] + col[n/2])/2.0;

    else
        median = col[n/2];
    
    return median;
}


