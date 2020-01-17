/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpiedra <dpiedra@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/16 17:16:44 by dpiedra           #+#    #+#             */
/*   Updated: 2020/01/17 15:11:29 by dpiedra          ###   ########.fr       */
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
	int asterisk;
	int period;
	int precision;
}				t_list;

int		ft_printf(const char *, ...);
int		ft_putchar(char c, int rtn);
t_list	ft_start_flags(t_list flags);
int		ft_isflag(char c);
t_list	ft_make_flags(const char *str, t_list flags, va_list args);
t_list	ft_sort_flag(char c, t_list flags, va_list args);
int		ft_isdigit(int c);
void	ft_find_conv(const char *str, va_list args, t_list flags);
void	ft_treat_cflags(va_list args, t_list flags);
void	ft_c_asterisk(va_list args, t_list flags, int value);

#endif