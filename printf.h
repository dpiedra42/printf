/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpiedra <dpiedra@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/16 17:16:44 by dpiedra           #+#    #+#             */
/*   Updated: 2020/01/20 17:10:47 by dpiedra          ###   ########.fr       */
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
	int	minus;
	int	width;
	int	period;
	int	precision;
}				t_list;

int		ft_printf(const char *, ...);
int		ft_new_putchar(char c, int rtn);
t_list	ft_start_flags(t_list flags);
t_list	ft_make_flags(const char *str, t_list flags, va_list args);
int		ft_isflag(char c);
t_list	ft_sort_flag(char c, t_list flags, va_list args);
int		ft_isdigit(int c);
t_list	ft_arg_flags(char c, t_list flags, va_list args);
int		ft_find_conv(const char *str, va_list args, t_list flags);
int		ft_c_conv(va_list args, t_list flags);
void	ft_putchar_fd(char c, int fd);
int		ft_fix_field(int flag, char c);
int		ft_str_conv(va_list args, t_list flags);

#endif