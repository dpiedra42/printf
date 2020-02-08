/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flag_tools.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpiedra <dpiedra@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/16 17:15:50 by dpiedra           #+#    #+#             */
/*   Updated: 2020/02/08 13:17:28 by dpiedra          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int		ft_isflag(char c)
{
	if (ft_isdigit(c) == 1 || c == '.' || c == '*' || c == '-')
		return (1);
	else
		return (0);
}

t_flag	ft_start_flags(t_flag flags)
{
	flags.zero = 0;
	flags.minus = 0;
	flags.width = 0;
	flags.period = -1;
	flags.precision = -1;
	return (flags);
}

t_flag	ft_arg_flags(char c, t_flag flags, va_list args)
{
	if (c == '*' && flags.period == 0)
		flags.precision = va_arg(args, int);
	else if (c == '*')
	{
		flags.width = va_arg(args, int);
		if (flags.width < 0)
		{
			flags.width *= -1;
			flags.minus = 1;
		}
	}
	return (flags);
}

t_flag	ft_sort_flag(char c, t_flag flags, va_list args)
{
	if (c == '-')
		flags.minus = 1;
	else if (c == '0' && flags.width == 0 && flags.period == -1)
		flags.zero = 1;
	else if (ft_isdigit(c) == 1 && flags.period == -1)
		flags.width = flags.width * 10 + c - '0';
	else if (c == '.')
	{
		flags.precision = 0;
		flags.period = 0;
	}
	else if (ft_isdigit(c) == 1 && flags.period == 0)
		flags.precision = flags.precision * 10 + c - '0';
	else if (c == '*')
		flags = ft_arg_flags(c, flags, args);
	return (flags);
}

t_flag	ft_make_flags(const char *str, t_flag flags, va_list args)
{
	int i;

	i = 0;
	while (ft_isflag(str[i]) == 1)
	{
		flags = ft_sort_flag(str[i], flags, args);
		i++;
	}
	return (flags);
}
