/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_signed_dec.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpiedra <dpiedra@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/21 16:44:31 by dpiedra           #+#    #+#             */
/*   Updated: 2020/01/22 17:38:05 by dpiedra          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int	ft_find_count(int decimal)
{
	int count;

	count = 0;
	if (decimal < 0)
	{
		decimal = decimal * -1;
		count++;
	}
	while (decimal > 0)
	{
		decimal = decimal / 10;
		count++;
	}
	return (count);
}

int	ft_neg_sign(int decimal)
{
	ft_putchar_fd('-', 1);
	decimal *= -1;
	return (decimal);
}

int	ft_signed_field(int count, int decimal, t_list flags)
{
	int rtn;

	rtn = 0;
	if (flags.minus == 1)
	{
		if (decimal < 0)
			rtn++;
		ft_putnbr_fd(decimal, 1);
		rtn += ft_fix_field(flags.width - count, ' ');
		return (rtn);
	}
	else if (flags.zero == 1)
	{
		if (decimal < 0)
			decimal = ft_neg_sign(decimal);
		rtn += ft_fix_field(flags.width - count, '0');
	}
	else if (flags.width >= 0)
		rtn = ft_fix_field(flags.width - count, ' ');
	ft_putnbr_fd(decimal, 1);
	return (rtn);
}

int	ft_signed_period(int width, int period, int decimal, int count)
{
	int rtn;
	int n;

	rtn = 0;
	if (width > 0 && period < count)
		rtn = ft_fix_field(width - count, ' ');
	else if (width > 0 && period > count && period < width)
	{
		rtn = ft_fix_field(width - period, ' ');
		rtn += ft_fix_field(period - count, '0');
	}
	else if (period > count)
	{
		if (decimal < 0)
			decimal = ft_neg_sign(decimal);
		rtn = ft_fix_field(period - count, '0');
	}
	ft_putnbr_fd(decimal, 1);
	rtn += count;
	return (rtn);
}

int	ft_signed_conv(va_list args, t_list flags)
{
	int rtn;
	int count;
	int decimal;

	rtn = 0;
	decimal = va_arg(args, int);
	count = ft_find_count(decimal);
	if ((flags.minus == 1 && flags.width > 0) ||
		(flags.zero == 1 && flags.width > 0 && flags.period == -1))
		rtn = ft_signed_field(count, decimal, flags);
	else if (flags.period >= 0)
	{
		rtn = ft_signed_period(flags.width, flags.period, decimal, count);
		return (rtn);
	}
	else if (flags.width >= 0)
		rtn = ft_signed_field(count, decimal, flags);
	rtn += count;
	return (rtn);
}
