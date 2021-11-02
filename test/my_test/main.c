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

/*
** tree를 결국 여기서 뻗어줌
** 부모노드의 빈도수를 저장하고, 다시 빈도수 리스트랑 우선순위를 판별한후 두개를 착출해서 큰걸 오른쪽에 붙히는 방식.
*/
t_node *creat_tree(t_node *t, t_list *fre)
{
	t_node *f = NULL;
	t_list *tmp = NULL;

	/*
	** step00. 빈도수 리스트 min에 대해서 여기 들어올때마다 정렬을 수행한다.
	** step01. min에 연결된 노드가 두개 이상이면, 두개를 바탕으로 새로운 노드를 생성한다. (생성한 노드의 정보를 담은 리스트를 추가한다)
	** step02. 생성된 노드에 min의 우선순위 두개를 연결한다.(데이터 기반, 주소도 가지고 있는게 좋겟음)
	** step03. 다시 creat_tree를 호출한다.
	** 언제까지?? -> min에 연결된 노드가 하나밖에 없을때까지.
	** min은 떼버린 정렬리스트, f는 합친 노드.인데... 합친노드가 필요없어지는거지. 주소를 가지고 있으니께.
	*/
	ft_fre_sort(fre);//정렬을 해줘야댕
	//printf("fre char %c\n", fre->data);
	if (fre && !fre->next)//여기가 min은 있고 next노드가 없어야댐.
	{
		//min에 노드주소를 담아줄수있도록 구현해서 주소를 연결해주자.
		t = fre->addr;//
		//pre_tree(t);
		return(t);
	}
	else//아직 합칠데이터가 있다는 의미랑 같아
	{
		//if (fre && fre->next)
		{
			f = (t_node *)malloc(sizeof(t_node));
			// f->left = (t_node *)malloc(sizeof(t_node));
			// f->right = (t_node *)malloc(sizeof(t_node));

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
				printf("lvalue: %c\n", f->right->value);
				printf("ldata: %c", fre->data);
			}
			if (fre->next->addr)
				f->left = fre->next->addr;
			else
			{
				f->left = (t_node *)malloc(sizeof(t_node));
				f->left->data = fre->next->count;
				f->left->value = fre->next->data;
				printf("rvalue: %c\n", f->right->value);
				printf("rdata: %c", fre->data);
			}
			f->data = fre->count + fre->next->count;
			//합친거에 대해서 리스트 제거해주기
			//지금 합친게 min이랑 min->next니까
			tmp = fre;
			fre = fre->next->next;
			free(tmp->next);
			free(tmp);
		}
		//else
		{
			//printf("일단은 에러\n");
		}
	// 위처럼 합친후에 추가되어야 하는게, 노드 정도를 기입해서 새로운 리스트노드를 만들고 min에 addback
		ft_lst_back(&fre ,ft_lst('\0', f->data, f));// 문자정보, 빈도수, 노드주소,

		//근데지금 문제가 .. 합친것들은 리스트에서 제거를 해줘야댐
		//addback result -> 
		printf(GREEN_COLOR);
		printf("\naddback result \n");
		printf(END_COLOR);
		ft_fre_sort(fre);
		// n = (t_node *)malloc(sizeof(t_node));
		// //(*t)->data = total;//빈도수 합
		// n->data = min->count + f->data;
		// n->left = (t_node *)malloc(sizeof(t_node));
		// n->left->data = min->count;
		// n->left->value = min->data;
		// n->left->left = NULL;//왼쪽엔 뭐 두지마.
		// n->left->right = NULL;//무조건 오른쪽만 자식을 달아줘

		// n->right = (t_node *)malloc(sizeof(t_node));
		// n->right = f;
		t = creat_tree(t, fre);
	}
	return(t);
}

// t_node *creat_tree(t_node *t, t_node *f, t_list *min)
// {
// 	t_node *n;
// 	//min의 데이터로 새노드를 만들고 f랑 합쳐주는 재귀함수(이진트리공식)
// 	//f가 빈도수 낮은애들을 자식으로 가지고 있는 부모노드
// 	if (!min)//일단 Null 재귀의 브레이크 포인트로 설정해놓고,
// 	{
// 		//printf("top111 data : %d\n", f->data);
// 		t = f;
// 		return(t);
// 	}
// 	else//아직 합칠데이터가 있다는 의미랑 같아
// 	{
// 		//새노드생성
// 		n = (t_node *)malloc(sizeof(t_node));
// 		//(*t)->data = total;//빈도수 합
// 		n->data = min->count + f->data;
// 		// printf("min->count %d\n", min->count);
// 		// printf("f->data %d\n", f->data);
// 		// printf("n->data %d\n", n->data);
// 		// 새로만든 min의빈도수랑 데이타의합, 재귀할때마다 오른쪽 노드가 됨.
// 		n->left = (t_node *)malloc(sizeof(t_node));
// 		n->left->data = min->count;
// 		n->left->value = min->data;
// 		n->left->left = NULL;//왼쪽엔 뭐 두지마.
// 		n->left->right = NULL;//무조건 오른쪽만 자식을 달아줘

