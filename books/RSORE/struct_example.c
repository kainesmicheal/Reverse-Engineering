#include <stdio.h>

struct head
{
	char _name[10];
	int id;
	float amount;
} h1; //it can also be declared here

int main()
{
	printf("%d\n",h1.id);
	//structs can be declared normally like data types
	struct head h1;
	h1.id = 10;
	printf("%d\n",h1.id);
	return 0;	
}
