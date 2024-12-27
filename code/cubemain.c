#include <stdio.h>
#include <stdlib.h>
#include "defines.h"
#include "cubefunc.c"

int main(){

    int* cube = malloc(sizeof(*cube) * CUBE_SIZE * 2);
    if (cube == NULL) {
        printf("malloc ERROR!\n");
        return 1;
    }
     
    resetCube(cube);
    
    // seems good, tested by cstimer.net https://i.imgur.com/57BCevm.png
    //rotateCube("D R2 B2 F2 U' F2 D L2 B2 D2 B D R2 U R U L' U' L' F2", cube);  
    rotateCube(generateScramble(), cube);
    drawCube(cube); 
    free(cube);
    generateBetterAIScramble();
    //printf("%s\n", generateScramble());
    return 0;
}