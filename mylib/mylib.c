#include <stdio.h>

void states(int s0, int s1, int o0, int i, int* S0, int* S1, int* O0) {
    *S0 = i;
    *S1 = (!s1) & s0 & (!i) | s1 & (!s0) | s1 & i;
    *O0 = (!s1) & s0 | s1 & (!s0);

    if ((s0 == 0) && (s1 == 0)){ // State 1 - the elevator is not moving at all
        if (i == 0){
            *S0 = 0;
            *S1 = 0;
            *O0 = 0;
        } else{
            *S0 = 0;
            *S1 = 1;
            *O0 = 1;
        }
    } else if ((s0 == 0) && (s1 == 1)) { // State 2 - button is pushed, the elevator is going up
        if (i == 0){
            *S0 = 1;
            *S1 = 0;
            *O0 = 1;
        } else{
            *S0 = 0;
            *S1 = 1;
            *O0 = 1;
        }
    } else if ((s0 == 1) && (s1 == 0)) { // State 3 - the elevator stays on the upstairs
        if (i == 0){
            *S0 = 1;
            *S1 = 0;
            *O0 = 1;
        } else{
            *S0 = 1;
            *S1 = 1;
            *O0 = 0;
        }
    } else if ((s0 == 1) && (s1 == 1)) { // State 4 - down button is pushed, the elevator is going down to state 1
        if (i == 0){
            *S0 = 0;
            *S1 = 0;
            *O0 = 0;
        } else{
            *S0 = 1;
            *S1 = 1;
            *O0 = 0;
        }
    }
}