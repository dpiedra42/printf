/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpiedra <dpiedra@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/16 17:16:20 by dpiedra           #+#    #+#             */
/*   Updated: 2020/02/06 17:03:24 by dpiedra          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int	main(void)
{
	char			c;
	char			*str;
	char			*str2;
	int				deci;
	unsigned int	unsi;
	int				i;
	char d;
	int				a;
	int				b;

	str = "test printf";
	str2 = "hello printf";
	unsi = -21;
	c = 'd';
	d = 'a';
	i = -12;
	deci = -52;
	printf("CONVERSION D'ENTIER NATUREL (PTR - p)\n");
	a = ft_printf("|1 : %p|\n", str);
	b =    printf("|1 : %p|\n", str);
	printf(" Your printf returned : %i\nTheir printf returned : %i\n", a, b);
	return (0);
}
