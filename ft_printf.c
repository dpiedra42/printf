/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpiedra <dpiedra@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/16 17:15:35 by dpiedra           #+#    #+#             */
/*   Updated: 2020/01/21 15:03:29 by dpiedra          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int	ft_new_putchar(char c, int rtn)
{
	if (c != '%' && c != '\0')
	{
		write(1, &c, 1);
		rtn++;
	}
	return (rtn);
}

int	ft_printf(const char *str, ...)
{
	va_list args;
	t_list	flags;
	int		i;
	int		rtn;

	i = 0;
	rtn = 0;
	va_start(args, str);
	while (*str != '\0')
	{
		rtn = ft_new_putchar(*str, rtn);
		if (*str == '%' && *str + 1 != '\0')
		{
			str++;
			flags = ft_start_flags(flags);
			flags = ft_make_flags(str, flags, args);
			while (ft_isflag(*str) == 1)
				str++;
			rtn += ft_find_conv(str, args, flags);
		}
		str++;
	}
	return (rtn);
}
