/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_argc_error.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgovinda <mgovinda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 17:10:09 by mgovinda          #+#    #+#             */
/*   Updated: 2023/11/29 16:36:35 by mgovinda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_argc_error(char *name)
{
	ft_printf(2, "Error %s: %s requieres 4 arguments to work.\n Like the \
	following : ./%s File1 Cmd1 Cmd2 File2\n", name, name, name);
	exit(EXIT_FAILURE);
}