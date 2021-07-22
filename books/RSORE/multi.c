#include <stdio.h>

int Multiply(int x, int y)
{
	int z;
	z = x * y;
	return z;
}

int main(int argc, char* args[])
{
	int res = Multiply(atoi(args[1]),atoi(args[2]));
	printf("Result: %d\n",res);
	return 0;
}
