#include <stdio.h>
#include "defines.h"
#include <time.h>
#include <string.h>
#include <stdlib.h>
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

    // Top (White)
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

    // Middle (Orange, Green, Red, Blue) 
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

    // Bottom (Yellow)
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

void rotateCube(const char *scramble, int *cube_arr) {
	while (*scramble != '\0') {
		switch (*scramble) {
			case 'D':
            if (*(scramble + 1) == 39) { // D' 
                //rotateSide(Di, cube_arr);             
                rotateSide(D, cube_arr);             
                rotateSide(D, cube_arr);             
                rotateSide(D, cube_arr);             
                break;
            }
            if (*(scramble + 1) == '2') { // D2 
                //rotateSide(D2, cube_arr);                
                rotateSide(D, cube_arr);                
                rotateSide(D, cube_arr);                 
                break;
            }
            rotateSide(D, cube_arr);
            break;
            
			case 'F':
            if (*(scramble + 1) == 39) { // F' 
                rotateSide(F, cube_arr);
                rotateSide(F, cube_arr);
                rotateSide(F, cube_arr);
                break;
            }
            if (*(scramble + 1) == '2') { // F2 
                rotateSide(F, cube_arr);
                rotateSide(F, cube_arr);
                break;
            }
            rotateSide(F, cube_arr);
            break;
            
			case 'B':
            if (*(scramble + 1) == 39) { // B' 
                rotateSide(B, cube_arr);
                rotateSide(B, cube_arr);
                rotateSide(B, cube_arr);
                break;
            }
            if (*(scramble + 1) == '2') { // B2 
                rotateSide(B, cube_arr);
                rotateSide(B, cube_arr);
                break;
            }
            rotateSide(B, cube_arr);
            break;
            
			case 'U':
            if (*(scramble + 1) == 39) { // U' 
                rotateSide(U, cube_arr);
                rotateSide(U, cube_arr);
                rotateSide(U, cube_arr);
                break;
            }
            if (*(scramble + 1) == '2') { // U2 
                rotateSide(U2, cube_arr);
                break;
            }
            rotateSide(U, cube_arr);
            break;
            
			case 'L':
            if (*(scramble + 1) == 39) { // L' 
                rotateSide(L, cube_arr);
                rotateSide(L, cube_arr);
                rotateSide(L, cube_arr);
                break;
            }
            if (*(scramble + 1) == '2') { // L2 
                //rotateSide(L2, cube_arr);
                rotateSide(L, cube_arr);
                rotateSide(L, cube_arr);
                break;
            }
            rotateSide(L, cube_arr);
            break;
            
			case 'R':
            if (*(scramble + 1) == 39) { // R' 
                rotateSide(R, cube_arr);
                rotateSide(R, cube_arr);
                rotateSide(R, cube_arr);
                break;
            }
            if (*(scramble + 1) == '2') { // R2 
                rotateSide(R2, cube_arr);
                break;
            }
            rotateSide(R, cube_arr);
            break;
            
			default: // Skip any nonsence 
            break; 
		}
		scramble++;
	}
}


char* generateScramble() {
    
    srand(time(NULL));
    int i = 0;
    char letters[] = "LRUDFB", add_letters[] = "'2", sequence[10000] = "", c, c_prev;
    
    c_prev = '\0';
    
    while(i < 20) {
        
        c = letters[rand() % 6];
//        printf("i=%d c=%c\n",i, c);
        if (c != c_prev) {
            strncat(sequence, &c, 1);
            if (rand() % 2)
            strncat(sequence, &add_letters[rand() %2], 1);

            i++;
            c_prev = c;
            strncat(sequence, " ", 2);
        }      
    }
    printf("%s (%lld)\n", strdup(sequence), strlen(sequence));
    
    return strdup(sequence);
}

