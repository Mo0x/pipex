/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgovinda <mgovinda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 16:09:31 by mgovinda          #+#    #+#             */
/*   Updated: 2023/11/09 19:32:06 by mgovinda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft.h"

int	ft_char(char c)
{
	ft_putchar_fd(c, 1);
	return (1);
}

int	ft_arg(va_list ap, char fmt)
{
	int		cchar;

	cchar = 0;
	if (fmt == 'c')
		cchar = ft_char(va_arg(ap, int));
	else if (fmt == 's')
		cchar = ft_string(va_arg(ap, char *));
	else if (fmt == 'i' || fmt == 'd' || fmt == 'c')
		cchar = ft_number(va_arg(ap, int));
	else if (fmt == 'u')
		cchar = (int)ft_unsigned(va_arg(ap, unsigned int));
	else if (fmt == 'p')
		cchar = ft_pointer((unsigned long int)va_arg(ap, void *));
	else if (fmt == 'x' || fmt == 'X')
		cchar = ft_hexa(va_arg(ap, unsigned int), fmt);
	else if (fmt == '%')
		cchar = ft_printpc();
	return (cchar);
}

int	ft_printf(const char *fmt, ...)
{
	va_list	ap;
	int		cchar;
	int		i;

	i = 0;
	cchar = 0;
	va_start(ap, fmt);
	while (fmt[i])
	{
		if (fmt[i] == '%' && fmt[i + 1])
		{
			cchar += ft_arg(ap, fmt[i + 1]);
			i++;
		}
		else
		{
			ft_putchar_fd(fmt[i], 1);
			cchar++;
		}
		i++;
	}
	va_end(ap);
	return (cchar);
}
