/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpiedra <dpiedra@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/16 17:16:20 by dpiedra           #+#    #+#             */
/*   Updated: 2020/02/08 13:19:00 by dpiedra          ###   ########.fr       */
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