char *generateBetterAIScramble() {
    int i = 0, rando = 0;    
    char* p_arr = malloc(sizeof(char) * 40);
    char letters[] = "LRUDFB", prev = 90;
    char* moves[] = {"", "2", "'"};

    srand(time(NULL)); 
       
    rando = rand() % 6;
    char c = letters[rando];
    
    while(i < 25) {
        
        rando = rand() % 6;
        c = letters[rando];
     
        if (i > 0 && c == prev)
       
        if (i > 0 && ((p_arr[i] != prev) ||            
            (p_arr[i] == L && prev != R) || 
            (p_arr[i] == R && prev != L) || 
            (p_arr[i] == U && prev != D) || 
            (p_arr[i] == D && p_arr[i - 1] != U) || 
            (p_arr[i] == F && p_arr[i - 1] != B) || 
            (p_arr[i] == B && p_arr[i - 1] != F))) {

                printf("%c%s", c, moves[rand() % 3]);
                prev = c;
                i++;
        }

        printf(" ");
        i++;
    }
    printf("\n");
    free(p_arr);
    return "";
}

char *generateBetterScramble() {
    int i = 0;    
    char* p_arr = malloc(sizeof(char) * 40);

    srand(time(NULL));
    while(i < 25) {
        p_arr[i] = rand() % 6;
        printf("(%d)", p_arr[i]);

        if (p_arr[i] == L) {
            if (p_arr[i - 1] != L || p_arr[i - 1] != R) {
                switch (rand() % 3) {
                    case 0:
                        printf("L");
                        i++;
                        break;
                    case 1:
                        printf("L2");
                        i++;
                        break;
                    case 2:
                        printf("L'");
                        i++;
                        break;
                }
            }
        }

        if (p_arr[i] == R) {
            if (p_arr[i - 1] != L || p_arr[i - 1] != R) {
                switch (rand() % 3) {
                    case 0:
                        printf("R");
                        i++;
                        break;
                    case 1:
                        printf("R2");
                        i++;
                        break;
                    case 2:
                        printf("R'");
                        i++;
                        break;
                }
            }
        }

        if (p_arr[i] == U) {
            if (p_arr[i - 1] != U || p_arr[i - 1] != D) {
                switch (rand() % 3) {
                    case 0:
                        printf("U");
                        i++;
                        break;
                    case 1:
                        printf("U2");
                        i++;
                        break;
                    case 2:
                        printf("U'");
                        i++;
                        break;
                }
            }
        }
        if (p_arr[i] == D) {
            if (p_arr[i - 1] != D || p_arr[i - 1] != U) {
                switch (rand() % 3) {
                    case 0:
                        printf("D");
                        i++;
                        break;
                    case 1:
                        printf("D2");
                        i++;
                        break;
                    case 2:
                        printf("D'");
                        i++;
                        break;
                }
            }
        }        
        if (p_arr[i] == F) {
            if (p_arr[i - 1] != F || p_arr[i - 1] != B) {
                switch (rand() % 3) {
                    case 0:
                        printf("F");
                        i++;
                        break;
                    case 1:
                        printf("F2");
                        i++;
                        break;
                    case 2:
                        printf("F'");
                        i++;
                        break;
                }
            }
        }                
        if (p_arr[i] == B) {
            if (p_arr[i - 1] != F || p_arr[i - 1] != B) {
                switch (rand() % 3) {
                    case 0:
                        printf("B");
                        i++;
                        break;
                    case 1:
                        printf("B2");
                        i++;
                        break;
                    case 2:
                        printf("B'");
                        i++;
                        break;
                }
            }
        }        

printf(" ");
i++;

      
    }
    printf("\n");
free(p_arr);
return "";
}

