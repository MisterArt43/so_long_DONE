/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_texture.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abucia <abucia@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/31 06:00:47 by abucia            #+#    #+#             */
/*   Updated: 2022/05/31 06:00:48 by abucia           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../include/header.h"

void	ft_put_wall1(t_pos v, t_map map, t_animation *txt, t_data *src)
{
	int					i;
	static const char	*tests[] = {"11111111", "11x10x0x", "x1101x0x",
		"x0x1011x", "x0x01x11", "11111x0x", "x1101x11", "11x1011x", "x0x11111",
		"x0x11x0x", "x1x00x1x", "x1x00x0x", "x0x00x1x", "x0x10x0x", "x0x01x0x",
		"x0x00x0x", "11111110", "11111011", "01111111", "11011111", "11011110",
		"11111010", "01111011", "01011111", "01011011", "01011110", "11011010",
		"01111010", "01011010", "11011011", "01111110", "01111x0x", "11011x0x",
		"x0x11110", "x0x11011", "01x1011x", "x1001x11", "11x1001x", "x1101x10",
		"01011x0x", "x1001x10", "x0x11010", "01x1001x", "01x10x0x", "x1001x0x",
		"x0x1001x", "x0x01x10"};

	i = 0;
	while (!try(map.c, tests[i], -1))
		i++;
	my_mlx_img_put(&txt->map, src[i], v);
	free(map.c);
}

void	ft_get_type(t_pos v, t_map map, t_animation *txt, t_data *src)
{
	map.c = ft_strdup("");
	map.c = ft_freestrjoin(map.c, ft_test_pos(v.x + 1, v.y + 1, map, map.a));
	map.c = ft_freestrjoin(map.c, ft_test_pos(v.x, v.y + 1, map, map.a));
	map.c = ft_freestrjoin(map.c, ft_test_pos(v.x - 1, v.y + 1, map, map.a));
	map.c = ft_freestrjoin(map.c, ft_test_pos(v.x + 1, v.y, map, map.a));
	map.c = ft_freestrjoin(map.c, ft_test_pos(v.x - 1, v.y, map, map.a));
	map.c = ft_freestrjoin(map.c, ft_test_pos(v.x + 1, v.y - 1, map, map.a));
	map.c = ft_freestrjoin(map.c, ft_test_pos(v.x, v.y - 1, map, map.a));
	map.c = ft_freestrjoin(map.c, ft_test_pos(v.x - 1, v.y - 1, map, map.a));
	ft_put_wall1(v, map, txt, src);
}

void	ft_put_border(t_pos v, t_map map, t_animation *txt)
{
	if (v.x == 0)
	{
		if (v.y == 0)
			my_mlx_img_put(&txt->map, txt->wall[18], v);
		else if (v.y == map.h - 1)
			my_mlx_img_put(&txt->map, txt->wall[17], v);
		else
			my_mlx_img_put(&txt->map, txt->wall[6], v);
	}
	else if (v.y == 0)
	{
		if (v.x == map.l - 1)
			my_mlx_img_put(&txt->map, txt->wall[19], v);
		else
			my_mlx_img_put(&txt->map, txt->wall[8], v);
	}
	else if (v.x == map.l - 1)
	{
		if (v.y == map.h - 1)
			my_mlx_img_put(&txt->map, txt->wall[16], v);
		else
			my_mlx_img_put(&txt->map, txt->wall[7], v);
	}
	else if (v.y == map.h - 1)
		my_mlx_img_put(&txt->map, txt->wall[5], v);
}

void	ft_sort(t_pos v, t_map map, t_animation *txt)
{
	my_mlx_img_put(&txt->map, txt->wall[0], v);
	if (!(v.x < 0 || v.x >= map.l || v.y < 0 || v.y >= map.h))
	{
		if (v.x == 0 || v.y == 0 || v.x == map.l - 1 || v.y == map.h - 1)
			ft_put_border(v, map, txt);
		else if (map.map[v.y][v.x] == '1')
		{
			map.a = '1';
			ft_get_type(v, map, txt, txt->wall);
		}
		else
		{
			map.a = '0';
			ft_get_type(v, map, txt, txt->floor);
			if (map.map[v.y][v.x] == 'C')
				my_mlx_img_put(&txt->layer, txt->obj[0], v);
			else if (map.map[v.y][v.x] == 'E')
				my_mlx_img_put(&txt->layer, txt->exit[0], v);
		}
	}
}
