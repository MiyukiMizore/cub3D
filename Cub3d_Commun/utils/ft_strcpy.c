/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: event <event@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 13:53:55 by event             #+#    #+#             */
/*   Updated: 2023/05/02 13:55:23 by event            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	ft_strcpy(char	*new, char *to_copy)
{
	int	i;

	i = 0;
	while (to_copy[i])
	{
		new[i] = to_copy[i];
		i++;
	}
}