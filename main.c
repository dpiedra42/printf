/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpiedra <dpiedra@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/16 17:16:20 by dpiedra           #+#    #+#             */
/*   Updated: 2020/01/20 17:10:48 by dpiedra          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int main()
{
    char c;
	char *str;

	c = 'd';
	str = "test printf";
	printf("CONVERSION DE STRING (s)\n");
	printf("1 : %s\n", str);
    printf("2 : %-12s\n", str);
    printf("3 : %.s\n", str);
    printf("4 : %.4s\n", str);
    printf("5 : %*s\n", 20, str);
    printf("6 : %12s\n", str);
    printf("7 : %015s\n", str);
    printf("8 : %.14s\n", str);
    printf("9 : %.017s\n", str);
    printf("10 : %*s\n", 15, str);
    printf("11 : %15s\n", str);
    printf("12 : %0s\n", str);
    printf("13 : %.0s\n\n", str);
    return (0);
}

// int     main()
// {
//     char c;
//     char *str; 
//     int deci;
//     unsigned int unsi;
//     int hexa; 
//     unsigned int uhexa;
// ​
//     c = 'd';
//     str = "test printf";
//     int a = 12;
//     deci = 12;
//     unsi = 10;
//     hexa = 1;
//     uhexa = 5;
// ​
//     printf("CONVERSION DE CHAR (c)\n");
//      ft_printf("1 : %c\n", c);
//      printf("1 : %c\n", c);
//      ft_printf("2 : %-c\n", c);
//      printf("2 : %-c\n", c);
//      ft_printf("3 : %-12c\n", c);
//      printf("3 : %-12c\n", c);
//      ft_printf("4 : %*c\n", 5, c);
//      printf("4 : %*c\n", 5, c);
//      ft_printf("5 : %------c\n", c);
//      printf("5 : %------c\n", c);
//      ft_printf("6 : %-----5c\n", c);
//      printf("6 : %-----5c\n", c);
//      ft_printf("7 : %7c\n", c);
//      printf("7 : %7c\n", c);
//      ft_printf("8 : %-10*c\n", 5, c);
//      printf("8 : %-10*c\n", 5, c);
//      ft_printf("9 : %0c\n", c);
//      printf("9 : %0c\n", c);
// ​
//     printf("CONVERSION DE STRING (s)\n");
//     printf("1 : %s\n", str);
//     printf("2 : %-12s\n", str);
//     printf("3 : %.s\n", str);
//     printf("4 : %.4s\n", str);
//     printf("5 : %*s\n", 20, str);
//     printf("6 : %12s\n", str);
//     printf("7 : %015s\n", str);
//     printf("8 : %.14s\n", str);
//     printf("9 : %.017s\n", str);
//     printf("10 : %*s\n", 15, str);
//     printf("11 : %15s\n", str);
//     printf("12 : %0s\n", str);
//     printf("13 : %.0s\n\n", str);
// ​
//     printf("CONVERSION DE POINTEUR (p)\n");
//     printf("1 : %p\n", &str);
//     printf("2 : %-p\n", &str);
//     printf("3 : %-45p\n", &str);
//     printf("4 : %45p\n", &str);
//     printf("5 : %045p\n", &str);
//     printf("6 : %.45p\n", &str);
//     printf("7 : %*p\n", 15, &str);
//     printf("8 : %0p\n", &str);
//     printf("9 : %.0p\n", &str);
//     printf("10 : %-------p\n", &str);
//     printf("11 : %-----45p\n", &str);
//     printf("12 : %-45*p\n", 12, &str);
//     printf("13 : %p\n", &a);
//     printf("14 : %p\n\n", &deci);
// ​
//     printf("CONVERSION D'ENTIER RELATIF (d, i)\n");
//     printf("1 : %d\n", deci);
//     printf("2 : %-d\n", deci);
//     printf("3 : %-10d\n", deci);
//     printf("4 : %0d\n", deci);
//     printf("5 : %04d\n", deci);
//     printf("6 : %.12d\n", deci);
//     printf("7 : %.0d\n", deci);
//     printf("8 : %*d\n", 5, deci);
//     printf("9 : %*d\n\n", 5, deci);
// ​
//     printf("1bis : %i\n", deci);
//     printf("2bis : %-i\n", deci);
//     printf("3bis : %-10i\n", deci);
//     printf("4bis : %0i\n", deci);
//     printf("5bis : %04i\n", deci);
//     printf("6bis : %.12i\n", deci);
//     printf("7bis : %.0i\n", deci);
//     printf("8bis : %*i\n\n", 5, deci);
// ​
//     printf("CONVERSION D'ENTIER NATUREL (unsigned - u)\n");
//     printf("1 : %u\n", unsi);
//     printf("2 : %-u\n", unsi);
//     printf("3 : %-10u\n", unsi);
//     printf("4 : %0u\n", unsi);
//     printf("5 : %04u\n", unsi);
//     printf("6 : %.12u\n", unsi);
//     printf("7 : %.0u\n", unsi);
//     printf("8 : %*u\n\n", 5, unsi);
// ​
//     printf("CONVERSION D'ENTIER EXPRIME EN HEXADECIMAL(x)\n");
//     printf("1 : %x\n\n", hexa);
// ​
//     printf("CONVERSION D'UNSIGNED EXPRIME EN HEXADECIMAL(X)\n");
//     printf("1 : %X\n\n", uhexa);
// }