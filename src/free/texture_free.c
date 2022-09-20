/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture_free.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abucia <abucia@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/31 06:22:06 by abucia            #+#    #+#             */
/*   Updated: 2022/06/02 08:57:45 by abucia           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../include/header.h"

void	free_build_map(t_map map, int current_h, char *er)
{
	while (current_h != -1)
	{
		free(map.map[current_h]);
		current_h--;
	}
	free(map.map);
	if (map.end_game == 3)
	{
		ft_putstr(er);
		exit(0);
	}
	ft_ermap(er);
}

int	my_destroy_img(void *mlx, t_data *data, int nb)
{
	while (nb != -1)
	{
		if (data[nb].img)
			mlx_destroy_image(mlx, data[nb].img);
		nb--;
	}
	free(data);
	return (1);
}

void	er_txt(int i, t_animation txt, char *er)
{
	if (i >= 0 && my_destroy_img(txt.mlx, txt.left, 5) && i >= 1
		&& my_destroy_img(txt.mlx, txt.right, 5) && i >= 2
		&& my_destroy_img(txt.mlx, txt.up, 5) && i >= 3
		&& my_destroy_img(txt.mlx, txt.down, 5) && i >= 4
		&& my_destroy_img(txt.mlx, txt.stand_l, 0) && i >= 5
		&& my_destroy_img(txt.mlx, txt.stand_r, 0) && i >= 6
		&& my_destroy_img(txt.mlx, txt.stand_u, 0) && i >= 7
		&& my_destroy_img(txt.mlx, txt.stand_d, 0) && i >= 8
		&& my_destroy_img(txt.mlx, txt.floor, 46) && i >= 9
		&& my_destroy_img(txt.mlx, txt.wall, 46) && i >= 10
		&& my_destroy_img(txt.mlx, txt.obj, 1) && i >= 11
		&& my_destroy_img(txt.mlx, txt.nu, 11) && i >= 12
		&& my_destroy_img(txt.mlx, txt.exit, 1))
		i = 0;
	if (txt.the_map.end_game >= 1)
	{
		if (txt.the_map.end_game >= 2)
			mlx_destroy_window(txt.mlx, txt.mlx_win);
	}
	free_build_map(txt.the_map, txt.the_map.h, er);
}

int	txt_stop_all(t_animation txt, t_data *side, int nb)
{
	my_destroy_img(txt.mlx, side, nb);
	return (1);
}
