/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juzoanya <juzoanya@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 14:36:19 by juzoanya          #+#    #+#             */
/*   Updated: 2022/06/03 11:49:28 by juzoanya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	err_file_open(void)
{
	ft_printf("File Open Error\n");
	exit(0);
}

void	err_file_close(void)
{
	ft_printf("File Close Error\n");
	exit(0);
}

void	err_extension(void)
{
	ft_printf("Extension Error!\n");
	exit(0);
}

void	err_map_char(void)
{
	ft_printf("Invalid Map Character\n");
	exit(0);
}

void	err_map_shape(void)
{
	ft_printf("Missaligned: Map not a Rectangle!\n");
	exit(0);
}
