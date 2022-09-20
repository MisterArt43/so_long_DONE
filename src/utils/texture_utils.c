/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abucia <abucia@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/31 06:00:17 by abucia            #+#    #+#             */
/*   Updated: 2022/05/31 06:00:19 by abucia           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../include/header.h"

char	*ft_test_pos(int x, int y, t_map map, char a)
{
	char	c;

	c = map.map[y][x];
	if ((a == '0' && (c == 'P' || c == 'E' || c == 'C')) || c == a)
		return ("1");
	return ("0");
}

int	try(char *src, const char *str, int i)
{
	while (str[++i])
		if (str[i] != 'x' && src[i] != str[i])
			return (0);
	return (1);
}

void	change_exit(t_animation *txt)
{
	t_pos	v;

	v.x = -1;
	while (++v.x < txt->the_map.l)
	{
		v.y = -1;
		while (++v.y < txt->the_map.h)
			if (txt->the_map.map[v.y][v.x] == 'E')
				my_mlx_img_put(&txt->layer, txt->exit[1], v);
	}
	txt->replace = 1;
}

void	put_to_img(int nb, int *pix, t_animation txt, int h)
{
	if (nb == 0)
	{
		mlx_put_image_to_window(txt.mlx, txt.mlx_win, txt.nu[0].img, *pix, h);
		*pix -= 16;
		return ;
	}
	while (nb)
	{
		mlx_put_image_to_window(txt.mlx, txt.mlx_win, txt.nu[nb % 10].img,
			*pix, h);
		*pix -= 16;
		nb /= 10;
		if (*pix < 0)
			break ;
	}
}

void	my_mlx_put_nb(int nb, int pix, t_animation txt, int h)
{
	put_to_img(nb, &pix, txt, h);
	mlx_put_image_to_window(txt.mlx, txt.mlx_win, txt.nu[10].img, DIM - 48, 42);
	pix = DIM - 64;
	put_to_img(txt.the_map.nb_collect, &pix, txt, 42);
	mlx_put_image_to_window(txt.mlx, txt.mlx_win, txt.nu[11].img, pix, 42);
	pix -= 16;
	put_to_img(txt.score, &pix, txt, 42);
}
