/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_texture.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abucia <abucia@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/14 15:32:42 by abucia            #+#    #+#             */
/*   Updated: 2022/06/02 05:12:50 by abucia           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../include/header.h"

t_data	*init_side(t_animation txt, char *path, int nb_image, int nb_txt)
{
	t_data	*new;
	int		i;
	char	*nb;
	char	*tmp;

	new = malloc(sizeof(t_data) * (nb_image));
	if (!new)
		er_txt(nb_txt, txt, "Error unable to malloc a texture");
	i = 0;
	while (i < nb_image)
	{
		nb = ft_itoa(i + 1);
		tmp = ft_freestrjoin(ft_strjoin(path, nb), EXTENTION);
		new[i].img = mlx_xpm_file_to_image(txt.mlx, tmp, &new[i].w, &new[i].h);
		free(nb);
		free(tmp);
		if (!new[i].img)
			if (txt_stop_all(txt, new, i))
				er_txt(nb_txt, txt, "Error occurred while loading texture");
		new[i].addr = mlx_get_data_addr(new[i].img, &new[i].bpp,
				&new[i].line_l, &new[i].endian);
		new[i].bpp /= 8;
		i++;
	}
	return (new);
}

t_animation	init_texture(t_animation txt, t_map map)
{
	txt.left = init_side(txt, "sprite/p/l_run", 6, 0);
	txt.right = init_side(txt, "sprite/p/r_run", 6, 1);
	txt.up = init_side(txt, "sprite/p/f_run", 6, 2);
	txt.down = init_side(txt, "sprite/p/b_run", 6, 3);
	txt.stand_l = init_side(txt, "sprite/p/l_stand", 1, 4);
	txt.stand_r = init_side(txt, "sprite/p/r_stand", 1, 5);
	txt.stand_u = init_side(txt, "sprite/p/f_stand", 1, 6);
	txt.stand_d = init_side(txt, "sprite/p/b_stand", 1, 7);
	txt.floor = init_side(txt, "sprite/floor/floor", 47, 8);
	txt.wall = init_side(txt, "sprite/wall/wall", 47, 9);
	txt.obj = init_side(txt, "sprite/obj/obj", 2, 10);
	txt.exit = init_side(txt, "sprite/obj/exit", 2, 11);
	txt.nu = init_side(txt, "sprite/obj/number", 12, 12);
	build_map(map, &txt);
	return (txt);
}
