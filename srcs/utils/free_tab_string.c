#include "minishell.h"

void	*free_tab_string(char **str)
{
	int	i;

	i = 0;
	if (str == NULL)
		return (NULL);
	while (str[i])
	{
		free(str[i]);
		str[i] = NULL;
		++i;
	}
	free(str);
	str = NULL;
	return (NULL);
}
