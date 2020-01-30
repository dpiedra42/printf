/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conv_tools.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpiedra <dpiedra@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/17 11:43:45 by dpiedra           #+#    #+#             */
/*   Updated: 2020/01/30 13:44:25 by dpiedra          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int	ft_fix_field(int flag, char c)
{
	int rtn;

	rtn = 0;
	if (flag == 0)
		return (rtn);
	while (flag > 0)
	{
		ft_putchar_fd(c, 1);
		flag--;
		rtn++;
	}
	return (rtn);
}

int	ft_find_count(int decimal)
{
	int count;

	count = 0;
	if (decimal <= 0)
	{
		count++;
		decimal *= -1;
	}
	while (decimal > 0)
	{
		decimal = decimal / 10;
		count++;
	}
	return (count);
}

int	ft_find_conv(const char *str, va_list args, t_flag flags)
{
	int rtn;

	if (*str == 'c')
		rtn = ft_c_conv(args, flags);
	if (*str == 's')
		rtn = ft_str_conv(args, flags);
	if (*str == 'd' || *str == 'i')
		rtn = ft_signed_conv(args, flags);
	// if (*str == 'u')
	// 	rtn = ft_unsigned_conv(args, flags);
	// if (*str == 'p')
	// 	rtn = ft_ptr_conv(args, flags);
	return (rtn);
}

// void	ft_putunbr_fd(unsigned int n, int fd)
// {
// 	if (n <= 9 && n >= 0)
// 	{
// 		ft_putchar_fd(n + '0', fd);
// 	}
// 	else if (n > 9)
// 	{
// 		ft_putunbr_fd(n / 10, fd);
// 		ft_putunbr_fd(n % 10, fd);
// 	}
// }
