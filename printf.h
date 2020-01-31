/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpiedra <dpiedra@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/16 17:16:44 by dpiedra           #+#    #+#             */
/*   Updated: 2020/01/31 14:23:02 by dpiedra          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINTF_H
# define PRINTF_H

# include <stdio.h>
# include <stdarg.h>
# include <unistd.h>
# include "./libft/libft.h"

typedef struct	s_flag
{
	int	zero;
	int	minus;
	int	width;
	int period;
	int	precision;
}				t_flag;

int		ft_printf(const char *, ...);
int		ft_new_putchar(char c, int rtn);
t_flag	ft_start_flags(t_flag flags);
t_flag	ft_make_flags(const char *str, t_flag flags, va_list args);
int		ft_isflag(char c);
t_flag	ft_sort_flag(char c, t_flag flags, va_list args);
int		ft_isdigit(int c);
t_flag	ft_arg_flags(char c, t_flag flags, va_list args);
int		ft_find_conv(const char *str, va_list args, t_flag flags);
int		ft_c_conv(va_list args, t_flag flags);
void	ft_putchar_fd(char c, int fd);
int		ft_fix_field(int flag, char c);
int		ft_str_conv(va_list args, t_flag flags);
size_t	ft_strlen(const char *str);
int		ft_str_width(t_flag flags, char *str, int count);
int		ft_str_precision(t_flag flags, char *str, int count);
int		ft_neg_precision(t_flag flags, char *str, int count);
void	ft_putstr_fd(char *s, int fd);
int		ft_signed_conv(va_list args, t_flag flags);
void	ft_putnbr_fd(int n, int fd);
int		ft_find_count(int decimal);
// int		ft_unsigned_conv(va_list args, t_flag flags);
// int		ft_find_ucount(unsigned int nbr);
// int		ft_unsigned_field(int count, unsigned int nbr, t_flag flags);
// void	ft_putunbr_fd(unsigned int n, int fd);
// int		ft_unsigned_precision(unsigned int nbr, int count, t_flag flags);
// // int		ft_ptr_conv(va_list args, t_flag flags);

#endif