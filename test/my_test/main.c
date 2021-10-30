#include "main.h"

/*
** 재귀형태로 구현되는구나 일반적인 동작은
*/
void	run_tree(t_node **t)
{
	int value;
	
	printf("트리에 저장할 값을 입력하세요 : ");
	scanf("%d", &value);

	printf("addr : %p\n", &value);
	printf("value : %d\n", value);
	printf("node addr** : %p\n", t);
	if (value < 0)//일단 음수를 재귀의 브레이크 포인트로 설정해놓고,
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

/*
** 허프만 작성규칙 두가지 기억해둘것. +++
** 접두어코드 + 이진트리
** 정렬 규칙 : 모든 집합을 빈도순으로 구분해 나열한다.
** 정복 규칙 : 빈도가 가장 낮은 2개의 그룹을 합친다. 빈도수가 큰 그룹에 0을 주고 빈도수가 작은 그룹에 1을 준다.
*/
int	main(int ac, char **av)
{
	t_node *t;
	
	run_tree(&t);
	printf("전위순회\n");
	pre_tree(t);
	printf("\n");

	printf("중위순회\n");	
	mid_tree(t);
	printf("\n");
	
	printf("후위순회\n");
	post_tree(t);
	printf("\n");


	exit(0);
	return 0;
}
