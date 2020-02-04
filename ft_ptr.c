/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ptr.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpiedra <dpiedra@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/24 13:43:21 by dpiedra           #+#    #+#             */
/*   Updated: 2020/02/04 16:58:45 by dpiedra          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int	ft_ptr_conv(va_list args, t_flag flags)
{
	char	*str;
	int		rtn;
	int		value;

	rtn = 0;
	str = va_arg(args, char *);
	printf("%p\n", str);
	return (rtn);
}
