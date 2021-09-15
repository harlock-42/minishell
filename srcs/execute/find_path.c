#include "minishell.h"

t_list	*ft_find_path(t_list *cmd)
{
	t_list	*tmp;

	tmp = cmd;
	while (tmp != NULL && ft_strcmp(tmp->name, "PATH") != 0)
		tmp = tmp->next;
	return (tmp);
}

void	ft_exec_failed(char **env, char **paths, char *str, char **av)
{
	ft_freetab(paths);
	ft_freetab(env);
	ft_putstr_fd(str, 2);
	free(str);
	ft_exit_proc(av, 0);
}

void	ft_free_proc(t_cli *cli)
{
	t_list	*tmp;

	free_cli(cli);
	while (g_glob.env)
	{
		free(g_glob.env->name);
		free(g_glob.env->value);
		tmp = g_glob.env;
		g_glob.env = g_glob.env->next;
		free(tmp);
	}
}
