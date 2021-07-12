#include "minishell.h"

static	t_list	*free_list(t_list *list)
{
	if (list->token)
		free(list->token);
	free(list);
	return (NULL);
}

t_list	*lst_rm_back(t_list *list)
{
	t_list	*tmp;
	t_list	*first;

	if (list == NULL)
		return (NULL);
	if (list->next == NULL)
		return (free_list(list));
	first = list;
	while (list)
	{
		tmp = list;
		list = list->next;
		if (list->next == NULL)
		{
			tmp->next = NULL;
			free_list(list);
			return (first);
		}
	}
	return (first);
}
