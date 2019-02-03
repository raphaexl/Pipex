/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tools.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abiri <kerneloverseer@protonmail>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/03 01:31:25 by abiri             #+#    #+#             */
/*   Updated: 2019/02/03 11:29:38 by ebatchas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_error(char *str)
{
	ft_putstr_fd(str, 2);
	exit(1);
}

void	ft_execvp(char **args, char **env)
{
	char *path;

	if (!(path = ft_getpath(ft_envpath(env), args[0])))
		return ;
	execve(path, args, env);
}

void	ft_transfer(int fd1, int fd2)
{
	char buffer[10];
	char len;

	len = 0;
	while ((len = read(fd1, buffer, 10)) > 0)
		write(fd2, buffer, len);
	close(fd1);
	close(fd2);
}
