#include "../include/minishell.h"

void	minishell(char *read, t_list *lex, t_cli *cli)
{
	while (1)
	{
		if (read == NULL)
			read = readline_color("Echecs $ ", PROMPT_COLOR, NC);
		if (read == NULL)
			ft_exit(NULL);
		if (read)
			lex = lexer(read, lex);
		add_history(read);
		free(read);
		if (lex)
			cli = parser(lex);
		g_glob.aff_prompt = NO;
		g_glob.sig_quit = 1;
//		lst_print_cli(cli);
		if (cli)
			ft_master(cli);
		g_glob.sig_quit = 0;
		g_glob.aff_prompt = YES;
		cli = free_cli(cli);
		lex = lst_free(lex);
		read = NULL;
	}
}

int	main(void)
{
	t_list	*lex;
	t_cli	*cli;
	char	*read;
	int		ret;

	ret = 0;
	lex = lst_new();
	signal(SIGINT, do_sigint);
	signal(SIGQUIT, do_sigquit);
	ft_bzero(&g_glob, sizeof(t_glob));
	cli = NULL;
	read = NULL;
	g_glob.env = get_env(g_glob.env, &ret);
	if (g_glob.env == NULL && ret == (-1))
		return (0);
	minishell(read, lex, cli);
	return (0);
}
