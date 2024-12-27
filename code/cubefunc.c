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
                rotateSide(D, cube_arr);
                rotateSide(D, cube_arr);
                rotateSide(D, cube_arr);
                break;
            }
            if (*(scramble + 1) == '2') { // D2 
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
                rotateSide(L2, cube_arr);
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
    int i = 0;    
    char* p_arr = malloc(sizeof(char) * 40);
    char letters[] = "LRUDFB", prev = 90;
    char* moves[] = {"", "2", "'"};

    srand(time(NULL));
    while(i < 25) {
        p_arr[i] = rand() % 6;
        printf("i = %d (%d)", i, p_arr[i]);

        char c = letters[(int)p_arr[i]];
        
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

        /* switch (p_arr[i]) {       
        case L:           
            if(p_arr[i - 1] == L || p_arr[i - 1] == R) {
               // printf("l");
                //i++;
                break;
            }
            if (rand() % 2) {
                switch (rand() % 3)
                {
                case 0:
                    printf("L2");
                    i++;
                    break;
                    case 1:
                   printf("L'");
                   i++;
                    break;
                    case 3:
                printf("L"); 
            i++;
            break;        
                
                default:
                    printf("how defaul?");
                    break;
                }
             }            
            //printf("L"); 
            //i++;
            break;

        case R:           
            if(p_arr[i - 1] == R || p_arr[i - 1] == L){
               // printf("r");
                //i++;
                break;
            }            
                        if (rand() % 2) {
                switch (rand() % 2)
                {
                case 0:
                    printf("R2");
                    i++;
                    break;
                    case 1:
                   printf("R'");
                   i++;
                    break;
                
                default:
                    printf("how defaul? r");
                    break;
                }
             } 
            printf("R"); 
            i++;
            break;
        case U:
            if(p_arr[i - 1] == U || p_arr[i - 1] == D){
                printf("u");
                //i++;
                break;
            }            
            printf("U"); 
            i++;
            break;
        case D:
                 if(p_arr[i - 1] == U || p_arr[i - 1] == D){
                printf("d");
                //i++;
                break;
            }            
            printf("D"); 
            i++;
            break;
        case F:
                 if(p_arr[i - 1] == F || p_arr[i - 1] == B){
                printf("f");
                //i++;
                break;
            }            
            printf("F"); 
            i++;
            break;
        case B:
        if(p_arr[i - 1] == F || p_arr[i - 1] == B){
                printf("b");
                //i++;
                break;
            }            
            printf("B"); 
            i++;
            break;

        
        default:           
            i++;
            break;
        } */
printf(" ");
i++;

/*         if (*p_arr == R) printf("R");
        if (*p_arr == U) printf("U");
        if (*p_arr == D) printf("D");
        if (*p_arr == F) printf("F");
        if (*p_arr == B) printf("B"); */
        
        /* if (*p_arr == L2) printf("L2");
        if (*p_arr == R2) printf("R2");
        if (*p_arr == U2) printf("U2");
        if (*p_arr == D2) printf("D2");
        if (*p_arr == F2) printf("F2");
        if (*p_arr == B2) printf("B2");

        if (*p_arr == Li) printf("L'");
        if (*p_arr == Ri) printf("R'");
        if (*p_arr == Ui) printf("U'");
        if (*p_arr == Di) printf("D'");
        if (*p_arr == Fi) printf("F'");
        if (*p_arr == Bi) printf("B'"); */
       
    }
    printf("\n");
free(p_arr);
return "";
}















/* 
        // генерируем последовательность из 6 букв
    char prev_char = '\0';
    for (int i = 0; i < 6; i++) {
        char c;
        do {
            c = letters[rand() % 10]; // генерируем случайную букву
            if (prev_char == 'L' && c == 'I') {
                continue;
            }
            if (prev_char == 'L' && c == 'R' && i == 2) {
                continue;
            }
        } while (c == 'L' && i == 0); // не генерируем L в начале
        strncat(sequence, &c, 1);
        prev_char = c;
    }

    // генерируем 30 последовательностей по 1-2 буквы
    for (int i = 0; i < 30; i++) {
        int len = rand() % 2 + 1; // генерируем случайную длину последовательности
        for (int j = 0; j < len; j++) {
            char c;
            do {
                c = letters[rand() % 10]; // генерируем случайную букву
                if (prev_char == 'L' && c == 'I') {
                    continue;
                }
                if (prev_char == 'L' && c == 'R' && j == 1) {
                    continue;
                }
            } while (c == 'L' && j == 0); // не генерируем L в начале
            strncat(sequence, &c, 1);
            prev_char = c;
        }
        strncat(sequence, " ", 1);
    }

    return strdup(sequence);
}  */
