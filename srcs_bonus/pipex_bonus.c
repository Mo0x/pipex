/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgovinda <mgovinda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 16:42:24 by mgovinda          #+#    #+#             */
/*   Updated: 2023/11/30 17:43:57 by mgovinda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	ft_piping(int f1, int *super_pipe, char *cmd, char **envp)
{
	char	**paths;
	char	**s_cmd;
	char	*ex;

	s_cmd = ft_split(cmd, ' ');
	paths = path_finder(envp);
	ex = command_finder(paths, s_cmd[0]);
	if (!ex)
		ft_error_path(s_cmd[0]);
	dup2(f1, 0);
	dup2(super_pipe[1], 1);
	close(super_pipe[0]);
	execve(ex, &s_cmd[1], envp);
	ft_free_array((void **)paths);
	ft_free_array((void **)s_cmd);
	free(ex);
	return (0);
}

int	process_two(int f2, int *super_pipe, char *cmd, char **envp)
{
	char	**paths;
	char	**s_cmd;
	char	*ex;

	s_cmd = ft_split(cmd, ' ');
	paths = path_finder(envp);
	ex = command_finder(paths, s_cmd[0]);
	if (!ex)
		ft_error_path(s_cmd[0]);
	dup2(f2, 1);
	dup2(super_pipe[0], 0);
	close(super_pipe[1]);
	execve(ex, &s_cmd[1], envp);
	ft_free_array((void **)paths);
	ft_free_array((void **)s_cmd);
	free(ex);
	return (0);
}

void	pipex(int f1, int f2, char **argv, char **envp, int ac)
{
	int	i;

	i = 0;
	dup2(f1, 0);
	while (i < ac - 2)
		ft_piping(av[i++], env)
}