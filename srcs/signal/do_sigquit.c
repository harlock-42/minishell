#include "minishell.h"

void	do_sigquit(int signum)
{
	ft_printf("Quit (core dumped)\n");
	signal(SIGQUIT, SIG_DFL);
	(void)signum;
}
