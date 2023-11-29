/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgovinda <mgovinda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 17:12:58 by mgovinda          #+#    #+#             */
/*   Updated: 2023/11/29 15:34:45 by mgovinda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

/*
open file1 (create rdonly)
open file1 (create, write)
fil1 cmd 1 | cmd2 >> file 2
*/

int	main(int argc, char **argv, char **envp)
{
	int	f1;
	int	f2;

	if (argc != 4)
		return (ft_argc_error(argv[0]));
	if (access(argv[1], F_OK | R_OK))
		f1 = open(argv[1], O_RDONLY);
	else
		perror();
	if (f1 < 0)
	{
		perror("Error opening file1 :");
		return (-1);
	}
	if (access(argv[4], F_OK | W_OK | R_OK))
		f2 = open(argv[4], O_CREAT | O_RDWR | O_TRUNC, 0644);
	else
		perror();
	if (f2 < 0)
	{
		perror("Error opening file2 :");
		return (-1);
	}
	pipex(f1, f2, argv, envp);
	return (0);
}
