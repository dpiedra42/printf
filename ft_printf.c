/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpiedra <dpiedra@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/16 17:15:35 by dpiedra           #+#    #+#             */
/*   Updated: 2020/01/20 16:10:00 by dpiedra          ###   ########.fr       */
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

	c = 'd';
	int a;
	int b;
	a = ft_printf("1 : |%2c|\n", c);
	b = printf("1 : |%2c|\n", c);
	printf("Your printf returned : %i\nTheir printf returned : %i\n", a, b);
	// ft_printf("2 : |%-c|\n", c);
	// printf("2 : |%-c|\n", c);
	// ft_printf("3 : |%-12c|\n", c);
	// printf("3 : |%-12c|\n", c);
	// ft_printf("4 : |%*c|\n", 5, c);
	// printf("4 : |%*c|\n", 5, c);
	// ft_printf("5 : |%------c|\n", c);
	// printf("5 : |%------c|\n", c);
	// ft_printf("6 : |%-----5c|\n", c);
	// printf("6 : |%-----5c|\n", c);
	// ft_printf("7 : |%7c|\n", c);
	// printf("7 : |%7c|\n", c);
	// ft_printf("8 : |%-10*c|\n", 5, c);
	// printf("8 : |%-10*c|\n", 5, c);
	return (0);
}
