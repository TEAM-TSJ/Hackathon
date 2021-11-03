#include "main.h"

void frequency_viewer(t_list *frequency)
{
	t_list *check = frequency;
	int number = 1;
	
	printf("\033[0;32m빈도수 리스트 확인(리스트)\033[0m\n");
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
	//exit(0);
}


void codetable_view(char **str)
{
	int k = -1;
	while(++k < NUM_ASCII)
	{
		if (str[k])
			printf("codetable cahr: %c, prefix: %s, length: %zu \n", (char)k, str[k], ft_strlen(str[k]));
	}
	printf("\n");
	printf("\n");
}
