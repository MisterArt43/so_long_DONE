/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_free.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abucia <abucia@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/31 06:18:41 by abucia            #+#    #+#             */
/*   Updated: 2022/05/31 06:18:42 by abucia           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../include/header.h"

void	read_error(int fd, char *str, char *er)
{
	int	i;

	i = 0;
	free(str);
	i = close(fd);
	if (i == -1)
		ft_ermap(er);
	ft_ermap(er);
}
