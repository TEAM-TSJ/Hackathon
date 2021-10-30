
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

/*
** 빈도수 정렬
** 아 여기는 갯수만 저장하는거야. 그리고 모든 갯수에 대해서 정렬을 때리는거지.
** 그다음 이진트리에 집어넣을때도 결국 데이터가 있자네 그데이터에다가는.. 음.. 아닌데
** 0인지 1인지를 기록해야 나중에 탐색할때 읽는건데;; 접두어 코드를 이진트리로 생성해주는 과정인건데..
** 하 어케짜야하나 이거..
*/
typedef struct	s_list
{
	int				data;//문자가 저장되는게 맞나....
	struct	s_list	*next;
	struct	s_list	*prev;
}				t_list;

#endif
