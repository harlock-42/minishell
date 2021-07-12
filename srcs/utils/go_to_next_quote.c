#include "minishell.h"

int	go_to_next_quote(char *str, int i, char quote)
{
	++i;
	while (str[i] && (str[i] != quote || c_is_escape(i, str) == YES))
		++i;
	return (i);
}
