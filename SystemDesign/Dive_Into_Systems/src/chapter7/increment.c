#include <stdio.h>
#include <stdlib.h>

int incrementX(int *x) {
	if (x != NULL) {
		return (*x)++;
	} else {
		return 1;
	}
}

int incrementX2(int **x) {
	return x ? (*x)++ : 1;
}

int main(void) {
int *x;
	x = malloc(sizeof(int));
	if (x == NULL) {
    printf("Bad malloc error\n");
    exit(1);
	}
	*x = 2;
	*x = incrementX(x);
	printf("%d\n", *x);
	free(x);
	x = NULL;
	return 0;
}
