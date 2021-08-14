#include "minishell.h"

static	int	is_var(char *str)
{
	if (str[0] == '$')
		if (c_is_alnum(str[1]) == YES)
			return (YES);
	return (NO);
}

static	int	is_an_ambiguous_red(t_list *lex)
{
	t_list	*tmp;

	tmp = lex;
	while (lex)
	{
		if (lex->kind == WD_RED && lex->next != NULL)
		{
			if (is_var(lex->next->token) == YES)
			{
				lex = tmp;
				return (YES);
			}
		}
		lex = lex->next;
	}
	lex = tmp;
	return (NO);
}

int	check_ambiguous_red(t_list *lex)
{
	t_list	*cmd;

	cmd = lst_dup(lex);
	cmd = expand_if_we_need_to(cmd);
	if (is_an_ambiguous_red(cmd) == YES)
	{
		g_glob.ret = 1;
		return (make_a_cli(lex));
	}
	return (0);
}
