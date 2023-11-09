/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_numbers.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgovinda <mgovinda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 19:17:15 by mgovinda          #+#    #+#             */
/*   Updated: 2023/11/09 19:29:48 by mgovinda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft.h"

int	ft_number(int nb)
{
	int	ret;

	ret = 0;
	if (nb == 0)
	{
		ft_putchar_fd('0', 1);
		return (1);
	}
	if (nb < 0)
		ret++;
	ft_putnbr_fd(nb, 1);
	while (nb)
	{
		nb /= 10;
		ret++;
	}
	return (ret);
}

unsigned int	ft_unsigned(unsigned int nb)
{
	unsigned int	ret;
	unsigned int	copy;

	if (nb == 0)
	{
		ft_putchar_fd('0', 1);
		return (1);
	}
	copy = nb;
	ret = 0;
	if (nb > 9)
	{
		ft_unsigned(nb / 10);
		ft_unsigned(nb % 10);
	}
	else
		ft_putchar_fd(nb + '0', 1);
	while (copy)
	{
		copy /= 10;
		ret++;
	}
	return (ret);
}
