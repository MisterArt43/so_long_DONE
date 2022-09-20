/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abucia <abucia@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/31 06:00:09 by abucia            #+#    #+#             */
/*   Updated: 2022/05/31 06:00:10 by abucia           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../include/header.h"

void	my_mlx_img_put(t_data *data, t_data src, t_pos v)
{
	char	*dst;
	char	*p;
	t_pos	v_txt;

	v_txt.x = 0;
	while (v_txt.x < src.h)
	{
		v_txt.y = 0;
		while (v_txt.y < src.h)
		{
			p = &*src.addr + (v_txt.y * src.line_l + v_txt.x * src.bpp);
				dst = data->addr + ((v_txt.y + (v.y + (0)) * src.h)
					* data->line_l + (v_txt.x + (v.x + (0)) * src.w)
					* data->bpp);
			dst[0] = p[0];
			dst[1] = p[1];
			dst[2] = p[2];
			dst[3] = p[3];
			v_txt.y++;
		}
		v_txt.x++;
	}
}

void	put_pixel_cam(char ***dst, t_pos v_txt, t_pos neg, t_animation txt)
{
	char	*p;

	p = dst[neg.x][neg.y];
	if (p[3] != -1)
	{
		txt.tab_layer_p[2][v_txt.y][v_txt.x][0] = p[0] + txt.r;
		txt.tab_layer_p[2][v_txt.y][v_txt.x][1] = p[1] + txt.g;
		txt.tab_layer_p[2][v_txt.y][v_txt.x][2] = p[2] + txt.b;
	}
}

void	my_camera(t_data *data, t_animation txt)
{
	t_pos	neg;
	int		i;
	t_pos	v_txt;

	v_txt.y = -1;
	while (++v_txt.y < data->h)
	{
		v_txt.x = -1;
		while (++v_txt.x < data->w)
		{
			neg.x = (txt.pos.y + v_txt.y + txt.calcx) % (txt.h_build);
			neg.y = (txt.pos.x + v_txt.x + txt.calcy) % (txt.l_build);
			if (neg.x < 0)
				neg.x *= -1;
			if (neg.y < 0)
				neg.y *= -1;
			i = -1;
			while (++i < NB_LAYER - 1)
				put_pixel_cam(txt.tab_layer_p[i], v_txt, neg, txt);
		}
	}
}

void	put_player(t_data src, t_animation txt)
{
	char	*p;
	t_pos	mid;
	t_pos	v_txt;

	mid.x = (DIM / 2 - src.w / 2);
	mid.y = (DIM / 2 - src.h * 2 / 3);
	v_txt.x = -1;
	while (++v_txt.x < src.h)
	{
		v_txt.y = -1;
		while (++v_txt.y < src.w)
		{
			p = &*src.addr + (v_txt.y * src.line_l + v_txt.x * (src.bpp));
			if ((int)p[3] != -1)
			{
				txt.tab_layer_p[2][v_txt.y + mid.y][v_txt.x + mid.x][0] = p[0];
				txt.tab_layer_p[2][v_txt.y + mid.y][v_txt.x + mid.x][1] = p[1];
				txt.tab_layer_p[2][v_txt.y + mid.y][v_txt.x + mid.x][2] = p[2];
			}
		}
	}
}

void	optimize_pos_calc(t_animation *txt, t_map *map, t_pos i)
{
	txt->mlx_win = mlx_new_window(txt->mlx, DIM, DIM, "it's been SO_LONG");
	txt->tab_layer_p[NB_LAYER - 1] = malloc(sizeof(char **) * DIM);
	if (!txt->tab_layer_p[NB_LAYER - 1])
		er_cam_pointer_tab(txt, i);
	while (i.x != DIM)
	{
		txt->tab_layer_p[NB_LAYER - 1][i.x] = malloc(sizeof(char *) * DIM);
		if (!txt->tab_layer_p[NB_LAYER - 1][i.x])
			er_cam_pointer_tab(txt, i);
		i.y = 0;
		while (i.y != DIM)
		{
			txt->tab_layer_p[NB_LAYER - 1][i.x][i.y] = map->img.addr
				+ (i.x * map->img.line_l + i.y * map->img.bpp);
			i.y++;
		}
		i.x++;
	}
}
