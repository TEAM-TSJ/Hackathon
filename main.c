#include "main.h"

/*
**-e -d
*/
int ft_exit(int value)
{
	switch(value)
	{
		case ARGUMENT:
		{
			write(2, "Error: argument\n", strlen("Error: invalid\n"));
			break ;
		}
		case OPTION:
		{
			write(2, "Error: option\n", strlen("Error: invalid\n"));
			break ;
		}
		case ERROR:
		{
			write(2, "Error: invalid\n", strlen("Error: invalid\n"));
			break ;
		}
		case FORMAT:
		{
			write(2, "Error: format\n", strlen("Error: format\n"));
			break ;
		}
		default:
			break;
	}
	return (value);
}

/*
** dls
*/
int ft_search(char *str, char ch)
{
	int idx = -1;

	while(str[++idx])
		if (str[idx] == ch)
			return (idx);
	return (-1);
}

/*
**
*/
int format_check(char *av, int type, int index)
{
	//printf("idx %d", index);
	if (type == ENCODE && av[index + 1] == 't' && av[index + 2] == 'x'
		&& av[index + 3] == 't' && av[index + 4] == '\0')
		return (ENCODE);
	else if (type == DECODE && av[index + 1] == 'b' && av[index + 2] == 'i'
		&& av[index + 3] == 'n' && av[index + 4] == '\0')
		return (DECODE);
	return (FORMAT);
}

/*
** sunclee .txt && (-e || -E) ->아니면 ERROR
** tjung .bin && (-d || -D) ->아니면 ERROR
*/
int invlaid_check(char **av)
{
	if (!strcmp(av[1], "-e") || !strcmp(av[1], "-E"))
		return(format_check(av[2], ENCODE, ft_search(av[2], '.')));
	else if (!strcmp(av[1], "-d") || !strcmp(av[1], "-D"))
		return(format_check(av[2], DECODE, ft_search(av[2], '.')));
	else
		return (OPTION);
	return (0);
}

int main(int ac, char **av)
{
	int value = 0;

	if (ac != 3)
		return (ft_exit(ARGUMENT));
	value = invlaid_check(av);
	switch (value)
	{
		case ENCODE:
			return (huffman_encoding(ac, av));
		case DECODE:
			return (huffman_decoding(ac, av));
		default:
			return (ft_exit(value));
	}
	return (0);
}
