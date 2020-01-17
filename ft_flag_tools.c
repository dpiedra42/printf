/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flag_tools.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpiedra <dpiedra@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/16 17:15:50 by dpiedra           #+#    #+#             */
/*   Updated: 2020/01/17 10:42:42 by dpiedra          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

t_list	ft_start_flags(t_list flags)
{
	flags.zero = 0;
	flags.minus = 0;
	flags.width = 0;
	flags.period = -1;
	flags.precision = -1;
	flags.asterisk = 0;
	return (flags);
}

t_list	ft_sort_flag(char c, t_list flags, va_list args)
{
	if (c == '-')
		flags.minus = 1;
	if (c == '0')
		flags.zero = 1;
	if (ft_isdigit(c) == 1)
		flags.width = flags.width * 10 + c - '0';
	if (c == '.')
		flags.period = 0;
	if (c == '*' && flags.period == 0)
		flags.precision = 0;
	else if (c == '*')
		flags.asterisk = 1;
	return (flags);
}

t_list	ft_make_flags(const char *str, t_list flags, va_list args)
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
