#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "mylib/mylib.h"

void reset(){
    printf("\033[0m");
}

void red(){
    printf("\033[0;31m");
}

void green(){
    printf("\033[0;32m");
}

int main(void){
    int s0 = 0, s1 = 0, i, o0 = 0;
    while (true){
        printf("Elevator is  ");
        if (o0 == 0){
            red();
            printf("NOT MOVING\n");
        } else{
            green();
            printf("GOING UP/DOWN\n");
        }
        reset();

        printf("Enter an input (0 for not pushing the up/down button, 1 for pushing the up/down button): ");
        scanf("%d", &i);

        if (i == 0 || i == 1){
            states(s0, s1, o0, i, &s0, &s1, &o0);
        } else{
            printf("Please enter a valid input based on the instructions\n");
        }
    }

    return 0;
}