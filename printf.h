/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deannapiedra <deannapiedra@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/16 17:16:44 by dpiedra           #+#    #+#             */
/*   Updated: 2020/02/07 13:30:07 by deannapiedr      ###   ########.fr       */
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
	int			zero;
	int			minus;
	int			width;
	int			period;
	int			precision;
}				t_flag;

int				ft_printf(const char *str, ...);
int				ft_new_putchar(char c, int rtn);
t_flag			ft_start_flags(t_flag flags);
t_flag			ft_make_flags(const char *str, t_flag flags, va_list args);
int				ft_isflag(char c);
t_flag			ft_sort_flag(char c, t_flag flags, va_list args);
int				ft_isdigit(int c);
t_flag			ft_arg_flags(char c, t_flag flags, va_list args);
int				ft_find_conv(const char *str, va_list args, t_flag flags);
int				ft_c_conv(va_list args, t_flag flags);
void			ft_putchar_fd(char c, int fd);
int				ft_fix_field(int flag, char c);
int				ft_str_conv(va_list args, t_flag flags);
size_t			ft_strlen(const char *str);
int				ft_str_width(t_flag flags, char *str, int count);
int				ft_str_precision(t_flag flags, char *str, int count);
int				ft_neg_precision(t_flag flags, char *str, int count);
void			ft_putstr_fd(char *s, int fd);
int				ft_signed_conv(va_list args, t_flag flags);
int				ft_find_count(int decimal);
int				ft_signed_flags(t_flag flags, int decimal, int sign, int count);
int				ft_signed_precision(t_flag flags, int sign, int count);
int				ft_signed_width(t_flag flags, int sign, int count);
void			ft_putnbr_fd(int n, int fd);
int				ft_unsigned_conv(va_list args, t_flag flags);
int				ft_find_ucount(unsigned int nbr);
int				ft_unsigned_width(t_flag flags, int count);
void			ft_putunbr_fd(unsigned int n, int fd);
int				ft_unsigned_precision(t_flag flags, int count);
int				ft_unsigned_flags(t_flag flags, unsigned int nbr, int count);
int				ft_hexa_conv(va_list args, t_flag flags, int x);
char			*ft_uitoa_base(unsigned int nbr, int base, int x);
int				ft_hexa_flags(t_flag flags, char *str, int len);
int				ft_ptr_conv(va_list args, t_flag flags);
char			*ft_longitoa_base(unsigned long long nbr, int base);
int				ft_ptr_flags(t_flag flags, char *str, int len);
int				ft_percent_conv(t_flag flags);

#endif
