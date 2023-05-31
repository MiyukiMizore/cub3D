/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_close.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfusil <mfusil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 15:33:22 by misimon           #+#    #+#             */
/*   Updated: 2023/05/12 17:55:30 by mfusil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

bool	check_close_str(char *t_str, char *m_str, char *b_str)
{
	int	i;

	i = 0;
	if (m_str[0] == '0' || t_str[0] == '0' || b_str[0] == '0'
		|| m_str[0] == 'N' || t_str[0] == 'N' || b_str[0] == 'N'
		|| m_str[0] == 'S' || t_str[0] == 'S' || b_str[0] == 'S'
		|| m_str[0] == 'E' || t_str[0] == 'E' || b_str[0] == 'E'
		|| m_str[0] == 'W' || t_str[0] == 'W' || b_str[0] == 'W')
		return (false);
	while (m_str[i])
	{
		if (m_str[i] == '0' || m_str[i] == 'N' || m_str[i] == 'S'
			|| m_str[i] == 'E' || m_str[i] == 'W')
		{
			if (m_str[i - 1] == ' ' || m_str[i + 1] == ' '
				|| m_str[i - 1] == '	' || m_str[i + 1] == '	')
				return (false);
			if (t_str[i] == ' ' || t_str[i] == '	' || b_str[i] == ' '
				|| b_str[i] == '	')
				return (false);
		}
		i++;
	}
	return (true);
}

bool	check_close_str2(char *str, char *str2)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] != ' ' && str[i] != '1')
			return (false);
		if (str2[i] == '0' || str2[i] == 'N' || str2[i] == 'S' || str2[i] == 'W'
			|| str2[i] == 'E')
		{
			if (str[i] != '1')
				return (false);
		}
		i++;
	}
	return (true);
}

int	check_close_map(char **map)
{
	int	i;

	i = 0;
	while (map[i])
		i++;
	if (i < 3)
		return (size_map_error);
	i = 0;
	while (map[i + 2])
	{
		if (check_close_str(map[i], map[i + 1], map[i + 2]) == false)
			return (map_not_close);
		i++;
	}
	if (check_close_str2(map[0], map[1]) == false
		|| check_close_str2(map[i + 1], map[i]) == false)
		return (map_not_close);
	return (no_problem);
}
