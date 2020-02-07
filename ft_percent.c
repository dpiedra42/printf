/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_percent.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deannapiedra <deannapiedra@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/06 11:58:15 by dpiedra           #+#    #+#             */
/*   Updated: 2020/02/07 14:08:58 by deannapiedr      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int	ft_percent_conv(t_flag flags)
{
	int					rtn;

	rtn = 0;
	if (flags.minus == 1)
	{
		ft_putchar_fd('%', 1);
		if (flags.zero == 1)
			rtn += ft_fix_field(flags.width - 1, '0');
		else
			rtn += ft_fix_field(flags.width - 1, ' ');
	}
	else if (flags.minus == 0)
	{
		if (flags.zero == 1)
			rtn += ft_fix_field(flags.width - 1, '0');
		else
			rtn += ft_fix_field(flags.width - 1, ' ');
		ft_putchar_fd('%', 1);
	}
	rtn += 1;
	return (rtn);
}
