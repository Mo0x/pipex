/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgovinda <mgovinda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 17:12:58 by mgovinda          #+#    #+#             */
/*   Updated: 2023/11/10 18:18:47 by mgovinda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

#include <sys/types.h>

int	main(int argc, char **argv)
{
	pid_t pid;

	(void)argc;
	(void)argv;
	pid = fork();
	if (pid == 0)
	{
		ft_printf(1, "kiddo%d\n", (int)getpid());
	}
	else if (pid < 0)
		return (-1);
	else
		ft_printf(1, "daddy%d\n", (int)getpid());
	/*if (argc < 2)
	{
		ft_argc_error(argv[0]);
		return (-1);
	}*/
	
	return (0);
}