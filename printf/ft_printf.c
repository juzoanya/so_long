/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juzoanya <juzoanya@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/21 13:57:18 by juzoanya          #+#    #+#             */
/*   Updated: 2022/02/21 11:45:49 by juzoanya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_flag_init(t_flags *flag)
{
	flag->dash = 0;
	flag->zero = 0;
	flag->dot = 0;
	flag->hash = 0;
	flag->space = 0;
	flag->sign = 0;
	flag->digit = -1;
}

static int	ft_is_flag(int c)
{
	return ((c == '.') || (c == '-') || (c == '0')
		|| (c == '#') || (c == ' ') || (c == '+'));
}

static int	ft_is_specifier(int c)
{
	return ((c == 'c') || (c == 's') || (c == 'p') || (c == 'd')
		|| (c == 'i') || (c == 'u') || (c == 'x') || (c == 'X') || (c == '%'));
}

int	ft_vsprint(const char *format, va_list args, int count)
{
	int		i;
	t_flags	flag;

	i = 0;
	count = 0;
	ft_flag_init(&flag);
	while (format[i])
	{
		if (format[i] == '%')
		{
			if (ft_is_flag(format[++i]))
			{
				flag = ft_eval_flag(format, &flag, i);
				i++;
			}
			while (ft_isdigit(format[i]))
				i++;
			if (ft_is_specifier(format[i]))
				count += ft_eval_specifier(format, args, &flag, i);
		}
		else
			count += write(1, &format[i], 1);
		i++;
	}
	return (count);
}

int	ft_printf(const char *format, ...)
{
	int		count;
	va_list	args;

	count = 0;
	va_start(args, format);
	count = ft_vsprint(format, args, count);
	va_end(args);
	return (count);
}

// #include <stdio.h>
// #include <limits.h>
// int	main(void)
// {
// 	printf("%d", ft_printf("%1s", ""));
// 	printf("\n");
// 	printf("%d", printf("%1s", ""));
// 	printf("\n______________\n");
// 	printf("%d", ft_printf("%-1s", ""));
// 	printf("\n");
// 	printf("%d", printf("%-1s", ""));
// 	printf("\n______________\n");
// }