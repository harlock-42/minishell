#include "minishell.h"

void	do_sigquit(int signum)
{
	ft_printf("Quit (core dumped)\n");
	signal(SIGQUIT, SIG_DFL);
	(void)signum;
}

void	do_sigign(int signum)
{
	ft_putstr_fd("\b\b  \b\b", 0);
	(void)signum;
}
