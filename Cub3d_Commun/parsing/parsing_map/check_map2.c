/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: misimon <misimon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 15:30:32 by misimon           #+#    #+#             */
/*   Updated: 2023/05/11 15:35:04 by misimon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

bool	caract_map_str(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] != ' ' && str[i] != 'N' && str[i] != 'S' && str[i] != 'W'
			&& str[i] != 'E' && str[i] != '1' && str[i] != '0')
			return (false);
		i++;
	}
	return (true);
}

int	caract_map_file(char **file)
{
	int	i;

	i = 0;
	while (file[i])
	{
		if (caract_map_str(file[i]) == false)
			return (wrong_caract_in_map);
		i++;
	}
	return (no_problem);
}

bool	first_line_map(char *str)
{
	int	cmpt_un;
	int	i;

	i = 0;
	cmpt_un = 0;
	if (str == NULL)
		return (true);
	while (str[i])
	{
		if (str[i] == '1')
			cmpt_un++;
		else if (str[i] != '1' && str[i] != ' ' && str[i] != '\n'
			&& str[i] != '0' && str[i] != 'N' && str[i] != 'S' && str[i] != 'W'
			&& str[i] != 'E')
			return (false);
		i++;
	}
	if (cmpt_un != 0)
		return (true);
	else
		return (false);
}
