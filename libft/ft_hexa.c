/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hexa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgovinda <mgovinda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 19:19:41 by mgovinda          #+#    #+#             */
/*   Updated: 2023/11/09 19:29:02 by mgovinda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft.h"

static	int	ft_sizehex(unsigned long nb)
{
	int	ret;

	ret = 0;
	while (nb)
	{
		nb /= 16;
		ret++;
	}
	return (ret);
}

static void	ft_puthex(unsigned long nb, char *base)
{
	if (nb > 15)
	{
		ft_puthex(nb / 16, base);
		ft_puthex(nb % 16, base);
	}
	else
		ft_putchar_fd(base[nb], 1);
}

int	ft_hexa(unsigned int nb, char format)
{
	int		ret;
	char	*base1;
	char	*base2;

	base1 = "0123456789abcdef";
	base2 = "0123456789ABCDEF";
	ret = 0;
	if (nb == 0)
	{
		ft_putchar_fd('0', 1);
		return (1);
	}
	if (format == 'x')
		ft_puthex(nb, base1);
	if (format == 'X')
		ft_puthex(nb, base2);
	ret = ft_sizehex(nb);
	return (ret);
}
