#include "minishell.h"

static	int	reset_shlvl(int value)
{
	ft_putstr_fd("minishell: warning: shell level too high (", 2);
	ft_putnbr_fd(value  + 1, 2);
	ft_putstr_fd("), initializer to 1\n", 2);
	//set SHLVL to 1
	return (0);
}

static	int	no_shlvl_var(void)
{
	g_glob.env = env_add_back("SHLVL", "1", 0, g_glob.env);
	if (g_glob.env == NULL)
		return (-1);
	return (0);
}

int	set_shlvl(void)
{
	char	*value;
	int		val;

	value = our_getenv("SHLVL");
	if (value == NULL)
		return (no_shlvl_var());
	val = ft_atoi(value);
	if (val >= 999)
		return (reset_shlvl(val));
	return (0);
}