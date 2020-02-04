/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_scraps.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpiedra <dpiedra@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/04 11:42:40 by dpiedra           #+#    #+#             */
/*   Updated: 2020/02/04 11:54:26 by dpiedra          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int		ft_count(int b, int pow)
{
	if (pow == 0)
		return (1);
	else
		return (b * ft_count(b, pow - 1));
}

char	*ft_itoa_base(unsigned long long int nbr, int base)
{
	int		i;
	char	*str;

	i = 1;
	if (nbr < 0)
		nbr *= -1;
	while (ft_count(base, i) - 1 < nbr)
		i++;
	printf("%i\n", i);
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

int		main(void)
{
	int i;

	i = 1;
	printf("%s\n", ft_itoa_base(i, 16));
	printf("%x\n", i);
	return (0);
}
