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

    struct key curr = {.x = 0, .y = 0};
    key[0] = curr;

    if(fgets(input, MAX, fp) != NULL) {
        //iterate through each direction of the input
        for(int i = 0; i < MAX; i++) {
            int in = 0;
            char dir = input[i];
            //change the coordinates according to the direction given 
            if(dir ==  '<') {
                curr.x = curr.x-1;
            } else if(dir == '^') {
                curr.y = curr.y-1;
            } else if(dir == '>') {
                curr.x = curr.x+1;
            } else if(dir == 'v') {
                curr.y = curr.y+1;
            }
            //check if coordinates is already passed
            for(int j = 0; j < counter; j++) {
                if((key[j].x == curr.x) && 
                    (key[j].y == curr.y)) {
                    in = 1;
                    break;
                }
            }
            //if not in map add to map and increment counter
            if(in == 0) {
                key[counter] = curr;
                counter += 1; 
            }
        }
    }
    fclose(fp);
    printf("%d\n", counter);
}
