/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpiedra <dpiedra@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/16 17:15:35 by dpiedra           #+#    #+#             */
/*   Updated: 2020/01/23 17:44:08 by dpiedra          ###   ########.fr       */
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

int	main(void)
{
	char c;
	char *str;
	int deci;
	unsigned int unsi;
	int hexa;
	int i;
	int a;
	int b;
	unsigned int uhexa;

	str = "test printf";
	c = 'd';
	i = 12;
	deci = -541;
	unsi = 10;
	hexa = 1;
	uhexa = 5;

	a = ft_printf("|1 : %5.5i|\n", deci);
	b = printf("|1 : %5.5i|\n", deci);
	printf("Your printf returned : %i\nTheir printf returned : %i\n", a, b);
	return (0);
}
