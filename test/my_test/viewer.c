#include "main.h"

void viewer(t_list *frequency)
{
	t_list *check = frequency;
	int number = 1;
	while(check)
	{
		printf("node num: %d\n", number);
		printf("cha : %c\n", check->data);
		printf("pre : %d\n", check->count);
		printf("\n");
		if(check->next)
			check = check->next;
		else
			break;
		number++;
	}
	exit(0);
}
