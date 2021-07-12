#include "minishell.h"

static	int	is_only_digit(char *str)
{
	int	i;

	i = 0;
	if (str[i] == '-')
		++i;
	if (str[i] == '\0')
		return (NO);
	while (str && str[i])
	{
		if (ft_isdigit(str[i]) == 0)
			return (NO);
		++i;
	}
	return (YES);
}

static	int	is_overflow(char *str)
{
	size_t	size;
	int		i;

	i = 0;
	size = ft_strlen(str);
	if (size < 19)
		return (NO);
	else if (size > 19)
		return (YES);
	if (ft_strcmp(str, "9223372036854775807") >= 0)
		return (YES);
	return (NO);
}

static	int	is_underflow(char *str)
{
	size_t	size;
	int		i;

	i = 0;
	size = ft_strlen(str);
	if (size < 20)
		return (NO);
	else if (size > 20)
		return (YES);
	if (ft_strcmp(str, "-9223372036854775807") >= 0)
		return (YES);
	return (NO);
}

int	is_arg_exit_valid(char *str)
{
	if (is_only_digit(str) == NO)
		return (NO);
	if (*str == '-')
	{
		if (is_underflow(str) == YES)
		{
			g_glob.ret = 2;
			ft_printf("exit\nbash: exit: %s : ", str);
			ft_printf("numeric argument required\n");
			return (NO);
		}
	}
	else
	{
		if (is_overflow(str) == YES)
		{
			g_glob.ret = 2;
			ft_printf("exit\nbash: exit: %s : ", str);
			ft_printf("numeric argument required\n");
			return (NO);
		}
	}
	return (YES);
}
