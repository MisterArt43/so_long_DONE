/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abucia <abucia@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 10:17:26 by abucia            #+#    #+#             */
/*   Updated: 2022/06/02 05:16:55 by abucia           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../include/header.h"

char	*ft_freestrjoin(char *s1, char *s2)
{
	char	*res;
	int		i;
	int		len;

	i = 0;
	len = ft_strlen(s1) + ft_strlen(s2);
	res = malloc((len + 1) * sizeof(char));
	if (!res)
		return (NULL);
	if (s1)
	{
		while (s1[i])
		{
			res[i] = s1[i];
			i++;
		}
	}
	len = 0;
	if (s2)
		while (s2[len])
			res[i++] = s2[len++];
	res[i] = 0;
	free(s1);
	return (res);
}

t_pos	init_t_pos(int i, int j)
{
	t_pos	v;

	v.x = i;
	v.y = j;
	return (v);
}

void	ft_putstr(char *str)
{
	int	i;
	int	res;

	i = 0;
	while (str[i])
	{
		res = write(1, &str[i], 1);
		if (res == -1)
			break ;
		i++;
	}
}

void	ft_putnbr(unsigned int nb)
{
	int		res;
	char	c;

	if (nb > 9)
	{
		ft_putnbr(nb / 10);
		ft_putnbr(nb % 10);
	}
	else
	{
		c = nb + '0';
		res = write(2, &c, 1);
		if (res == -1)
			return ;
	}
}

void	ft_ermap(char *str)
{
	int		i;
	size_t	res;

	i = 0;
	if (!str)
		exit(0);
	while (str[i])
	{
		res = write(2, &str[i], 1);
		if (res == 0)
			break ;
		i++;
	}
	exit(0);
}
