/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_evaluator_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juzoanya <juzoanya@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/20 23:04:38 by juzoanya          #+#    #+#             */
/*   Updated: 2022/02/21 10:48:59 by juzoanya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_flags	ft_eval_flag(const char *format, t_flags *flag, int i)
{
	if (format[i] == '-')
		flag->dash = 1;
	if (format[i] == '0')
		flag->zero = 1;
	if (format[i] == '.')
		flag->dot = 1;
	if (format[i] == '#')
		flag->hash = 1;
	if (format[i] == ' ')
		flag->space = 1;
	if (format[i] == '+')
		flag->sign = 1;
	while (ft_isdigit(format[++i]))
		flag->digit = ft_atoi(&format[i]);
	return (*flag);
}
