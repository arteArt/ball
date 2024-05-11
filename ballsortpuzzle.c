#include <stdio.h>
#include <stdlib.h> 
#include "ballsortpuzzle.h"
#include <time.h>
#include <stdbool.h>

void generator(const int rows, const int columns, char field[rows][columns]){
    int vacuum1 = rand() % columns;
    int vacuum2 = rand() % columns;

    srand(time(NULL));

    while(vacuum1 == vacuum2){
        vacuum2 = rand() % columns;
    }

    char symbols[] = {'@','*','+','^','~','$','&','#','?','!'};
    int arr[columns-2];
    for(int i = 0; i < columns-2; i++){
        arr[i] = 0;
    }

    for(int i = 0; i < rows; i++){
        for(int j = 0; j < columns; j++){
            if(j == vacuum2 || j == vacuum1){
                field[i][j] = ' ';
                continue;
            }
            int temp = rand() % (columns-2);
            while(arr[temp] == rows){
                temp = rand() % (columns -2);
            }
            if(arr[temp] < rows){
                field[i][j] = symbols[temp];
                arr[temp]+=1;
            }

        }
    }
}


void down_possible(const int rows, const int columns, char field[rows][columns], int x, int y) {
    char getSymbol = '\0';
    int symbolIndex = 0;
    if (x <= columns && x > 0 && y <= columns && y > 0 && x != y) { 
 
        for (int i = 0; i < rows; i++) {
            if (field[i][x-1] != ' ') {
                getSymbol = field[i][x-1];
                symbolIndex = i;
                break;
            }
        }
 
        if (field[rows-1][y-1] == ' ' && getSymbol != '\0') {
            // drop symbol to the last row
            field[rows-1][y-1] = getSymbol;
            field[symbolIndex][x-1] = ' ';
        } else if (getSymbol != '\0') {
            int findFlag = 0;
            for (int i = 0; i < rows-1; i++) {
                if (field[i][y-1] == ' ' && field[i + 1][y-1] != ' ' && field[i+1][y-1] == field[symbolIndex][x-1]) {
                    field[i][y-1] = getSymbol;
                    field[symbolIndex][x-1] = ' ';
                    findFlag = 1;
                }
            }
            if (findFlag == 0) {
                printf("ERROR %d\n", symbolIndex);
            }
        } else {
            printf("ERROR\n");
        }
    } else {
        printf("ERROR\n");
    }
}


bool check(const int rows, const int columns, char field[rows][columns])
{
    char tmpSymbol = '\0';
    for (int j = 0; j < columns; j++) {
        tmpSymbol = field[0][j];
        for (int i = 1; i < rows; i++) {
            if (tmpSymbol != field[i][j]) {
                return false;
            }
        }
    }
    return true;
}


void game_field(const int rows, const int columns, char field[rows][columns]){
    for(int i = 0; i < rows; i++){
        printf("%i", i+1);
        for(int j = 0; j < columns; j++){
            printf(" | %c", field[i][j]);
        }
        printf(" | \n");
    }
    printf("   ---");
    for(int i = 1; i < columns; i++){
        printf(" ---");
    }
    printf("\n");
    printf("    1");
    for(int i = 1; i < columns; i++){
        printf("   %i",i+1);
    }
    printf("\n");


}
