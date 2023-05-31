/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_parsing.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: misimon <misimon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 17:40:36 by event             #+#    #+#             */
/*   Updated: 2023/05/30 18:22:52 by misimon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	check_wrong_line(int fd)
{
	char	*str;

	str = get_next_line(fd);
	while (str)
	{
		if (different_type_of_line(str) == false)
		{
			free(str);
			return (wrong_line);
		}
		free(str);
		str = get_next_line(fd);
	}
	free(str);
	return (no_problem);
}

void	error2(int error)
{
	if (error == wrong_line)
		ft_printf(WRONG_LINE);
	if (error == map_not_close)
		ft_printf(MAP_OPEN);
	if (error == empty_line_in_map)
		ft_printf(EMPTY_LINE);
	if (error == error_pl)
		ft_printf(ERROR_PL);
	if (error == error_texture)
		ft_printf(ERROR_TEXT);
	if (error == error_rgb)
		ft_printf(ERROR_RGB);
}

bool	error(int error)
{
	if (error != no_problem)
	{
		if (error == error_arg)
			ft_printf(ARG_ERROR);
		if (error == wrong_file)
			ft_printf(WRONG_FILE);
		if (error == empty_file)
			ft_printf(EMPTY_FILE);
		if (error == redefine_sprite)
			ft_printf(REDEFINE_SPRITE);
		if (error == missing_sprite)
			ft_printf(MISSING_SPRITE);
		if (error == redefine_rgb)
			ft_printf(REDEFINE_RGB);
		if (error == missing_rgb)
			ft_printf(MISSING_RGB);
		if (error == wrong_caract_in_map)
			ft_printf(WRONG_CRT);
		if (error == missing_map)
			ft_printf(MISS_MAP);
		error2(error);
		close_all_fd();
	}
	return (false);
}

bool	start_parsing(int ac, char **av, t_parsing *parse)
{
	int	error_files;
	int	fd;

	fd = 0;
	if (ac != 2)
		return (error(error_arg));
	fd = open(av[1], O_RDONLY);
	if (fd < 2)
		return (error(wrong_file));
	error_files = check_file(fd, av[1], parse);
	if (error_files != no_problem)
		return (error(error_files));
	error_files = check_file_rgb(open(av[1], O_RDONLY), parse);
	if (error_files != no_problem)
		return (error(error_files));
	error_files = check_wrong_line(open(av[1], O_RDONLY));
	if (error_files != no_problem)
		return (error(error_files));
	error_files = check_map(open(av[1], O_RDONLY), parse, av[1]);
	if (error_files != no_problem)
		return (error(error_files));
	return (true);
}

int	check_file_rgb(int fd, t_parsing *parse)
{
	char	*str;
	int		cmpt_f;
	int		cmpt_c;

	cmpt_c = 0;
	cmpt_f = 0;
	str = get_next_line(fd);
	while (str)
	{
		if (found(str, "F", parse) == true)
			cmpt_f++;
		else if (found(str, "C", parse) == true)
			cmpt_c++;
		free(str);
		str = get_next_line(fd);
	}
	close(fd);
	if (cmpt_c > 1 || cmpt_f > 1)
		return (redefine_rgb);
	if (cmpt_c == 0 || cmpt_f == 0)
		return (missing_rgb);
	return (no_problem);
}
