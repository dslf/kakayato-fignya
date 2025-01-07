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
                case Li:
                    cube_arr[0] = buffer_arr[18];
                    cube_arr[3] = buffer_arr[21];
                    cube_arr[6] = buffer_arr[24];
                    cube_arr[9] = buffer_arr[11];
                    cube_arr[10] = buffer_arr[14];
                    cube_arr[11] = buffer_arr[17];
                    cube_arr[12] = buffer_arr[10];
                    cube_arr[14] = buffer_arr[16];
                    cube_arr[15] = buffer_arr[9];
                    cube_arr[16] = buffer_arr[12];
                    cube_arr[17] = buffer_arr[15];
                    cube_arr[18] = buffer_arr[45];
                    cube_arr[21] = buffer_arr[48];
                    cube_arr[24] = buffer_arr[51];
                    cube_arr[38] = buffer_arr[6];
                    cube_arr[41] = buffer_arr[3];
                    cube_arr[44] = buffer_arr[0];
                    cube_arr[45] = buffer_arr[44];
                    cube_arr[48] = buffer_arr[41];
                    cube_arr[51] = buffer_arr[38];
                    break;

                case Di:
                    cube_arr[15] = buffer_arr[24];
                    cube_arr[16] = buffer_arr[25];
                    cube_arr[17] = buffer_arr[26];
                    cube_arr[24] = buffer_arr[33];
                    cube_arr[25] = buffer_arr[34];
                    cube_arr[26] = buffer_arr[35];
                    cube_arr[33] = buffer_arr[42];
                    cube_arr[34] = buffer_arr[43];
                    cube_arr[35] = buffer_arr[44];
                    cube_arr[42] = buffer_arr[15];
                    cube_arr[43] = buffer_arr[16];
                    cube_arr[44] = buffer_arr[17];
                    cube_arr[45] = buffer_arr[47];
                    cube_arr[46] = buffer_arr[50];
                    cube_arr[47] = buffer_arr[53];
                    cube_arr[48] = buffer_arr[46];
                    cube_arr[50] = buffer_arr[52];
                    cube_arr[51] = buffer_arr[45];
                    cube_arr[52] = buffer_arr[48];
                    cube_arr[53] = buffer_arr[51];
                    break;

                case D2:
                    cube_arr[42] = buffer_arr[33];
                    cube_arr[43] = buffer_arr[34];
                    cube_arr[44] = buffer_arr[35];
                    cube_arr[15] = buffer_arr[42];
                    cube_arr[16] = buffer_arr[43];
                    cube_arr[17] = buffer_arr[44];
                    cube_arr[24] = buffer_arr[15];
                    cube_arr[25] = buffer_arr[16];
                    cube_arr[26] = buffer_arr[17];
                    cube_arr[33] = buffer_arr[24];
                    cube_arr[34] = buffer_arr[25];
                    cube_arr[35] = buffer_arr[26];
                    cube_arr[51] = buffer_arr[53];
                    cube_arr[48] = buffer_arr[52];
                    cube_arr[45] = buffer_arr[51];
                    cube_arr[52] = buffer_arr[50];
                    cube_arr[46] = buffer_arr[48];
                    cube_arr[53] = buffer_arr[47];
                    cube_arr[50] = buffer_arr[46];
                    cube_arr[47] = buffer_arr[45];
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