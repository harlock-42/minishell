#include "minishell.h"

/*
** For a simple chained list
** delete the next link of the list.
*/

t_list	*lst_rm_next(t_list *lst)
{
	t_list	*next;

	next = NULL;
	if (lst == NULL || lst->next == NULL)
		return (lst);
	next = lst->next->next;
	free(lst->next->token);
	free(lst->next);
	lst->next = next;
	return (lst);
}
