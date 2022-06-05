/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printers.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juzoanya <juzoanya@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/20 21:44:46 by juzoanya          #+#    #+#             */
/*   Updated: 2022/02/21 11:21:05 by juzoanya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_int(va_list args, t_flags *flag)
{
	int	n;
	int	count;

	count = 0;
	n = va_arg(args, long int);
	if (flag->sign == 1 && n >= 0)
		count += ft_putchar('+');
	if (flag->space == 1 && n >= 0)
		count += ft_putchar(' ');
	if (flag->zero == 1 && flag->digit > 0)
	{
		while (flag->digit - 1 != 0)
		{
			count += ft_putchar('0');
			flag->digit--;
		}
	}
	count += ft_putnbr(n);
	return (count);
}

int	ft_print_unsigned(va_list args)
{
	unsigned int	n;
	int				count;

	count = 0;
	n = va_arg(args, unsigned int);
	count += ft_putunbr(n);
	return (count);
}

int	ft_print_ptr(va_list args)
{
	unsigned long int	n;
	int					count;

	n = va_arg(args, unsigned long int);
	write(1, "0x", 2);
	count = 2;
	count += ft_putptr(n);
	return (count);
}

int	ft_print_hex(va_list args, t_flags *flag, int cap)
{
	unsigned int	n;
	int				count;

	count = 0;
	n = va_arg(args, unsigned int);
	if (flag->hash == 1 && n > 0)
	{
		if (cap == 0)
			write(1, "0x", 2);
		else
			write(1, "0X", 2);
		count = 2;
		count += ft_puthex(n, cap);
		return (count);
	}
	count += ft_puthex(n, cap);
	return (count);
}
