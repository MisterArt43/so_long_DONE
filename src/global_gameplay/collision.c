/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collision.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abucia <abucia@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/31 06:12:44 by abucia            #+#    #+#             */
/*   Updated: 2022/06/02 05:01:44 by abucia           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../include/header.h"

int	align_colision(t_animation *txt)
{
	if (txt->dir == 'e')
		txt->futur_pos.x -= 1;
	else if (txt->dir == 'o')
		txt->futur_pos.x += 1;
	else if (txt->dir == 'n')
		txt->futur_pos.y += 1;
	else if (txt->dir == 's')
		txt->futur_pos.y -= 1;
	else if (!(txt->calc_pos.x < txt->the_map.l
			&& txt->calc_pos.y < txt->the_map.h && txt->calc_pos.x >= 0
			&& txt->calc_pos.y >= 0))
		return (0);
	else
		return (0);
	return (1);
}

t_animation	*colision(t_animation *txt, t_map *map, int i)
{
	while (map->map[txt->calc_pos.y][txt->calc_pos.x] == '1' && ++i)
	{
		txt->calc_pos.x = ((txt->pos.x + (DIM / 2) + txt->calcy
					+ txt->futur_pos.x) / 96) % map->l;
		txt->calc_pos.y = ((txt->pos.y + (DIM / 2) + txt->calcx
					+ txt->futur_pos.y + 20) / 96) % map->h;
		if (!align_colision(txt))
			break ;
		if (i > map->l * 96 || i > map->h * 96)
		{
			txt->pos = init_t_pos(0, 0);
			txt->futur_pos = init_t_pos(0, 0);
			break ;
		}
	}
	if (txt->futur_pos.x > 0 || txt->futur_pos.y > 0 || txt->futur_pos.y < 0
		|| txt->futur_pos.x < 0)
	{
		txt->step++;
		ft_putstr("step : ");
		ft_putnbr(txt->step);
		ft_putstr("\n");
	}
	return (txt);
}
