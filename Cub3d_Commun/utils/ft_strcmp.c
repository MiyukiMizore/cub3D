/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: event <event@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 16:41:53 by event             #+#    #+#             */
/*   Updated: 2023/04/24 11:10:04 by event            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

bool	ft_strcmp(char *str, char *str2)
{
	int	i;

	i = 0;
	if (!str || !str2)
		return (false);
	if (ft_strlen(str) != ft_strlen(str2))
		return (false);
	while (str[i] && str2[i])
	{
		if (str[i] != str2[i])
			return (false);
		i++;
	}
	return (true);
}
