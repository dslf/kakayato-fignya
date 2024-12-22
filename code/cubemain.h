#define CUBE_SIZE 3*3*6
#define CUBE_FACE_SIZE 9

#define MAPPING_TOP 0
#define MAPPING_LEFT 9
#define MAPPING_FRONT 18
#define MAPPING_RIGHT 27
#define MAPPING_BACK 36
#define MAPPING_BOTTOM 45

typedef struct {
    int* data; 
    int* top; 
    int* left;
    int* front;
    int* right;
    int* back; 
    int* bottom;
} Cube;

