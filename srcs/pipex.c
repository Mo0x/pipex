/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgovinda <mgovinda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 16:42:24 by mgovinda          #+#    #+#             */
/*   Updated: 2023/11/29 14:56:03 by mgovinda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

int process_one(int f1, char *cmd)
{
	//haha	
}

void 	exec(int file, char *cmd, char **envp)
{
	//char	**	
}

void	pipex(int f1, int f2, char **argv, char **envp)
{
	int		super_pipe[2];
	int		status;
	pid_t	child_1;
	pid_t	child_2;

	(void)envp;
	pipe(super_pipe);
	child_1 = fork();
	if (child_1 < 0)
		return (perror("Fork: "));
	if (child_1 == 0)
		process_one(f1, argv[2]);
	child_2 = fork();
	if (child_2 < 0)
		return (perror("Fork: "));
	if (child_2 == 0)
		process_two(f2, argv[3]);
	close(super_pipe[0]);
	close(super_pipe[1]);
	waitpid(child_1, &status, 0);
	waitpid(child_2, &status, 0);
}