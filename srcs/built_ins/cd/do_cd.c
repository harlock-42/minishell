#include "minishell.h"

static	char	*change_value(char *value, char *old)
{
	char	*new;

	new = ft_strdup(value);
	if (new == NULL)
		return (NULL);
	free(old);
	return (new);
}

static	int	modify_variable(char *name, char *value, int kind)
{
	t_list	*tmp;

	tmp = g_glob.env;
	while (g_glob.env)
	{
		if (ft_strcmp(name, g_glob.env->name) == YES)
		{
			g_glob.env->value = change_value
				(value, g_glob.env->value);
			if (g_glob.env->value == NULL)
				return (-1);
			g_glob.env->kind = kind;
			g_glob.env = tmp;
			return (0);
		}
		g_glob.env = g_glob.env->next;
	}
	g_glob.env = tmp;
	return (0);
}

static	int	handle_path_var(char *path)
{
	int		ret;
	char	*old_pwd;
	char	*to_dup;

	ret = 0;
	old_pwd = NULL;
	to_dup = our_getenv("PWD");
	if (to_dup != NULL)
		old_pwd = ft_strdup(to_dup);
	if (old_pwd == NULL)
		return (-1);
	path = getcwd(NULL, 0);
	if (path == NULL)
	{
		ft_perror("minishell: cd");
		return (-1);
	}
	ret = modify_variable("PWD", path, 0);
	ret = modify_variable("OLDPWD", old_pwd, 0);
	free(old_pwd);
	free(path);
	return (1);
}

int	do_cd(char *path)
{
	int	error;

	error = 0;
	if (chdir(path))
	{
		error = errno;
		if (error == ENOENT)
		{
			ft_printf("minishell: cd: No such file or folder\n");
			g_glob.ret = 1;
		}
		return (-1);
	}
	handle_path_var(path);
	g_glob.ret = 0;
	return (1);
}
