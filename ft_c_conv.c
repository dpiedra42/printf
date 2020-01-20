/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_c_conv.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpiedra <dpiedra@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/17 12:20:52 by dpiedra           #+#    #+#             */
/*   Updated: 2020/01/20 14:51:56 by dpiedra          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int		ft_c_flags(va_list args, t_list flags)
{
	int value;
	int rtn;

	rtn = 0;
	if (flags.minus == 1 && flags.width > 1)
	{
		ft_putchar_fd(va_arg(args, int), 1);
		rtn = ft_fix_field(flags.width - 1, ' ');
	}
	else if (flags.zero == 1 && flags.width > 1)
	{
		rtn = ft_fix_field(flags.width - 1, '0');
		ft_putchar_fd(va_arg(args, int), 1);
	}
	else if (flags.width > 0)
		rtn = ft_fix_field(flags.width - 1, ' ');
	ft_putchar_fd(va_arg(args, int), 1);
	rtn += 1;

	return (rtn);
}
