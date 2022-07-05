/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drayl <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/05 06:13:55 by drayl             #+#    #+#             */
/*   Updated: 2022/03/05 06:13:57 by drayl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB_H
# define CUB_H
# include "../srcs/libft/libft.h"
# include "../srcs/mlx/mlx.h"
//#include <mlx.h>
# include "constants.h"
# include "strings.h"
# include "structs.h"
# include <sys/fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <math.h>

//   --- parser ---   //
int		up_atoi(const char *str);
int		get_index(const char *str, char delimiter);
int		check_side(const char *line);
int		check_surface(const char *line);
void	put_error_and_arg(char *arg, char *message, int error_status);
void	put_error(const char *message, int error_status);
void	validation_check_path(char *path);
void	validation_check_color(t_color *color);
void	check_valid_map(t_map *map);
char	*get_subline(const char *line);
char	*read_file(char *file_name);
t_map	*create_map(void);
t_map	*convert_line_to_map(char *line);
t_data	*create_data(void);
t_data	*convert_line_to_data(char *line);
t_data	*parse(int argc, char **argv);

//   --- mlx_utils ---   //
void	init_mlx(t_game *game, t_data *data);
void	draw_line(t_game *game, t_icoord pos, int end);
void	draw_pixel(t_tex *scr, t_icoord pos, int color);
void	draw_wall(t_game *game, t_ray *r, int x);
void	draw_block(t_tex *scr, int start_x, int start_y, int color);
void	draw_mini_map(t_game *game);
int		get_tex_color(t_tex *tex, t_icoord pos);

//   --- game ---   //
t_game	*init_game(t_data *data);
void	rotate_for_mouse(t_game *game, t_icoord *mouse);
int		key_manager(int key, t_game *game);
int		exit_ok(int key);
int		recasting(t_game *game);

//   --- xlam.c ---   //
void	print_string_array(char **arr);
void	print_data(t_data *data);
void	print(char *mes);
void	print_ray(t_ray ray);

#endif
