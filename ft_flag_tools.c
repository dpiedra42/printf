/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flag_tools.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpiedra <dpiedra@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/15 14:47:31 by dpiedra           #+#    #+#             */
/*   Updated: 2020/01/16 11:01:53 by dpiedra          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

t_list	ft_startflags(t_list flags)
{
	flags.zero = 0;
	flags.minus = 0;
	flags.width = 0;
	flags.period = 0;
	flags.precision = 0;
	return (flags);
}

int	ft_isflag(char c)
{
	if (ft_isdigit(c) == 1 || c == '.' || c == '*' || c == '-')
		return (1);
	else
		return (0);
}
