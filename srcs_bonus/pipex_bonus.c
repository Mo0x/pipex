/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgovinda <mgovinda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 16:42:24 by mgovinda          #+#    #+#             */
/*   Updated: 2023/12/11 14:53:34 by mgovinda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

int	ft_exec(char *cmd, char **envp)
{
	char	**paths;
	char	**s_cmd;
	char	*ex;
	int		check;

	s_cmd = ft_split(cmd, ' ');
	if (!s_cmd)
		return (-1);
	paths = path_finder(envp);
	ex = command_finder(paths, s_cmd[0]);
	if (!ex)
		ft_error_path(s_cmd[0]);
	check = execve(ex, &s_cmd[1], envp);
	if (check < 0)
		ft_eq("Error executing command, think about the shebang !");
	ft_free_array((void **)paths);
	ft_free_array((void **)s_cmd);
	free(ex);
	return (0);
}

int	ft_piping(char *cmd, char **envp)
{
	int		super_pipe[2];
	pid_t	pid;

	if (pipe(super_pipe) == -1)
		ft_eq("Pipe creation error:");
	pid = fork();
	if (pid == -1)
		ft_eq("Fork error:");
	if (!pid)
	{
		close(super_pipe[0]);
		dup2(super_pipe[1], 1);
		ft_exec(cmd, envp);
	}
	else
	{
		close(super_pipe[1]);
		dup2(super_pipe[0], 0);
	}
	return (0);
}
