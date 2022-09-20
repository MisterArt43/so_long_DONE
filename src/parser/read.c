/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abucia <abucia@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/31 05:39:30 by abucia            #+#    #+#             */
/*   Updated: 2022/06/02 05:16:30 by abucia           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../include/header.h"

char	*ft_readall(int fd)
{
	char	*all;
	char	*buffer;
	int		i;

	if (fd == -1)
		ft_ermap("error, can't open this file\n");
	all = NULL;
	buffer = malloc((17) * sizeof(char));
	if (!buffer)
		return (NULL);
	i = 1;
	while (i != 0)
	{
		i = read(fd, buffer, 16);
		if (i == -1)
			read_error(fd, buffer, "an error occurred while reading the file\n");
		buffer[i] = '\0';
		all = ft_freestrjoin(all, buffer);
		if (!all)
			read_error(fd, buffer, "an error occurred while reading the file\n");
	}
	free(buffer);
	return (all);
}

void	map_dimension(char *line, int *h, int *l)
{
	int	i;

	i = -1;
	*l = 0;
	*h = 0;
	while (line[++i] != '\n' && line[i])
		*l += 1;
	i = 0;
	while (line[i])
	{
		if (line[i] == '\n')
		{
			if (line[i + 1] == '\n' || line[i + 1] == '\0')
			{
				free(line);
				ft_ermap("Invalid map format\n");
			}
			*h = *h + 1;
		}
		else if (line[i + 1] == '\0')
			*h = *h + 1;
		i++;
	}
}

char	*make_line(char *str, int n, int l, int i)
{
	int		len;
	char	*line;

	while (n != 0 && str[i])
		if (str[i++] == '\n' || str[i] == '\r')
			n--;
	line = malloc(sizeof(char) * (l + 1));
	if (!line)
	{
		free(str);
		return (NULL);
	}
	len = 0;
	while ((str[i] != '\n') && str[i])
		line[len++] = str[i++];
	line[len] = 0;
	if (len != l)
	{
		free(line);
		free(str);
		return (NULL);
	}
	return (line);
}

t_map	line_parser(char *line, int fd)
{
	int		i;
	t_map	map;

	i = 0;
	map_dimension(line, &map.h, &map.l);
	map.map = malloc(sizeof(char *) * (map.h + 1));
	if (!map.map)
		read_error(fd, line, "malloc error while creating the map array\n");
	map.map[map.h] = NULL;
	while (i < map.h)
	{
		map.map[i] = make_line(line, i, map.l, 0);
		if (map.map[i] == NULL)
			free_build_map(map, i, "malloc error while filling the map\n");
		i++;
	}
	free(line);
	return (map);
}
