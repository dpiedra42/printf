/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deannapiedra <deannapiedra@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/16 17:16:20 by dpiedra           #+#    #+#             */
/*   Updated: 2020/02/07 16:58:40 by deannapiedr      ###   ########.fr       */
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
	a = ft_printf("%.2s is a string", "");
	printf("\n");
	b =    printf("%.2s is a string", "");
	printf("\n");
	printf(" Your printf returned : %i\nTheir printf returned : %i\n", a, b);
	return (0);
}
