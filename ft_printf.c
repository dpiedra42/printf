/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpiedra <dpiedra@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/13 17:49:21 by deannapiedr       #+#    #+#             */
/*   Updated: 2020/01/15 17:14:51 by dpiedra          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int	ft_putchar(char c, int rtn)
{
	write(1, &c, 1);
	rtn++;
	return (rtn);
}

int	ft_printf(const char *str, ...)
{
	va_list args;
	int		i;
	int		rtn;

	i = 0;
	rtn = 0;
	va_start(args, str);
	while (str[i] != '\0')
	{
		if (str[i] != '%')
			rtn = ft_putchar(str[i], rtn);
		else if (str[i] == '%' && str[i + 1] != '\0')
		{
			i++;
			if (ft_isflag(str[i] == 1))
				ft_findflag(str[i]);
		}
		i++;
	}
	return (rtn);
}
