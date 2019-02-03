/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abiri <kerneloverseer@protonmail>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/02 20:58:26 by abiri             #+#    #+#             */
/*   Updated: 2019/02/03 11:30:24 by ebatchas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_cmd1(char *cmd1, int *pipefd, int filefd, char **env)
{
	int		pid;
	char	**argum;

	if ((pid = fork()) == 0)
	{
		close(pipefd[R]);
		dup2(pipefd[W], 1);
		dup2(filefd, 0);
		argum = ft_getargs(cmd1);
		ft_execvp(argum, env);
		exit(1);
	}
	else
		close(pipefd[W]);
	wait(NULL);
	close(filefd);
}

void	ft_cmd2(char *cmd1, int *pipefd, int *pipefd2, char **env)
{
	int		pid;
	char	**argum;

	if ((pid = fork()) == 0)
	{
		close(pipefd[W]);
		close(pipefd2[R]);
		dup2(pipefd[R], 0);
		dup2(pipefd2[W], 1);
		argum = ft_getargs(cmd1);
		ft_execvp(argum, env);
		exit(1);
	}
	else
	{
		close(pipefd[R]);
		close(pipefd2[W]);
	}
	wait(NULL);
}

int		ft_file1(char *filename)
{
	int fd;

	fd = open(filename, O_RDONLY);
	if (fd < 0)
		ft_error("pipex: file1 does not exist\n");
	return (fd);
}

int		ft_file2(char *filename)
{
	int fd;

	fd = open(filename, O_CREAT | O_WRONLY,
			S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH);
	if (fd < 0)
		ft_printpathstatus(ft_execright(filename), filename);
	return (fd);
}

int		main(int argc, char **argv, char **env)
{
	int pipe1[2];
	int pipe2[2];

	if (argc != 5)
		return (1);
	pipe(pipe1);
	pipe(pipe2);
	ft_cmd1(argv[2], pipe1, ft_file1(argv[1]), env);
	ft_cmd2(argv[3], pipe1, pipe2, env);
	ft_transfer(pipe2[R], ft_file2(argv[4]));
	return (0);
}
