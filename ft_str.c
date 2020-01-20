/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpiedra <dpiedra@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/20 16:19:50 by dpiedra           #+#    #+#             */
/*   Updated: 2020/01/20 17:10:43 by dpiedra          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int	ft_str_conv(va_list args, t_list flags)
{
	int		rtn;
	char	*str;

	rtn = 0;
	str = va_arg(args, char *);


	
	while (*str != '\0')
	{
		ft_putchar_fd(*str, 1);
		str++;
	}
	return (rtn);
}
