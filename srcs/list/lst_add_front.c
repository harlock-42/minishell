#include "minishell.h"

t_list	*lst_add_front(char *token, int kind, t_list *list)
{
	t_list	*new;

	new = (t_list *)malloc(sizeof(t_list));
	if (!new)
		return (NULL);
	new->token = token;
	new->kind = kind;
	new->next = list;
	return (new);
}
