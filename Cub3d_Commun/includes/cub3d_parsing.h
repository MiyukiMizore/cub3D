/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_parsing.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: misimon <misimon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 16:23:10 by mfusil            #+#    #+#             */
/*   Updated: 2023/05/11 16:32:54 by misimon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_PARSING_H
# define CUB3D_PARSING_H

# include "cub3d.h"

//-----------DEFINE_ERROR + struct s_parsing + enum e_error------------//

enum e_error
{
	no_problem,
	error_arg,
	wrong_file,
	empty_file,
	redefine_sprite,
	missing_sprite,
	redefine_rgb,
	missing_rgb,
	wrong_caract_in_map,
	missing_map,
	wrong_line,
	size_map_error,
	map_not_close,
	empty_line_in_map,
	error_pl,
	error_texture,
	error_rgb
};

enum e_direction
{
	north,
	south,
	east,
	west
};

typedef struct s_parsing
{
	int		y_pl;
	int		x_pl;
	int		player_direction;
	bool	texture_check;
	char	*texture_no;
	char	*texture_so;
	char	*texture_we;
	char	*texture_ea;
	char	*value_rgb_c;
	char	*value_rgb_f;
	int		color_c;
	int		color_f;
	char	**map;
}t_parsing;

# define ARG_ERROR  "Error\nArgument incorrect\n"
# define WRONG_FILE "Error\nfiles don't find or can't be open\n"
# define EMPTY_FILE "Error\nfiles is empty so... :/\n"
# define REDEFINE_SPRITE "Error\nMutiple ID{NO or SO or WE or EA}{PATH} in file\n"
# define MISSING_SPRITE "Error\nMissing ID{NO or SO or WE or EA}{PATH} in file\n"
# define MISSING_RGB "ERROR\nMissing RGB_ID{C or F}{PATH} in file \n"
# define REDEFINE_RGB "ERROR\nMutiple RGB_ID{C or F}{PATH} in file \n"
# define WRONG_CRT "ERROR\nWrong caractere in the map only {N,S,E,W,1,0, spc}\n"
# define MISS_MAP "ERROR\nMap not found in file\n"
# define WRONG_LINE "ERROR\nWrong line in the file\n"
# define SIZE_MAP "ERROR\nMap size can't be > to 50 or < 3\n"
# define MAP_OPEN "ERROR\nMap not close\n"
# define EMPTY_LINE "ERROR\nEmpty line in map\n"
# define ERROR_PL "ERROR\nError with the player id\n"
# define ERROR_TEXT "ERROR\nError with texture path\n"
# define ERROR_RGB "ERROR\nError with RGB in file\n"

//-----------free_fonction.free_tab------------//
void			free_tab(char **tab);
int				free_struct(t_parsing *parse); /*in main.c*/
//----------------Struct_Game----------------//

//-----------parsing.check_file-------------------//

enum e_id
{
	ID_NO,
	ID_SO,
	ID_WE,
	ID_EA
};

bool			found(char *line, char *to_found, t_parsing *parse);
int				check_file(int fd, char *file_name, t_parsing *parse);
int				check_file_path_texture(char **file, t_parsing *parse);
unsigned int	file_size(int fd);

//----------parsing/parsing_sprite_rgb.start_parsing----------------//

int				check_file_rgb(int fd, t_parsing *parse);
void			close_all_fd(void);
bool			start_parsing(int ac, char **av, t_parsing *parse);
bool			error(int error);

//----------parsing/parsing_map.check_map----------------//

char			**cpy_file(int fd, char **file, char *name_file);

//----------parsing/parsing_map/check_close.c----------------//

int				check_close_map(char **map);

//----------parsing/parsing_map/check_map.c----------------//

char			**actual_map(char **file);
void			update_all_line_size(char **map, size_t size_line);
int				empty_line_in_map2(char **map);
int				verif_map(char **map, t_parsing *parse);
int				check_map(int fd, t_parsing *parse, char *name_file);

//----------parsing/parsing_map/check_map2.c----------------//

bool			caract_map_str(char *str);
int				caract_map_file(char **file);
bool			first_line_map(char *str);

//----------parsing/parsing_map/check_player.c----------------//

bool			caract_player(char c, t_parsing *direction);
void			add_loc_player(t_parsing *parse, int y, int x);
int				player_loc(char **map, t_parsing *parse, int y);

//----------parsing/parsing_map/check_texture.c----------------//

bool			check_str_rgb(char *str);
int				check_tab_rgb(char *l1, char *l2, char *l3, int color);
int				tab_len(char **tab);
int				rgb_check_value(t_parsing *parse);
int				verif_texture_and_rgb(t_parsing *parse);

//----------parsing/parsing_map/map_utils.c----------------//

bool			empty_str(char *str);
void			empty_line_del(char **tab);
int				get_max_size(char **map);
void			add_space_line(char *str);
char			*update_line(char *new_str, char *old_str, size_t size);

//----------parsing/parsing_sprite_rgb/sprite_utils.c----------------//

void			close_all_fd(void);

#endif