// 		n->right = (t_node *)malloc(sizeof(t_node));
// 		n->right = f;
// 		t = creat_tree(t, n, min->next);
// 	}
// 	return(t);
// }

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

// void	encode(t_node *t, char str, int fre)
// {//이진트리랑, 문자하나, 빈도수 이렇게 넘겨받아온다.
// 	// 재귀 브레이크 포인트
// 	// 음.. 부모노드면, left부터 돌면서 출력하게 하고,
// 	// 마지막 잎새노드면(더이상 자식이없으면) 그게 문자랑 같을때 출력 아니면 대기. 
// 	//printf("ggg : %d\n", fre);
// 	if (!t)
// 		return;
// 	else
// 	{
// 		if(!t->left && !t->right && fre == t->data && str == t->value)
// 		{
// 			return;
// 		}
// 		if(t->left && fre == t->left->data && str == t->left->value)
// 		{
// 			printf("0");
// 			encode(t->left, str, fre);
// 			return;
// 		}
// 		if(t->left && t->right)
// 		{
// 			printf("1");
// 			encode(t->right, str, fre);
// 		}
// 	}
// }

void	encode(t_node *t, t_list *pre, char str, int fre)
{
	t_list *new;
	t_list *tmp;
	static int check;
	//이진트리랑, 문자하나, 빈도수 이렇게 넘겨받아온다.
	// 재귀 브레이크 포인트
	// 음.. 부모노드면, left부터 돌면서 출력하게 하고,
	// 마지막 잎새노드면(더이상 자식이없으면) 그게 문자랑 같을때 출력 아니면 대기. 
	//printf("ggg : %d\n", fre);
	// 인코딩자료 남은거 별도처리.. 2비트남은경우 1바이트 새롭게 따서.
	if (!t)
	{
		check = 0;
		return;
	}
	else
	{
		if(!t->left && !t->right && str == t->value)
		{
			printf("\nstr: %c, t->value %c\n", str, t->value);
			//printf("fre: %d, t->data: %d\n", fre, t->data);
			check = 1;
			tmp = (pre);
			while(tmp->next)
			{
				if (tmp->count >= 0)
					printf("%d", tmp->count);
				else
					printf(" ");
				tmp = tmp->next;
				if (tmp->prev)
					free(tmp->prev);
			}
			return;
		}
		else // 열어봤는데 결국 아니란 말이지.
		{

		}
		if(t->left)
		{
			//printf("0");
			if (t->left && !t->left->value)
			{
				new = ft_lst('\0', 0, 0);
				ft_lst_back(&pre, new);
			}
			// printf("\n data: %c : %c\n",t->value, str);
			// if (t->value)
			// 	printf("\nt->value %c\n", t->value);
			encode(t->left, pre, str, fre);
		}
		if(t->right)
		{
			//printf("1");
			if (t->right && !t->right->value && check != 1)
			{
				new = ft_lst('\0', 1, 0);
				ft_lst_back(&pre, new);
			}
			// if (t->value)
			// 	printf("\nt->value %c\n", t->value);
			//printf("\n data: %c\n",t->value);
			encode(t->right, pre, str, fre);
		}
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

/*
** 리스트에 노드정보에 대한 주소가 추가되었기때문에, 그거 추가할것.
*/
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
	// printf("\n--------info, node size :%d-----\n", node_cnt);

	// // 들어가 있는 내용 확인.
	// tmp = fre;
	// int h = -1;
	// while(tmp)
	// {
	// 	printf("문자 : %c\n",tmp->data);
	// 	printf("빈도수 : %d\n",tmp->count);
	// 	printf("노드주소 : %p\n",tmp->addr);
	// 	tmp = tmp->next;
	// }

	// 스왑(버블정렬)
	int idx = -1;
	while(++idx < node_cnt)
	{
		tmp = fre;
		//printf("문자 : %c\n",tmp->data);
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
			// if (tmp && tmp->data)
			// 	printf("문자11 : %c\n",tmp->data);
				//  뽑아낸 데이터는 바로바로 짤라서 해제; 만들어진 새로운 리스트는 추가후 다시 정렬(길이 다시쟤고)
				//  그럼 결국ㄱ 프리솔트 함수 재귀함수.
				//  하나 남을때까지
				// 그럼 여기서 합쳐진 노드를 계속 들고있고, 그 정보는 리스트에 추가되고, 그게 합쳐질때 노드를 생성하고
				// 하는 방식으로다가, 수행.
		}
		

	}

	// tmp = fre;
	// node_cnt = 0;
	// while (tmp)
	// {
	// 	node_cnt++;
	// 	tmp = tmp->next;
	// }
	// printf("\n--------info, node size :%d-----\n", node_cnt);
	
	// //viwer
	// tmp = fre;
	// h = -1;
	// while(tmp)
	// {
	// 	printf("문자 : %c\n",tmp->data);
	// 	printf("빈도수 : %d\n",tmp->count);
	// 	printf("노드주소 : %p\n",tmp->addr);
	// 	tmp = tmp->next;
	// }
	return(fre);
}

