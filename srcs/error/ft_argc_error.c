/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_argc_error.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgovinda <mgovinda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 17:10:09 by mgovinda          #+#    #+#             */
/*   Updated: 2023/11/10 17:45:42 by mgovinda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_argc_error(char *name)
{
	ft_printf(2, "%s: %s requieres arguments to work.\n", name, name);
}