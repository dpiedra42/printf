/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unsigned.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpiedra <dpiedra@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/24 15:18:21 by dpiedra           #+#    #+#             */
/*   Updated: 2020/02/08 13:18:26 by dpiedra          ###   ########.fr       */
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

int	ft_unsigned_width(t_flag flags, int count)
{
	int rtn;

	rtn = 0;
	if (flags.zero == 1)
		rtn = ft_fix_field(flags.width - count, '0');
	else if (flags.precision >= count)
		rtn += ft_fix_field(flags.width - flags.precision, ' ');
	else
		rtn += ft_fix_field(flags.width - count, ' ');
	return (rtn);
}

int	ft_unsigned_precision(t_flag flags, int count)
{
	int rtn;

	rtn = 0;
	if (flags.precision > 0)
		rtn += ft_fix_field(flags.precision - count, '0');
	return (rtn);
}

int	ft_unsigned_flags(t_flag flags, unsigned int nbr, int count)
{
	int rtn;

	rtn = 0;
	if (flags.minus == 1)
	{
		rtn = ft_unsigned_precision(flags, count);
		ft_putunbr_fd(nbr, 1);
		rtn += ft_unsigned_width(flags, count);
	}
	else if (flags.minus == 0)
	{
		rtn = ft_unsigned_width(flags, count);
		rtn += ft_unsigned_precision(flags, count);
		ft_putunbr_fd(nbr, 1);
	}
	return (rtn);
}

int	ft_unsigned_conv(va_list args, t_flag flags)
{
	int				rtn;
	int				count;
	unsigned int	nbr;

	rtn = 0;
	nbr = va_arg(args, unsigned int);
	count = ft_find_ucount(nbr);
	if ((flags.precision == 0 && nbr == 0 && flags.zero == 1) ||
		(flags.precision == 0 && nbr == 0))
	{
		rtn += ft_fix_field(flags.width, ' ');
		return (rtn);
	}
	else if (flags.zero == 1 && (flags.minus == 1 || flags.precision >= 0))
		flags.zero = 0;
	rtn += ft_unsigned_flags(flags, nbr, count);
	rtn += count;
	return (rtn);
}
