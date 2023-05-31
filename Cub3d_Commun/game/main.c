/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: misimon <misimon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 14:38:03 by mfusil            #+#    #+#             */
/*   Updated: 2023/05/30 22:25:08 by misimon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	verif_cub(char *map)
{
	size_t	i;

	i = ft_strlen(map);
	if (i <= ft_strlen(".cub"))
		return (1);
	if (map[i - 1] == 'b')
		if (map[i - 2] == 'u')
			if (map [i - 3] == 'c')
				if (map [i - 4] == '.')
					return (0);
	return (1);
}



t_game	*init_game(char *arg, t_parsing *parse)
{
	t_game	*game;

	game = ft_calloc(1, sizeof(t_game));
	init_struct(game, arg, parse);
	printf("Initialization of the structure (game)\n");
	printf("Window initialization of cub3d\n");
	return (game);
}

// Officielement le debut du programme apres verification des infos 
void	start(char *arg, t_parsing *parse)
{
	t_game	*game;

	game = init_game(arg, parse);
	print_textures_in_minimap(game);
	mlx_loop_hook(game->mlx_ptr, pressed_key, game);
	mlx_loop_hook(game->mlx_ptr, render_3d, game);
	mlx_loop(game->mlx_ptr);
}

int	main(int argc, char **argv)
{
	t_parsing	*parse;

	if (argc != 2)
	{
		printf("Error\n");
		return (0);
	}
	if (verif_cub(argv[1]) != 0)
		return (ft_printf("Error : the map doesn't end with a .cub\n"));
	parse = ft_calloc((sizeof(t_parsing)), 1);
	if (start_parsing(argc, argv, parse) == false)
		return (free_struct(parse));
	start(argv[1], parse);
}
