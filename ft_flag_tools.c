/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flag_tools.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpiedra <dpiedra@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/15 14:47:31 by dpiedra           #+#    #+#             */
/*   Updated: 2020/01/16 15:06:09 by dpiedra          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

t_list	ft_start_flags(t_list flags)
{
	flags.zero = 0;
	flags.minimum = 0;
	flags.minus = 0;
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

t_list	ft_assign_flag(char s, t_list flags)
{
	int i;

	i = 0;
	if ((ft_isdigit(s) == 1) && s == '0')
		flags.zero = 1;
	else if (ft_isdigit(s) == 1)
		flags.minimum = s;
	else if (s == '-')
		flags.minus = 1;
	else if (s == '*')
		flags.width = 1;
	else if (s == '.')
		flags.period = 1;
	else if (s == '.' && s == '*')
		flags.precision = 1;
	return (flags);
}

t_list	ft_make_flags(const char *str, t_list flags, va_list args)
{
	flags = ft_assign_flag(*str, flags);
	return (flags);
}
