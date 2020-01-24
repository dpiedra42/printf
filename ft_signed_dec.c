/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_signed_dec.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpiedra <dpiedra@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/21 16:44:31 by dpiedra           #+#    #+#             */
/*   Updated: 2020/01/24 16:46:18 by dpiedra          ###   ########.fr       */
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

int	ft_neg_sign(int decimal, t_list flags, int count, int rtn)
{
	if (flags.width > 0 && flags.period > count &&
			flags.period < flags.width)
	{
		rtn = ft_fix_field(flags.width - flags.period - 1, ' ');
		ft_putchar_fd('-', 1);
		rtn += ft_fix_field(flags.period - count + 1, '0');
	}
	else if (flags.period > count)
	{
		ft_putchar_fd('-', 1);
		rtn = ft_fix_field(flags.period - count + 1, '0');
	}
	else if (flags.width > 0 && flags.period < count)
	{
		rtn = ft_fix_field(flags.width - count, ' ');
		ft_putchar_fd('-', 1);
	}
	else if (flags.period < count)
	{
		rtn = ft_fix_field(flags.period - count, '0');
		ft_putchar_fd('-', 1);
	}
	return (rtn);
}

int	ft_signed_field(int count, int decimal, t_list flags)
{
	int rtn;

	rtn = 0;
	if (flags.minus == 1)
	{
		ft_putnbr_fd(decimal, 1);
		rtn += ft_fix_field(flags.width - count, ' ');
		return (rtn);
	}
	else if (flags.zero == 1)
	{
		if (decimal < 0)
		{
			ft_putchar_fd('-', 1);
			decimal *= -1;
		}
		rtn += ft_fix_field(flags.width - count, '0');
	}
	else if (flags.width >= 0)
		rtn = ft_fix_field(flags.width - count, ' ');
	ft_putnbr_fd(decimal, 1);
	return (rtn);
}

int	ft_signed_period(int decimal, int count, t_list flags)
{
	int rtn;
	int n;

	rtn = 0;
	if (decimal < 0)
	{
		rtn = ft_neg_sign(decimal, flags, count, rtn);
		decimal *= -1;
	}
	else if (flags.width > 0 && flags.period < count)
		rtn = ft_fix_field(flags.width - count, ' ');
	else if (flags.width > 0 && flags.period > count &&
		flags.period < flags.width)
	{
		rtn = ft_fix_field(flags.width - flags.period, ' ');
		rtn += ft_fix_field(flags.period - count, '0');
	}
	else if (flags.period > count)
		rtn = ft_fix_field(flags.period - count, '0');
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
		rtn = ft_signed_period(decimal, count, flags);
		return (rtn);
	}
	else if (flags.width >= 0)
		rtn = ft_signed_field(count, decimal, flags);
	rtn += count;
	return (rtn);
}
