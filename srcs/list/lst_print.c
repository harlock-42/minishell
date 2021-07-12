#include "minishell.h"

void	lst_print(t_list *list)
{
	int	i;

	i = 0;
	while (list)
	{
		printf("%s%d |%s%s\n", CYAN, list->kind, list->token, NC);
		++i;
		list = list->next;
	}
	printf("%s      NULL%s\n", YELLOW, NC);
}
