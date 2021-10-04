#include "minishell.h"

static	t_list	*dup_lst_add_back(t_list *lex, t_list *new)
{
	char	*token;

	token = ft_strdup(lex->token);
	if (token == NULL)
		return (NULL);
	new = lst_add_back(token, lex->kind, new);
	if (new == NULL)
		return (NULL);
	return (new);
}

t_list	*add_sep_tok(t_list *new)
{
	char	*token;

	token = ft_strdup("");
	if (token == NULL)
		return (NULL);
	new = lst_add_back(token, WD_SEP_TOK, new);
	if (new == NULL)
		return (NULL);
	return (new);
}

t_list	*add_sep_tok_for_red(t_list *lex)
{
	t_list	*tmp;
	t_list	*new;

	tmp = lex;
	new = NULL;
	while (lex)
	{
		new = dup_lst_add_back(lex, new);
		if (lex->next && lex->kind == WD_RED && lex->next->kind != WD_SEP_TOK)
		{
			new = add_sep_tok(new);
			if (new == NULL)
				return (lst_free(new));
		}
		if (new == NULL)
			return (lst_free(new));
		lex = lex->next;
	}
	lex = tmp;
	lst_free(lex);
	return (new);
}