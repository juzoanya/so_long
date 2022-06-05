/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juzoanya <juzoanya@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 10:57:31 by juzoanya          #+#    #+#             */
/*   Updated: 2022/02/21 11:17:07 by juzoanya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>
# include "libft/libft.h"

typedef struct s_flags
{
	int		dash;
	int		zero;
	int		dot;
	int		hash;
	int		space;
	int		sign;
	int		digit;
}				t_flags;

int				ft_putchar(int c);
int				ft_eval_specifier(const char *format, va_list args,
					t_flags *flag, int i);
t_flags			ft_eval_flag(const char *format, t_flags *flag, int i);
int				ft_printf(const char *format, ...);
int				ft_vsprint(const char *format, va_list args, int count);
int				ft_print_char(va_list args, t_flags *flag);
int				ft_print_str(va_list args, t_flags *flag);
int				ft_print_int(va_list args, t_flags *flag);
int				ft_print_unsigned(va_list args);
int				ft_print_ptr(va_list args);
int				ft_print_hex(va_list args, t_flags *flag, int cap);
int				ft_putnbr(long int n);
int				ft_putunbr(unsigned int n);
int				ft_putptr(unsigned long int n);
int				ft_puthex(unsigned int n, int cap);
unsigned int	ft_intlen(int n);

#endif