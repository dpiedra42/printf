/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_signed_dec.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpiedra <dpiedra@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/21 16:44:31 by dpiedra           #+#    #+#             */
/*   Updated: 2020/01/31 15:50:51 by dpiedra          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int	ft_signed_width(t_flag flags, int decimal, int sign, int count)
{
	int rtn;

	rtn = 0;
	rtn = ft_fix_field(flags.width - count, ' ');
	return (rtn);
}

int	ft_signed_precision(t_flag flags, int decimal, int sign, int count)
{
	int rtn;

	rtn = 0;
	if (sign == 1 && flags.precision < count && flags.zero == 0)
		ft_putchar_fd('-', 1);
	else if (flags.precision > 0)
	{
		ft_putchar_fd('-', 1);
		rtn++;
		rtn += ft_fix_field(flags.width, '0');
	}
	return (rtn);
}

int	ft_signed_flags(t_flag flags, int decimal, int sign, int count)
{
	int rtn;

	rtn = 0;
	if (flags.minus == 1)
	{
		rtn = ft_signed_precision(flags, decimal, sign, count);
		ft_putnbr_fd(decimal, 1);
		rtn += ft_signed_width(flags, decimal, sign, count);
	}
	return (rtn);
}

int	ft_signed_conv(va_list args, t_flag flags)
{
	int rtn;
	int sign;
	int count;
	int decimal;

	rtn = 0;
	sign = 0;
	decimal = va_arg(args, int);
	count = ft_find_count(decimal);
	if (decimal < 0)
	{
		sign = 1;
		decimal *= -1;
	}
	if (flags.zero == 1 && (flags.minus == 1 || flags.precision >= 0))
		flags.zero = 0;
	else if (flags.precision == 0 && decimal == 0)
	{
		rtn = ft_fix_field(flags.width, ' ');
		return (rtn);
	}
	rtn += ft_signed_flags(flags, decimal, sign, count);
	rtn += count;
	return (rtn);
}
