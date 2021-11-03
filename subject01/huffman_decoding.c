#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct s_leaf {
	char	c;
	int		pf_size;
	char	*prefix;
}	t_leaf;

typedef struct s_info {
	t_leaf	*c_info;
	int		char_num;
	int		comp_data;
}	t_info;
/*
void	write_bfile(void)
{
	FILE	*nf;
	int		data[12];

	nf = fopen("b_test_01.bin", "wb");
	if (!nf)
	{
		printf("can't make b_file\n");
		return ;
	}
	data[0] = 3;
	data[1] = 97;
	data[2] = 19;
	data[3] = 17;
	data[4] = 76;
	data[5] = 101;
	data[6] = 128;
	data[7] = 0;
	data[8] = 0;
	data[9] = 4;
	data[10] = 138;
	data[11] = 192;
	for (int i = 0; i < 12; i++)
		fwrite(&data[i], 1, 1, nf);
}
*/
char	*free_double_malloc(char **ptr)
{
	if (ptr)
	{
		for(int i = 0; ptr[i] != NULL; i++)
		{
			if (ptr[i])
				free(ptr[i]);
		}
		free(ptr);
	}
	return (NULL);
}

char	my_itoa(int n)
{
	return ((char)(n + 48));
}

int		my_atoi(char c)
{
	return ((int)(c - 48));
}

int		get_file_size(FILE *ptr)
{
	int	file_size;

	fseek(ptr, 0, SEEK_END);
	file_size = ftell(ptr);
	fseek(ptr, 0, SEEK_SET);
	return (file_size);
}

int		*read_data(FILE *ptr, int size)
{
	int	*predata;

	predata = (int *)malloc(sizeof(int) * size);
	if (!predata)
	{
		printf("failed malloc\n");
		return (NULL);
	}
	for (int i = 0; i < size; i++)
		fread(&predata[i], 1, 1, ptr);
	return (predata);
}

char	*trans_to_binary(int *data, int size)
{
	char	**predata;
	char	*trans_data;
	int		result;

	predata = (char **)malloc(sizeof(char *) * size + 1);
	predata[size] = NULL;
	if (!predata)
	{
		printf("failed malloc\n");
		return (free_double_malloc(predata));
	}
	for (int i = 0; i < size; i++)
	{
		predata[i] = NULL;
		predata[i] = (char *)malloc(sizeof(char) * 9);
		if (!predata[i])
		{
			printf("failed malloc\n");
			return (free_double_malloc(predata));
		}
		predata[i][8] = '\0';
		result = 0;
		for (int j = 7; j >= 0; j--)
		{
			result = data[i] >> j & 1;
			predata[i][7 - j] = my_itoa(result);
		}
	}
	trans_data = (char *)malloc(sizeof(char) * (size * 8) + 1);
	for (int i = 0; i < size; i++)
		strcat(trans_data, predata[i]);
	free_double_malloc(predata);
	return (trans_data);
}

void	decode_header(t_info *info, char *s)
{
	char	num[9];
	int		decimal;
	int		position;
	int		len;

	len = strlen(s);
	num[8] = 0;
	for (int i = 0; i < 8; i++)
		num[i] = s[i];
	decimal = 0;
	position = 0;
	for (int j = 7; j >= 0; j--)
	{
		if (my_atoi(num[j]) == 1)
			decimal += 1 << position;
		position++;
	}
	info->char_num = decimal;
}

void	read_header(t_info *info, FILE *ptr)
{
	int		*data;
	char	*trans_data;
	int		size;

	size = get_file_size(ptr);
	data = read_data(ptr, size);
	trans_data = trans_to_binary(data, size);
	decode_header(info, trans_data);
	free(data);
	free(trans_data);
}

void	read_bfile(t_info *info, FILE *ptr)
{
	memset(info, 0, sizeof(*info));
	read_header(info, ptr);
}

int 	main(int ac, char **av)
{
	t_info	info;
	FILE	*fp;
	char	*file_name;

//	write_bfile();
	if (ac != 2)
	{
		printf("Invalid argument\n");
		return (1);
	}
	file_name = av[1];
	fp = fopen(file_name, "rb");
	if (!fp)
	{
		printf("can't open file\n");
		return (1);
	}
	read_bfile(&info, fp);
	fclose(fp);
	return (0);
}