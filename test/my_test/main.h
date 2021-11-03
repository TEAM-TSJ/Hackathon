
#ifndef MAIN_H
# define MAIN_H

# include <stdio.h>
# include <unistd.h>
# include <limits.h>
# include <stdlib.h>
# include <string.h>

# define GREEN_COLOR "\033[0;32m"
# define  END_COLOR "\033[0m"

//아스키넘버 정의(확장까지로 일단은)
# define NUM_ASCII 256

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

short stack[100];
int pos;
int find;

/*
** 이렇게 내맘대로 구조체로 찍어내는게 아니고 이진트리부터 정확하게 구현할줄 알아야겠다.
** 이진트리 : 모든 노드가 2개의 서브트리를 가지고 있는 트리이다.
*/
typedef struct s_node
{
	int		data;
	char	value;
	int		is_visit;
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
	char			data;//문자정보;
	t_node			*addr;//생성된노드의 주소;
	int				count;//노드의 빈도수 -> 부모노드일경우 자식들의 빈도수의 합이 될것임.
	//여기다가 이진트리 내용을 추가할까.
	char			*prefix;

	struct	s_list	*next;//빈도수가 더 높은게 뒤로 위치하게 될것임
	struct	s_list	*prev;//음... 푸시스왑때 쓰던거고, 지금은 안쓰고 있어서 빼도 되긴함 일단 킵.
}				t_list;

/*gnl.c*/
void	make_read_buffer_free(char *read_buffer);
int	get_next_line(int fd, char **line);


/*main.c*/
void 	frequency_viewer(t_list *frequency);
void	ft_lst_back(t_list **list, t_list *new);
t_list	*ft_lst(char value, int count, t_node *addr);
void	pre_tree(t_node *t);
t_list *ft_fre_sort(t_list *fre);
void creat_file(char **sym_code, char *ptr, int total);

/*
** viewer.c
*/

void codetable_view(char **str);

/*
** libft.c
*/
size_t	ft_strlen(const char *s);
size_t	ft_strlcat(char *dst, const char *src, size_t dstsize);
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);
char	*ft_strjoin(char const *str1, char const *str2);
char	*ft_strdup(const char *s1);
void		*ft_memcpy(void *dst, const void *src, size_t n);
char						*ft_itoa(int n);

#endif
