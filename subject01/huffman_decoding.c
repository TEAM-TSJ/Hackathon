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
	int		comp_len;
	char	*comp_data;
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
char	*my_substr(char const *s, unsigned int start, size_t len)
{
	unsigned int	i;
	char			*sub;

	if (s == NULL)
		return (NULL);
	if (start >= strlen(s))
		return (strdup(""));
	if ((sub = (char *)malloc(sizeof(char) * len + 1)) == NULL)
		return (NULL);
	i = 0;
	while (i < len)
	{
		sub[i] = s[start + i];
		i++;
	}
	sub[i] = '\0';
	return (sub);
}

char	my_itoa(int n)
{
	return ((char)(n + 48));
}

int		my_atoi(char c)
{
	return ((int)(c - 48));
}

int		bin_to_int(char *s, int len)
{
	int	decimal;
	int	position;

	decimal = 0;
	position = 0;
	for (int j = len; j >= 0; j--)
	{
		if (my_atoi(s[j]) == 1)
			decimal += 1 << position;
		position++;
	}
	return (decimal);
}

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

int		get_char_num(char *s, int *i)
{
	char	*num;
	int		decimal;
	int		len;

	len = strlen(s);
	num = (char *)malloc(sizeof(char) * 9);
	num[8] = 0;
	while (*i < 8)
	{
		num[*i] = s[*i];
		(*i)++;
	}
	decimal = bin_to_int(num, 7);
	free(num);
	return (decimal);
}

t_leaf	*get_leaf_info(t_info *info, char *s, int *i)
{
	t_leaf	*leaf;
	char	*char_info;
	char	*pf_size;

	leaf = (t_leaf *)malloc(sizeof(t_leaf) * info->char_num);
	if (!leaf)
	{
		printf("don't get c_info\n");
		return (NULL);
	}
	char_info = (char *)malloc(sizeof(char) * 9);
	pf_size = (char *)malloc(sizeof(char) * 5);
	for (int j = 0; j < info->char_num; j++)
	{
		char_info = my_substr(s, *i, 8);
		leaf[j].c = (char)bin_to_int(char_info, 7);
		free(char_info);
		*i += 8;
		pf_size = my_substr(s, *i, 4);
		leaf[j].pf_size = bin_to_int(pf_size, 3);
		free(pf_size);
		*i += 4;
		leaf[j].prefix = (char *)malloc(sizeof(char) * leaf[j].pf_size + 1);
		leaf[j].prefix = my_substr(s, *i, leaf[j].pf_size);
		*i += leaf[j].pf_size;
	}
	return (leaf);
}

int		get_comp_length(char *s, int *i)
{
	char	*data;
	int		len;

	data = (char *)malloc(sizeof(char) * 33);
	data = my_substr(s, *i, 32);
	len = bin_to_int(data, 31);
	*i += 32;
	return (len);
}

char	*get_comp_data(t_info *info, char *s, int *i)
{
	char	*data;

	data = (char *)malloc(sizeof(char) * info->comp_len + 1);
	data = my_substr(s, *i, info->comp_len);
	return (data);
}

void	decode_header(t_info *info, char *s)
{
	int		i;

	i = 0;
	info->char_num = get_char_num(s, &i);
	info->c_info = get_leaf_info(info, s, &i);
	info->comp_len = get_comp_length(s, &i);
	info->comp_data = get_comp_data(info, s, &i);
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
/*
	printf("문자 개수 : %d\n", info->char_num);
	for (int i = 0; i < info->char_num; i++)
		printf("%5c\t%5d\t%s\n", info->c_info[i].c, info->c_info[i].pf_size, info->c_info[i].prefix);
	printf("압축 문자 비트 길이 : %d\n", info->comp_len);
	printf("압축 문자 : %s\n", info->comp_data);
*/
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