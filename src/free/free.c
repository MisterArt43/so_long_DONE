/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abucia <abucia@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 10:07:22 by abucia            #+#    #+#             */
/*   Updated: 2022/06/02 05:04:21 by abucia           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../include/header.h"

void	free_p_tab(char ***p, t_pos v)
{
	int	vp;

	vp = v.x;
	while (vp != -1)
	{
		free(p[vp]);
		vp -= 1;
	}
	free(p);
}

void	er_cam_pointer_tab(t_animation *txt, t_pos v)
{
	free_p_tab(txt->tab_layer_p[NB_LAYER - 1], v);
}

void	er_pointer_tab(t_animation *txt, int i, t_pos v, char *str)
{
	if (i == 0)
	{
		free_p_tab(txt->tab_layer_p[0], v);
		mlx_destroy_image(txt->mlx, txt->layer.img);
	}
	else if (i == 1)
	{
		free_p_tab(txt->tab_layer_p[1], v);
		free_p_tab(txt->tab_layer_p[0], init_t_pos(txt->h_build,
				txt->l_build));
		mlx_destroy_image(txt->mlx, txt->layer.img);
	}
	else
	{
		free_p_tab(txt->tab_layer_p[0], init_t_pos(txt->h_build -1,
				txt->l_build));
		free_p_tab(txt->tab_layer_p[1], init_t_pos(txt->h_build -1,
				txt->l_build));
		mlx_destroy_image(txt->mlx, txt->layer.img);
	}
	mlx_destroy_image(txt->mlx, txt->map.img);
	free(txt->tab_layer_p);
	er_txt(12, *txt, str);
}

int	stop(t_animation *txt)
{
	t_pos	i;

	i = init_t_pos(DIM - 1, DIM - 1);
	free_p_tab(txt->tab_layer_p[NB_LAYER - 1], i);
	mlx_destroy_image(txt->mlx, txt->the_map.img.img);
	txt->the_map.end_game = 3;
	er_pointer_tab(txt, 2, i, "thanks for playing.");
	return (0);
}
