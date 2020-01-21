/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpiedra <dpiedra@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/20 16:19:50 by dpiedra           #+#    #+#             */
/*   Updated: 2020/01/21 12:00:05 by dpiedra          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int	ft_str_field(int width, int count, char *str, t_list flags)
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
	return (rtn);
}

int	ft_str_period(int flag, char *str, int count)
{
	int rtn;

	rtn = 0;
	if (count < flag)
	{
		ft_putstr_fd(str, 1);
		return (count);
	}
	while (flag != 0)
	{
		ft_putchar_fd(*str, 1);
		flag--;
		str++;
		rtn++;
	}
	return (rtn);
}

int	ft_str_conv(va_list args, t_list flags)
{
	int		count;
	int		rtn;
	char	*str;

	rtn = 0;
	str = va_arg(args, char *);
	count = ft_strlen(str);
	if ((flags.minus == 1 && flags.width > 0) ||
		(flags.zero == 1 && flags.width > 0))
		rtn = ft_str_field(flags.width, count, str, flags);
	else if (flags.period == 0, )
	{
		rtn = ft_str_period(flags.width, str, count);
		return (rtn);
	}
	rtn += count;
	return (rtn);
}

// while (*str != '\0')
	// {
	// 	ft_putchar_fd(*str, 1);
	// 	str++;
	// 	rtn++;
	// }
