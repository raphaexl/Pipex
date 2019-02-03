/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abiri <kerneloverseer@protonmail>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/02 21:49:23 by abiri             #+#    #+#             */
/*   Updated: 2019/02/03 01:36:57 by abiri            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H
# include "libft.h"
# define R 0
# define W 1

char		**ft_getargs(char *cmd);
char		*ft_getpath(char *envpath, char *execname);
int			ft_verifpath(char *execname, char **possible, char ***available,
		char *envpath);
char		*ft_envpath(char **env);
void		ft_error(char *str);
int			ft_execright(char *path);
void		ft_printpathstatus(int status, char *execname);
void		ft_execvp(char **args, char **env);
void		ft_transfer(int fd1, int fd2);
#endif
