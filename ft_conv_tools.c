/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conv_tools.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpiedra <dpiedra@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/17 11:43:45 by dpiedra           #+#    #+#             */
/*   Updated: 2020/01/20 11:59:20 by dpiedra          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int	ft_find_conv(const char *str, va_list args, t_list flags, int rtn)
{
	if (*str == 'c')
		rtn = ft_treat_cflags(args, flags);
	// if (*str == 's')
	// {
	// }
	// if (*str == 'p')
	// {
	// }
	// if (*str == 'd' || *str == 'i')
	// {
	// }
	// if (*str == 'u')
	// {
	// }
	// if (*str == 'x' || *str == 'X')
	// {
	// }
}
