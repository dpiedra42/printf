/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_longitoa_base.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpiedra <dpiedra@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/04 11:42:40 by dpiedra           #+#    #+#             */
/*   Updated: 2020/02/06 11:52:03 by dpiedra          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int		ft_longcount_space(int base, int i)
{
	if (i == 0)
		return (1);
	else
		return (base * ft_count_space(base, i - 1));
}

char	*ft_longitoa_base(unsigned long long nbr, int base)
{
	int		i;
	char	*str;

	i = 1;
	while (ft_count_space(base, i) - 1 < nbr)
		i++;
	if (nbr > 0)
		i += 1;
	str = (char*)malloc(sizeof(str) * i);
	str[i] = '\0';
	while (i-- > 0)
	{
		if (nbr % base > 9)
			str[i] = (nbr % base) + 'a' - 10;
		else
			str[i] = (nbr % base) + '0';
		nbr = nbr / base;
	}
	return (str);
}
