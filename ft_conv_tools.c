/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conv_tools.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpiedra <dpiedra@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/17 11:43:45 by dpiedra           #+#    #+#             */
/*   Updated: 2020/01/17 14:00:12 by dpiedra          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void	ft_treat_c(va_list args, t_list flags)
{
	int value; 

	if (flags.minus == 1 && flags.width > 0)
	{
		flags.width -= 1;
		value = va_arg(args, int);
		write(1, &value, 1);
		while (flags.width != 0)
		{
			write(1, " ", 1);
			flags.width--;
		}
	}
}

int	ft_find_conv(const char *str, va_list args, t_list flags)
{
	int i;
	char value;

	i = 0;
	if (*str == 'c')
		ft_treat_c(args, flags);
	if (*str == 's')
	{
	}
	if (*str == 'p')
	{
	}
	if (*str == 'd' || *str == 'i')
	{
	}
	if (*str == 'u')
	{
	}
	if (*str == 'x' || *str == 'X')
	{
	}
	return (i);
}
