/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hexa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpiedra <dpiedra@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/04 11:21:23 by dpiedra           #+#    #+#             */
/*   Updated: 2020/02/04 15:14:59 by dpiedra          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"


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
	if (flags.zero == 1 && (flags.minus == 1 || flags.precision >= 0))
		flags.zero = 0;
	else if (flags.precision == 0 && *str == 0)
	{
		rtn += ft_fix_field(flags.width, ' ');
		return (rtn);
	}
	rtn += ft_hexa_flags(flags, nbr, len);
	rtn += len;
	return (rtn);
}
