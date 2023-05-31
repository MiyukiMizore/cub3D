/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   replace_caract.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: event <event@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/21 10:27:22 by event             #+#    #+#             */
/*   Updated: 2023/04/24 11:09:52 by event            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	replace_caract(char *str, char to_replace, char new_char)
{
	int	i;

	i = 0;
	while (str && str[i])
	{
		if (str[i] == to_replace)
		{
			str[i] = new_char;
			return ;
		}
		i++;
	}
	return ;
}
