/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: misimon <misimon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 15:20:32 by misimon           #+#    #+#             */
/*   Updated: 2023/05/11 15:35:22 by misimon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

bool	empty_str(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] != ' ')
			return (false);
		else
			i++;
	}
	return (true);
}

void	empty_line_del(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
		i++;
	i--;
	while (empty_str(tab[i]) == true)
	{
		tab[i] = NULL;
		i--;
	}
}

int	get_max_size(char **map)
{
	int		i;
	size_t	size;

	size = 0;
	i = 0;
	while (map[i])
	{
		if (ft_strlen(map[i]) > size)
			size = ft_strlen(map[i]);
		else
		i++;
	}
	if (size > 50 || i > 50)
		return (-1);
	return (size);
}

void	add_space_line(char *str)
{
	str[ft_strlen(str)] = ' ';
}

char	*update_line(char *new_str, char *old_str, size_t size)
{
	ft_strcpy(new_str, old_str);
	while (ft_strlen(new_str) != size)
		add_space_line(new_str);
	free(old_str);
	return (new_str);
}
