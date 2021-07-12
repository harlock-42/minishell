#include "minishell.h"

t_cli	*free_cli(t_cli *cli)
{
	t_cli	*tmp;

	tmp = cli;
	while (cli)
	{
		tmp = cli;
		cli->cmd = lst_free(cli->cmd);
		cli->red = lst_free(cli->red);
		cli = cli->next;
		free(tmp);
	}
	return (NULL);
}
