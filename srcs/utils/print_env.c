#include "minishell.h"

void	print_env(void)
{
	t_list	*tmp;

	tmp = g_glob.env;
	while (g_glob.env)
	{
		ft_printf("%s=%s\n", g_glob.env->name, g_glob.env->value);
		g_glob.env = g_glob.env->next;
	}
	g_glob.env = tmp;
}
