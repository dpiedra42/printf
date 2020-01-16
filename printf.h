/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpiedra <dpiedra@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/13 18:29:58 by deannapiedr       #+#    #+#             */
/*   Updated: 2020/01/16 15:06:11 by dpiedra          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINTF_H
# define PRINTF_H

# include <stdio.h>
# include <stdarg.h>
# include <unistd.h>

typedef struct	s_list
{
	int	zero;
	int minimum;
	int minus;
	int width;
	int period;
	int precision;
}				t_list;

int		ft_printf(const char *, ...);
int		ft_putchar(char c, int rtn);
t_list	ft_start_flags(t_list flags);
int		ft_isflag(char c);
t_list	ft_assign_flag(char s, t_list flags);
t_list	ft_make_flags(const char *str, t_list flags, va_list args);
int		ft_isdigit(int c);

#endif