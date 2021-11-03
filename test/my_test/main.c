#include "main.h"

/*
** tree를 결국 여기서 뻗어줌
** 부모노드의 빈도수를 저장하고, 다시 빈도수 리스트랑 우선순위를 판별한후 두개를 착출해서 큰걸 오른쪽에 붙히는 방식.
*/
t_node *creat_tree(t_node *t, t_list *fre)
{
	t_node *f = NULL;
	t_list *tmp = NULL;

	ft_fre_sort(fre);//정렬을 해줘야댕
	if (fre && !fre->next)//여기가 min은 있고 next노드가 없어야댐.
	{
		//min에 노드주소를 담아줄수있도록 구현해서 주소를 연결해주자.
		t = fre->addr;//
		return(t);
	}
	else//아직 합칠데이터가 있다는 의미랑 같아
	{
		f = (t_node *)malloc(sizeof(t_node));

		//프리퀀시에 이만큼에 문자가 없으면 터질수밖에 없지(첫번째 세그폴트 지점)
		//./test jjkkkdddsss
		if (fre->addr)
			f->right = fre->addr;
		else
		{
			f->right = (t_node *)malloc(sizeof(t_node));
			/// fre->next->count는 오른쪽 노드의 빈도수가 아니라, 부모노드의 빈도수일경우가 존재함. 고칠것.
			// ㅇㅕ기에 들어가야하는 조건문은 붙여줘야하는게 부모노드인지를 확인해서, 부모노드면, 
			f->right->data = fre->count;
			f->right->value = fre->data;
		}
		if (fre->next->addr)
			f->left = fre->next->addr;
		else
		{
			f->left = (t_node *)malloc(sizeof(t_node));
			f->left->data = fre->next->count;
			f->left->value = fre->next->data;
		}
		f->data = fre->count + fre->next->count;
		//합친거에 대해서 리스트 제거해주기
		//지금 합친게 min이랑 min->next니까
		tmp = fre;
		fre = fre->next->next;
		free(tmp->next);
		free(tmp);
	// 위처럼 합친후에 추가되어야 하는게, 노드 정도를 기입해서 새로운 리스트노드를 만들고 min에 addback
		ft_lst_back(&fre ,ft_lst('\0', f->data, f));// 문자정보, 빈도수, 노드주소, 
		ft_fre_sort(fre);
		t = creat_tree(t, fre);
	}
	return(t);
}

/*
** 전위방식(pre traversal)
** root->left->right순서대로 순회(역시나 재귀)
*/
void	pre_tree(t_node *t)
{
	if (!t)
		return;
	else
	{
		pre_tree(t->left);
		pre_tree(t->right);
	}
}

t_node	*encode(t_node *t, t_list *pre, char str, int fre)
{
	t_list *new;
	t_list *tmp;
	t_node *val;

	if (!t)
		return (t);
	else
	{
		if(!t->left && !t->right && str == t->value)
		{
			tmp = (pre);
			while(tmp->next)
			{
				if (tmp->count >= 0)
					printf("%d", tmp->count);
				else
					printf(" ");
				tmp = tmp->next;
			}
			return (t);
		}
		else // 열어봤는데 결국 아니란 말이지.
		{
				printf("!!!! :%d\n", t->data);
				printf("hihihihihihi\n");
		}
		if(t->left)
		{
			if (t->left && t->left->value != str)
			{
				new = ft_lst('\0', 0, 0);
				ft_lst_back(&pre, new);
			}
			val = encode(t->left, pre, str, fre);
		}
		if(t->right && val->value != str)
		{
			if (t->right && !t->right->value)
			{
				new = ft_lst('\0', 1, 0);
				ft_lst_back(&pre, new);
			}
			val = encode(t->right, pre, str, fre);
		}
	}
	return (val);
}

/*
** 후위방식(post traversal)
** left->right->root순서대로 순회(역시나 재귀)
*/
void	post_tree(t_node *t)
{
	if (!t)
		return;
	else
	{
		pre_tree(t->left);
		pre_tree(t->right);
		printf("%d ",t->data);
	}
}

