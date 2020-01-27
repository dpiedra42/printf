/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_signed_dec.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpiedra <dpiedra@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/21 16:44:31 by dpiedra           #+#    #+#             */
/*   Updated: 2020/01/27 14:22:09 by dpiedra          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int	ft_find_count(int decimal)
{
	int count;

	count = 0;
	if (decimal == 0)
		count++;
	else if (decimal < 0)
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

int	ft_neg_sign(int decimal, t_flag flags, int count, int rtn)
{
	if (flags.width > 0 && flags.precision > count &&
			flags.precision < flags.width)
	{
		rtn = ft_fix_field(flags.width - flags.precision - 1, ' ');
		ft_putchar_fd('-', 1);
		rtn += ft_fix_field(flags.precision - count + 1, '0');
	}
	else if (flags.precision > count)
	{
		ft_putchar_fd('-', 1);
		rtn = ft_fix_field(flags.precision - count + 1, '0');
	}
	else if (flags.width > 0 && flags.precision < count)
	{
		rtn = ft_fix_field(flags.width - count, ' ');
		ft_putchar_fd('-', 1);
	}
	else if (flags.precision < count)
	{
		rtn = ft_fix_field(flags.precision - count, '0');
		ft_putchar_fd('-', 1);
	}
	return (rtn);
}

int	ft_signed_field(int count, int decimal, t_flag flags)
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

int	ft_signed_precision(int decimal, int count, t_flag flags)
{
	int rtn;

	rtn = 0;
	if (decimal < 0)
	{
		rtn = ft_neg_sign(decimal, flags, count, rtn);
		decimal *= -1;
	}
	else if (flags.width > 0 && flags.precision <= count)
		rtn = ft_fix_field(flags.width - count, ' ');
	else if (flags.width > 0 && flags.precision > count &&
		flags.precision < flags.width)
	{
		rtn = ft_fix_field(flags.width - flags.precision, ' ');
		rtn += ft_fix_field(flags.precision - count, '0');
	}
	else if (flags.precision > count)
		rtn = ft_fix_field(flags.precision - count, '0');
	ft_putnbr_fd(decimal, 1);
	rtn += count;
	return (rtn);
}

int	ft_signed_conv(va_list args, t_flag flags)
{
	int rtn;
	int count;
	int decimal;

	rtn = 0;
	decimal = va_arg(args, int);
	count = ft_find_count(decimal);
	if ((flags.minus == 1 && flags.width > 0) ||
		(flags.zero == 1 && flags.width > 0 && flags.precision == -1))
		rtn = ft_signed_field(count, decimal, flags);
	else if (flags.precision >= 0)
	{
		rtn = ft_signed_precision(decimal, count, flags);
		return (rtn);
	}
	else if (flags.width >= 0)
		rtn = ft_signed_field(count, decimal, flags);
	rtn += count;
	return (rtn);
}
