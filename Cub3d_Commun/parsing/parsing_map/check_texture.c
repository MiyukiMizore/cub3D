/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_texture.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdutschk <jdutschk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 15:17:57 by misimon           #+#    #+#             */
/*   Updated: 2023/05/30 21:49:48 by jdutschk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

bool	check_str_rgb(char *str)
{
	int	i;

	i = 0;
	if (ft_strlen(str) > 3)
		return (false);
	while (str[i])
	{
		if (str[i] >= '0' && str[i] <= '9')
			i++;
		else
			return (false);
	}
	return (true);
}

int	check_tab_rgb(char *l1, char *l2, char *l3, int color)
{
	if (check_str_rgb(l1) == false || check_str_rgb(l2) == false
		|| check_str_rgb(l3) == false)
		return (1);
	if (ft_atoi(l1) < 0 || ft_atoi(l1) > 255)
		return (1);
	if (ft_atoi(l2) < 0 || ft_atoi(l2) > 255)
		return (1);
	if (ft_atoi(l3) < 0 || ft_atoi(l3) > 255)
		return (1);
	color = (ft_atoi(l1) << 16) | (ft_atoi(l2) << 8) | ft_atoi(l3);
	return (0);
}

int	tab_len(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
		i++;
	return (i);
}

int	rgb_check_value(t_parsing *parse)
{
	char	**result_c;
	char	**result_f;
	int		error[2];

	result_c = ft_split(parse->value_rgb_c, ',');
	result_f = ft_split(parse->value_rgb_f, ',');
	if (tab_len(result_c) != 3 || tab_len(result_f) != 3)
		return (error_rgb);
	error[0] = check_tab_rgb(result_c[0], result_c[1], result_c[2],
			parse->color_c);
	error[1] = check_tab_rgb(result_f[0], result_f[1], result_f[2],
			parse->color_f);
	if (error[0] != no_problem || error[1] != no_problem)
		return (error_rgb);
	parse->color_c = color_pixel(ft_atoi(result_c[0]), ft_atoi(result_c[1]),
			ft_atoi(result_c[2]), 255);
	parse->color_f = color_pixel(ft_atoi(result_f[0]), ft_atoi(result_f[1]),
			ft_atoi(result_f[2]), 255);
	return (no_problem);
}

int	verif_texture_and_rgb(t_parsing *parse)
{
	int	fd[4];

	fd[0] = open(parse->texture_ea, 0);
	fd[1] = open(parse->texture_no, 0);
	fd[2] = open(parse->texture_so, 0);
	fd[3] = open(parse->texture_we, 0);
	if (fd[0] <= 1 || fd[1] <= 1 || fd[2] <= 1 || fd[3] <= 1)
		return (error_texture);
	else
		return (rgb_check_value(parse));
}
