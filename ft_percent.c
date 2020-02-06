/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_percent.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpiedra <dpiedra@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/06 11:58:15 by dpiedra           #+#    #+#             */
/*   Updated: 2020/02/06 17:06:58 by dpiedra          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int	ft_percent_flags(t_flag flags)
{
	int	rtn;

	rtn = 0;
	if (flags.minus == 1)
	{
		ft_putchar_fd('%', 1);
		rtn += ft_fix_field(flags.width - 1, ' ');
	}
	else if (flags.minus == 0)
	{
		rtn += ft_fix_field(flags.width - 1, ' ');
		ft_putchar_fd('%', 1);
	}
	return (rtn);
}

int	ft_percent_conv(t_flag flags)
{
	int	rtn;

	rtn = 0;
	rtn += ft_percent_flags(flags);
	rtn += 1;
	return (rtn);
}
