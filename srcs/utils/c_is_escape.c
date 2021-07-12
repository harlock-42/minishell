#include "minishell.h"

int	c_is_escape(int i, char *str)
{
	int	count;

	count = 0;
	if (i == 0)
		return (NO);
	--i;
	while (i >= 0 && str[i] == '\\')
	{
		++count;
		--i;
	}
	if (count % 2)
		return (YES);
	return (NO);
}
