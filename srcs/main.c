/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgovinda <mgovinda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 17:12:58 by mgovinda          #+#    #+#             */
/*   Updated: 2023/11/10 19:33:45 by mgovinda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"


int	main(int argc, char **argv)
{
	pid_t pid;
	pid_t wpid;
	int status;
	(void)argc;
	(void)argv;
	pid = fork();
	if (pid == 0)
	{
		ft_printf(1, "kiddo%d\n", (int)getpid());
		return(0);
	}
	else if (pid < 0)
	{
		//perror(fork);
		status = -1;
		return (status);
	}
	else
	{
		wpid = waitpid(pid, &status, WUNTRACED);
		if (wpid == -1)
		{
			perror("waitpid");
			exit(EXIT_FAILURE);
		}
		if (WIFEXITED(status))
			ft_printf(1, "ended, code =%d\n", WEXITSTATUS(status));
		ft_printf(1, "daddy%d\n", (int)getpid());
	}
	/*if (argc < 2)
	{
		ft_argc_error(argv[0]);
		return (-1);
	}*/
	
	return (status);
}