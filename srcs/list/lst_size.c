#include "minishell.h"

size_t	lst_size(t_list *list)
{
	size_t	size;
	t_list	*tmp;

	size = 0;
	tmp = list;
	while (list)
	{
		size++;
		list = list->next;
	}
	list = tmp;
	return (size);
}
