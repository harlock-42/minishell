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

	(void)cmd;
	path = our_getenv("PWD");
	ft_printf("%s\n", path);
	g_glob.ret = 0;
	return (1);
}
