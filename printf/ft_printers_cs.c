/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printers_cs.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juzoanya <juzoanya@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/23 17:16:41 by juzoanya          #+#    #+#             */
/*   Updated: 2022/02/21 11:49:29 by juzoanya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_char(va_list args, t_flags *flag)
{
	char	c;
	int		n;
	int		count;

	count = 0;
	c = va_arg(args, int);
	count += ft_putchar(c);
	if (flag->dash == 1 && flag->digit > 0)
	{
		n = flag->digit - 1;
		while (n != 0)
		{
			count += ft_putchar(' ');
			n--;
		}
	}
	return (count);
}

int	ft_print_str(va_list args, t_flags *flag)
{
	int		i;
	int		count;
	char	*str;

	i = 0;
	count = 0;
	str = va_arg(args, char *);
	if (!str)
		str = "(null)";
	if (flag->space == 1 && flag->digit > 0)
	{
		while (flag->digit != 0)
		{
			count += ft_putchar(' ');
			flag->digit--;
		}
	}
	while (str[i])
	{
		count += ft_putchar(str[i]);
		i++;
	}
	return (count);
}
