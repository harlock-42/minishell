#include "../../include/minishell.h"

t_cli	*parser(t_list *lex)
{
	t_cli	*cli;

	cli = NULL;
	cli = get_cli(lex);
	if (cli)
		cli = get_redirect(cli);
	if (cli)
		rm_red_from_cmd(cli);
	if (cli)
		cli = remove_bs_red(cli);
	if (cli)
		cli = dev_quote(cli);
	if (cli)
		cli = rm_sep_token(cli);
	if (cli)
		cli = kind_cli(cli);
	return (cli);
}
