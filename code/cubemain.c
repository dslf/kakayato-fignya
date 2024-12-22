#include <stdio.h>
#include <stdlib.h>
#include "cubemain.h"

Cube create_cube(int);

int main(){
    Cube cubelmao;
    
    cubelmao.data = malloc(sizeof(*cubelmao.data) * CUBE_SIZE);
    if (cubelmao.data == NULL) {
        printf("malloc cubelmao.data ERROR! \n");
        return 1;
    }

    cubelmao.top = cubelmao.data;
    cubelmao.left = cubelmao.data + 9;
    cubelmao.front = cubelmao.data + 18;
    cubelmao.right = cubelmao.data + 27;
    cubelmao.back = cubelmao.data + 36;
    cubelmao.bottom = cubelmao.data + 45;
    
    for(int i = 0; i < CUBE_SIZE; i++)
        cubelmao.data[i] = 0;

    for(int i = 0; i < CUBE_FACE_SIZE; i++)
        cubelmao.left[i] = 8;

    for(int i = 0; i < CUBE_SIZE; i++)
        printf("i+%d = %d\n", i, cubelmao.data[i]);
    free(cubelmao.data);
    return 0;
}

Cube create_cube(int size) {
    Cube cube;
    cube.data = malloc(size);
    cube.top = cube.data + MAPPING_TOP;
    cube.left = cube.data + MAPPING_LEFT;
    cube.front = cube.data + MAPPING_FRONT;
    cube.right = cube.data + MAPPING_RIGHT;
    cube.back = cube.data + MAPPING_BACK;
    cube.bottom = cube.data + MAPPING_BOTTOM;
    return cube;
}