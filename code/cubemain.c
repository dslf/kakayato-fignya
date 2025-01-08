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

/*     int* cube_saved = malloc(sizeof(*cube_saved) * CUBE_SIZE * 2);
    if (cube_saved == NULL) {
        printf("malloc saved ERROR!\n");
        return 1;
    } */


    //int* buffer_arr = cube_arr + CUBE_SIZE;
	//memcpy(buffer_arr, cube_arr, sizeof(*cube_arr) * CUBE_SIZE);

    //resetCube(cube);
    //set_cube_matrix(cube);
    // drawCubeX(cube);
     /*
    memcpy(cube_saved, cube, sizeof(*cube) * (CUBE_SIZE * 2)); */

   // print_cube_matrix(cube);
   // rotateCube("R'", cube);  
   // drawCubeX(cube);

    //print_cube_matrix(cube);
    //print_cube(cube);  // print cube matrix as int array

   // resetCube(cube);
    // seems good, tested by cstimer.net https://i.imgur.com/57BCevm.png
    //rotateCube("D R2 B2 F2 U' F2 D L2 B2 D2 B D R2 U R U L' U' L' F2", cube);  

    //rotateCube("UR2FBRB2RU2LB2RU'D'R2FR'LB2U2F2", cube);
    //rotateCube("F2 D R2 D' B2 L2 B2 U2 L2 D R D2 F R2 D R' B' L B2 R'", cube);
   // drawCube(cube);
    //print_cube(cube);

    test_cube(); // this is test 


/*     resetCube(cube);
    // https://i.imgur.com/v89rtAT.png
    rotateCube("L2 U R2 F2 R' D2 L2 B2 R' D2 B2 L' F2 L F' R' D' F' L2 D2 B", cube);
    drawCube(cube); */



/*     rotateCube(generateScramble(), cube);
    drawCube(cube); 
    generateBetterAIScramble(); */

    //printf("%s\n", generateScramble());
    free(cube);
    return 0;
}