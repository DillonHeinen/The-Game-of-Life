#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "life.h"

void populateWorld(char fname[], char *grid[], int *numRows, int *numCols) {

    FILE *fptr;
    fptr = fopen(fname, "r");               // open file in read mode

    if(fptr == NULL) {
        printf("File Error\n");
        exit(-1);
    }
    else {
        char buf[BUFSIZ];
        int rowNum = 0;
        while(fgets(buf, sizeof(buf), fptr)) {
            grid[rowNum] = (char *) malloc(strlen(buf));      // allocate space for output grid
            strcpy(grid[rowNum], buf);
            (rowNum)++;
//            printf("File Success");
        }
        *numRows = rowNum;
        *numCols = strlen(buf);
    }
}

void showWorld(char *grid[], int numRows, int numCols) {
    int i;
    int j;

    for(i = 0; i < numRows; i++) {              // reads rows and columns to draw world using printf
        for(j = 0; j < numCols; j++) {
            if(grid[i][j] == '1') {
                printf("*");
            }
            else if (grid[i][j] == '0') {
                printf(".");
            }
        }
        printf("\n");
    }
    printf("\n");
}

int numNeighbors(char *grid[], int row, int col, int numRows, int numCols) {
    int count = 0;
    if(row == 0) {
        if(col == 0) {
            if(grid[row + 1][col] == '1') {
                count++;
            }
            if(grid[row + 1][col + 1] == '1') {
                count++;
            }
            if(grid[row][col + 1] == '1') {
                count++;
            }
        }
        else if(col == (numCols - 1)) {
            if(grid[row][col - 1] == '1') {
                count++;
            }
            if(grid[row + 1][col -1] == '1') {
                count++;
            }
            if(grid[row + 1][col] == '1') {
                count++;
            }
        }
        else {
            if(grid[row][col - 1] == '1') {
                count++;
            }
            if(grid[row][col + 1] == '1'){
                count++;
            }
            if(grid[row + 1][col - 1] == '1') {
                count++;
            }
            if(grid[row + 1][col] == '1') {
                count++;
            }
            if(grid[row + 1][col + 1] == '1') {
                count++;
            }
        }
    }
    else if(col == 0) {
        if(row == (numRows - 1)) {
            if(grid[row - 1][col] == '1') {
                count++;
            }
            if(grid[row - 1][col + 1] == '1') {
                count++;
            }
            if(grid[row][col + 1] == '1') {
                count++;
            }
        }
        else {
            if(grid[row - 1][col] == '1') {
                count++;
            }
            if(grid[row - 1][col + 1] == '1') {
                count++;
            }
            if(grid[row][col + 1] == '1') {
                count++;
            }
            if(grid[row + 1][col + 1] == '1') {
                count++;
            }
            if(grid[row + 1][col] == '1') {
                count++;
            }
        }
    }
    else if(col == (numCols - 1)) {
        if(row == (numRows - 1)) {
            if(grid[row - 1][col] == '1') {
                count++;
            }
            if(grid[row - 1][col - 1] == '1') {
                count++;
            }
            if(grid[row][col - 1] == '1') {
                count++;
            }
        }
        else {
            if(grid[row - 1][col] == '1') {
                count++;
            }
            if(grid[row - 1][col - 1] == '1') {
                count++;
            }
            if(grid[row][col - 1] == '1') {
                count++;
            }
            if(grid[row + 1][col -1] == '1') {
                count++;
            }
            if(grid[row + 1][col] == '1') {
                count++;
            }
        }
    }
    else if(row == (numRows - 1)) {
        if(grid[row][col - 1] == '1') {
            count++;
        }
        if(grid[row][col + 1] == '1') {
            count++;
        }
        if(grid[row - 1][col - 1] == '1') {
            count++;
        }
        if(grid[row - 1][col] == '1') {
            count++;
        }
        if(grid[row - 1][col + 1] == '1') {
            count++;
        }
    }
    else {
        if(grid[row - 1][col - 1] == '1') {
            count++;
        }
        if(grid[row - 1][col] == '1') {
            count++;
        }
        if(grid[row - 1][col + 1] == '1') {
            count++;
        }
        if(grid[row][col - 1] == '1') {
            count++;
        }
        if(grid[row][col + 1] == '1') {
            count++;
        }
        if(grid[row + 1][col - 1] == '1') {
            count++;
        }
        if(grid[row + 1][col] == '1') {
            count++;
        }
        if(grid[row + 1][col + 1] == '1') {
            count++;
        }
    }
    return count;
}

int isAlive(char *grid[], int row, int col, int numRows, int numCols) {
    int lifeStatus;
    if((numNeighbors(grid, row, col, numRows, numCols) == 3) && (grid[row][col] == '0')) {
        lifeStatus = 1;
    }
    else if(numNeighbors(grid, row, col, numRows, numCols) >= 4) {
        lifeStatus = 0;
    }
    else if(numNeighbors(grid, row, col, numRows, numCols) <= 1) {
        lifeStatus = 0;
    }
    else if(((numNeighbors(grid, row, col, numRows, numCols) == 2) || (numNeighbors(grid, row, col, numRows, numCols) == 3)) && (grid[row][col] == '1') ) {
        lifeStatus = 1;
    }
    else {
        lifeStatus = 0;
    }
    return lifeStatus;
}

void iterateGeneration(char *grid[], int numRows, int numCols) {
    int i;
    int j;
    char tempGrid[numRows][numCols];

    for(i = 0; i < numRows; i++) {
        for(j = 0; j < numCols; j++) {
            tempGrid[i][j] = isAlive(grid, i, j, numRows, numCols);
        }
    }
    for(i = 0; i < numRows; i++) {
        for(j = 0; j < numCols; j++) {
            if(tempGrid[i][j] == 1) {
                grid[i][j] = '1';
            }
            else if(tempGrid[i][j] == 0) {
                grid[i][j] = '0';
            }
        }
    }
}
