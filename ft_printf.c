/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpiedra <dpiedra@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/16 17:15:35 by dpiedra           #+#    #+#             */
/*   Updated: 2020/02/03 13:24:53 by dpiedra          ###   ########.fr       */
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
	t_flag	flags;
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

int	main(void)
{
	char			c;
	char			*str;
	char			*str2;
	int				deci;
	unsigned int	unsi;
	int				i;
	char d;
	int				a;
	int				b;

	str = "test printf";
	str2 = "hello deanna";
	unsi = 0;
	c = 'd';
	d = 'a';
	i = -12;
	deci = -52;
	printf("CONVERSION D'ENTIER NATUREL (unsigned - u)\n");
	a = ft_printf("|1 : %*.u|\n", 10, unsi);
	b =    printf("|1 : %*.u|\n", 10, unsi);
	printf(" Your printf returned : %i\nTheir printf returned : %i\n", a, b);
	return (0);
}
