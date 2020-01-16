/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpiedra <dpiedra@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/13 17:49:21 by deannapiedr       #+#    #+#             */
/*   Updated: 2020/01/16 14:45:17 by dpiedra          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int	ft_putchar(char c, int rtn)
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
		rtn = ft_putchar(*str, rtn);
		if (*str == '%' && *str + 1 != '\0')
		{
			str++;
			flags = ft_start_flags(flags);
			if (ft_isflag(*str) == 1)
				flags = ft_make_flags(str, flags, args);
		}
		str++;
	}
	return (rtn);
}

int	main(void)
{
	ft_printf("hello %-10d", 42);
	return (0);
}
