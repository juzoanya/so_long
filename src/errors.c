/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juzoanya <juzoanya@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 14:36:19 by juzoanya          #+#    #+#             */
/*   Updated: 2022/06/07 20:14:43 by juzoanya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	err_file_open(void)
{
	ft_putendl_fd("File Open Error!", 1);
	exit(0);
}

void	err_file_close(void)
{
	ft_putendl_fd("File Close Error!", 1);
	exit(0);
}

void	err_extension(void)
{
	ft_putendl_fd("Extension Error!", 1);
	exit(0);
}

void	err_map_char(void)
{
	ft_putendl_fd("Invalid Map Character!", 1);
	exit(0);
}

void	err_map_shape(void)
{
	ft_putendl_fd("Missaligned: Map not a Rectangle!", 1);
	exit(0);
}
