#include <stdio.h>

int	main(int ac, char **av)
{
	char	c;
	int		cnt;
	int		i;
	int		j;

	if (ac != 2)
	{
		printf("Invalid argument\n");
		return (1);
	}
	i = 0;
	while (av[1][i] != '\0')
	{
		c = av[1][i];
		printf("%c", c);
		cnt = 1;
		j = i + 1;
		if (c == av[1][j])
		{
			while (c == av[1][j])
			{
				j++;
				cnt++;
			}
			printf("%d", cnt);
			i = j;
		}
		else
			i++;
	}
	return (0);
}