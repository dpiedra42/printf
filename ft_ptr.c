/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ptr.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deannapiedra <deannapiedra@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/24 13:43:21 by dpiedra           #+#    #+#             */
/*   Updated: 2020/02/08 11:54:42 by deannapiedr      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int	ft_ptr_flags(t_flag flags, char *str, int len)
{
	int	rtn;

	rtn = 0;
	if (*str == '0' && flags.width == 0 && flags.period == 0)
		ft_putstr_fd("0x", 1);
	else if (flags.minus == 1)
	{
		ft_putstr_fd("0x", 1);
		ft_putstr_fd(str, 1);
		rtn += ft_fix_field(flags.width - (len + 2), ' ');
	}
	else if (flags.minus == 0)
	{
		rtn += ft_fix_field(flags.width - (len + 2), ' ');
		ft_putstr_fd("0x", 1);
		ft_putstr_fd(str, 1);
	}
	return (rtn);
}

int	ft_ptr_conv(va_list args, t_flag flags)
{
	char				*str;
	int					rtn;
	int					len;
	unsigned long long	value;

	rtn = 0;
	value = va_arg(args, unsigned long long);
	str = ft_longitoa_base(value, 16);
	len = ft_strlen(str);
	rtn += ft_ptr_flags(flags, str, len);
	if (*str == '0' && flags.width == 0 && flags.period == 0)
		rtn += 2;
	else
		rtn += len + 2;
	free(str);
	return (rtn);
}
