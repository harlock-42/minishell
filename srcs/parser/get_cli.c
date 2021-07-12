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