void set_cube_matrix(int *cube) {

int j = 0;

for (int i = 0; i < CUBE_SIZE * 2; i++) {

if (i == MAPPING_TOP) j = 0;
if (i == MAPPING_LEFT) j = 0;
if (i == MAPPING_FRONT) j = 0;
if (i == MAPPING_RIGHT) j = 0;
if (i == MAPPING_BACK) j = 0;
if (i == MAPPING_BOTTOM) j = 0;

if (i == MAPPING_TOP + CUBE_SIZE) j = 0;
if (i == MAPPING_LEFT + CUBE_SIZE) j = 0;
if (i == MAPPING_FRONT + CUBE_SIZE) j = 0;
if (i == MAPPING_RIGHT + CUBE_SIZE) j = 0;
if (i == MAPPING_BACK + CUBE_SIZE) j = 0;
if (i == MAPPING_BOTTOM + CUBE_SIZE) j = 0;


    if (i >= MAPPING_BOTTOM + CUBE_SIZE) {
        cube[i] = j + MAPPING_BOTTOM;
        //printf("(B-B%d)", j + MAPPING_BOTTOM);
        j++;
    }

    else if (i >= MAPPING_BACK + CUBE_SIZE) {
        cube[i] = j + MAPPING_BACK;
        j++;
    }
    else if (i >= MAPPING_RIGHT + CUBE_SIZE) {
        cube[i] = j + MAPPING_RIGHT;
        j++;
    }
    else if (i >= MAPPING_FRONT + CUBE_SIZE) {
        cube[i] = j + MAPPING_FRONT;
        j++;
    }
    else if (i >= MAPPING_LEFT + CUBE_SIZE) {
        cube[i] = j + MAPPING_LEFT;
        j++;
    }
    else if (i >= MAPPING_TOP + CUBE_SIZE) {
        cube[i] = j + MAPPING_TOP;
        j++;
    }



    else if (i >= MAPPING_BOTTOM) {
        cube[i] = j + MAPPING_BOTTOM;
        j++;
    }

    else if (i >= MAPPING_BACK) {
        cube[i] = j + MAPPING_BACK;
        j++;
    }
    else if (i >= MAPPING_RIGHT) {
        cube[i] = j + MAPPING_RIGHT;
        j++;
    }
    else if (i >= MAPPING_FRONT) {
        cube[i] = j + MAPPING_FRONT;
        j++;
    }
    else if (i >= MAPPING_LEFT) {
        cube[i] = j + MAPPING_LEFT;
        j++;
    }
    else if (i >= MAPPING_TOP ) {
        cube[i] = j + MAPPING_TOP;
        j++;
    }
}

}

void print_cube_matrix(int *cube, int *cube_saved) {

    for (int i = 0; i < CUBE_SIZE; i++)
    if (cube[i] != cube_saved[i]) printf("cube_arr[%d]=buffer_arr[%d];\n", cube_saved[i], cube[i]);
    //printf("cube_arr[%d]=buffer_arr[%d];\n", cube_saved[i  + CUBE_SIZE], cube[i]);
    //printf("%d=%d\n", cube_saved[i], cube[i]);

}

void print_cube(int *cube) {
    printf("\n = {");
    for (int i = 0; i < CUBE_SIZE; i++)
    printf("%d, ", cube[i]);
    printf("};\n");   
}

void drawCubeX(int *cube) {
	int i, j, k = 0;

    // Top (White)
	for (j = 0; j < 9; j++) {       
		if (k == 0) 
			printf("\033[0m       ");
		if (k == 3) {
			k = 0;
			printf("\n\033[0m       ");
		}
		printf("%02d ",cube[j]);
		k++;
	}
	printf("\n\n");
	k = 0;

    // Middle (Orange, Green, Red, Blue) 
	for (i = 1; i < 5; i++)         
		for (j = 0; j < 3; j++) {
            if (k == 3) {
                k = 0;
                printf("\033[0m ");
        }
        printf("%02d ",cube[CUBE_FACE_SIZE * i + j]);
        //printf("%s  \033[0m", colors[cube[CUBE_FACE_SIZE * i + j]]);      
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
        printf("%d ", cube[CUBE_FACE_SIZE * i + j]);
        //printf("%s  \033[0m", colors[cube[CUBE_FACE_SIZE * i + j]]);       
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
        printf("%d ", cube[CUBE_FACE_SIZE * i + j]);
        //printf("%s  \033[0m", colors[cube[CUBE_FACE_SIZE * i + j]]);       
        k++;
    }
	printf("\n");

    // Bottom (Yellow)
	for (j = 0; j < 9; j++) {
		if (k == 0) 
			printf("\033[0m       ");
		if (k == 3) {
			k = 0;			
			printf("\n\033[0m       ");
		}
        printf("%d ", cube[CUBE_FACE_SIZE * 5 + j]);
		//printf("%s  \033[0m", colors[cube[CUBE_FACE_SIZE * 5 + j]]);		
		k++;
	}
	printf("\n\n");
    for (int i = 0; i < CUBE_SIZE; i++) if (i != cube[i]) printf("%02d = %02d\n", i, cube[i]);
    printf("\n\n");
}

