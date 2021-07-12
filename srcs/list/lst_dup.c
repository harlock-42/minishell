#include "minishell.h"

t_list	*lst_dup(t_list *list)
{
	t_list	*new;
	t_list	*tmp;

	new = NULL;
	tmp = list;
	while (list)
	{
		new = lst_add_back(ft_strdup(list->token), list->kind, new);
		if (!new)
			return (NULL);
		list = list->next;
	}
	list = tmp;
	return (new);
}
