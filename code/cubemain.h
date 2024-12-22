#pragma once

#define CUBE_SIZE 54
#define CUBE_FACE_SIZE 9

#define RESET_COLOR 6

typedef struct {
    int* data; 
    int* top; 
    int* left;
    int* front;
    int* right;
    int* back; 
    int* bottom;
} Cube;

void drawCube(int *cube);
void setColor(int n);
void resetCube(int *cube);