#include "main.h"

t_list	*ft_lst(char value, int count)
{
	t_list	*new_node;

	new_node = malloc(sizeof(t_list));
	if (!new_node)
		return (0);
	new_node->data = value;
	new_node->count = count;
	new_node->next = 0;
	new_node->prev = 0;
	return (new_node);
}

void	ft_lst_back(t_list **list, t_list *new)
{
	t_list	*last;

	if (!list || !new)
		return ;
	last = *list;
	if (last)
	{
		while (last->next)
			last = last->next;
		last->next = new;
		new->prev = last;
		new->next = 0;
	}
	else
		*list = new;
}
