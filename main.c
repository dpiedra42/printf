/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpiedra <dpiedra@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/16 17:16:20 by dpiedra           #+#    #+#             */
/*   Updated: 2020/02/06 17:21:53 by dpiedra          ###   ########.fr       */
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
	a = ft_printf("|1 : %p|\n", str);
	b = printf("|1 : %p|\n", str);
	printf(" Your printf returned : %i\nTheir printf returned : %i\n", a, b);
	return (0);
}
