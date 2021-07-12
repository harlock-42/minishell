#include "minishell.h"

int	empty_home_value(char *home_path)
{
	if (home_path)
		free(home_path);
	g_glob.ret = 0;
	return (1);
}
