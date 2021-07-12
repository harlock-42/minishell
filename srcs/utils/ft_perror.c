#include "minishell.h"

void	ft_perror(const char *str)
{
	char	*err_msg;

	err_msg = strerror(errno);
	ft_printf("%s%s", str, err_msg);
}
