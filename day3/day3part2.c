#include <stdio.h>
#define MAX 8192

//coordinates
struct key {
    int x;
    int y;
};

int main(int argc, char * argv[]) {
    //initial values 
    int counter = 1;
    struct key key[MAX];

    //read file
    char input[MAX];
    char file_name[] = "input.txt";
    FILE * fp = fopen(file_name, "r");

    struct key santa = {.x = 0, .y = 0};
    struct key robot = {.x = 0, .y = 0};
    key[0] = santa;

    if(fgets(input, MAX, fp) != NULL) {
        //iterate through each direction of the input
        for(int i = 0; i < MAX; i += 2) {
            int in = 0;
            char dir = input[i];
            //change the coordinates according to the direction given 
            if(dir ==  '<') {
                santa.x = santa.x-1;
            } else if(dir == '^') {
                santa.y = santa.y-1;
            } else if(dir == '>') {
                santa.x = santa.x+1;
            } else if(dir == 'v') {
                santa.y = santa.y+1;
            }
            //check if coordinates is already passed
            for(int j = 0; j < counter; j++) {
                if((key[j].x == santa.x) && 
                    (key[j].y == santa.y)) {
                    in = 1;
                    break;
                }
            }
            //if not in map add to map and increment counter
            if(in == 0) {
                key[counter] = santa;
                counter += 1; 
            }
        }

        for(int i = 1; i < MAX; i += 2) {
            int in = 0;
            char dir = input[i];
            //change the coordinates according to the direction given 
            if(dir ==  '<') {
                robot.x = robot.x-1;
            } else if(dir == '^') {
                robot.y = robot.y-1;
            } else if(dir == '>') {
                robot.x = robot.x+1;
            } else if(dir == 'v') {
                robot.y = robot.y+1;
            }
            //check if coordinates is already passed
            for(int j = 0; j < counter; j++) {
                if((key[j].x == robot.x) && 
                    (key[j].y == robot.y)) {
                    in = 1;
                    break;
                }
            }
            //if not in map add to map and increment counter
            if(in == 0) {
                key[counter] = robot;
                counter += 1; 
            }
        }
    }
    fclose(fp);
    printf("%d\n", counter);
}
