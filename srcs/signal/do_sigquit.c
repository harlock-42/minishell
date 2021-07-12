#include "minishell.h"

void	do_sigquit(int signum)
{
	if (g_glob.sig_quit == 0)
	{
		signal(SIGQUIT, SIG_IGN);
	}
	else
	{
		ft_printf("Quit (core dumped)\n");
		signal(SIGQUIT, SIG_DFL);
	}
	(void)signum;
}
