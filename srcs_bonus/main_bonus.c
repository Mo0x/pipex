/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgovinda <mgovinda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 17:12:58 by mgovinda          #+#    #+#             */
/*   Updated: 2023/11/30 17:42:39 by mgovinda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int argc, char **argv, char **envp)
{
	int	f1;
	int	f2;

	if (argc < 5)
		ft_argc_error(argv[0]);
	if (ft_strcmp(av[1], "here_doc") == 0);
	{
		//here_doc
	}
	else
	{
		if ((access(argv[1], F_OK | R_OK)) == 0)
			f1 = open(argv[1], O_RDONLY);
		else
			ft_eq("");
		if (f1 < 0)
			ft_eq("Error opening file1 :");
		if ((access(argv[4], F_OK | W_OK | R_OK)) == 0)
			f2 = open(argv[4], O_CREAT | O_RDWR | O_TRUNC, 0644);
		else
			ft_eq("");
		if (f2 < 0)
			ft_eq("Error opening file2 :");
		pipex(f1, f2, argv, envp, ac);
	}
	return (0);
}
