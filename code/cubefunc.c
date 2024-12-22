#include <stdio.h>
#include "cubemain.h"


void drawCube(int *cube) {
	int i, j, k = 0;
    printf("\n");
	/* Top (White) */
	for (j = 0; j < 9; j++) {
		if (k == 0) {
			setColor(RESET_COLOR);
			printf("       ");
		}
		if (k == 3) {
			k = 0;
			printf("\n");
			setColor(RESET_COLOR);
			printf("       ");
		}
		setColor(cube[0+j]);
		printf("  ");
		setColor(RESET_COLOR);
		k++;
	}
	printf("\n\n");
	k = 0;
    
	/* Middle row (Orange, Green, Red, Blue) */
	for (i = 1; i < 5; ++i)
		for (j = 0; j < 3; j++) {
        if (k == 3) {
            k = 0;
            setColor(RESET_COLOR);
            printf(" ");
        }
        setColor(cube[CUBE_FACE_SIZE * i + j]);
        printf("  ");
        setColor(RESET_COLOR);
        ++k;
    }
	printf("\n");
	k = 0;
    
	for (i = 1; i < 5; ++i)
		for (j = 3; j < 6; j++) {
        if (k == 3) {
            k = 0;
            setColor(RESET_COLOR);
            printf(" ");
        }
        setColor(cube[CUBE_FACE_SIZE *i+j]);
        printf("  ");
        setColor(RESET_COLOR);
        ++k;
    }
	printf("\n");
	k = 0;
    
	for (i = 1; i < 5; ++i)
		for (j = 6; j < 9; j++) {
        if (k == 3) {
            k = 0;
            setColor(RESET_COLOR);
            printf(" ");
        }
        setColor(cube[CUBE_FACE_SIZE *i+j]);
        printf("  ");
        setColor(RESET_COLOR);
        ++k;
    }
	printf("\n");
    
	for (j = 0; j < 9; j++) {
		if (k == 0) {
			setColor(RESET_COLOR);
			printf("       ");
		}
		if (k == 3) {
			k = 0;
			printf("\n");
			setColor(RESET_COLOR);
			printf("       ");
		}
        
		/* Bottom (Yellow) */
		setColor(cube[CUBE_FACE_SIZE *5+j]);
		printf("  ");
		setColor(RESET_COLOR);
		k++;
	}
	printf("\n");
}

void setColor(int n){
	if (n == 0) printf("\033[48;05;15m");           // White
    if (n == 1) printf("\033[48;5;214m");           // Orange 
	if (n == 2) printf("\033[48;05;46m");           // Green 
	if (n == 3) printf("\033[48;5;196m");           // Red
	if (n == 4) printf("\033[48;05;21m");           // Blue
    if (n == 5) printf("\033[48;5;226m");           // Yellow
    if (n == 6) printf("\033[0m");                  // Reset
}

void resetCube(int *cube){
	int i,j;
	int k=0;
	for (i = 0; i < 6; i++)
		for(j = 0; j < 9; j++){
        cube[k] = i;
        k++;
	}
}