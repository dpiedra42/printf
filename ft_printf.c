/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deannapiedra <deannapiedra@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/13 17:49:21 by deannapiedr       #+#    #+#             */
/*   Updated: 2020/01/08 18:53:38 by deannapiedr      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdarg.h>

int ft_printf(const char *str, ...)
{
    va_list args;
    int i;
    int rtn;

    i = 0;
    rtn = 0;
    va_start(args, str);
    while (str[i] != '\0')
    {
        if (str[i] != '%')
        {
            write(1, &str[i], 1);
            i++;
            rtn++;
        }
       else if (str[i] == '%' && str[i + 1] != '\0')
       {

       }
       i++;
    }
    return(rtn); 
}