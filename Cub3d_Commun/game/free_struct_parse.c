/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_struct_parse.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfusil <mfusil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 17:28:49 by mfusil            #+#    #+#             */
/*   Updated: 2023/05/30 17:29:09 by mfusil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

//Free la structure du parsing en verifiant
//si le malloc a eu lieux ou pas pour empecher un abort

int	free_struct(t_parsing *parse)
{
	if (parse->texture_ea != NULL)
		free(parse->texture_ea);
	if (parse->texture_no != NULL)
		free(parse->texture_no);
	if (parse->texture_so != NULL)
		free(parse->texture_so);
	if (parse->texture_we != NULL)
		free(parse->texture_we);
	if (parse->value_rgb_c != NULL)
		free(parse->value_rgb_c);
	if (parse->value_rgb_f != NULL)
		free(parse->value_rgb_f);
	free(parse);
	return (1);
}
