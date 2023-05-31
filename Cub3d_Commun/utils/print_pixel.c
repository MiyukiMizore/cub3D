/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_pixel.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfusil <mfusil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 16:09:57 by mfusil            #+#    #+#             */
/*   Updated: 2023/05/05 17:31:06 by mfusil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	print_pixel(t_game *game, int i, int j)
{
	int	cmpt;
	int	cmpt_2;
	int	tmp;

	cmpt = 0;
	cmpt_2 = 0;
	tmp = j;
	while (cmpt != 16)
	{
		while (cmpt_2 != 16)
		{
			mlx_put_pixel(game->minimap->img, j, i, 0xFFFFFFFF);
			j++;
			cmpt_2++;
		}
		j = tmp;
		cmpt_2 = 0;
		i++;
		cmpt++;
	}
}
