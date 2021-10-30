#include "main.h"

/*
** 재귀형태로 구현되는구나 일반적인 동작은
*/
void	run_tree(t_node **t)
{
	char value;
	
	printf("트리에 저장할 값을 입력하세요 : ");
	scanf("%c", &value);

	printf("addr : %p\n", &value);
	printf("value : %c\n", value);
	printf("node addr** : %p\n", t);
	if (!value)//일단 Null 재귀의 브레이크 포인트로 설정해놓고,
	{
		*t = NULL;
		return;
	}
	else
	{
		*t = (t_node *)malloc(sizeof(t_node));// 브레이크포인트가 아니면 계속 가지를 뻗어주자
		(*t)->data = value;
		printf("left tree ++\n");// left가 브레크 걸릴때까지 먼저 넣어주고
		run_tree(&((*t)->left));
		printf("right tree ++\n");// 브레이크가 걸리면 역순으로 라이트를 받겠지
		run_tree(&((*t)->right));
	}
}

/*
** 전위방식(pre traversal)
** root->left->right순서대로 순회(역시나 재귀)
*/
void	pre_tree(t_node *t)
{
	//재귀 브레이크 포인트
	if (!t)
		return;
	else
	{
		printf("%d ",t->data);
		pre_tree(t->left);
		pre_tree(t->right);
	}
}

/*
** 후위방식(post traversal)
** left->right->root순서대로 순회(역시나 재귀)
*/
void	post_tree(t_node *t)
{
	//재귀 브레이크 포인트
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

/*
** 허프만 구현을 위한 아이디어 노트 11
*/
// char *ft_sort(char **av)
// {
// 	int i = -1;
// 	int check = 0;

// 	// 음.. 일단 빈도수 별로 정렬하고 하나씩 합쳐야 하는데,,
// 	// 문자에 대한 리스트가 있어야하나??
// 	// 들어온 문자를 리스트에 넣어가면서 똑같은지를 계속 찾는거지, 없으면 새노드, 있으면 그노드에 count
// 	// 모두다 리스트에 집어넣었으면 버블정렬 갈겨서 count크기로 정렬때리구, 작은것부터 오른쪽1 큰건 왼쪽0에 넣는거지.
// 	// 그다음 해당문자를
// 	while(av[1][++i])
// 		ft_count(av[i][i]);
// 	return (0);//리스트의 주소가 되어야할듯
// }

t_list *ft_frequency(char *ch)
{
	t_list *frequency = NULL;
	t_list *new = NULL;
	int idx = -1;
	int jdx;
	int count = 0;
	
	//전체문자에서, 중복되는 숫자를 하나로 쳤을때,
	//이숫자가 앞에 있었으면 건너뛰어 앞에 없었으면 뒤에부터 측정
	//갯수 -1만큼 총길이에서 뺌
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
				frequency = ft_lst(ch[idx], count);	
			else
				new = ft_lst(ch[idx], count);
			ft_lst_back(&frequency, new);	
		}
	}
	
	//일단 제대로 저장되나 찍어보자 viewer
	viewer(frequency);
	return (frequency);
}

/*
** 허프만 작성규칙 두가지 기억해둘것. +++
** 접두어코드 + 이진트리
** 정렬 규칙 : 모든 집합을 빈도순으로 구분해 나열한다.
** 정복 규칙 : 빈도가 가장 낮은 2개의 그룹을 합친다. 빈도수가 큰 그룹에 0을 주고 빈도수가 작은 그룹에 1을 준다.
*/
int	main(int ac, char **av)
{
	t_node *t;
	char *ptr;
	
	if (ac != 2)
		return (ft_exit(1));
	//만약 aaabbc가 들어왔다고 가정하고 뭘해야할지 생각해보자.
	//step00 : 빈도수로 정렬하기
	//문자열을 돌면서 이문자가 몇번이나 중복되는지를 체크한다.
	
	ft_frequency(av[1]);
	// ptr = ft_sort(av);
	// //낮은 빈도수부터 트리에 집어넣는다?
	
	// ft_huffman(ptr);
	
	// run_tree(&t);
	// printf("전위순회\n");
	// pre_tree(t);
	// printf("\n");

	// printf("중위순회\n");	
	// mid_tree(t);
	// printf("\n");
	
	// printf("후위순회\n");
	// post_tree(t);
	// printf("\n");

	return (ft_exit(0));
}
