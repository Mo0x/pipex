/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgovinda <mgovinda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 17:10:09 by mgovinda          #+#    #+#             */
/*   Updated: 2023/11/30 17:19:15t  by mgovinda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_argc_error(char *name)
{
	ft_printf(2, "Error %s: %s requieres 4 arguments to work.\n", name, name);
	ft_printf(2, "Like the following : %s File1 Cmd1 Cmd2 File2\n", name);
	exit(EXIT_FAILURE);
}

void	ft_eq(char *msg)
{
	perror(msg);
	exit(EXIT_FAILURE);
}

void	ft_error_path(char *cmd)
{
	ft_printf(2, "Error %s commmand couldn't be found check ", cmd);
	ft_printf(2, "spelling and retry !\n");
}
