/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conv_tools.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpiedra <dpiedra@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/17 11:43:45 by dpiedra           #+#    #+#             */
/*   Updated: 2020/01/20 16:32:38 by dpiedra          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int	ft_fix_field(int flag, char c)
{
	int rtn;

	rtn = 0;
	if (flag == 0)
		return (rtn);
	while (flag != 0)
	{
		write(1, &c, 1);
		flag--;
		rtn++;
	}
	return (rtn);
}

int	ft_find_conv(const char *str, va_list args, t_list flags)
{
	int rtn;

	if (*str == 'c')
		rtn = ft_c_conv(args, flags);
	if (*str == 's')
		rtn = ft_s_conv(args, flags);

	return (rtn);
}

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