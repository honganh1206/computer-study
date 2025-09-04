#include <stdio.h>

void shiftAddOpt(int *a, int *b){
    *a = (*a * 10) + *b;
}

void shiftAdd(int *a, int *b){
    *a = *a * 10; 
    // If a and b are both pointing to the same location here
    // i.e., a and b are both &x
    // then we risks doubling the value pointed by both a and b
    *a += *b; 
}

int main(void){
    int x = 5;
    int y = 6;
    shiftAdd(&x, &x); //should produce 56
    printf("shiftAdd produces: %d\n", x);

    x = 5; //reset x
    shiftAddOpt(&x, &x); //should produce 56
    printf("shiftAddOpt produces: %d\n", x);

    return 0;
}
