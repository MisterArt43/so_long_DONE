/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abucia <abucia@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/31 06:11:31 by abucia            #+#    #+#             */
/*   Updated: 2022/06/02 05:03:07 by abucia           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../include/header.h"

void	correc_pos(t_animation *txt)
{
	if (txt->pos.x <= txt->l_build - 96 * 0)
		txt->pos.x += txt->l_build + (0) * 2 * txt->floor[0].h;
	else if (txt->pos.x / txt->l_build > 1)
		txt->pos.x -= txt->l_build - (0) * 2 * txt->floor[0].h;
	if (txt->pos.y <= txt->h_build - 96 * 0)
		txt->pos.y += txt->h_build + 0 * txt->floor[0].h;
	else if (txt->pos.y / txt->h_build > 1)
		txt->pos.y -= txt->h_build - 0 * txt->floor[0].h;
}

void	check_pos(t_map *map, t_animation *txt)
{
	txt->calc_pos = init_t_pos(
			((txt->pos.x + (DIM / 2) + txt->calcy + txt->futur_pos.x) / 96)
			% map->l, ((txt->pos.y + (DIM / 2) + txt->calcx
					+ txt->futur_pos.y + 20) / 96) % map->h);
	if (txt->calc_pos.x <= map->l && txt->calc_pos.y <= map->h
		&& txt->calc_pos.x >= 0 && txt->calc_pos.y >= 0 && txt->visible == 1)
	{
		txt = colision(txt, map, 0);
		if (map->map[txt->calc_pos.y][txt->calc_pos.x] == 'C')
		{
			my_mlx_img_put(&txt->layer, txt->obj[1], txt->calc_pos);
			map->map[txt->calc_pos.y][txt->calc_pos.x] = '0';
			txt->score++;
		}
		else if (txt->replace == 1
			&& map->map[txt->calc_pos.y][txt->calc_pos.x] == 'E')
			stop(txt);
	}
	txt->pos = init_t_pos(txt->pos.x + txt->futur_pos.x, txt->pos.y
			+ txt->futur_pos.y);
	correc_pos(txt);
}

void	sort_player(t_animation *txt)
{
	if (txt->visible == 1)
	{
		if (txt->dir == 'n')
			put_player(txt->down[txt->last_anime], *txt);
		else if (txt->dir == 's')
			put_player(txt->up[txt->last_anime], *txt);
		else if (txt->dir == 'e')
			put_player(txt->right[txt->last_anime], *txt);
		else if (txt->dir == 'o')
			put_player(txt->left[txt->last_anime], *txt);
		else if (txt->dir == 'u')
			put_player(txt->stand_u[0], *txt);
		else if (txt->dir == 'd')
			put_player(txt->stand_d[0], *txt);
		else if (txt->dir == 'l')
			put_player(txt->stand_l[0], *txt);
		else if (txt->dir == 'r')
			put_player(txt->stand_r[0], *txt);
	}
}

void	sort_animation(t_map *map, t_animation *txt)
{
	txt->anime_time--;
	if (txt->anime_time < 0)
	{
		txt->anime_time = ATIME;
		txt->last_anime++;
		if (txt->last_anime > 5)
			txt->last_anime = 0;
	}
	if (txt->dir == 'u' || txt->dir == 'l' || txt->dir == 'r'
		|| txt->dir == 'd')
		txt->last_anime = 0;
	check_pos(map, txt);
	sort_player(txt);
	txt->futur_pos = init_t_pos(0, 0);
}
