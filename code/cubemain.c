#include <stdio.h>
#include <stdlib.h>
#include "cubemain.h"

Cube create_cube(int);

int main(){
    Cube cube;
    
    cube.data = malloc(sizeof(*cube.data) * CUBE_SIZE);
    if (cube.data == NULL) {
        printf("malloc cube.data ERROR! \n");
        return 1;
    }

    cube.top = cube.data;
    cube.left = cube.data + 9;
    cube.front = cube.data + 18;
    cube.right = cube.data + 27;
    cube.back = cube.data + 36;
    cube.bottom = cube.data + 45;
    
  /*   for(int i = 0; i < CUBE_SIZE; i++)
        cube.data[i] = 0;

    for(int i = 0; i < CUBE_FACE_SIZE; i++)
        cube.left[i] = 4;

    for(int i = 0; i < CUBE_SIZE; i++)
        printf("i+%d = %d\n", i, cube.data[i]); */

    resetCube(cube.data);
    drawCube(cube.data);
    
    free(cube.data);
    return 0;
}