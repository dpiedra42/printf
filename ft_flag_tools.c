/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flag_tools.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpiedra <dpiedra@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/15 14:47:31 by dpiedra           #+#    #+#             */
/*   Updated: 2020/01/16 14:43:19 by dpiedra          ###   ########.fr       */
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
	return (flags);
}

int		ft_isflag(char c)
{
	if (ft_isdigit(c) == 1 || c == '.' || c == '*' || c == '-')
		return (1);
	else
		return (0);
}

t_list	ft_assign_flag(const char *str, t_list flags)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (str[j] != '%')
		j++;
	j++;
	if (ft_isdigit(str[j]) == 1)
		flags.zero = 1;
	else if (str[j] == '-')
		flags.minus = 1;
	else if (str[j] == '*')
		flags.width = 1;
	else if (str[j] == ".")
		flags.period = 1;
	else if (str[j] == '.' && str[j + 1] == '*')
		flags.precision = 1;
	return (flags);
}

t_list	ft_make_flags(const char *str, t_list flags, va_list args)
{
	printf("\n%s\n", str);
	flags = ft_assign_flag(str, flags);
	return (flags);
}
