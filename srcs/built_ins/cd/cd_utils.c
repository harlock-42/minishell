#include "minishell.h"

int	is_path_valid(char *str)
{
	int	i;

	i = 0;
	while (str && str[i])
	{
		if (str[i] != '-')
			return (NO);
		++i;
	}
	if (i > 2)
		return (NO);
	return (YES);
}

int	print_err_cd(char *str, char *old_pwd)
{
	if (old_pwd)
		free(old_pwd);
	ft_printf("minishell: cd: %s not set\n", str);
	g_glob.ret = 1;
	return (1);
}
