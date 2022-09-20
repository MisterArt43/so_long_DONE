/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abucia <abucia@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/13 21:35:47 by abucia            #+#    #+#             */
/*   Updated: 2022/06/02 05:16:14 by abucia           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../include/header.h"

void	make_img(t_animation *txt, t_map *map)
{
	t_pos	i;

	i.x = 0;
	if (txt->calcx == 0)
	{
		map->img.h = DIM;
		map->img.w = DIM;
		map->img.img = mlx_new_image(txt->mlx, map->img.h, map->img.w);
		if (!map->img.img)
			exit(0);
		map->img.addr = mlx_get_data_addr(map->img.img, &map->img.bpp,
				&map->img.line_l, &map->img.endian);
		map->img.bpp /= 8;
		txt->calcx = map->player.x * txt->floor->h + (txt->floor->h
				/ 2 - map->img.h / 2);
		txt->calcy = map->player.y * txt->floor->h + (txt->floor->h
				/ 2 - map->img.w / 2);
		optimize_pos_calc(txt, map, i);
	}
	if (map->nb_collect == txt->score && txt->replace == 0)
		change_exit(txt);
	my_camera(&map->img, *txt);
	sort_animation(map, txt);
	mlx_put_image_to_window(txt->mlx, txt->mlx_win, map->img.img, 0, 0);
	my_mlx_put_nb(txt->step, DIM - 27, *txt, 16);
}

t_animation	init_game(void)
{
	t_animation	txt;

	txt.the_map.end_game = 0;
	txt.step = 0;
	txt.calc_pos = init_t_pos(0, 0);
	txt.replace = 0;
	txt.visible = 1;
	txt.score = 0;
	txt.dir = 'd';
	txt.futur_pos.x = 0;
	txt.futur_pos.y = 0;
	txt.anime_time = ATIME;
	txt.last_anime = 0;
	txt.pos.x = 0;
	txt.pos.y = 0;
	txt.the_map.img.h = 0;
	txt.r = 0;
	txt.g = 0;
	txt.b = 0;
	txt.calcx = 0;
	txt.calcy = 0;
	return (txt);
}

int	main(int argc, char **argv)
{
	t_animation	txt;

	if (argc == 2)
	{
		txt = init_game();
		txt.the_map = map_parser(argv[1]);
		txt.mlx = mlx_init();
		if (!txt.mlx)
			er_pointer_tab(&txt, 2, init_t_pos(txt.l_build, txt.h_build),
				"Error, mlx failed while initiating\n");
		txt.the_map.end_game = 1;
		txt = init_texture(txt, txt.the_map);
		make_img(&txt, &txt.the_map);
		mlx_hook(txt.mlx_win, 2, 1L << 0, key_press, &txt);
		mlx_hook(txt.mlx_win, 17, 0L, stop, &txt);
		mlx_loop(txt.mlx);
	}
	else
		ft_ermap("the map arguments is missing\n");
}
