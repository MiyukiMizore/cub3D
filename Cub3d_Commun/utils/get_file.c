/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_file.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: event <event@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 15:53:31 by event             #+#    #+#             */
/*   Updated: 2023/04/27 16:43:29 by event            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

char	**get_file(int fd, int size_to_allocate)
{
	char	**file;
	char	*str;
	int		i;

	i = 0;
	file = ft_calloc(sizeof(char *), size_to_allocate);
	str = get_next_line(fd);
	while (str)
	{
		replace_caract(str, '\n', ' ');
		file[i] = str;
		str = get_next_line(fd);
		i++;
	}
	file[i] = NULL;
	return (file);
}
