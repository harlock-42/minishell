/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_cli.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tallaire <tallaire@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/16 10:44:01 by tallaire          #+#    #+#             */
/*   Updated: 2021/09/16 10:44:02 by tallaire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
** split the command line in simple commands
** in function of the command separators (';' '|').
*/

t_cli	*get_cli(t_list *lex)
{
	t_cli	*cli;
	t_list	*cmd;
	t_list	*dup;

	cli = NULL;
	cmd = NULL;
	dup = NULL;
	cli = get_cli_continued(lex, cli, cmd, dup);
	return (cli);
}
