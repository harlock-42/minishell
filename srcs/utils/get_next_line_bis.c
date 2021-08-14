/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tallaire <tallaire@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/05 19:50:38 by tallaire          #+#    #+#             */
/*   Updated: 2021/05/31 15:45:28 by tallaire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	recursive(char **line, size_t index, int fd)
{
	char	buf;
	int		ret;

	ret = read(fd, &buf, 1);
	if (ret == 1 && buf != '\n')
	{
		ret = recursive(line, index + 1, fd);
		if (ret != -1)
			(*line)[index] = buf;
	}
	else if (ret != -1)
	{
		*line = (char *)malloc(sizeof(char) * (index + 1));
		if (*line != NULL)
			(*line)[index] = '\0';
		else
			ret = -1;
	}
	return (ret);
}

int	get_next_line_bis(int fd, char **line)
{
	int ret;
	t_list *lex;
	t_cli *cli;

	lex = lst_new();
	cli = NULL;
	ft_printf("> ");
	ret = recursive(line, 0, fd);
	if (ret == 0)
		*line = NULL;
	if (g_glob.ret == 130)
		minishell(*line, lex, cli);
	return (ret);
}
