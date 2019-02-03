/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cmdline.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abiri <kerneloverseer@protonmail>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/17 20:04:33 by abiri             #+#    #+#             */
/*   Updated: 2019/02/03 11:32:10 by ebatchas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char		*ft_envpath(char **env)
{
	size_t	i;
	char	**splited;
	char	*path;

	i = 0;
	path = NULL;
	while (env[i])
	{
		splited = ft_strsplit(env[i], '=');
		if (ft_strequ(splited[0], "PATH"))
			path = ft_strdup(splited[1]);
		ft_tabfree(splited);
		i++;
	}
	if (path)
		return (path);
	ft_putstr_fd("PATH variable not found\n", 2);
	return (NULL);
}

char		**ft_getargs(char *cmd)
{
	char	**result;
	int		i;
	int		inquote;
	char	lastquote;

	i = -1;
	inquote = 0;
	lastquote = 0;
	cmd = ft_strdup(cmd);
	while (cmd[++i])
	{
		if (!inquote && ft_ischarin(WHITESPACES, cmd[i]) && (cmd[i] = -1))
			continue ;
		if (!inquote && (cmd[i] == 39 || cmd[i] == '"'))
			lastquote = cmd[i];
		else if (inquote && cmd[i] == lastquote)
			lastquote = 0;
		else
			continue ;
		cmd[i] = -2;
		inquote = (inquote) ? 0 : 1;
	}
	result = ft_strsplit(ft_removechars(&cmd, -2), -1);
	free(cmd);
	return (result);
}

void		ft_printpathstatus(int status, char *execname)
{
	if (status == 0)
	{
		ft_putstr_fd("pipex: command ", 2);
		ft_putstr_fd(execname, 2);
		ft_putstr_fd(" not found\n", 2);
	}
	if (status == -1)
	{
		ft_putstr_fd("pipex: ", 2);
		ft_putstr_fd(execname, 2);
		ft_putstr_fd(" permission denied\n", 2);
	}
}

int			ft_execright(char *path)
{
	if (access(path, F_OK))
		return (0);
	if (access(path, X_OK))
		return (-1);
	return (1);
}

char		*ft_getpath(char *envpath, char *execname)
{
	char	**available;
	char	*possible;
	int		i;
	int		status;

	i = -1;
	available = ft_strsplit(envpath, ':');
	while (available[++i])
	{
		possible = ft_strcjoin(available[i], '/', execname);
		if ((status = ft_execright(possible)) == 1)
		{
			ft_tabfree(available);
			return (possible);
		}
		else if (status == -1)
			break ;
		free(possible);
	}
	ft_printpathstatus(status, execname);
	ft_tabfree(available);
	return (NULL);
}
