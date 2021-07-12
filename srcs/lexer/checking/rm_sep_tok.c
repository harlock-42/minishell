#include "minishell.h"

t_list	*rm_sep_tok(t_list *lex)
{
	t_list	*tmp;
	t_list	*cmd;

	cmd = NULL;
	tmp = lex;
	while (lex)
	{
		if (lex->kind != WD_SEP_TOK)
		{
			cmd = lst_add_back(ft_strdup(lex->token),
					lex->kind, cmd);
			if (!cmd)
				return (NULL);
		}
		lex = lex->next;
	}
	lex = tmp;
	return (cmd);
}