void test_cube() {
    //char scramble1[] = "302104305442211123511523230451032432545140130023554450";
    int cube[CUBE_SIZE];
    int scramble_1[] = {3, 0, 2, 1, 0, 4, 3, 0, 5, 4, 4, 2, 2, 1, 1, 1, 2, 3, 5, 1, 1, 5, 2, 3, 2, 3, 0, 4, 5, 1, 0, 3, 2, 4, 3, 2, 5, 4, 5, 1, 4, 0, 1, 3, 0, 0, 2, 3, 5, 5, 4, 4, 5, 0};
    int scramble_2[] = {5, 1, 1, 5, 0, 1, 0, 4, 0, 2, 4, 2, 4, 1, 5, 5, 3, 1, 3, 1, 3, 1, 2, 3, 4, 2, 1, 4, 2, 2, 4, 3, 5, 2, 2, 3, 0, 0, 3, 2, 4, 0, 4, 3, 1, 0, 3, 5, 5, 5, 0, 4, 0, 5};
    int scramble_3[] = {0, 2, 0, 2, 0, 1, 0, 3, 4, 4, 5, 2, 3, 1, 1, 2, 1, 5, 3, 5, 5, 2, 2, 3, 1, 0, 5, 1, 4, 1, 0, 3, 5, 3, 1, 0, 2, 0, 3, 4, 4, 4, 1, 2, 5, 2, 4, 4, 5, 5, 0, 3, 3, 4};
    int scramble_4[] = {5, 4, 1, 4, 0, 2, 1, 3, 3, 2, 1, 2, 1, 1, 3, 3, 2, 5, 0, 0, 0, 2, 2, 4, 3, 5, 4, 2, 0, 5, 5, 3, 1, 1, 1, 1, 2, 0, 3, 5, 4, 2, 4, 4, 4, 4, 3, 5, 5, 5, 0, 0, 3, 0};
    int scramble_5[] = {4, 0, 1, 4, 0, 4, 4, 3, 2, 3, 5, 5, 4, 1, 1, 1, 1, 5, 1, 5, 3, 4, 2, 2, 3, 3, 3, 0, 0, 5, 1, 3, 5, 5, 0, 4, 2, 3, 0, 2, 4, 3, 0, 1, 2, 4, 2, 2, 0, 5, 2, 0, 5, 1};

    resetCube(cube);
    rotateCube("D R2 B2 F2 U' F2 D L2 B2 D2 B D R2 U R U L' U' L' F2", cube);
    if (memcmp(cube, scramble_1, sizeof(scramble_1)) == 0) printf("1st Equal\n"); else printf("1st Not equal\n");
    
    resetCube(cube);
    rotateCube("B U' L2 U B U' F' D2 R B2 R' D2 B2 D2 F2 L' U2 R L2 U' L'", cube);
    if (memcmp(cube, scramble_2, sizeof(scramble_2)) == 0) printf("2nd Equal\n"); else printf("2nd Not equal\n");

    resetCube(cube);
    rotateCube("F R F2 U R' U2 B' U' D2 B D2 F' L2 F' D2 F R2 L2 F2", cube);
    if (memcmp(cube, scramble_3, sizeof(scramble_3)) == 0) printf("3rd Equal\n"); else printf("3rd Not equal\n");

    resetCube(cube);
    rotateCube("L2 B' R2 B D2 L2 F2 R2 B' R2 D2 B L R' F R' B2 R U' L2 U", cube);
    if (memcmp(cube, scramble_4, sizeof(scramble_4)) == 0) printf("4th Equal\n"); else printf("4th Not equal\n");
    
    resetCube(cube);
    rotateCube("R' D U' L2 U' F2 D L2 U B2 F' R F D' F L2 B' F D'", cube);
    if (memcmp(cube, scramble_5, sizeof(scramble_5)) == 0) printf("5th Equal\n"); else printf("5th Not equal\n");

}