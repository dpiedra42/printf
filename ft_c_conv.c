/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_c_conv.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpiedra <dpiedra@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/17 12:20:52 by dpiedra           #+#    #+#             */
/*   Updated: 2020/01/20 12:01:04 by dpiedra          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void	ft_c_minus(va_list args, t_list flags, int value)
{
	value = va_arg(args, int);
	if (flags.width != 0)
	{
		flags.width -= 1;
		write(1, &value, 1);
		while (flags.width != 0)
		{
			write(1, " ", 1);
			flags.width--;
		}
	}
	else
		write(1, &value, 1);
}

void	ft_c_asterisk(va_list args, t_list flags, int value)
{
	value = va_arg(args, int);
	if (flags.width != 0)
	{
		flags.width -= 1;
		while (flags.width != 0)
		{
			write(1, " ", 1);
			flags.width--;
		}
		write(1, &value, 1);
	}
	else
		write(1, &value, 1);
}

int		ft_treat_cflags(va_list args, t_list flags)
{
	int value;

	if (flags.minus == 1 && flags.width >= 0)
		ft_c_minus(args, flags, value);
	else
	{
		value = va_arg(args, int);
		write(1, &value, 1);
	}
}
