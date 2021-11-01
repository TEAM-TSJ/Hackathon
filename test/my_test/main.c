#include "main.h"

/*
** 재귀형태로 구현되는구나 일반적인 동작은
*/
// void	run_tree(t_node **t)
// {
// 	char value;
	
// 	printf("트리에 저장할 값을 입력하세요 : ");
// 	scanf("%c", &value);

// 	printf("addr : %p\n", &value);
// 	printf("value : %c\n", value);
// 	printf("node addr** : %p\n", t);
// 	if (!value)//일단 Null 재귀의 브레이크 포인트로 설정해놓고,
// 	{
// 		*t = NULL;
// 		return;
// 	}
// 	else
// 	{
// 		*t = (t_node *)malloc(sizeof(t_node));// 브레이크포인트가 아니면 계속 가지를 뻗어주자
// 		(*t)->data = value;
// 		printf("left tree ++\n");// left가 브레크 걸릴때까지 먼저 넣어주고
// 		run_tree(&((*t)->left));
// 		printf("right tree ++\n");// 브레이크가 걸리면 역순으로 라이트를 받겠지
// 		run_tree(&((*t)->right));
// 	}
// }

// void encode(t_node *t)
// {
// 	char str[11] = {'a', 'a', 'a', 'a', 'a', 'b', 'b', 'b', 'c', 'd', 'd', '\0'};
// 	int idx = -1;

// 	while(++idx)
// 	{
// 		while(str[idx]);
// 	}
// 	if (!t)
// 		return;
// 	else
// 	{
// 		printf("%d ",t->data);
// 		pre_tree(t->left);
// 		pre_tree(t->right);
// 	}
// }
t_node *creat_tree(t_node *t, t_node *f, t_list *min)
{
	t_node *n;
	//min의 데이터로 새노드를 만들고 f랑 합쳐주는 재귀함수(이진트리공식)
	//f가 빈도수 낮은애들을 자식으로 가지고 있는 부모노드
	if (!min)//일단 Null 재귀의 브레이크 포인트로 설정해놓고,
	{
		//printf("top111 data : %d\n", f->data);
		t = f;
		return(t);
	}
	else//아직 합칠데이터가 있다는 의미랑 같아
	{
		//새노드생성
		n = (t_node *)malloc(sizeof(t_node));
		//(*t)->data = total;//빈도수 합
		n->data = min->count + f->data;
		// printf("min->count %d\n", min->count);
		// printf("f->data %d\n", f->data);
		// printf("n->data %d\n", n->data);
		// 새로만든 min의빈도수랑 데이타의합, 재귀할때마다 오른쪽 노드가 됨.
		n->left = (t_node *)malloc(sizeof(t_node));
		n->left->data = min->count;
		n->left->left = NULL;//왼쪽엔 뭐 두지마.
		n->left->right = NULL;//무조건 오른쪽만 자식을 달아줘

		n->right = (t_node *)malloc(sizeof(t_node));
		n->right = f;
		t = creat_tree(t, n, min->next);
	}
	return(t);
}

/*
** 전위방식(pre traversal)
** root->left->right순서대로 순회(역시나 재귀)
*/
void	pre_tree(t_node *t)
{
	//재귀 브레이크 포인트
	if (!t)
	{
		// printf("X \n");
		return;
	}
	else
	{
		printf("%d ",t->data);
		// printf("(0) 왼:");
		pre_tree(t->left);
		// printf("(1) 오:");
		pre_tree(t->right);
	}
}

void	search_tree(t_node *t, int fre)
{
	//재귀 브레이크 포인트
	if (!t)
		return;
	else
	{
		if(!t->left && !t->right && fre == t->data)
		{
			printf("->%d \n",t->data);
			return;
		}
		if(t->left && fre == t->left->data)
		{
			printf("0");
			search_tree(t->left, fre);
			return;
		}
		if(t->left && t->right)
			printf("1");
		search_tree(t->right, fre);
	}
}

