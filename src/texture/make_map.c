/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abucia <abucia@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/31 05:51:41 by abucia            #+#    #+#             */
/*   Updated: 2022/06/02 05:16:43 by abucia           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../include/header.h"

char	***pointer_tab(t_animation *txt, t_data *data, int i, t_pos v)
{
	char	***p;

	p = malloc(sizeof(char **) * (txt->h_build));
	if (!p && i == 0)
		er_pointer_tab(txt, i, init_t_pos(v.x - 1, v.y - 1),
			"Error occurred while making the layer");
	while (v.x != txt->h_build)
	{
		p[v.x] = malloc(sizeof(char *) * (txt->l_build));
		if (!p[v.x])
			er_pointer_tab(txt, i, init_t_pos(v.x, txt->l_build - 1),
				"Error occurred while making the layer");
		v.y = 0;
		while (v.y != txt->l_build)
		{
			p[v.x][v.y] = data->addr + (v.x * data->line_l + v.y * data->bpp);
			if (p[v.x][v.y][0] == 0 && p[v.x][v.y][1] == 0
					&& p[v.x][v.y][2] == 0 && p[v.x][v.y][3] == 0)
				p[v.x][v.y][3] = -1;
			v.y++;
		}
		v.x++;
	}
	return (p);
}

t_data	create_image(t_animation *txt, int i)
{
	t_data	new_layer;

	new_layer.img = mlx_new_image(txt->mlx, txt->l_build, txt->h_build);
	if (!new_layer.img)
	{
		if (i == 1)
			mlx_destroy_image(txt->mlx, txt->map.img);
		er_txt(12, *txt, "Error, unable to create a new layer");
	}
	new_layer.addr = mlx_get_data_addr(new_layer.img, &new_layer.bpp,
			&new_layer.line_l, &new_layer.endian);
	new_layer.bpp /= 8;
	return (new_layer);
}

void	build_map(t_map map, t_animation *txt)
{
	t_pos	v;

	v = init_t_pos(-1, -1);
	txt->l_build = (map.l) * txt->wall[0].h;
	txt->h_build = (map.h) * txt->wall[0].w;
	txt->map = create_image(txt, 0);
	txt->layer = create_image(txt, 1);
	while (++v.y < map.h)
	{
		while (++v.x < map.l)
			ft_sort(v, map, txt);
		v.x = -1;
	}
	txt->tab_layer_p = malloc(sizeof(char ***) * NB_LAYER);
	if (!txt->tab_layer_p)
	{
		mlx_destroy_image(txt->mlx, txt->map.img);
		er_txt(12, *txt, "Error, unable to create a new layer");
	}
	txt->tab_layer_p[0] = pointer_tab(txt, &txt->map, 0, init_t_pos(0, 0));
	txt->tab_layer_p[1] = pointer_tab(txt, &txt->layer, 1, init_t_pos(0, 0));
}
