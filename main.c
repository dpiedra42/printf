/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deannapiedra <deannapiedra@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/16 17:16:20 by dpiedra           #+#    #+#             */
/*   Updated: 2020/02/07 14:27:33 by deannapiedr      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int	main(void)
{
	char			*str;
	int				a;
	int				b;
	int 			i;

	str = "test printf";
	i = -2147483648;
	printf("CONVERSION D'ENTIER NATUREL (PTR - p)\n");
	a = ft_printf("|1 : %d|\n", i);
	b =    printf("|1 : %d|\n", i);
	printf(" Your printf returned : %i\nTheir printf returned : %i\n", a, b);
	return (0);
}
