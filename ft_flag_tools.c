/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flag_tools.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpiedra <dpiedra@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/15 14:47:31 by dpiedra           #+#    #+#             */
/*   Updated: 2020/01/16 16:43:40 by dpiedra          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

t_list	ft_start_flags(t_list flags)
{
	flags.zero = 0;
	flags.minus = -1;
	flags.width = 0;
	flags.period = -1;
	flags.precision = -1;
	return (flags);
}

int		ft_isflag(char c)
{
	if (ft_isdigit(c) == 1 || c == '.' || c == '*' || c == '-')
		return (1);
	else
		return (0);
}

t_list	ft_arg_flag(const char *str, t_list flags, va_list args)
{
	// if (*str == '*')
	// {
		// flags.width = 1;
	// }
	// else if (*str == '.' && *str == '*')
		// flags.precision = 1;
	if (*str == '.')
	{
		flags.period = 0;
		str++;
		while (*str >= '0' && *str <= '9')
		{
			flags.period = flags.period * 10 + *str - '0';
			str++;
		}
	}
	return (flags);
}

t_list	ft_make_flags(const char *str, t_list flags, va_list args)
{
	if (ft_isdigit(*str) == 1)
	{
		if (*str == '0')
			str++;
		while (*str >= '0' && *str <= '9')
		{
			flags.zero = flags.zero * 10 + *str - '0';
			str++;
		}
	}
	if (*str == '-')
	{
		flags.minus = 0;
		str++;
		while (*str >= '0' && *str <= '9')
		{
			flags.minus = flags.minus * 10 + *str - '0';
			str++;
		}
	}
	if (*str == '*' || *str == '.')
		flags = ft_arg_flag(str, flags, args);
	return (flags);
}
