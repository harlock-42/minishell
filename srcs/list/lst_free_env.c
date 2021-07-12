#include "minishell.h"

t_list	*lst_free_env(t_list *env)
{
	t_list	*tmp;

	tmp = env;
	while (env)
	{
		tmp = env;
		free(env->name);
		free(env->value);
		env = env->next;
		free(tmp);
	}
	return (NULL);
}
