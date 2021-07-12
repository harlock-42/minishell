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
	ft_exit_proc(av, 0);
}
