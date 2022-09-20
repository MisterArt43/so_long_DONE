/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   common_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abucia <abucia@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/31 05:59:55 by abucia            #+#    #+#             */
/*   Updated: 2022/05/31 05:59:57 by abucia           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../include/header.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*res;
	int		i;
	int		len;

	i = 0;
	len = ft_strlen(s1) + ft_strlen(s2);
	res = malloc((len + 1) * sizeof(char));
	if (!res)
		return (NULL);
	while (s1[i])
	{
		res[i] = s1[i];
		i++;
	}
	len = 0;
	while (s2[len])
	{
		res[i] = s2[len];
		i++;
		len++;
	}
	res[i] = 0;
	return (res);
}

size_t	ft_len(int n)
{
	int		nb;
	size_t	len;

	nb = n;
	len = 0;
	if (nb < 0)
	{
		nb *= -1;
		len++;
	}
	while (nb / 10)
	{
		nb /= 10;
		len++;
	}
	return (++len);
}

char	*ft_itoa(int n)
{
	char	*res;
	long	nb;
	size_t	len;

	len = ft_len(n);
	res = malloc(sizeof(char) * (len + 1));
	if (!res)
		return (NULL);
	res[len--] = '\0';
	nb = n;
	if (len == 0)
		res[0] = 48;
	if (nb < 0)
	{
		nb *= -1;
		res[0] = '-';
	}
	while (nb)
	{
		res[len--] = 48 + (nb % 10);
		nb /= 10;
	}
	return (res);
}

size_t	ft_strlen(const char *str)
{
	int	i;

	if (!str)
		return (0);
	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strdup(char *s1)
{
	char	*cpy;
	size_t	i;

	i = 0;
	cpy = malloc((ft_strlen(s1) + 1) * sizeof(char));
	if (!cpy)
		return (NULL);
	while (s1[i])
	{
		cpy[i] = s1[i];
		i++;
	}
	cpy[i] = 0;
	return (cpy);
}
