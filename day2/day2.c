#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 2

int main(int argc, char * argv[]) {
    char input[15];
    char file_name[] = "input.txt";
    FILE * fp = fopen(file_name, "r");
    int total = 0;

    //read file 
    while(fgets(input, 15, fp) != NULL) {
        //remove trailing newline
        input[strcspn(input, "\n")] = 0;
        int length;
        int width;
        int height;

        length = atoi(strtok(input, "x"));
        width = atoi(strtok(NULL, "x"));
        height = atoi(strtok(NULL, "x"));
        total += 2*length*width + 2*width*height + 2*height*length;
        if((width >= length) && (width >= height)){
            total += length*height;
        } else if((length >= height) && (length >= width)){
            total += width*height;
        } else if((height >= length) && (height >= width)){
            total += length*width;
        }
    }
    fclose(fp);
    printf("%d\n",total);
}
