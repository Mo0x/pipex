/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pointer.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgovinda <mgovinda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 19:17:55 by mgovinda          #+#    #+#             */
/*   Updated: 2023/11/09 15:30:25 by mgovinda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static	int	ft_sizeaddr(unsigned long addr)
{
	int	ret;

	ret = 0;
	while (addr)
	{
		addr /= 16;
		ret++;
	}
	return (ret);
}

static void	ft_putaddr(unsigned long addr)
{
	char	*base;

	base = "0123456789abcdef";
	if (addr > 15)
	{
		ft_putaddr(addr / 16);
		ft_putaddr(addr % 16);
	}
	else
		ft_putchar_fd(base[addr], 1);
}

int	ft_pointer(unsigned long addr)
{
	int		ret;

	ret = 2;
	ft_putstr_fd("0x", 1);
	if (addr == 0)
	{
		ft_putchar_fd('0', 1);
		ret++;
	}
	else
	{
		ft_putaddr(addr);
		ret += ft_sizeaddr(addr);
	}
	return (ret);
}