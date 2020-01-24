/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unsigned.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpiedra <dpiedra@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/24 15:18:21 by dpiedra           #+#    #+#             */
/*   Updated: 2020/01/24 16:16:51 by dpiedra          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int	ft_unsigned_conv(va_list args, t_list flags)
{
	int rtn;
	int count;
	int nbr;

	rtn = 0;
	nbr = va_arg(args, int);

	count = ft_find_count(nbr);
	return (rtn);
}