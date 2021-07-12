#include "minishell.h"

t_list	*lst_free(t_list *list)
{
	t_list	*tmp;

	while (list)
	{
		tmp = list;
		list = list->next;
		if (tmp->token)
			free(tmp->token);
		free(tmp);
	}
	return (NULL);
}
