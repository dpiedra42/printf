/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unsigned.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpiedra <dpiedra@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/24 15:18:21 by dpiedra           #+#    #+#             */
/*   Updated: 2020/01/27 11:01:45 by dpiedra          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int	ft_unsigned_conv(va_list args, t_flag flags)
{
	int				rtn;
	int				count;
	unsigned int	nbr;

	rtn = 0;
	nbr = va_arg(args, int);
	count = ft_find_count(nbr);
	if ((flags.minus == 1 && flags.width > 0) ||
		(flags.zero == 1 && flags.width > 0 && flags.period == -1))
		rtn = ft_signed_field(count, nbr, flags);
	else if (flags.period >= 0)
	{
		rtn = ft_signed_period(nbr, count, flags);
		return (rtn);
	}
	else if (flags.width >= 0)
		rtn = ft_signed_field(count, nbr, flags);
	rtn += count;
	return (rtn);
}
