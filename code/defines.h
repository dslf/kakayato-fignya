#pragma once

#define CUBE_SIZE 54
#define CUBE_FACE_SIZE 9

#define MAPPING_TOP 0
#define MAPPING_LEFT 9
#define MAPPING_FRONT 18
#define MAPPING_RIGHT 27
#define MAPPING_BACK 36
#define MAPPING_BOTTOM 45

// TODO: looks like I need enum here
#define L 0
#define R 1
#define F 2
#define B 3
#define U 4
#define D 5

#define L2 6
#define R2 7
#define F2 8
#define B2 9
#define U2 10
#define D2 11

#define Li 12
#define Ri 13
#define Fi 14
#define Bi 15
#define Ui 16
#define Di 17

void drawCube(int *cube);
void resetCube(int *cube);
void set_cube_matrix(int *cube);
void print_cube_matrix(int *cube);
void rotateCube(const char *scramble, int *cube_arr);
void rotateSide(int direction, int *cube_arr);
char* generateScramble();
char* generateBetterScramble(); 
char *generateBetterAIScramble();