void	encode(t_node *t, int fre)
{
	//재귀 브레이크 포인트
	//printf("ggg : %d\n", fre);
	if (!t)
		return;
	else
	{
		if(!t->left && !t->right && fre == t->data)
		{
			return;
		}
		if(t->left && fre == t->left->data)
		{
			printf("0");
			encode(t->left, fre);
			return;
		}
		if(t->left && t->right)
			printf("1");
		encode(t->right, fre);
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
	int		node_cnt = 0;

	tmp = fre;
	while (tmp)
	{
		node_cnt++;
		tmp = tmp->next;
	}

	tmp = fre;
	int idx = -1;
	while(++idx < node_cnt)
	{
		if (tmp->data > tmp->next->data)
			;// 탑노드랑 넥스트노드를 스왑하는과정을 하는 함수를 cnt만큼 반복
			//  뽑아낸 데이터는 바로바로 짤라서 해제; 만들어진 새로운 리스트는 추가후 다시 정렬(길이 다시쟤고)
			//  그럼 결국ㄱ 프리솔트 함수 재귀함수.
			//  하나 남을때까지
			// 그럼 여기서 합쳐진 노드를 계속 들고있고, 그 정보는 리스트에 추가되고, 그게 합쳐질때 노드를 생성하고
			// 하는 방식으로다가, 수행.
			// 
	}
	printf("node size :%d\n", node_cnt);
	return(fre);
}

t_node *ft_huffman(t_list *fre, char *str)
{
	//
	t_node *t;
	t_node *f;

	// 가장작은 값 2개를 골라
	t_list *min;
	t_list *min2;

	//빈도수가 낮은 노드를 뽑아내고
	//while((min = min_fre(fre)) > 0)
	min = fre;

	//min->count;//가장작은 빈도수가 될것임
	//min->next->count;// 그다음 작은 빈도수가 될거임

	/*
	** 수정안 : 리스트에서 부모노드를 생성할때마다 부모노드를 기준으로하는 빈도수정렬을 다시 수행함
	** 언제까지? 탐노드 하나남을때까지.
	** 재귀 로직은 : 노드를 합치고 정렬이 다시된 리스트를 
	*/

	// 합치고 대체하게 하는거지 . 그렇지.

	// 노드를 하나생성해서 쟤네를 이어주고 트리를 만들어주는거에 넣어줘보자(널가드는 일단 신경쓰지말고)
	// 이렇게 하면 제일 작은거에 대해서 기본적으로 이어붙힐 뼈대가 된거잖아 그럼 크리에이트로 들어가서는
	// 이제 재귀로 얘랑 min데이터를 하나씩 묶어주기만 하면 됨 언제까지? min데이터가 끝날때까지
	f = (t_node *)malloc(sizeof(t_node));
	f->left = (t_node *)malloc(sizeof(t_node));
	f->right = (t_node *)malloc(sizeof(t_node));

	//프리퀀시에 이만큼에 문자가 없으면 터질수밖에 없지(첫번째 세그폴트 지점)
	//./test jjkkkdddsss

	f->left->data = min->next->count;
	f->right->data = min->count;
	f->data = min->count + min->next->count;

	// 만약 f의 데이터값이(빈도수가) 보다 작은게 두개있으면 그두개를 부모노드로 묶어줌
	// 두개의 부모노드가 

	t = creat_tree(t, f, min->next->next);

	// printf("top data t : %d\n", t->data);
	printf("\n");
	printf("\033[0;32m이진트리 정상작동 확인(전위순회)\033[0m\n");
	pre_tree(t);
	printf("\n");
	printf("\n");

	printf("\033[0;32m접두어코드\033[0m\n");
	search_tree(t, 1);
	search_tree(t, 2);
	search_tree(t, 3);
	search_tree(t, 4);

	printf("\n");
	printf("\033[0;32m인코드\033[0m\n");
	int j = -1;
	while (str[++j])
		encode(t, fre_check(str[j], fre));//빈도수뱉게
	printf("\n");
	printf("\n");
	return (t);
	//부모트리를 만들어서 붙힘. 오른쪽 왼쪽순.
}

/*
** 허프만 작성규칙 두가지 기억해둘것. +++
** 접두어코드 + 이진트리
** 정렬 규칙 : 모든 집합을 빈도순으로 구분해 나열한다.
** 정복 규칙 : 빈도가 가장 낮은 2개의 그룹을 합친다. 빈도수가 큰 그룹에 0을 주고 빈도수가 작은 그룹에 1을 준다.
** 리스트 빈도순으로 정렬할것.
** 디코드는 결국 트리를 따라가는 
*/
int	main(int ac, char **av)
{
	t_node *t;
	t_list *fre;
	char *ptr;
	
	if (ac != 2)
		return (ft_exit(1));
	// 만약 aaabbc가 들어왔다고 가정하고 뭘해야할지 생각해보자.
	// 문자당 빈도수가 들어있다. 정렬할 필요는 없을거같은게
	// 문자는 av를 그대로 활용하면 되잖아. 그냥 빈도수 낮은거찾아서 집어넣자.
	// 집어넣은거는 빈도수 음수로 바꿔주면 되자너, 버블솔트 구현해논거 가져올수도있는데, 이게 나을거같음.
	fre = ft_frequency(av[1]);
	
	//일단 제대로 저장되나 찍어보자 viewer
	ft_fre_sort(fre);
	//난 문자별로 빈도수가 적힌 리스트가 있고(fre), 원래 문자열을 알고있어(av)
	//허프만에서는 쟤네를 이진트리로 집어넣어야해, 빈도수가 낮은게 1오른쪽자식 높은게 0왼쪽자식이야.
	//ft_huffman(fre, av[1]);
	// frequency_viewer(fre);
	
	//printf("top value: %d", t->data);
	// run_tree(&t);
	// printf("전위순회\n");
	// pre_tree(t);
	// printf("\n");
	exit(0);

	// printf("중위순회\n");	
	// mid_tree(t);
	// printf("\n");
	
	// printf("후위순회\n");
	// post_tree(t);
	// printf("\n");

	return (ft_exit(0));
}
