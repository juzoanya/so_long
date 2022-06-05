/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juzoanya <juzoanya@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/20 18:54:52 by juzoanya          #+#    #+#             */
/*   Updated: 2022/02/21 11:16:30 by juzoanya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

unsigned int	ft_intlen(int n)
{
	int	i;

	i = 0;
	if (n == 0)
		return (1);
	if (n < 0)
		i++;
	while (n)
	{
		n = n / 10;
		i++;
	}
	return (i);
}

int	ft_putunbr(unsigned int n)
{
	int	count;

	count = 0;
	if (n >= 10)
	{
		count += ft_putunbr(n / 10);
		count += ft_putunbr(n % 10);
	}
	if (n <= 9)
		count += ft_putchar(n + '0');
	return (count);
}

int	ft_putnbr(long int n)
{
	int	count;

	count = ft_intlen(n);
	if (n < 0)
	{
		ft_putchar('-');
		n *= -1;
	}
	if (n <= 9)
		ft_putchar(n + '0');
	else
	{
		ft_putnbr(n / 10);
		ft_putnbr(n % 10);
	}
	return (count);
}

int	ft_putptr(unsigned long int n)
{
	int			count;
	int			temp;
	const char	base[16] = "0123456789abcdef";

	count = 0;
	if (n > 15)
		count += ft_putptr(n / 16);
	temp = n % 16;
	count += ft_putchar(base[temp]);
	return (count);
}

int	ft_puthex(unsigned int n, int cap)
{
	int			count;
	int			temp;
	const char	base[16] = "0123456789ABCDEF";

	count = 0;
	if (n > 15)
		count += ft_puthex(n / 16, cap);
	temp = n % 16;
	if (cap == 0)
		count += ft_putchar(ft_tolower(base[temp]));
	else
		count += ft_putchar(base[temp]);
	return (count);
}
