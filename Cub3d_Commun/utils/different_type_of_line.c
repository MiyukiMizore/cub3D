/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   different_type_of_line.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: event <event@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/01 10:37:17 by event             #+#    #+#             */
/*   Updated: 2023/05/01 11:38:22 by event            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"	

bool	line_ok(char *str)
{
	char	**tab;
	int		i;

	i = 0;
	tab = ft_split(str, ' ');
	while (tab[i])
		i++;
	if (i != 2 || ft_strlen(tab[0]) > 2)
	{
		free_tab(tab);
		return (false);
	}
	if (tab[0][0] != 'N' && tab[0][0] != 'S' && tab[0][0] != 'W'
		&& tab[0][0] != 'E' && tab[0][1] != 'O' && tab[0][1] != 'E'
		&& tab[0][1] != 'A' && tab[0][0] != 'F' && tab[0][0] != 'C'
		&& tab[0][1] != '\0')
	{
		free_tab(tab);
		return (false);
	}
	free_tab(tab);
	return (true);
}

bool	is_empty_line(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (NULL);
	while (str[i])
	{
		if (str[i] == ' ' || str[i] == '\n')
			i++;
		else
			return (false);
	}
	return (true);
}

bool	different_type_of_line(char *str)
{
	if (is_empty_line(str) == true)
		return (true);
	if (first_line_map(str) == true)
		return (true);
	if (line_ok(str) == false)
		return (false);
	return (true);
}
