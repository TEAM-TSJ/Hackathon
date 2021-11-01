#include <stdio.h>
#include <stdlib.h>

typedef struct	s_Node {
	int cnt;
	char c;
	struct Node *left;
	struct Node *right;
}				t_Node;

//문자열에서 중복제거한 문자의 수
int		get_word_num(char *str) {
	char	check[100] = "";
	int		ret = 1;

	check[0] = str[0];
	int i = 0;
	while (str[i]) {
		char c = str[i];
		int j = 0;
		int is_exist = 0;
		while (check[j]) {
			if (c == check[j])
				is_exist = 1;
			j++;
		}
		if (!is_exist) {
			check[j] = c;
			ret++;
		}
		i++;
	}
	return ret;
}

//노드생성단계
void	make_lst(t_Node *lst, char *str) {
	t_Node *first = malloc(sizeof(t_Node));
	first->c = str[0];
	lst[0] = *first;

	int i = 0;
	while (str[i]) {
		char c = str[i];
		int j = 0;
		int is_exist = 0;
		while (lst[j].c) {
			if (c == lst[j].c)
				is_exist = 1;
			j++;
		}
		if (!is_exist) {
			t_Node *tmp = malloc(sizeof(t_Node));
			tmp->c = c;
			lst[j] = *tmp;
		}
		i++;
	}

	i = 0;
	while (str[i]) {
		for (int j = 0; j < get_word_num(str); j++)
			if (lst[j].c == str[i])
				lst[j].cnt++;
		i++;
	}
}

int main(void) {
	char *str = "aaaaaavvvvv";

	t_Node *lst_node = malloc((sizeof(t_Node) * get_word_num(str))) ;
	make_lst(lst_node, str);

	for (int j = 0; j < get_word_num(str); j++)
		printf("%d\n", lst_node[j].cnt);
	return 0;
}

