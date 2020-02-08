/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hexa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpiedra <dpiedra@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/04 11:21:23 by dpiedra           #+#    #+#             */
/*   Updated: 2020/02/08 13:17:40 by dpiedra          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int	ft_hexa_flags(t_flag flags, char *str, int len)
{
	int rtn;

	rtn = 0;
	if (flags.minus == 1)
	{
		rtn = ft_unsigned_precision(flags, len);
		ft_putstr_fd(str, 1);
		rtn += ft_unsigned_width(flags, len);
	}
	else if (flags.minus == 0)
	{
		rtn = ft_unsigned_width(flags, len);
		rtn += ft_unsigned_precision(flags, len);
		ft_putstr_fd(str, 1);
	}
	return (rtn);
}

int	ft_hexa_conv(va_list args, t_flag flags, int x)
{
	int				rtn;
	char			*str;
	unsigned int	nbr;
	int				len;

	rtn = 0;
	nbr = va_arg(args, unsigned int);
	str = ft_uitoa_base(nbr, 16, x);
	len = ft_strlen(str);
	if ((flags.precision == 0 && nbr == 0 && flags.zero == 1) ||
		(flags.precision == 0 && nbr == 0))
	{
		rtn += ft_fix_field(flags.width, ' ');
		return (rtn);
	}
	if (flags.zero == 1 && (flags.minus == 1 || flags.precision >= 0))
		flags.zero = 0;
	rtn += ft_hexa_flags(flags, str, len);
	rtn += len;
	free(str);
	return (rtn);
}
