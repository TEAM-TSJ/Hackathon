#include <stdio.h>
#include <stdlib.h>

typedef struct	s_Node {
	int cnt;
	char c;
	struct s_Node *left;
	struct s_Node *right;
}				t_Node;

//문자열에서 중복제거한 문자의 수
int		get_word_num(char *str) {
	char	check[130] = "";
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
	lst[0].c = str[0];

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
		if (!is_exist)
			lst[j].c = c;
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

//리스트 정렬
void	sort_lst(t_Node *lst, int sen_cnt) {
	for (int i = 0; i < sen_cnt - 1; i++) {
		for(int j = i + 1; j < sen_cnt; j++) {
			if (lst[i].cnt > lst[j].cnt) {
				t_Node tmp = lst[i];
				lst[i] = lst[j];
				lst[j] = tmp;
			}
		}
	}
}

int	stulen(t_Node *lst) {
	int i = 0;
	while (lst[i].cnt)
		i++;
	return (i);
}

t_Node *make_tree(t_Node *lst_node) {
	t_Node tmp;
	tmp.c = '\0';
	tmp.cnt = lst_node[0].cnt + lst_node[1].cnt;
	tmp.right = &lst_node[0];
	tmp.left = &lst_node[1];

	t_Node *ret = malloc((sizeof(t_Node) * stulen(lst_node)) - 1);
	int i = 0;
	for (i = 2; i < stulen(lst_node); i++) {
		ret[i-2] = lst_node[i];
	}
	ret[i - 2] = tmp;
	return (ret);
}

void	pre_tree(t_Node *t)
{
	//재귀 브레이크 포인트
	if (!t)
	{
		// printf("X \n");
		return;
	}
	else
	{
		printf("%d ",t->cnt);
		//printf("(0) 왼:");
		pre_tree(t->left);
		//printf("(1) 오:");
		pre_tree(t->right);
	}
}

int main(void) {
	char *str = "aaaaabbbbcccdde";
	int sen_cnt = get_word_num(str);

	t_Node *lst_node = malloc((sizeof(t_Node) * get_word_num(str)));
	for (int i = 0; i < get_word_num(str); i++) {
		lst_node[i].left = NULL;
		lst_node[i].right = NULL;
	}
	make_lst(lst_node, str);
	sort_lst(lst_node, sen_cnt);
	
	t_Node *result = malloc(sizeof(t_Node));
	result = make_tree(lst_node);
	sort_lst(lst_node, sen_cnt);

	while (stulen(result) != 1) {
		sort_lst(result, stulen(result));
		result = make_tree(result);
		sort_lst(result, stulen(result));
	}

	pre_tree(result);

	
	return 0;
}

