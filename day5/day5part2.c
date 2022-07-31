#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 100

void main() {
    char input[MAX];
    char file_name[] = "input.txt";
    FILE * fp = fopen(file_name, "r");

    int nice = 0;
    
    while(fgets(input, MAX, fp) != NULL) {
        int repeat = 0;
        int twice = 0;
        for(int i = 0; input[i+2] != '\n'; i++) {
            if(input[i] == input[i+2]) {
                repeat = 1; 
            }

            if(input[i+3] != '\n') {
                for(int j = i + 2; input[j+1] != '\n'; j++) {
                    if(input[j] ==  input[i]) {
                        if(input[j+1] == input[i+1]) {
                            twice = 1;
                            break;
                        }
                    }
                }
            }
        }

        if(repeat && twice) {
            nice++;
        }
    }

    fclose(fp);
    printf("%d\n", nice);
}
