#include "minishell.h"

static	int	is_arg_name_valid(char *str)
{
	int	i;

	i = 0;
	if (str[0] == '\0' || (str[0] >= '0' && str[0] <= '9'))
	{
		ft_printf("minishell: export: %s : ", str);
		ft_printf("invalid option\n");
		return (NO);
	}
	while (str && str[i])
	{
		if (c_is_alnum(str[i]) == NO && str[i] != '_')
		{
			ft_printf("minishell: export: %s : ", str);
			ft_printf("invalid option\n");
			return (NO);
		}
		++i;
	}
	return (YES);
}

int	check_name_and_value(char *name, char *value)
{
	(void)value;
	if (is_arg_name_valid(name) == NO)
	{
		g_glob.ret = 1;
		free(name);
		return (NO);
	}
	return (YES);
}