/*
** 중위방식(inorder traversal)
** left->root->right순서대로 순회(역시나 재귀)
*/
void	mid_tree(t_node *t)
{
	//재귀 브레이크 포인트
	if (!t)
		return;
	else
	{
		pre_tree(t->left);
		printf("%d ",t->data);
		pre_tree(t->right);
	}
}

int ft_exit(int value)
{
	if (value == 1)
		printf("error: ac: Invalid\n");
	else
		printf("exit: all good\n");
	exit(0);
	return(0);
}

t_list *ft_frequency(char *ch)
{
	t_list *frequency = NULL;
	t_list *new = NULL;
	int idx = -1;
	int jdx;
	int count = 0;

	while (ch[++idx])
	{
		jdx = -1;
		count = 0;
		while (ch[++jdx])
		{
			if (jdx < idx && ch[jdx] == ch[idx])
				break;
			else if (jdx >= idx &&  ch[jdx] == ch[idx])
				count++;
		}
		if (!(jdx < idx && ch[jdx] == ch[idx]))
		{
			if (!frequency)
				frequency = ft_lst(ch[idx], count, NULL);	
			else
				new = ft_lst(ch[idx], count, NULL);
			ft_lst_back(&frequency, new);	
		}
	}
	return (frequency);
}

int fre_check(char value, t_list *fre)
{
	t_list *tmp;

	tmp = fre;
	while(tmp)
	{
		if (tmp->data == value)
			return(tmp->count);
		tmp = tmp->next;
	}
	return (-1);
}

t_list *ft_fre_sort(t_list *fre)
{
	t_list *tmp = 0;
	t_list swp;
	int		node_cnt = 0;

	// 여기서 길이 측정.
	tmp = fre;
	while (tmp)
	{
		node_cnt++;
		tmp = tmp->next;
	}
	// 스왑(버블정렬)
	int idx = -1;
	while(++idx < node_cnt)
	{
		tmp = fre;
		while (tmp)
		{
			if (tmp->next && (tmp->count > tmp->next->count))
			{
				swp.addr = tmp->addr;
				swp.data = tmp->data;
				swp.count = tmp->count;
				
				tmp->addr = tmp->next->addr;
				tmp->data = tmp->next->data;
				tmp->count = tmp->next->count;
				
				tmp->next->addr = swp.addr;
				tmp->next->data = swp.data;
				tmp->next->count = swp.count;
			}
			tmp = tmp->next;
		}
		

	}
	return(fre);
}

