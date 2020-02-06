/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uitoa_base.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpiedra <dpiedra@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/03 16:22:02 by dpiedra           #+#    #+#             */
/*   Updated: 2020/02/06 17:09:30 by dpiedra          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

unsigned int	ft_count_space(int base, int i)
{
	if (i == 0)
		return (1);
	else
		return (base * ft_count_space(base, i - 1));
}

char			*ft_uitoa_base(unsigned int nbr, int base, int x)
{
	int		i;
	char	*str;

	i = 1;
	while (ft_count_space(base, i) - 1 < nbr)
		i++;
	str = (char*)malloc(sizeof(str) * i);
	str[i] = '\0';
	while (i-- > 0)
	{
		if (x == 1 && nbr % base > 9)
			str[i] = (nbr % base) + 'A' - 10;
		else if (nbr % base > 9 && x == 0)
			str[i] = (nbr % base) + 'a' - 10;
		else
			str[i] = (nbr % base) + '0';
		nbr = nbr / base;
	}
	return (str);
}
