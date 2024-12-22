#include <stdio.h>
#include <stdlib.h>
#include "defines.h"
#include "cubefunc.c"

int main(){
    Cube cube;

    cube.data = malloc(sizeof(*cube.data) * CUBE_SIZE * 2);
    //cube.buff = malloc(sizeof(*cube.buff) * CUBE_SIZE);
    if (cube.data == NULL) {
        printf("malloc ERROR!\n");
        return 1;
    }

    cube.top = cube.data;
    cube.left = cube.data + 9;
    cube.front = cube.data + 18;
    cube.right = cube.data + 27;
    cube.back = cube.data + 36;
    cube.bottom = cube.data + 45;
    cube.buff = cube.data + CUBE_SIZE;
    
    resetCube(cube.data);
    
    // seems good, tested by cstimer.net https://i.imgur.com/57BCevm.png
    rotateCube("D R2 B2 F2 U' F2 D L2 B2 D2 B D R2 U R U L' U' L' F2", cube.data, cube.buff);  

    drawCube(cube.data);
    
    free(cube.data);
    //free(cube.buff);
    return 0;
}