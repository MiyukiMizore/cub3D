/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfusil <mfusil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 16:23:10 by mfusil            #+#    #+#             */
/*   Updated: 2023/05/30 20:09:35 by mfusil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <math.h>
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdbool.h>
# include "../Libft/libft.h"
# include "cub3d_parsing.h"
# include "../../MLX42/include/MLX42/MLX42.h"

# define PI 3.1415926535

//----------------Struct_Game----------------//

typedef struct draw_oe
{
	uint8_t		*texture_pixels;
	int			texture_width;
	int			texture_height;
	int			texture_x;
	int			texture_y;
	int			texture_pixel_index;
	int			pixel_y;
	uint8_t		r;
	uint8_t		b;
	uint8_t		g;
	uint8_t		a;
	uint32_t	color;
	float		wall_x;
}	t_draw_oe;

typedef struct draw_ns
{
	uint8_t		r;
	uint8_t		g;
	uint8_t		b;
	uint8_t		a;
	uint8_t		*texture_pixels;
	uint32_t	color;
	int			texture_width;
	int			texture_height;
	int			texture_x;
	int			texture_y;
	int			texture_pixel_x;
	int			texture_pixel_index;
	int			pixel_y;
	float		wall_x;
}	t_draw_ns;

typedef struct render
{
	float	ray_angle;
	float	scale;
	float	ray_x;
	float	ray_y;
	float	fov;
	double	cos_ray;
	double	sin_ray;
	float	distance_to_wall;
	bool	hit_wall;
	int		direction;
	int		resolution_width;
	int		resolution_height;
	int		wall_height;
}	t_render;
typedef struct image
{
	xpm_t		*texture;
	mlx_image_t	*img;
	mlx_image_t	*img_2;
	char		*path;
}	t_image;

typedef struct player
{
	float	px;
	float	py;
	float	pdx;
	float	pdy;
	float	pa;
}	t_player;

typedef struct game
{
	void		*mlx_ptr;
	char		**map;
	int			key;
	int			width;
	int			height;
	int			collor_cellar;
	int			collor_floor;
	float		max_view_distance;
	t_image		texture[4];
	mlx_image_t	*projection;
	mlx_image_t	*third_d;
	t_image		*image_player;
	t_image		*minimap;
	t_player	*player;
	t_render	*render;
	t_draw_ns	*draw_ns;
	t_draw_oe	*draw_oe;
}	t_game;

//----------------Functions----------------//

int		main(int argc, char **argv);
void	pressed_key(void *param);
void	init_struct(t_game *game, char *arg, t_parsing *parse);
void	print_textures_in_minimap(t_game *game);
bool	is_a_wall(char **map, int x, int y);
void	render_3d(void *param);
void	draw_vertical_column_ns(t_game *game, int x, int y);
void	draw_vertical_column(t_game *game, int x, int y, int color);
void	draw_vertical_column_oe(t_game *game, int x, int y);
int		color_pixel(int r, int g, int b, int a);
bool	player_collision(char **map, int x, int y);
int		what_face_of_wall(int x, int y, t_game *game);
bool	is_a_corner(int x, int y, t_game *game);
int		free_struct(t_parsing *parse);
void	print_floor_cellar(t_game *game);
void	init_render(t_game *game);
void	init_draw_ns(t_game *game);
void	init_draw_oe(t_game *game);

//-----------free_fonction.free_tab------------//

void	free_tab(char **tab);
int		free_struct(t_parsing *parse); /*in main.c*/

//----------------UTILS-----------------------//

bool	ft_strcmp(char *str, char *str2);
void	replace_caract(char *str, char to_replace, char new_char);
void	print_tab(char **tab);
char	**stock_map(char *map, int i, int j); // tmp
void	print_pixel(t_game *game, int i, int j);
char	**get_file(int fd, int size_to_allocate);
bool	different_type_of_line(char *str);
bool	first_line_map(char *str);
void	ft_strcpy(char	*new, char *to_copy);

#endif
