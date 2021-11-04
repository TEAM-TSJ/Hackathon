#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>


short stack[100];
int pos = 0;
int find = 0;

typedef struct	s_Node {
	int cnt;
	char c;
	int is_visit;
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
void	make_lst(char *alpha, t_Node *lst, char *str) {
	lst[0].c = str[0];
	alpha[0] = str[0];

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
			lst[j].c = c;
			alpha[j] = c;
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
	tmp.is_visit = 0;
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

//전위순회
void	pre_tree(t_Node *t)
{
	//재귀 브레이크 포인트
	if (!t) {
		return;
	}
	else {
		printf("%d ",t->cnt);
		pre_tree(t->left);
		pre_tree(t->right);
	}
}

//노드방문기록 제거
void	clear_tree(t_Node *t)
{
	//재귀 브레이크 포인트
	if (!t) {
		return;
	}
	else {
		t->is_visit = 0;
		clear_tree(t->left);
		clear_tree(t->right);
	}
}

//해당 문자를 찾을때까지 dfs로 반복
void	find_char(t_Node *t, char ch)
{
	if (!t) {
		stack[pos--] = -1;
		return;
	}
	else if (t->c == ch) {
		find = 1;
		return;
	}
	else {
		t->is_visit = 1;
		if (!find && t->left && !t->left->is_visit) {
			stack[pos++] = 0;
			find_char(t->left, ch);
			if (!find)
				stack[pos--] = -1;
		}
		if (!find && t->right && !t->right->is_visit) {
			stack[pos++] = 1;
			find_char(t->right, ch);
			if (!find)
				stack[pos--] = -1;
		}
	}
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	i;
	size_t	j;
	size_t	len;
	char	*str;

	i = 0;
	if (!s1 || !s2)
		return (NULL);
	len = strlen(s1) + strlen(s2);
	if (!(str = (char *)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	while (s1[i])
	{
		str[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j])
		str[i++] = s2[j++];
	str[i] = '\0';
	return (str);
}

char *make_binary(int x, int bits){
	char *ret = malloc(sizeof(char) * bits + 1);
	for (int i = 0; i < bits; i++)
		ret[i] = '0';
	int binary;
    while(x > 0) {
        binary = x % 2;
        x /= 2;
        ret[--bits] = binary + '0';
    }
	return (ret);
}

char *size_change_to_8(char *str) {
	int i = strlen(str);
	if (i % 8)
		for (int j = 0; j < i % 8; j++)
			str = ft_strjoin(str, "0");
	return (str);
}

int main(void) {

	char *str = "aaaaabbbbcccdde";
	int sen_cnt = get_word_num(str);

	char *alpha = malloc(sizeof(char) * get_word_num(str));
	t_Node *lst_node = malloc((sizeof(t_Node) * get_word_num(str)));
	for (int i = 0; i < get_word_num(str); i++) {
		lst_node[i].is_visit = 0;
		lst_node[i].left = NULL;
		lst_node[i].right = NULL;
	}
	make_lst(alpha, lst_node, str);
	sort_lst(lst_node, sen_cnt);
	
	t_Node *result = malloc(sizeof(t_Node));
	result = make_tree(lst_node);
	sort_lst(lst_node, sen_cnt);

	while (stulen(result) != 1) {
		sort_lst(result, stulen(result));
		result = make_tree(result);
		sort_lst(result, stulen(result));
	}

	//pre_tree(result);

	int i = 0;
	while (!stack[i])
		stack[i++] = -1;

	//보낼순으로 출력하기==========================
	char *all_most = malloc(sizeof(char));
		//단어개수
	int word_cnt = get_word_num(str);
	all_most = ft_strjoin(all_most, make_binary(word_cnt, 8));
	//printf ("%s", make_binary(word_cnt, 8));

		//문자표시
	int a = 0;
	while (alpha[a]) {
		all_most = ft_strjoin(all_most, make_binary((int)alpha[a], 8));
		//printf("%c --> %s ", alpha[a], make_binary((int)alpha[a], 8));
		int j = 0;
		pos = 0;
		find = 0;
		j = 0;
		find_char(result, alpha[a]);
		int word_length = 0;
		while (stack[j] != -1) {
			word_length++;
			j++;
		}
		all_most = ft_strjoin(all_most, make_binary(word_length, 4));
		//printf(" %s ", make_binary(word_length, 4));	//접두어 코드 길이출력
		j=0;
		while (stack[j] != -1) {
			char *tmp = malloc(sizeof(char));
			tmp[0] = stack[j] + '0';
			all_most = ft_strjoin(all_most, tmp);
			//printf("%d", stack[j]);
			stack[j] = -1;
			j++;
		}
		//printf("%s", all_most);
		//printf("\n");
		clear_tree(result);
		a++;
	}

	//========================================

	//stack
	sen_cnt = 0;
	i = 0;
	int j = 0;
	while (str[i]) {
		pos = 0;
		find = 0;
		j = 0;
		find_char(result, str[i]);
		while (stack[j] != -1) {
			sen_cnt++;
			stack[j] = -1;
			j++;
		}
		clear_tree(result);
		i++;
	}

	all_most = ft_strjoin(all_most, make_binary(sen_cnt, 16));
	//printf("%s", all_most);
	i = 0;
	j = 0;
	while (str[i]) {
		pos = 0;
		find = 0;
		j = 0;
		find_char(result, str[i]);
		while (stack[j] != -1) {
			char *tmp = malloc(sizeof(char));
			tmp[0] = stack[j] + '0';
			all_most = ft_strjoin(all_most, tmp);
			stack[j] = -1;
			j++;
		}
		clear_tree(result);
		//printf("	<--   %c\n", str[i]);
		i++;
	}
	//printf("\n%s", all_most);
	all_most = size_change_to_8(all_most);
	printf("%s", all_most);
	

	return 0;
}