t_node *ft_huffman(t_list *fre, char *str)
{
	t_node *t;
	t_node *f;

	t_list *min;

	//빈도수가 낮은 노드를 뽑아내고
	//while((min = min_fre(fre)) > 0)
	min = fre;
	/*
	** 수정안 : 리스트에서 부모노드를 생성할때마다 부모노드를 기준으로하는 빈도수정렬을 다시 수행함
	** 언제까지? 탐노드 하나남을때까지.
	** 재귀 로직은 : 노드를 합치고 정렬이 다시된 리스트를 
	*/

	// 합치고 대체하게 하는거지 . 그렇지.

	// 노드를 하나생성해서 쟤네를 이어주고 트리를 만들어주는거에 넣어줘보자(널가드는 일단 신경쓰지말고)
	// 이렇게 하면 제일 작은거에 대해서 기본적으로 이어붙힐 뼈대가 된거잖아 그럼 크리에이트로 들어가서는
	// 이제 재귀로 얘랑 min데이터를 하나씩 묶어주기만 하면 됨 언제까지? min데이터가 끝날때까지
	
	//여기가 작은거 두개를 뽑아내서 노드를 생성해주는 부분이네.
	if (min && min->next)
	{
		f = (t_node *)malloc(sizeof(t_node));
		f->left = (t_node *)malloc(sizeof(t_node));
		f->right = (t_node *)malloc(sizeof(t_node));

		//프리퀀시에 이만큼에 문자가 없으면 터질수밖에 없지(첫번째 세그폴트 지점)
		//./test jjkkkdddsss
		f->left->data = min->next->count;
		f->left->value = min->next->data;
		f->right->data = min->count;
		f->right->value = min->data;
		f->data = min->count + min->next->count;
		//합친거에 대해서 리스트 제거해주기
		//지금 합친게 min이랑 min->next니까
		fre = min->next->next;
		free(min->next);
		free(min);
	}
	else
	{
		printf("일단은 에러\n");
	}
	// 위처럼 합친후에 추가되어야 하는게, 노드 정도를 기입해서 새로운 리스트노드를 만들고 min에 addback
	ft_lst_back(&fre ,ft_lst('\0', f->data, f));// 문자정보, 빈도수, 노드주소,
	
	//근데지금 문제가 .. 합친것들은 리스트에서 제거를 해줘야댐
	//addback result -> 
	printf(GREEN_COLOR);
	printf("\naddback result \n");
	printf(END_COLOR);
	ft_fre_sort(fre);
	// 만약 f의 데이터값이(빈도수가) 보다 작은게 두개있으면 그두개를 부모노드로 묶어줌
	// 두개의 부모노드가

	t = creat_tree(t, fre);//최소두개 떼버린 리스트랑 그거 합친새노드f

	// // printf("top data t : %d\n", t->data);
	// printf("\n");
	printf("\033[0;32m이진트리 정상작동 확인(전위순회): 루왼오\033[0m\n");
	pre_tree(t);
	printf("\n");
	printf("\n");
	
	printf("중위순회: 왼루오\n");	
	mid_tree(t);
	printf("\n");
	printf("\n");

	printf("후위순회: 왼오루\n");
	post_tree(t);
	printf("\n");
	printf("\n");

	// // printf("\033[0;32m접두어코드\033[0m\n");
	// // search_tree(t, 1);
	// // search_tree(t, 2);
	// // search_tree(t, 3);
	// // search_tree(t, 4);

	t_list *temp = ft_lst('\0', -1, 0);
	printf("\033[0;32m인코드\033[0m\n");// 논리구조 바꿔야댐 트리구조가 바꼈으니까.
	int j = -1;
	while (str[++j])
		encode(t, temp, str[j], fre_check(str[j], fre));//빈도수뱉게
	printf("\n");
	printf("\n");
	return (t);
	// //부모트리를 만들어서 붙힘. 오른쪽 왼쪽순.
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
	ft_fre_sort(fre);// 검증완료
	//난 문자별로 빈도수가 적힌 리스트가 있고(fre), 원래 문자열을 알고있어(av)
	//허프만에서는 쟤네를 이진트리로 집어넣어야해, 빈도수가 낮은게 1오른쪽자식 높은게 0왼쪽자식이야.
	ft_huffman(fre, av[1]);
	// frequency_viewer(fre);
	
	//printf("top value: %d", t->data);
	// run_tree(&t);
	// printf("전위순회\n");
	// pre_tree(t);
	// printf("\n");
	exit(0);


	return (ft_exit(0));
}
// printf("중위순회\n");	
// mid_tree(t);
// printf("\n");

// printf("후위순회\n");
// post_tree(t);
// printf("\n");
