/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parser.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abucia <abucia@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 20:42:28 by abucia            #+#    #+#             */
/*   Updated: 2022/06/02 05:10:41 by abucia           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../include/header.h"

t_map	map_parser(char *path)
{
	t_map	newmap;
	int		fd;
	int		i;

	i = ft_strlen(path) - 1;
	if (i < 4)
		ft_ermap("file name invalid\n");
	else if (path[i] != 'r' || path[i - 1] != 'e'
		|| path[i - 2] != 'b' || path[i - 3] != '.')
		ft_ermap("file extension invalid\n");
	fd = open(path, O_RDONLY);
	newmap = line_parser(ft_readall(fd), fd);
	if (close(fd) == -1)
		free_build_map(newmap, newmap.h,
			"an error occured while closing the file");
	newmap.nb_player = 0;
	newmap.nb_exit = 0;
	newmap.nb_collect = 0;
	newmap.nb_wall = 0;
	newmap.nb_void = 0;
	newmap.nb_enemy = 0;
	newmap = map_checker(newmap, 0, 0);
	return (newmap);
}
