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
        // printf("%s\n",token);
        
        while(token != NULL)
        {
            val = atoi(token);
            // printf("%d\n",val);
            data[r][c] = val;
            // printf("colums:%d",c);
            // printf("rows:%d\n",r);
            c++;
            token = strtok(NULL, ",");
        }
        c=0;
        r++;        
    }

    // printf("%d\n", data[1][0]);

    for(int i=0; i<100; i++){
        for(int j=0; j<15; j++){
            printf("%d\t", data[i][j]);
    }
    printf("\n");
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