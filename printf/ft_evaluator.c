/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_evaluator.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juzoanya <juzoanya@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/20 19:01:05 by juzoanya          #+#    #+#             */
/*   Updated: 2022/02/19 11:07:25 by juzoanya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_eval_specifier(const char *format, va_list args, t_flags *flag, int i)
{
	int	count;

	count = 0;
	if (format[i] == 'c')
		count += ft_print_char(args, flag);
	else if (format[i] == 'd' || format[i] == 'i')
		count += ft_print_int(args, flag);
	else if (format[i] == 's')
		count += ft_print_str(args, flag);
	else if (format[i] == 'u')
		count += ft_print_unsigned(args);
	else if (format[i] == 'p')
		count += ft_print_ptr(args);
	else if (format[i] == 'x')
		count += ft_print_hex(args, flag, 0);
	else if (format[i] == 'X')
		count += ft_print_hex(args, flag, 1);
	else if (format[i] == '%')
		count += ft_putchar('%');
	return (count);
}
