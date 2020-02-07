/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deannapiedra <deannapiedra@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/16 17:16:20 by dpiedra           #+#    #+#             */
/*   Updated: 2020/02/07 13:21:34 by deannapiedr      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int	main(void)
{
	char			*str;
	int				a;
	int				b;

	str = "test printf";
	printf("CONVERSION D'ENTIER NATUREL (PTR - p)\n");
	b = printf("|1 : %%|\n");
	printf(" Your printf returned : %i\nTheir printf returned : %i\n", a, b);
	return (0);
}
