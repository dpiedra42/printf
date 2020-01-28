/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpiedra <dpiedra@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/20 16:19:50 by dpiedra           #+#    #+#             */
/*   Updated: 2020/01/28 12:34:19 by dpiedra          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int	ft_str_field(int count, char *str, t_flag flags)
{
	int rtn;

	rtn = 0;
	if (flags.minus == 1)
	{
		ft_putstr_fd(str, 1);
		rtn = ft_fix_field(flags.width - count, ' ');
	}
	else if (flags.zero == 1)
	{
		rtn = ft_fix_field(flags.width - count, '0');
		ft_putstr_fd(str, 1);
	}
	else if (flags.width >= 0)
	{
		rtn = ft_fix_field(flags.width - count, ' ');
		ft_putstr_fd(str, 1);
	}
	return (rtn);
}

int	ft_str_precision(int flag, int precision, char *str, int count)
{
	int rtn;

	rtn = 0;
	if (flag > 0 && flag > count && precision > count)
		rtn = ft_fix_field(flag - count, ' ');
	else if (flag > 0 && flag < count)
		rtn = ft_fix_field(flag - precision, ' ');
	else if (flag > 0 && precision < count)
		rtn = ft_fix_field(flag - precision, ' ');
	else if (count < precision)
	{
		ft_putstr_fd(str, 1);
		return (count);
	}
	while (precision > 0 && count > 0)
	{
		ft_putchar_fd(*str, 1);
		precision--;
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
	rtn += count;
	return (rtn);
}
// if ((flags.minus == 1 && flags.width > 0) ||
	// 	(flags.zero == 1 && flags.width > 0 && flags.precision == -1))
	// 	rtn = ft_str_field(count, str, flags);
	// else if (flags.precision >= 0)
	// {
	// 	rtn = ft_str_precision(flags.width, flags.precision, str, count);
	// 	return (rtn);
	// }
	// else if (flags.width >= 0)
	// 	rtn = ft_str_field(count, str, flags);
