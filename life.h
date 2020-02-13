// life.h
// -- EE 312 Project 2

/* Student information for project:
 *
 * Replace <NAME> with your name.
 *
 * On my honor, <NAME>, this programming project is my own work
 * and I have not provided this code to any other student.
 *
 * Name: Dillon Heinen
 * email address: dillonheinen@utexas.edu
 * UTEID: deh2486
 * Section 5 digit ID: 16085
 *
 *///
// Created by priebe on 9/5/2018.
//

#ifndef UNTITLED1_LIFE_H
#define UNTITLED1_LIFE_H

#endif //UNTITLED1_LIFE_H

void populateWorld(char fname[], char *grid[], int *numRows, int *numCols);             // stores current map of dead and alive

void showWorld(char *grid[], int numRows, int numCols);                                 // prints map of dead and alive

void iterateGeneration(char *grid[], int numRows, int numCols);                         // recalculates dead and alive according to generations

int numNeighbors(char *grid[], int row, int col, int numRows, int numCols);             // determines how many living neighbors according to grid location

int isAlive(char *grid[], int row, int col, int numRows, int numCols);                  // delivers semaphore for dead or alive
