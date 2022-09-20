/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abucia <abucia@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/31 06:08:31 by abucia            #+#    #+#             */
/*   Updated: 2022/06/02 09:11:36 by abucia           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../include/header.h"

int	key_release(int keycode, t_animation *txt)
{
	if (keycode == K_DN || keycode == K_LT || keycode == K_UP
		|| keycode == K_RT)
	{
		if (keycode == K_DN)
			txt->dir = 'u';
		else if (keycode == K_LT)
			txt->dir = 'l';
		else if (keycode == K_UP)
			txt->dir = 'd';
		else if (keycode == K_RT)
			txt->dir = 'r';
		make_img(txt, &txt->the_map);
	}
	return (0);
}

int	key_press(int keycode, t_animation *txt)
{
	if (keycode == K_LINUX_ESC)
		stop(txt);
	if (manage_rgb(keycode, txt))
	{
		ft_putstr("RGB : ");
		ft_putnbr(txt->r);
		ft_putstr(",");
		ft_putnbr(txt->g);
		ft_putstr(",");
		ft_putnbr(txt->b);
		ft_putstr("\n");
	}
	manage_theme(keycode, txt);
	manage_spectator(keycode, txt);
	if (manage_mov(keycode, txt))
	{
		keycode++;
	}
	make_img(txt, &txt->the_map);
	return (0);
}
