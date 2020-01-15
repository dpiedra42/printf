/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpiedra <dpiedra@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/13 18:29:58 by deannapiedr       #+#    #+#             */
/*   Updated: 2020/01/15 15:55:04 by dpiedra          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINTF_H
# define PRINTF_H

# include <stdio.h>
# include <stdarg.h>
# include <unistd.h>

typedef struct		s_list
{
	int	zero;
	int minus;
	int width;
	int period;
	int precision;
	int	minimum;
}					t_list;

int ft_printf(const char *, ...);
int	ft_printchar(char c, int rtn);
int	ft_isdigit(int c);

#endif