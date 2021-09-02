#include "minishell.h"

void	do_sigquit(int signum)
{
	ft_printf("Quit (core dumped)\n");
	signal(SIGQUIT, SIG_DFL);
	(void)signum;
}

void	do_sigign(int signum)
{
	//write(1, "\b\b\b", 3);
	ft_printf("mais putain quoi\n");
	//signal(SIGQUIT, SIG_IGN);
	(void)signum;
}
