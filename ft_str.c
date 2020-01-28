/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpiedra <dpiedra@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/20 16:19:50 by dpiedra           #+#    #+#             */
/*   Updated: 2020/01/28 15:10:41 by dpiedra          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int	ft_str_width(int width, int precision, char *str, int count)
{
	int rtn;

	rtn = 0;
	if (width > 0 && width > count && precision > count)
		rtn = ft_fix_field(width - count, ' ');
	else
		rtn = ft_fix_field(width - precision, ' ');
	return (rtn);
}

int	ft_str_precision(t_flag flags, char *str, int count)
{
	int rtn;

	rtn = 0;
	if (flags.width > 0)
		rtn += ft_str_width(flags.width, flags.precision, str, count);
	// deal with *. and negative numbers;
	else if (count < flags.precision || flags.precision < 0)
	{
		ft_putstr_fd(str, 1);
		return (count);
	}
	while (flags.precision > 0 && count > 0)
	{
		ft_putchar_fd(*str, 1);
		flags.precision--;
		count--;
		str++;
		rtn++;
	}
	return (rtn);
}

int	ft_str_conv(va_list args, t_flag flags)
{
	int		count;
	int		rtn;
	char	*str;

	rtn = 0;
	str = va_arg(args, char *);
	count = ft_strlen(str);
	if (flags.minus == 1 && flags.width >= 0)
	{
		ft_putstr_fd(str, 1);
		rtn = ft_fix_field(flags.width - count, ' ');
	}
	else if (flags.period == 0)
	{
		rtn = ft_str_precision(flags, str, count);
		return (rtn);
	}
	else if (flags.width >= 0)
	{
		rtn = ft_fix_field(flags.width - count, ' ');
		ft_putstr_fd(str, 1);
	}
	rtn += count;
	return (rtn);
}
