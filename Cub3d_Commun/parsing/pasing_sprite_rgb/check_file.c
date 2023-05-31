/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: misimon <misimon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 18:22:59 by event             #+#    #+#             */
/*   Updated: 2023/05/11 15:40:58 by misimon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	add_texture_in_parsing(t_parsing *parse, char *id, char *to_cpy)
{
	if (ft_strcmp(id, "NO") == true)
		parse->texture_no = ft_strdup(to_cpy);
	else if (ft_strcmp(id, "SO") == true)
		parse->texture_so = ft_strdup(to_cpy);
	else if (ft_strcmp(id, "WE") == true)
		parse->texture_we = ft_strdup(to_cpy);
	else if (ft_strcmp(id, "EA") == true)
		parse->texture_ea = ft_strdup(to_cpy);
	else if (ft_strcmp(id, "F") == true)
	{
		parse->value_rgb_f = ft_strdup(to_cpy);
		replace_caract(parse->value_rgb_f, '\n', '\0');
	}
	else if (ft_strcmp(id, "C") == true)
	{
		parse->value_rgb_c = ft_strdup(to_cpy);
		replace_caract(parse->value_rgb_c, '\n', '\0');
	}
	return ;
}

bool	found(char *line, char *to_found, t_parsing *parse)
{
	char	**tab;
	int		i;
	int		y;

	i = 0;
	y = 0;
	tab = ft_split(line, ' ');
	while (tab[i])
		i++;
	if (i != 2)
	{
		free_tab(tab);
		return (false);
	}
	i = 0;
	if (ft_strcmp(tab[0], to_found) == false)
	{
		free_tab(tab);
		return (false);
	}
	add_texture_in_parsing(parse, tab[0], tab[1]);
	free_tab(tab);
	return (true);
}

unsigned int	file_size(int fd)
{
	char	*str;
	int		i;

	i = 0;
	str = get_next_line(fd);
	while (str)
	{
		free(str);
		str = get_next_line(fd);
		i++;
	}
	close(fd);
	return (i);
}

int	check_file_path_texture(char **file, t_parsing *parse)
{
	int	i;
	int	id[4];

	id[ID_NO] = 0;
	id[ID_SO] = 0;
	id[ID_WE] = 0;
	id[ID_EA] = 0;
	i = 0;
	while (file[i])
	{
		if (found(file[i], "NO", parse) == true)
			id[ID_NO]++;
		if (found(file[i], "SO", parse) == true)
			id[ID_SO]++;
		if (found(file[i], "WE", parse) == true)
			id[ID_WE]++;
		if (found(file[i], "EA", parse) == true)
			id[ID_EA]++;
		i++;
	}
	if (id[ID_NO] > 1 || id[ID_SO] > 1 || id[ID_WE] > 1 || id[ID_EA] > 1)
		return (redefine_sprite);
	if (id[ID_NO] == 0 || id[ID_SO] == 0 || id[ID_WE] == 0 || id[ID_EA] == 0)
		return (missing_sprite);
	return (0);
}

int	check_file(int fd, char *file_name, t_parsing *parse)
{
	char	**files_cpy;
	char	*str;
	int		i;
	int		error;

	i = 0;
	files_cpy = malloc(sizeof(char *) * file_size(fd) + 1);
	fd = open(file_name, O_RDONLY);
	str = get_next_line(fd);
	replace_caract(str, '\n', '\0');
	if (str == NULL)
		return (3);
	while (str)
	{
		files_cpy[i] = str;
		i++;
		str = get_next_line(fd);
		replace_caract(str, '\n', '\0');
	}
	files_cpy[i] = NULL;
	close (fd);
	error = check_file_path_texture(files_cpy, parse);
	free_tab(files_cpy);
	return (error);
}
