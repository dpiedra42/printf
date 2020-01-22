/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_signed_dec.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpiedra <dpiedra@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/21 16:44:31 by dpiedra           #+#    #+#             */
/*   Updated: 2020/01/21 17:55:35 by dpiedra          ###   ########.fr       */
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

int	ft_signed_field(int count, int decimal, t_list flags)
{
	int rtn;

	rtn = 0;
	if (flags.minus == 1)
	{
		ft_putnbr_fd(decimal, 1);
		rtn = ft_fix_field(flags.width - count, ' ');
	}
	else if (flags.zero == 1)
	{
		rtn = ft_fix_field(flags.width - count, '0');
		ft_putnbr_fd(decimal, 1);
	}
	else if (flags.width >= 0)
	{
		rtn = ft_fix_field(flags.width - count, ' ');
		ft_putnbr_fd(decimal, 1);
	}
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
	else if (flags.period == 0)
	{
		rtn = 
	}
	rtn += count;
	return (rtn);
}
