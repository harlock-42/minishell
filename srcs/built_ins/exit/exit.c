/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/08 17:06:31 by user42            #+#    #+#             */
/*   Updated: 2021/06/11 19:26:53 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static	int	our_exit(int ret)
{
	t_list	*tmp;

	while (g_glob.env)
	{
		free(g_glob.env->name);
		free(g_glob.env->value);
		tmp = g_glob.env;
		g_glob.env = g_glob.env->next;
		free(tmp);
	}
	exit(ret);
	return (1);
}

static	int	set_ret_value(char *str)
{
	unsigned char	ret_char;
	long long		ret;

	ret = ft_atoll(str);
	ret_char = (unsigned char)ret;
	g_glob.ret = (int)ret_char;
	free(str);
	return ((int)ret_char);
}

int	valid_num_of_arg(char *str)
{
	if (is_arg_exit_valid(str) == NO)
		return (our_exit(255));
	if (g_glob.ispipe == 0)
		write(2, "exit\n", 5);
	our_exit(set_ret_value(str));
	return (1);
}

int	ft_exit(t_list *cmd)
{
	size_t	size;
	char	*str;

	size = lst_size(cmd);
	if (size > 1)
	{
		ft_printf("exit\nminishell: exit: too many arguments\n");
		g_glob.ret = 1;
		lst_free(cmd);
	}
	else if (size == 1)
	{
		str = ft_strdup(cmd->token);
		lst_free(cmd);
		valid_num_of_arg(str);
	}
	else
	{
		if (g_glob.ispipe == 0)
			write(2, "exit\n", 5);
		lst_free(cmd);
		our_exit(0);
		g_glob.ret = 0;
	}
	return (1);
}
