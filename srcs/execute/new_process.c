/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_process.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/31 17:48:40 by user42            #+#    #+#             */
/*   Updated: 2021/07/03 17:30:05 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_command_not_found(char **av, char **paths, char **env)
{
	ft_putstr_fd("Minishell: command not found: ", 2);
	ft_putstr_fd(av[0], 2);
	ft_putstr_fd("\n", 2);
	ft_freetab(paths);
	ft_freetab(env);
	ft_freetab(av);
	exit(127);
}

char	**ft_cmd_to_tab(t_list *cmd, int depth)
{
	char	**av;

	av = NULL;
	if (cmd && cmd->next != NULL)
	{
		av = ft_cmd_to_tab(cmd->next, depth + 1);
		av[depth] = ft_strdup(cmd->token);
	}
	else if (cmd)
	{
		av = malloc(sizeof(char *) * (depth + 2));
		av[depth] = ft_strdup(cmd->token);
		av[depth + 1] = NULL;
		return (av);
	}
	return (av);
}

void	ft_execute_loc(char **av, char **env, char **paths)
{
	struct stat	buf;

	stat(av[0], &buf);
	if (S_ISDIR(buf.st_mode))
	{
		errno = EISDIR;
		ft_exec_failed(env, paths, ft_double_strjoin
			("Minishell: ", av[0], " : "), av);
	}
	if (paths != NULL && av[0][0] && av[0][1] == '/')
	{
		execve(av[0], av, env);
		ft_exec_failed(env, paths, ft_double_strjoin
			("Minishell: ", av[0], " : "), av);
	}
	else
		ft_command_not_found(av, paths, env);
}

void	ft_execute(char **av, char **env, char **paths)
{
	struct stat	buf;
	char		*str;
	int			i;

	i = -1;
	if (ft_strcmp("..", av[0]) == 0 || ft_strcmp(".", av[0]) == 0
		|| av[0][0] == 0)
		ft_command_not_found(av, paths, env);
	if (stat(av[0], &buf) == -1
		|| (S_ISDIR(buf.st_mode) == 0 && !(buf.st_mode & S_IXUSR)))
	{
		while (paths != NULL && paths[++i] != NULL)
		{
			str = ft_strjoin(paths[i], av[0]);
			if (execve(str, av, env) == -1 && errno == 2)
				free(str);
			else
				ft_exec_failed(env, paths, ft_double_strjoin
					("Minishell: ", paths[i], ft_strjoin(av[0], ": ")), av);
		}
		ft_command_not_found(av, paths, env);
	}
	else
		ft_execute_loc(av, env, paths);
}

int	ft_execute_prog(t_cli *cli)
{
	char	**av;
	t_list	*path;

	if (cli->cmd == NULL)
		return (0);
	av = ft_cmd_to_tab(cli->cmd, 0);
	path = ft_find_path(g_glob.env);
	if (path == NULL)
		ft_execute(av, ft_env_to_tab(g_glob.env, 0), NULL);
	else
		ft_execute(av, ft_env_to_tab(g_glob.env, 0), ft_split_slash
			(path->value, ":"));
	return (0);
}
