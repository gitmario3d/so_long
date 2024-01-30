/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malena-b <mario3d93@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/27 11:44:21 by malena-b          #+#    #+#             */
/*   Updated: 2024/01/30 14:16:10 by malena-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_BONUS_H
# define SO_LONG_BONUS_H

# include "MLX42/include/MLX42/MLX42.h"
# include "my_libft/libft.h"

typedef struct t_player_rend
{
	mlx_image_t		*player_01;
	mlx_image_t		*player_02;
	mlx_image_t		*player_03;
	mlx_image_t		*player_04;
	mlx_image_t		*player_05;
	mlx_texture_t	*player_01_t;
	mlx_texture_t	*player_02_t;
	mlx_texture_t	*player_03_t;
	mlx_texture_t	*player_04_t;
	mlx_texture_t	*player_05_t;
}				t_player_render;

typedef struct t_map_information
{
	int				collectables;
	int				players;
	int				exits;
	int				x_size;
	int				y_size;
	char			**map;
	int				p_pos_x;
	int				p_pos_y;
	int				ff_collec;
	int				ff_exits;
	char			**ff_map;
	int				fd;
	char			*path_name;
	int				steps;
	char			*count;
	mlx_t			*mlx;
	mlx_image_t		*stone;
	mlx_image_t		*ground;
	mlx_image_t		*coin;
	mlx_image_t		*exit;
	mlx_image_t		*b_wall;
	mlx_image_t		*t_wall;
	mlx_image_t		*r_wall;
	mlx_image_t		*l_wall;
	mlx_image_t		*corner_bl;
	mlx_image_t		*corner_br;
	mlx_image_t		*corner_tl;
	mlx_image_t		*corner_tr;
	mlx_image_t		*c_exit;
	mlx_image_t		*moves_img;
	mlx_texture_t	*b_wall_t;
	mlx_texture_t	*t_wall_t;
	mlx_texture_t	*l_wall_t;
	mlx_texture_t	*r_wall_t;
	mlx_texture_t	*corner_bl_t;
	mlx_texture_t	*corner_br_t;
	mlx_texture_t	*corner_tl_t;
	mlx_texture_t	*corner_tr_t;
	mlx_texture_t	*stone_t;
	mlx_texture_t	*ground_t;
	mlx_texture_t	*coin_t;
	mlx_texture_t	*exit_t;
	mlx_texture_t	*c_exit_t;
	t_player_render	*player_r;
}				t_map_info;


void		check_map(int argc, char **argv, t_map_info *map_info);
void		print_error(char *errormsg, t_map_info *map_info);
t_map_info	*new_map_info(void);
void		check_floodfill(t_map_info *map_info);
void		free_mat(char **mat);
char		**matdup(char **mat);
void		set_tiles(t_map_info *map_info);
void		load_textures_imgs(t_map_info *map_info);
int			check_move(t_map_info *map_info, int direction, int y, int x);
void		set_player_t(t_map_info *map_info);
void		reload_player(t_map_info *map_info);
char		*create_path(t_map_info *map_info, char *str, char *path);
void		free_all(t_map_info *map_info);
void		reload_count(t_map_info *m_i);
void		my_keyhook(mlx_key_data_t keydata, void *param);
t_map_info	*new_map_info(void);
void		save_player_t(t_map_info *map_info);
mlx_image_t	*init_pl_img(t_map_info *m_i, mlx_texture_t *texture);
void		main_hook(void *map_info);
void		disable_anim_imgs(t_player_render *player_r);

#endif