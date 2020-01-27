/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unsigned.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpiedra <dpiedra@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/24 15:18:21 by dpiedra           #+#    #+#             */
/*   Updated: 2020/01/27 14:55:21 by dpiedra          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int	ft_find_ucount(unsigned int nbr)
{
	int count;

	count = 0;
	if (nbr == 0)
		count++;
	while (nbr > 0)
	{
		nbr = nbr / 10;
		count++;
	}
	return (count);
}

int	ft_unsigned_precision(unsigned int nbr, int count, t_flag flags)
{
	int rtn;

	rtn = 0;
	if (flags.width > 0 && flags.precision <= count)
		rtn = ft_fix_field(flags.width - count, ' ');
	else if (flags.width > 0 && flags.precision > count &&
		flags.precision < flags.width)
	{
		rtn = ft_fix_field(flags.width - flags.precision, ' ');
		rtn += ft_fix_field(flags.precision - count, '0');
	}
	else if (flags.precision > count)
		rtn = ft_fix_field(flags.precision - count, '0');
	ft_putunbr_fd(nbr, 1);
	rtn += count;
	return (rtn);
}

int	ft_unsigned_field(int count, unsigned int nbr, t_flag flags)
{
	int rtn;

	rtn = 0;
	if (flags.minus == 1)
	{
		ft_putunbr_fd(nbr, 1);
		rtn += ft_fix_field(flags.width - count, ' ');
		return (rtn);
	}
	else if (flags.zero == 1)
		rtn += ft_fix_field(flags.width - count, '0');
	else if (flags.width >= 0)
		rtn = ft_fix_field(flags.width - count, ' ');
	ft_putunbr_fd(nbr, 1);
	return (rtn);
}

int	ft_unsigned_conv(va_list args, t_flag flags)
{
	int				rtn;
	int				count;
	char			*str;
	unsigned int	nbr;

	rtn = 0;
	nbr = va_arg(args, unsigned int);
	count = ft_find_ucount(nbr);
	if ((flags.minus == 1 && flags.width > 0) ||
		(flags.zero == 1 && flags.width > 0 && flags.precision == -1))
		rtn = ft_unsigned_field(count, nbr, flags);
	else if (flags.precision >= 0)
	{
		rtn = ft_unsigned_precision(nbr, count, flags);
		return (rtn);
	}
	else if (flags.width >= 0)
		rtn = ft_unsigned_field(count, nbr, flags);
	rtn += count;
	return (rtn);
}
