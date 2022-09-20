/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abucia <abucia@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/31 06:06:02 by abucia            #+#    #+#             */
/*   Updated: 2022/06/02 09:08:28 by abucia           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../include/header.h"

int	manage_rgb(int keycode, t_animation *txt)
{
	if (keycode == K_LINUX_R)
	{
		if (txt->r > 256)
			txt->r = 0;
		else
			txt->r++;
		return (1);
	}
	else if (keycode == K_LINUX_G)
	{
		if (txt->g > 256)
			txt->g = 0;
		else
			txt->g++;
		return (1);
	}
	else if (keycode == K_LINUX_B)
	{
		if (txt->b > 256)
			txt->b = 0;
		else
			txt->b++;
		return (1);
	}
	return (0);
}

void	manage_theme(int keycode, t_animation *txt)
{
	if (keycode == PV_3)
	{
		txt->r = 176;
		txt->g = 202;
		txt->b = 203;
	}
	else if (keycode == PV_2)
	{
		txt->r = 206;
		txt->g = 203;
		txt->b = 154;
	}
	else if (keycode == PV_1)
	{
		txt->r = 103;
		txt->g = 221;
		txt->b = 47;
	}
	else if (keycode == PV_0)
	{
		txt->r = 0;
		txt->g = 0;
		txt->b = 0;
	}
}

int	manage_mov(int keycode, t_animation *txt)
{
	if (keycode == K_DN || keycode == K_S)
	{
		txt->futur_pos.y += MOV;
		txt->dir = 's';
	}
	else if (keycode == K_LT || keycode == K_A)
	{
		txt->futur_pos.x -= MOV;
		txt->dir = 'o';
	}
	else if (keycode == K_UP || keycode == K_W)
	{
		txt->futur_pos.y -= MOV;
		txt->dir = 'n';
	}
	else if (keycode == K_RT || keycode == K_D)
	{
		txt->futur_pos.x += MOV;
		txt->dir = 'e';
	}
	else
		return (0);
	return (1);
}

void	manage_spectator(int keycode, t_animation *txt)
{
	if (keycode == K_V)
	{
		if (txt->visible == 1)
			txt->visible = 0;
		else
		{
			txt->visible = 1;
			sort_animation(&txt->the_map, txt);
		}
	}
}
