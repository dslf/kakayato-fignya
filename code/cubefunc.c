#include <stdio.h>
#include "defines.h"
#include "cubemoves.c"

const char *colors[] = {
    "\033[48;05;15m",   // White
    "\033[48;5;214m",   // Orange 
    "\033[48;05;46m",   // Green 
    "\033[48;5;196m",   // Red
    "\033[48;05;21m",   // Blue
    "\033[48;5;226m"    // Yellow
    };

void drawCube(int *cube) {
	int i, j, k = 0;

    // Top row, white
    printf("\n");
	for (j = 0; j < 9; j++) {       
		if (k == 0) 
			printf("\033[0m       ");
		if (k == 3) {
			k = 0;
			printf("\n\033[0m       ");
		}
		printf("%s  \033[0m", colors[cube[j]]);
		k++;
	}
	printf("\n\n");
	k = 0;

    // Middle row (Orange, Green, Red, Blue) 
	for (i = 1; i < 5; i++)         
		for (j = 0; j < 3; j++) {
        if (k == 3) {
            k = 0;
            printf("\033[0m ");
        }
        printf("%s  \033[0m", colors[cube[CUBE_FACE_SIZE * i + j]]);      
        k++;
    }
	printf("\n");
	k = 0;
    
	for (i = 1; i < 5; i++)
		for (j = 3; j < 6; j++) {
        if (k == 3) {
            k = 0;           
            printf("\033[0m ");
        }
        printf("%s  \033[0m", colors[cube[CUBE_FACE_SIZE * i + j]]);       
        k++;
    }
	printf("\n");
	k = 0;
    
	for (i = 1; i < 5; i++)
		for (j = 6; j < 9; j++) {
        if (k == 3) {
            k = 0;           
            printf("\033[0m ");
        }
        printf("%s  \033[0m", colors[cube[CUBE_FACE_SIZE * i + j]]);       
        k++;
    }
	printf("\n");

    // Bottom row, Yellow
	for (j = 0; j < 9; j++) {
		if (k == 0) 
			printf("\033[0m       ");
		if (k == 3) {
			k = 0;			
			printf("\n\033[0m       ");
		}
		printf("%s  \033[0m", colors[cube[CUBE_FACE_SIZE * 5 + j]]);		
		k++;
	}
	printf("\n");
}

void resetCube(int *cube){
    int k = 0;
	for (int i = 0; i < 6; i++)
		for(int j = 0; j < 9; j++, k++)
            cube[k] = i;
}

void rotateCube(const char *str, int *cube_arr) {
	while (*str != '\0') { /* Go through every char in str, until null-terminator */
		switch (*str) {
			case 'D':
            if (*(str + 1) == 39) { /* D' */
                rotateSide(D, cube_arr);
                rotateSide(D, cube_arr);
                rotateSide(D, cube_arr);
                break;
            }
            if (*(str + 1) == '2') { /* D2 */
                rotateSide(D, cube_arr);
                rotateSide(D, cube_arr);
                break;
            }
            rotateSide(D, cube_arr);
            break;
            
			case 'F':
            if (*(str + 1) == 39) { /* F' */
                rotateSide(F, cube_arr);
                rotateSide(F, cube_arr);
                rotateSide(F, cube_arr);
                break;
            }
            if (*(str + 1) == '2') { /* F2 */
                rotateSide(F, cube_arr);
                rotateSide(F, cube_arr);
                break;
            }
            rotateSide(F, cube_arr);
            break;
            
			case 'B':
            if (*(str + 1) == 39) { /* B' */
                rotateSide(B, cube_arr);
                rotateSide(B, cube_arr);
                rotateSide(B, cube_arr);
                break;
            }
            if (*(str + 1) == '2') { /* B2 */
                rotateSide(B, cube_arr);
                rotateSide(B, cube_arr);
                break;
            }
            rotateSide(B, cube_arr);
            break;
            
			case 'U':
            if (*(str + 1) == 39) { /* U' */
                rotateSide(U, cube_arr);
                rotateSide(U, cube_arr);
                rotateSide(U, cube_arr);
                break;
            }
            if (*(str + 1) == '2') { /* U2 */
                rotateSide(U2, cube_arr);
                break;
            }
            rotateSide(U, cube_arr);
            break;
            
			case 'L':
            if (*(str + 1) == 39) { /* L' */
                rotateSide(L, cube_arr);
                rotateSide(L, cube_arr);
                rotateSide(L, cube_arr);
                break;
            }
            if (*(str + 1) == '2') { /* L2 */
                rotateSide(L2, cube_arr);
                break;
            }
            rotateSide(L, cube_arr);
            break;
            
			case 'R':
            if (*(str + 1) == 39) { /* R' */
                rotateSide(R, cube_arr);
                rotateSide(R, cube_arr);
                rotateSide(R, cube_arr);
                break;
            }
            if (*(str + 1) == '2') { /* R2 */
                rotateSide(R2, cube_arr);
                break;
            }
            rotateSide(R, cube_arr);
            break;
            
			default: /* Skip any nonsence */
            break; 
		}
		str++;
	}
}