#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 100

void main() {
    const char vowels[5] = {'a', 'e', 'i', 'o', 'u'};

    char input[MAX];
    char file_name[] = "input.txt";
    FILE * fp = fopen(file_name, "r");

    int nice = 0;
    
    while(fgets(input, MAX, fp) != NULL) {
        int vow = 0;
        int row = 0;
        int contain = 0;
        for(int i = 0; input[i] != '\n'; i++) {
            for(int j = 0; j < 5; j++) {
                if(input[i] == vowels[j]) {
                    vow++;
                    break;
                }
            }

            if(input[i+1] != '\n') {
                if(input[i] == input[i+1]) {
                    row = 1;
                }

                if((input[i] == 'a') &&
                        (input[i+1] =='b')) {
                    contain = 1;
                    break;
                } else if((input[i] == 'c') &&
                        (input[i+1] =='d')) {
                    contain = 1;
                    break;
                } else if((input[i] == 'p') &&
                        (input[i+1] =='q')) {
                    contain = 1;
                    break;
                } else if((input[i] == 'x') &&
                        (input[i+1] =='y')) {
                    contain = 1;
                    break;
                }
            }
        }

        if((vow >= 3) && (row == 1) && (contain == 0)) {
            nice++;
        }
    }

    fclose(fp);
    printf("%d\n", nice);
}
