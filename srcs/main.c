/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgovinda <mgovinda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 17:12:58 by mgovinda          #+#    #+#             */
/*   Updated: 2023/11/16 16:37:22 by mgovinda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

/*
open file1 (create rdonly)
open file1(create, write)
fil1 cmd 1 | cmd2 >> file 2
*/

int	main(int argc, char **argv, char **envp)
{
	int	f1;
	int	f2;

	(void) argc;
	f1 = open(argv[1], O_RDONLY);
	f2 = open(argv[4], O_CREAT | O_RDWR | O_TRUNC, 0644);
	if (f1 < 0 || f2 < 0)
	// put erorr msg here
		return(-1);
	ft_printf(1, "%s", envp);
	//pipex(f1, f2, argv, envp);
	return (0);
}
