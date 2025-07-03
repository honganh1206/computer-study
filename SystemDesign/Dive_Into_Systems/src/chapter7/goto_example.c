#include <stdio.h>

int getSmallest(int x, int y) {
	int smallest;

	if (x <= y) {
		goto else_statement;
	}
	smallest = y;
	goto done;

else_statement:
	smallest= x;

done:
	return smallest;
}

int getSmallest_cmov(int x, int y) {
	return x > y ? y : x;
}


int main(void) {
	int x;
	x = getSmallest_cmov(10, 20);
	printf("x is: %d\n", x);
	return 0;
}
