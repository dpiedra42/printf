/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpiedra <dpiedra@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/13 17:49:21 by deannapiedr       #+#    #+#             */
/*   Updated: 2020/01/15 11:11:38 by dpiedra          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdarg.h>

int	ft_printf(const char *str, ...)
{
	va_list args;
	int		i;
	int		rtn;
/* return is the total number of chars written, or neg if fail */

	i = 0;
	rtn = 0;
	va_start(args, str);
	while (str[i] != '\0')
	{
		if (str[i] != '%')
		{
			write(1, &str[i], 1);
			i++;
			rtn++;
		}
		else if (str[i] == '%' && str[i + 1] != '\0')
		{
		}
		i++;
	}
	return (rtn);
}
