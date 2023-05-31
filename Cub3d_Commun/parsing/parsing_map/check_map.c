/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfusil <mfusil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 10:53:35 by event             #+#    #+#             */
/*   Updated: 2023/05/12 17:56:54 by mfusil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

char	**actual_map(char **file)
{
	char	**new;
	int		i;

	i = 0;
	if (file[i] == NULL)
		return (NULL);
	while (file[i])
		i++;
	new = ft_calloc(i + 1, sizeof(char *));
	i = 0;
	while (file[i])
	{
		new[i] = ft_strdup(file[i]);
		i++;
	}
	return (new);
}

void	update_all_line_size(char **map, size_t size_line)
{
	int		i;
	char	*str;

	i = 0;
	while (map[i])
	{
		if (ft_strlen(map[i]) != size_line)
		{
			str = ft_calloc(1, size_line + 1);
			map[i] = update_line(str, map[i], size_line);
		}
		i++;
	}
}

int	empty_line_in_map2(char **map)
{
	int	i;

	i = 0;
	while (map[i])
	{
		if (empty_str(map[i]) == true)
			return (empty_line_in_map);
		i++;
	}
	return (no_problem);
}

int	verif_map(char **map, t_parsing *parse)
{
	int	resize;
	int	error;

	error = no_problem;
	resize = get_max_size(map);
	if (resize == -1)
		return (size_map_error);
	update_all_line_size(map, resize);
	error = check_close_map(map);
	if (error != no_problem)
		return (error);
	empty_line_del(map);
	error = empty_line_in_map2(map);
	if (error != no_problem)
		return (error);
	error = player_loc(map, parse, 0);
	if (error != no_problem)
		return (error);
	error = verif_texture_and_rgb(parse);
	return (error);
}

int	check_map(int fd, t_parsing *parse, char *name_file)
{
	char	**file;
	int		s_file;
	int		i;

	i = 0;
	(void)parse;
	s_file = file_size(fd);
	fd = open(name_file, O_RDONLY);
	file = ft_calloc(sizeof(char *), s_file);
	file = get_file(fd, s_file);
	while (first_line_map(file[i]) == false)
		i++;
	parse->map = actual_map(&file[i]);
	free_tab(file);
	if (parse->map == NULL)
		return (missing_map);
	return (verif_map(parse->map, parse));
}
