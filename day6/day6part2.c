#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 1000

void main() {
    int grid[MAX][MAX] = {0};
    
    char input[150];
    FILE * fp = fopen("input.txt", "r");

    while(fgets(input, 150, fp) != NULL) {
        char * word;
        int start_x;
        int start_y;
        int dest_x;
        int dest_y;
        word = strtok(input, " ");
        if(!strcmp(word, "toggle")) {
            start_x = atoi(strtok(NULL, ","));
            start_y = atoi(strtok(NULL, " "));
        } else if(!strcmp(word, "turn")) {
            word = strtok(NULL, " ");
            start_x = atoi(strtok(NULL, ","));
            start_y = atoi(strtok(NULL, " "));
        }
        strtok(NULL, " ");
        dest_x = atoi(strtok(NULL, ","));
        dest_y = atoi(strtok(NULL, " "));
        
        for(int i = start_x; i <= dest_x; i++) {
            for(int j = start_y; j <= dest_y; j++) {
                if(!strcmp(word, "on")) {
                    grid[i][j]++; 
                } else if(!strcmp(word, "off")) {
                    if(grid[i][j] != 0) {
                        grid[i][j]--;
                    }
                } else if(!strcmp(word, "toggle")) {
                    grid[i][j] += 2;
                }
            }
        }
    }

    int counter = 0; 
    for(int i = 0; i < MAX; i++) {
        for(int j = 0; j < MAX; j++) {
            counter += grid[i][j];
        }
    }
    printf("%d", counter);
}
