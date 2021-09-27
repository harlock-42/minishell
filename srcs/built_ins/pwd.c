/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tallaire <tallaire@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/08 17:02:54 by user42            #+#    #+#             */
/*   Updated: 2021/09/16 10:40:28 by tallaire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_pwd(t_list *cmd)
{
	char	*path;
	size_t	size;

	size = lst_size(cmd);
	if (size > 0)
	{
		ft_printf("pwd: too many arguments\n");
		return (1);
	}
	path = getcwd(NULL, 0);
	if (path == NULL)
	{
		ft_perror("Echec: pwd:");
		return (1);
	}
	ft_printf("%s\n", path);
	free(path);
	g_glob.ret = 0;
	return (1);
}
