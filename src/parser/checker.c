/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abucia <abucia@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/31 05:40:56 by abucia            #+#    #+#             */
/*   Updated: 2022/05/31 05:40:57 by abucia           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../include/header.h"

t_map	char_checker(t_map map, int i, int j)
{
	if ((i == 0 || i == map.h - 1 || j == 0 || j == map.l - 1)
		&& map.map[i][j] != '1')
		free_build_map(map, map.h,
			"error, map is not surronded by wall\n");
	else if (map.map[i][j] == 'P')
	{
		map.player.x = i;
		map.player.y = j;
		map.nb_player++;
	}
	else if (map.map[i][j] == 'E')
		map.nb_exit++;
	else if (map.map[i][j] == 'C')
		map.nb_collect++;
	else if (map.map[i][j] == '1')
		map.nb_wall++;
	else if (map.map[i][j] == '0')
		map.nb_void++;
	else
		free_build_map(map, map.h, "error, invalid character in the map\n");
	return (map);
}

t_map	map_checker(t_map map, int i, int j)
{
	while (map.map[i])
	{
		while (map.map[i][j])
		{
			map = char_checker(map, i, j);
			j++;
		}
		j = 0;
		i++;
	}
	if (map.nb_collect < 1)
		free_build_map(map, map.h,
			"error, invalid number of collectable (at least 1)\n");
	if (map.nb_exit < 1)
		free_build_map(map, map.h,
			"error, invalid number of exit (at least 1)\n");
	if (map.nb_player < 1)
		free_build_map(map, map.h,
			"error, invalid number of player (at least 1)\n");
	return (map);
}
