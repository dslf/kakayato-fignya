#pragma once

#define CUBE_SIZE 54
#define CUBE_FACE_SIZE 9

#define RESET_COLOR 6

#define MAPPING_TOP 0
#define MAPPING_LEFT 9
#define MAPPING_FRONT 18
#define MAPPING_RIGHT 27
#define MAPPING_BACK 36
#define MAPPING_BOTTOM 45

#define L 0
#define R 1
#define F 2
#define B 3
#define U 4
#define D 5

#define L2 10
#define R2 11
#define F2 12
#define B2 13
#define U2 14
#define D2 15

#define Li 20
#define Ri 21
#define Fi 22
#define Bi 23
#define Ui 24
#define Di 25

void drawCube(int *cube);
void resetCube(int *cube);
void rotateCube(const char *str, int *cube_arr);
void rotateSide(int direction, int *cube_arr);
