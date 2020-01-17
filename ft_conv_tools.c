/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conv_tools.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpiedra <dpiedra@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/17 11:43:45 by dpiedra           #+#    #+#             */
/*   Updated: 2020/01/17 12:25:55 by dpiedra          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int	ft_find_conv(const char *str, va_list args, t_list flags)
{
	int i;
	char value;

	i = 0;
	if (*str == 'c')
		ft_treat_c(args, flags);
	if (*str == 's')
	{
	}
	if (*str == 'p')
	{
	}
	if (*str == 'd' || *str == 'i')
	{
	}
	if (*str == 'u')
	{
	}
	if (*str == 'x' || *str == 'X')
	{
	}
	return (i);
}

// value = va_arg(args, int);
// 		write(1, &value, 1);