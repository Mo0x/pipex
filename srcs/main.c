/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgovinda <mgovinda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 17:12:58 by mgovinda          #+#    #+#             */
/*   Updated: 2023/11/15 17:46:50 by mgovinda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

/*
open file1 (create rdonly)
open file1(create, write)
fil1 cmd 1 | cmd2 >> file 2
*/

int	main(int argc, char **argv)
{
	int		dope_pipe[2];
	pid_t	pid;

	/*if (argc != 5)
	{
		ft_argc_error (argv[0]);
		return (EXIT_FAILURE);
	}*/
	if (pipe(dope_pipe))
	{
		ft_printf(2, "Pipe Failed.\n");
		return (EXIT_FAILURE);
	}
	pid = fork();
	if (pid == -1)
	{
		perror("fork");
		return (EXIT_FAILURE);
	}
	execve()
}
