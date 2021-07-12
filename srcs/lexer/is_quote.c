#include "../../include/minishell.h"

static	int	find_foot(int i, char *str, char *quote)
{
	while (str[i] && ((c_is_str(str[i], "\'\"") == NO)))
		++i;
	*quote = str[i];
	return (i);
}

static	int	find_top(int foot, char *str, char quote)
{
	int	i;

	i = foot;
	if (quote == '\0')
		return (foot);
	else
		++i;
	while (str[i] && ((str[i] != quote)))
		++i;
	return (i);
}

int	is_quote(int y, char *str)
{
	int	top;
	int	foot;
	int	i;
	char		quote;

	top = 0;
	foot = 0;
	i = 0;
	while (str && str[i])
	{
		foot = find_foot(i, str, &quote);
		top = find_top(foot, str, quote);
		i = top;
		if (y >= foot && y <= top)
			return (YES);
		if (str[i])
			++i;
	}
	return (NO);
}
