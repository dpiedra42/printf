/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpiedra <dpiedra@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/16 17:16:44 by dpiedra           #+#    #+#             */
/*   Updated: 2020/01/16 17:16:47 by dpiedra          ###   ########.fr       */
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
	int minus;
	int width;
	int period;
	int precision;
}				t_list;

int		ft_printf(const char *, ...);
int		ft_putchar(char c, int rtn);
t_list	ft_start_flags(t_list flags);
int		ft_isflag(char c);
t_list	ft_arg_flag(const char *str, t_list flags, va_list args);
t_list	ft_make_flags(const char *str, t_list flags, va_list args);
int		ft_isdigit(int c);

#endif