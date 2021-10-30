
#ifndef MAIN_H
# define MAIN_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>

/*
** 이렇게 내맘대로 구조체로 찍어내는게 아니고 이진트리부터 정확하게 구현할줄 알아야겠다.
** 이진트리 : 모든 노드가 2개의 서브트리를 가지고 있는 트리이다.
*/
typedef struct s_node
{
	int		data;
	struct s_node *left;
	struct s_node *right;

}				t_node;

#endif
