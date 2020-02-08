/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deannapiedra <deannapiedra@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/16 17:16:20 by dpiedra           #+#    #+#             */
/*   Updated: 2020/02/08 11:56:07 by deannapiedr      ###   ########.fr       */
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
	printf("-------------\n");
	a = ft_printf("{%5p}", NULL);
	printf("\n");
	b =    printf("{%5p}", NULL);
	printf("\n");
	printf(" Your printf returned : %i\nTheir printf returned : %i\n", a, b);
	return (0);
}
