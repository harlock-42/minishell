#include "minishell.h"

t_list	*init_kind(t_list *env)
{
	t_list	*tmp;

	tmp = env;
	while (env)
	{
		env->kind = 0;
		env = env->next;
	}
	env = tmp;
	return (env);
}

t_list	*env_failed(int **ret, t_list *env, char *name, char *value)
{
	**ret = (-1);
	if (name)
		free(name);
	if (value)
		free(value);
	if (env)
		env = lst_free(env);
	return (NULL);
}
