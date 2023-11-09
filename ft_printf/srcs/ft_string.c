/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_string.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgovinda <mgovinda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 19:35:46 by mgovinda          #+#    #+#             */
/*   Updated: 2023/11/08 19:45:51 by mgovinda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_string(char *string)
{
	int	ret;

	ret = 0;
	if (string == NULL)
	{
		ft_putstr_fd("(null)", 1);
		return (6);
	}
	ret = ft_strlen(string);
	ft_putstr_fd(string, 1);
	return (ret);
}
