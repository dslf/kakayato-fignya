#pragma once
#include <string.h>
#include "defines.h"

void rotateSide(int direction, int *cube_arr) {   

    int* buffer_arr = cube_arr + CUBE_SIZE;

	memcpy(buffer_arr, cube_arr, sizeof(*cube_arr) * CUBE_SIZE);

	switch(direction) {
		case L:
			cube_arr[MAPPING_LEFT]=buffer_arr[MAPPING_LEFT+6];
			cube_arr[MAPPING_LEFT+1]=buffer_arr[MAPPING_LEFT+3];
			cube_arr[MAPPING_LEFT+2]=buffer_arr[MAPPING_LEFT];

			cube_arr[MAPPING_LEFT+3]=buffer_arr[MAPPING_LEFT+7];
			cube_arr[MAPPING_LEFT+4]=buffer_arr[MAPPING_LEFT+4];
			cube_arr[MAPPING_LEFT+5]=buffer_arr[MAPPING_LEFT+1];

			cube_arr[MAPPING_LEFT+6]=buffer_arr[MAPPING_LEFT+8];
			cube_arr[MAPPING_LEFT+7]=buffer_arr[MAPPING_LEFT+5];
			cube_arr[MAPPING_LEFT+8]=buffer_arr[MAPPING_LEFT+2];
			
			cube_arr[MAPPING_TOP]=buffer_arr[MAPPING_BACK+8];
			cube_arr[MAPPING_TOP+3]=buffer_arr[MAPPING_BACK+5];
			cube_arr[MAPPING_TOP+6]=buffer_arr[MAPPING_BACK+2];
			
			cube_arr[MAPPING_BACK+8]=buffer_arr[MAPPING_BOTTOM];
			cube_arr[MAPPING_BACK+5]=buffer_arr[MAPPING_BOTTOM+3];
			cube_arr[MAPPING_BACK+2]=buffer_arr[MAPPING_BOTTOM+6];

			cube_arr[MAPPING_BOTTOM]=buffer_arr[MAPPING_FRONT];
			cube_arr[MAPPING_BOTTOM+3]=buffer_arr[MAPPING_FRONT+3];
			cube_arr[MAPPING_BOTTOM+6]=buffer_arr[MAPPING_FRONT+6];

			cube_arr[MAPPING_FRONT]=buffer_arr[MAPPING_TOP];
			cube_arr[MAPPING_FRONT+3]=buffer_arr[MAPPING_TOP+3];
			cube_arr[MAPPING_FRONT+6]=buffer_arr[MAPPING_TOP+6];
			break;

		case R: 
			cube_arr[MAPPING_TOP+2]=buffer_arr[MAPPING_FRONT+2];
			cube_arr[MAPPING_TOP+5]=buffer_arr[MAPPING_FRONT+5];
			cube_arr[MAPPING_TOP+8]=buffer_arr[MAPPING_FRONT+8];

			cube_arr[MAPPING_FRONT+2]=buffer_arr[MAPPING_BOTTOM+2];
			cube_arr[MAPPING_FRONT+5]=buffer_arr[MAPPING_BOTTOM+5];
			cube_arr[MAPPING_FRONT+8]=buffer_arr[MAPPING_BOTTOM+8];

			cube_arr[MAPPING_BOTTOM+2]=buffer_arr[MAPPING_BACK+6];
			cube_arr[MAPPING_BOTTOM+5]=buffer_arr[MAPPING_BACK+3];
			cube_arr[MAPPING_BOTTOM+8]=buffer_arr[MAPPING_BACK];

			cube_arr[MAPPING_BACK+6]=buffer_arr[MAPPING_TOP+2];
			cube_arr[MAPPING_BACK+3]=buffer_arr[MAPPING_TOP+5];
			cube_arr[MAPPING_BACK]=buffer_arr[MAPPING_TOP+8];

			cube_arr[MAPPING_RIGHT]=buffer_arr[MAPPING_RIGHT+6];
			cube_arr[MAPPING_RIGHT+1]=buffer_arr[MAPPING_RIGHT+3];
			cube_arr[MAPPING_RIGHT+2]=buffer_arr[MAPPING_RIGHT];

			cube_arr[MAPPING_RIGHT+3]=buffer_arr[MAPPING_RIGHT+7];
			cube_arr[MAPPING_RIGHT+4]=buffer_arr[MAPPING_RIGHT+4];
			cube_arr[MAPPING_RIGHT+5]=buffer_arr[MAPPING_RIGHT+1];

			cube_arr[MAPPING_RIGHT+6]=buffer_arr[MAPPING_RIGHT+8];
			cube_arr[MAPPING_RIGHT+7]=buffer_arr[MAPPING_RIGHT+5];
			cube_arr[MAPPING_RIGHT+8]=buffer_arr[MAPPING_RIGHT+2];
			break;

		case U:   
			cube_arr[MAPPING_TOP]=buffer_arr[MAPPING_TOP+6];
			cube_arr[MAPPING_TOP+1]=buffer_arr[MAPPING_TOP+3];
			cube_arr[MAPPING_TOP+2]=buffer_arr[MAPPING_TOP];

			cube_arr[MAPPING_TOP+3]=buffer_arr[MAPPING_TOP+7];
			cube_arr[MAPPING_TOP+4]=buffer_arr[MAPPING_TOP+4];
			cube_arr[MAPPING_TOP+5]=buffer_arr[MAPPING_TOP+1];

			cube_arr[MAPPING_TOP+6]=buffer_arr[MAPPING_TOP+8];
			cube_arr[MAPPING_TOP+7]=buffer_arr[MAPPING_TOP+5];
			cube_arr[MAPPING_TOP+8]=buffer_arr[MAPPING_TOP+2];

			cube_arr[MAPPING_FRONT]=buffer_arr[MAPPING_RIGHT];
			cube_arr[MAPPING_FRONT+1]=buffer_arr[MAPPING_RIGHT+1];
			cube_arr[MAPPING_FRONT+2]=buffer_arr[MAPPING_RIGHT+2];

			cube_arr[MAPPING_RIGHT]=buffer_arr[MAPPING_BACK];
			cube_arr[MAPPING_RIGHT+1]=buffer_arr[MAPPING_BACK+1];
			cube_arr[MAPPING_RIGHT+2]=buffer_arr[MAPPING_BACK+2];

			cube_arr[MAPPING_BACK]=buffer_arr[MAPPING_LEFT];
			cube_arr[MAPPING_BACK+1]=buffer_arr[MAPPING_LEFT+1];
			cube_arr[MAPPING_BACK+2]=buffer_arr[MAPPING_LEFT+2];

			cube_arr[MAPPING_LEFT]=buffer_arr[MAPPING_FRONT];
			cube_arr[MAPPING_LEFT+1]=buffer_arr[MAPPING_FRONT+1];
			cube_arr[MAPPING_LEFT+2]=buffer_arr[MAPPING_FRONT+2];
			break;

		case F:
			cube_arr[MAPPING_FRONT]=buffer_arr[MAPPING_FRONT+6];
			cube_arr[MAPPING_FRONT+1]=buffer_arr[MAPPING_FRONT+3];
			cube_arr[MAPPING_FRONT+2]=buffer_arr[MAPPING_FRONT];

			cube_arr[MAPPING_FRONT+3]=buffer_arr[MAPPING_FRONT+7];
			cube_arr[MAPPING_FRONT+4]=buffer_arr[MAPPING_FRONT+4];
			cube_arr[MAPPING_FRONT+5]=buffer_arr[MAPPING_FRONT+1];

			cube_arr[MAPPING_FRONT+6]=buffer_arr[MAPPING_FRONT+8];
			cube_arr[MAPPING_FRONT+7]=buffer_arr[MAPPING_FRONT+5];
			cube_arr[MAPPING_FRONT+8]=buffer_arr[MAPPING_FRONT+2];

			cube_arr[MAPPING_TOP+6]=buffer_arr[MAPPING_LEFT+8];
			cube_arr[MAPPING_TOP+7]=buffer_arr[MAPPING_LEFT+5];
			cube_arr[MAPPING_TOP+8]=buffer_arr[MAPPING_LEFT+2];

			cube_arr[MAPPING_LEFT+8]=buffer_arr[MAPPING_BOTTOM+2];
			cube_arr[MAPPING_LEFT+5]=buffer_arr[MAPPING_BOTTOM+1];
			cube_arr[MAPPING_LEFT+2]=buffer_arr[MAPPING_BOTTOM];

			cube_arr[MAPPING_BOTTOM+2]=buffer_arr[MAPPING_RIGHT];
			cube_arr[MAPPING_BOTTOM+1]=buffer_arr[MAPPING_RIGHT+3];
			cube_arr[MAPPING_BOTTOM]=buffer_arr[MAPPING_RIGHT+6];

			cube_arr[MAPPING_RIGHT]=buffer_arr[MAPPING_TOP+6];
			cube_arr[MAPPING_RIGHT+3]=buffer_arr[MAPPING_TOP+7];
			cube_arr[MAPPING_RIGHT+6]=buffer_arr[MAPPING_TOP+8];
			break;

		case B:
			cube_arr[MAPPING_BACK]=buffer_arr[MAPPING_BACK+6];
			cube_arr[MAPPING_BACK+1]=buffer_arr[MAPPING_BACK+3];
			cube_arr[MAPPING_BACK+2]=buffer_arr[MAPPING_BACK];

			cube_arr[MAPPING_BACK+3]=buffer_arr[MAPPING_BACK+7];
			cube_arr[MAPPING_BACK+4]=buffer_arr[MAPPING_BACK+4];
			cube_arr[MAPPING_BACK+5]=buffer_arr[MAPPING_BACK+1];

			cube_arr[MAPPING_BACK+6]=buffer_arr[MAPPING_BACK+8];
			cube_arr[MAPPING_BACK+7]=buffer_arr[MAPPING_BACK+5];
			cube_arr[MAPPING_BACK+8]=buffer_arr[MAPPING_BACK+2];

			cube_arr[MAPPING_TOP]=buffer_arr[MAPPING_RIGHT+2];
			cube_arr[MAPPING_TOP+1]=buffer_arr[MAPPING_RIGHT+5];
			cube_arr[MAPPING_TOP+2]=buffer_arr[MAPPING_RIGHT+8];

			cube_arr[MAPPING_RIGHT+2]=buffer_arr[MAPPING_BOTTOM+8];
			cube_arr[MAPPING_RIGHT+5]=buffer_arr[MAPPING_BOTTOM+7];
			cube_arr[MAPPING_RIGHT+8]=buffer_arr[MAPPING_BOTTOM+6];

			cube_arr[MAPPING_BOTTOM+8]=buffer_arr[MAPPING_LEFT+6];
			cube_arr[MAPPING_BOTTOM+7]=buffer_arr[MAPPING_LEFT+3];
			cube_arr[MAPPING_BOTTOM+6]=buffer_arr[MAPPING_LEFT];

			cube_arr[MAPPING_LEFT+6]=buffer_arr[MAPPING_TOP];
			cube_arr[MAPPING_LEFT+3]=buffer_arr[MAPPING_TOP+1];
			cube_arr[MAPPING_LEFT]=buffer_arr[MAPPING_TOP+2];
			break;

		case D:   
			cube_arr[MAPPING_BOTTOM]=buffer_arr[MAPPING_BOTTOM+6];
			cube_arr[MAPPING_BOTTOM+1]=buffer_arr[MAPPING_BOTTOM+3];
			cube_arr[MAPPING_BOTTOM+2]=buffer_arr[MAPPING_BOTTOM];

			cube_arr[MAPPING_BOTTOM+3]=buffer_arr[MAPPING_BOTTOM+7];
			cube_arr[MAPPING_BOTTOM+4]=buffer_arr[MAPPING_BOTTOM+4];
			cube_arr[MAPPING_BOTTOM+5]=buffer_arr[MAPPING_BOTTOM+1];

			cube_arr[MAPPING_BOTTOM+6]=buffer_arr[MAPPING_BOTTOM+8];
			cube_arr[MAPPING_BOTTOM+7]=buffer_arr[MAPPING_BOTTOM+5];
			cube_arr[MAPPING_BOTTOM+8]=buffer_arr[MAPPING_BOTTOM+2];

			cube_arr[MAPPING_FRONT+6]=buffer_arr[MAPPING_LEFT+6];
			cube_arr[MAPPING_FRONT+7]=buffer_arr[MAPPING_LEFT+7];
			cube_arr[MAPPING_FRONT+8]=buffer_arr[MAPPING_LEFT+8];

			cube_arr[MAPPING_LEFT+6]=buffer_arr[MAPPING_BACK+6];
			cube_arr[MAPPING_LEFT+7]=buffer_arr[MAPPING_BACK+7];
			cube_arr[MAPPING_LEFT+8]=buffer_arr[MAPPING_BACK+8];

			cube_arr[MAPPING_BACK+6]=buffer_arr[MAPPING_RIGHT+6];
			cube_arr[MAPPING_BACK+7]=buffer_arr[MAPPING_RIGHT+7];
			cube_arr[MAPPING_BACK+8]=buffer_arr[MAPPING_RIGHT+8];

			cube_arr[MAPPING_RIGHT+6]=buffer_arr[MAPPING_FRONT+6];
			cube_arr[MAPPING_RIGHT+7]=buffer_arr[MAPPING_FRONT+7];
			cube_arr[MAPPING_RIGHT+8]=buffer_arr[MAPPING_FRONT+8];
			break;

		case L2:
			cube_arr[MAPPING_LEFT]=buffer_arr[MAPPING_LEFT+8];
			cube_arr[MAPPING_LEFT+1]=buffer_arr[MAPPING_LEFT+7];
			cube_arr[MAPPING_LEFT+2]=buffer_arr[MAPPING_LEFT+6];

			cube_arr[MAPPING_LEFT+3]=buffer_arr[MAPPING_LEFT+5];
			cube_arr[MAPPING_LEFT+4]=buffer_arr[MAPPING_LEFT+4];
			cube_arr[MAPPING_LEFT+5]=buffer_arr[MAPPING_LEFT+3];

			cube_arr[MAPPING_LEFT+6]=buffer_arr[MAPPING_LEFT+2];
			cube_arr[MAPPING_LEFT+7]=buffer_arr[MAPPING_LEFT+1];
			cube_arr[MAPPING_LEFT+8]=buffer_arr[MAPPING_LEFT+0];
			
			cube_arr[MAPPING_TOP]=buffer_arr[MAPPING_BOTTOM];
			cube_arr[MAPPING_TOP+3]=buffer_arr[MAPPING_BOTTOM+3];
			cube_arr[MAPPING_TOP+6]=buffer_arr[MAPPING_BOTTOM+6];
			
			cube_arr[MAPPING_BACK+2]=buffer_arr[MAPPING_FRONT+6];
			cube_arr[MAPPING_BACK+5]=buffer_arr[MAPPING_FRONT+3];
			cube_arr[MAPPING_BACK+8]=buffer_arr[MAPPING_FRONT];

			cube_arr[MAPPING_BOTTOM]=buffer_arr[MAPPING_TOP];
			cube_arr[MAPPING_BOTTOM+3]=buffer_arr[MAPPING_TOP+3];
			cube_arr[MAPPING_BOTTOM+6]=buffer_arr[MAPPING_TOP+6];

			cube_arr[MAPPING_FRONT]=buffer_arr[MAPPING_BACK+8];
			cube_arr[MAPPING_FRONT+3]=buffer_arr[MAPPING_BACK+5];
			cube_arr[MAPPING_FRONT+6]=buffer_arr[MAPPING_BACK+2];
			break;

		case R2:
			cube_arr[MAPPING_TOP+2]=buffer_arr[MAPPING_BOTTOM+2];
			cube_arr[MAPPING_TOP+5]=buffer_arr[MAPPING_BOTTOM+5];
			cube_arr[MAPPING_TOP+8]=buffer_arr[MAPPING_BOTTOM+8];

			cube_arr[MAPPING_FRONT+2]=buffer_arr[MAPPING_BACK+6];
			cube_arr[MAPPING_FRONT+5]=buffer_arr[MAPPING_BACK+3];
			cube_arr[MAPPING_FRONT+8]=buffer_arr[MAPPING_BACK];

			cube_arr[MAPPING_BOTTOM+2]=buffer_arr[MAPPING_TOP+2];
			cube_arr[MAPPING_BOTTOM+5]=buffer_arr[MAPPING_TOP+5];
			cube_arr[MAPPING_BOTTOM+8]=buffer_arr[MAPPING_TOP+8];

			cube_arr[MAPPING_BACK]=buffer_arr[MAPPING_FRONT+8];
			cube_arr[MAPPING_BACK+3]=buffer_arr[MAPPING_FRONT+5];
			cube_arr[MAPPING_BACK+6]=buffer_arr[MAPPING_FRONT+2];

			cube_arr[MAPPING_RIGHT]=buffer_arr[MAPPING_RIGHT+8];
			cube_arr[MAPPING_RIGHT+1]=buffer_arr[MAPPING_RIGHT+7];
			cube_arr[MAPPING_RIGHT+2]=buffer_arr[MAPPING_RIGHT+6];

			cube_arr[MAPPING_RIGHT+3]=buffer_arr[MAPPING_RIGHT+5];
			cube_arr[MAPPING_RIGHT+4]=buffer_arr[MAPPING_RIGHT+4];
			cube_arr[MAPPING_RIGHT+5]=buffer_arr[MAPPING_RIGHT+3];

			cube_arr[MAPPING_RIGHT+6]=buffer_arr[MAPPING_RIGHT+2];
			cube_arr[MAPPING_RIGHT+7]=buffer_arr[MAPPING_RIGHT+1];
			cube_arr[MAPPING_RIGHT+8]=buffer_arr[MAPPING_RIGHT];
			break;
		
		case U2:   
			cube_arr[MAPPING_TOP]=buffer_arr[MAPPING_TOP+8];
			cube_arr[MAPPING_TOP+1]=buffer_arr[MAPPING_TOP+7];
			cube_arr[MAPPING_TOP+2]=buffer_arr[MAPPING_TOP+6];

			cube_arr[MAPPING_TOP+3]=buffer_arr[MAPPING_TOP+5];
			cube_arr[MAPPING_TOP+4]=buffer_arr[MAPPING_TOP+4];
			cube_arr[MAPPING_TOP+5]=buffer_arr[MAPPING_TOP+3];

			cube_arr[MAPPING_TOP+6]=buffer_arr[MAPPING_TOP+2];
			cube_arr[MAPPING_TOP+7]=buffer_arr[MAPPING_TOP+1];
			cube_arr[MAPPING_TOP+8]=buffer_arr[MAPPING_TOP];

			cube_arr[MAPPING_FRONT]=buffer_arr[MAPPING_BACK];
			cube_arr[MAPPING_FRONT+1]=buffer_arr[MAPPING_BACK+1];
			cube_arr[MAPPING_FRONT+2]=buffer_arr[MAPPING_BACK+2];

			cube_arr[MAPPING_RIGHT]=buffer_arr[MAPPING_LEFT];
			cube_arr[MAPPING_RIGHT+1]=buffer_arr[MAPPING_LEFT+1];
			cube_arr[MAPPING_RIGHT+2]=buffer_arr[MAPPING_LEFT+2];

			cube_arr[MAPPING_BACK]=buffer_arr[MAPPING_FRONT];
			cube_arr[MAPPING_BACK+1]=buffer_arr[MAPPING_FRONT+1];
			cube_arr[MAPPING_BACK+2]=buffer_arr[MAPPING_FRONT+2];

			cube_arr[MAPPING_LEFT]=buffer_arr[MAPPING_RIGHT];
			cube_arr[MAPPING_LEFT+1]=buffer_arr[MAPPING_RIGHT+1];
			cube_arr[MAPPING_LEFT+2]=buffer_arr[MAPPING_RIGHT+2];
			break;
	}
}