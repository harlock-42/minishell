#include "minishell.h"

void	do_sigint(int signum)
{
	(void)signum;
	if (g_glob.aff_prompt == YES)
		ft_printf("\n%s%s%s ", PROMPT_COLOR, PROMPT, NC);
	else
		ft_printf("\n");
	g_glob.ret = 130;
	rl_replace_line("", 0);
}
