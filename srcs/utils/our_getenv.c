#include "minishell.h"

/*
** return the value of a variable from our env.
** If the variable does not exist, the fuction return NULL.
*/

char	*our_getenv(char *name)
{
	char	*value;
	t_list	*tmp;

	value = NULL;
	tmp = g_glob.env;
	while (g_glob.env)
	{
		if (ft_strcmp(name, g_glob.env->name) == YES)
		{
			value = g_glob.env->value;
			g_glob.env = tmp;
			return (value);
		}
		g_glob.env = g_glob.env->next;
	}
	g_glob.env = tmp;
	return (value);
}
