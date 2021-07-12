#include "minishell.h"

static	t_list	*first_link(char *token, int kind)
{
	t_list	*list;

	list = (t_list *)malloc(sizeof(t_list));
	if (!list)
		return (NULL);
	list->token = token;
	list->kind = kind;
	list->next = NULL;
	return (list);
}

t_list	*lst_add_back(char *token, int kind, t_list *list)
{
	t_list	*new;
	t_list	*tmp;

	tmp = list;
	if (list == NULL)
		return (first_link(token, kind));
	new = (t_list *)malloc(sizeof(t_list));
	if (!new)
	{
		if (token != NULL)
			free(token);
		return (NULL);
	}
	new->token = token;
	new->kind = kind;
	new->next = NULL;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = new;
	return (list);
}
