#include "minishell.h"

t_list	*lst_rm_front(t_list *list)
{
	t_list	*tmp;

	if (list == NULL)
		return (NULL);
	tmp = list->next;
	if (list->token)
		free(list->token);
	free(list);
	return (tmp);
}
