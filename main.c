#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <ctype.h>
#include <windows.h>


void displayColumnSummary(int col[100][100]);
void calcStDev(int);
void handleMissingValues(int);
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
        token = strtok(row, ",");

        while(token != NULL)
        {
            val = atoi(token);
            data[r][c] = val;
            c++;
            token = strtok(NULL, ",");
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
    float sum=0;
    float avg=0;
    char opt;

    printf("Please Eenter a method to fil the missing values:\nA.) Mean\nB.) Median\nC.) Mode\n\n=>");
    scanf("%c", &opt);

    switch(opt){

    case 'A':
        for(i=0; i<15; i++){
            for(j=0; j<100; j++){
                sum = sum + col[j][i];
            }
        avg = sum / 100;
        printf("The average of colum %d is %.2f\n", i+1, avg);
        sum=0;
        avg=0;
        }
        break;

    case 'B':

        break;

    case 'C':
        break;

    }
}


void calcStDev(int data){

}

void handleMissingValues(int data){


}

int variableType(int data){

}