void	find_char(t_node *t, char ch)
{
	if (!t) {
		stack[pos--] = -1;
		return;
	}
	else if (t->value == ch) {
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

void	clear_tree(t_node *t)
{
	if (!t) {
		return;
	}
	else {
		t->is_visit = 0;
		clear_tree(t->left);
		clear_tree(t->right);
	}
}

t_node *ft_huffman(t_list *fre, char *str)
{
	t_node *t;
	t_node *f;
	t_list *min;

	min = fre;
	if (min && min->next)
	{
		f = (t_node *)malloc(sizeof(t_node));
		f->left = (t_node *)malloc(sizeof(t_node));
		f->right = (t_node *)malloc(sizeof(t_node));
		f->is_visit = 0;
		f->left->data = min->next->count;
		f->left->value = min->next->data;
		f->right->data = min->count;
		f->right->value = min->data;
		f->data = min->count + min->next->count;
		fre = min->next->next;
		free(min->next);
		free(min);
	}
	ft_lst_back(&fre ,ft_lst('\0', f->data, f));// 문자정보, 빈도수, 노드주소
	ft_fre_sort(fre);

	t = creat_tree(t, fre);
	char *sym_code[NUM_ASCII];
	memset(sym_code, 0, sizeof(sym_code));

	int i = 0;
	while (!stack[i])
		stack[i++] = -1;

	i = 0;
	int j = 0;
	int check = 0;
	int total = 0;
	char *ptr;

	ptr = ft_strdup("");
	while (str[i]) {
		pos = 0;
		find = 0;
		j = 0;
		find_char(t, str[i]);
		if (sym_code[(int)str[i]])
			check = 1;
		else
			check = 0;
		while (stack[j] != -1) {
			if (!check)
				sym_code[(int)str[i]] = ft_strjoin(sym_code[(int)str[i]], ft_strdup(ft_itoa(stack[j])));
			ptr = ft_strjoin(ptr, ft_strdup(ft_itoa(stack[j])));
			stack[j] = -1;
			j++;
			total++;
		}
		clear_tree(t);
		i++;
	}
	creat_file(sym_code, ptr, total);
	return (t);
}

int	word_count(char **str)
{
	int idx = -1;
	int num = 0;

	while(++idx < NUM_ASCII)
		if (str[idx])
			num++;
	return (num);
}

char *ten_to_two(unsigned n, int bit)
{
	char *tmp = ft_strdup("");
	int i = -1;
	unsigned a = 0x80000000;// 1000 0000 0000 0000 0000 0000 0000 0000(2) <약 21억>
	while(++i < 32)
	{
		if(i > 31 - bit)
		{
			if ((a & n) == a)
				tmp = ft_strjoin(tmp, ft_itoa(1));
			else
				tmp = ft_strjoin(tmp, ft_itoa(0));
		}
		a >>= 1;
	}
	return(tmp);
}

void creat_file(char **sym_code, char *ptr, int total)
{
	printf("\033[0;32m코드테이블 저장상태 확인\033[0m\n");
	codetable_view(sym_code);
	FILE *fd = 0;
	char *filename = "test.encode";
	char *tmp;
	int n = 0;
	fd = fopen(filename, "wb");
	if(fd)
	{
		n = word_count(sym_code);
		tmp = ten_to_two(n, 8);
		//tmp = ft_itoa(n);
		fwrite(tmp, /*배열의길이*/strlen(tmp), /*자료형 크기*/1, /*fd*/fd);//문자 개수
		//fwrite(" ", /*배열의길이*/1, /*자료형 크기*/1, /*fd*/fd);//일단 구분자.
		free(tmp);
		int k = -1;
		while(++k < NUM_ASCII)
		{
			if (sym_code[k])
			{
				//tmp = ft_itoa(k);
				tmp = ten_to_two(k, 8);
				fwrite(tmp, /*배열의길이*/strlen(tmp), /*자료형 크기*/1, /*fd*/fd);//아스키코드
				free(tmp);
				//tmp = ft_itoa(strlen(sym_code[k]));
				tmp = ten_to_two(strlen(sym_code[k]), 4);
				fwrite(tmp, /*배열의길이*/strlen(tmp), /*자료형 크기*/1, /*fd*/fd);//접두어코드 길이
				free(tmp);
				tmp = ten_to_two(atoi(sym_code[k]), strlen(sym_code[k]));
				fwrite(tmp, /*배열의길이*/strlen(tmp), /*자료형 크기*/1, /*fd*/fd);
				//fwrite(sym_code[k], /*배열의길이*/strlen(sym_code[k]), /*자료형 크기*/1, /*fd*/fd);//접두어코드
				free(tmp);
				//fwrite(" ", /*배열의길이*/1, /*자료형 크기*/1, /*fd*/fd);//일단 구분자.
			}
		}
		//tmp = ft_itoa(total);
		tmp = ten_to_two(total, 32);
		fwrite(tmp, /*배열의길이*/strlen(tmp), /*자료형 크기*/1, /*fd*/fd);//인코드된 길이.
		//fwrite(" ", /*배열의길이*/1, /*자료형 크기*/1, /*fd*/fd);//일단 구분자.
		free(tmp);

		// 여기에 인코드 내용
		fwrite(ptr, /*배열의길이*/strlen(ptr), /*자료형 크기*/1, /*fd*/fd);//인코드
		//fwrite(" ", /*배열의길이*/1, /*자료형 크기*/1, /*fd*/fd);//일단 구분자.
		free(ptr);
		fclose(fd);

	}
	else
		printf("일단에러!!!!!!\n");
}

int	main(int ac, char **av)
{
	t_node *t;
	t_list *fre;
	char *ptr;
	
	if (ac != 2)
		return (ft_exit(1));
	fre = ft_frequency(av[1]);
	ft_fre_sort(fre);
	ft_huffman(fre, av[1]);
	return (ft_exit(0));
}
