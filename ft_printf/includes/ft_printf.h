/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgovinda <mgovinda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 15:22:59 by mgovinda          #+#    #+#             */
/*   Updated: 2023/11/09 16:52:17 by mgovinda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>
# include "../../libft/libft.h"

int				ft_printf(const char *fmt, ...);
int				ft_printpc(void);
unsigned int	ft_unsigned(unsigned int nb);
int				ft_pointer(unsigned long addr);
int				ft_hexa(unsigned int nb, char format);
int				ft_number(int nb);
int				ft_string(char *string);

#endif
