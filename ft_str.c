/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpiedra <dpiedra@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/20 16:19:50 by dpiedra           #+#    #+#             */
/*   Updated: 2020/01/31 14:22:35 by dpiedra          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int	ft_str_width(t_flag flags, char *str, int count)
{
	int rtn;

	rtn = 0;
	if (flags.minus == 1)
	{
		while (flags.precision > 0 && *str != '\0')
		{
			ft_putchar_fd(*str, 1);
			flags.precision--;
			str++;
			rtn++;
		}
		rtn += ft_fix_field(flags.width - rtn, ' ');
		return (rtn);
	}
	else if (flags.width > 0 && flags.width > count && flags.precision > count)
		rtn = ft_fix_field(flags.width - count, ' ');
	else
		rtn = ft_fix_field(flags.width - flags.precision, ' ');
	return (rtn);
}

int	ft_neg_precision(t_flag flags, char *str, int count)
{
	int rtn;

	rtn = 0;
	if (flags.minus == 0)
	{
		rtn = ft_fix_field(flags.width - count, ' ');
		ft_putstr_fd(str, 1);
	}
	if (flags.minus == 1)
	{
		ft_putstr_fd(str, 1);
		rtn = ft_fix_field(flags.width - count, ' ');
	}
	rtn += count;
	return (rtn);
}

int	ft_str_precision(t_flag flags, char *str, int count)
{
	int rtn;

	rtn = 0;
	if (flags.precision < 0 && flags.width > 0)
		rtn = ft_neg_precision(flags, str, count);
	else if (flags.width > 0)
		rtn += ft_str_width(flags, str, count);
	else if (count < flags.precision || flags.precision < 0)
	{
		ft_putstr_fd(str, 1);
		return (count);
	}
	while (flags.precision > 0 && *str != '\0' && flags.minus == 0)
	{
		ft_putchar_fd(*str, 1);
		flags.precision--;
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
	if (str == NULL)
		str = "(null)";
	count = ft_strlen(str);
	if (flags.minus == 1 && flags.width >= 0 && flags.period == -1)
	{
		ft_putstr_fd(str, 1);
		rtn = ft_fix_field(flags.width - count, ' ');
		rtn += count;
	}
	else if (flags.period == 0)
		rtn = ft_str_precision(flags, str, count);
	else if (flags.width >= 0)
	{
		rtn = ft_fix_field(flags.width - count, ' ');
		ft_putstr_fd(str, 1);
		rtn += count;
	}
	return (rtn);
}
