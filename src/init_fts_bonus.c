/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_fts_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malena-b <mario3d93@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 12:37:16 by malena-b          #+#    #+#             */
/*   Updated: 2024/02/01 12:00:30 by malena-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long_bonus.h"

mlx_texture_t	*init_player_t(t_map_info *map_info, char *filename)
{
	mlx_texture_t	*texture;
	char			*path;

	path = NULL;
	path = create_path(map_info, filename, path);
	texture = mlx_load_png(path);
	free (path);
	return (texture);
}

void	save_player_t(t_map_info *map_info)
{
	map_info->player_r->player_01_t = init_player_t(map_info, "player_01.png");
	map_info->player_r->player_02_t = init_player_t(map_info, "player_02.png");
	map_info->player_r->player_03_t = init_player_t(map_info, "player_03.png");
	map_info->player_r->player_04_t = init_player_t(map_info, "player_04.png");
	map_info->player_r->player_05_t = init_player_t(map_info, "player_05.png");
}

void	initialize_textures(t_map_info *map_info)
{
	map_info->b_wall_t = NULL;
	map_info->t_wall_t = NULL;
	map_info->l_wall_t = NULL;
	map_info->r_wall_t = NULL;
	map_info->corner_bl_t = NULL;
	map_info->corner_br_t = NULL;
	map_info->corner_tl_t = NULL;
	map_info->corner_tr_t = NULL;
	map_info->stone_t = NULL;
	map_info->ground_t = NULL;
	map_info->coin_t = NULL;
	map_info->exit_t = NULL;
	map_info->c_exit_t = NULL;
	map_info->player_r->player_01 = NULL;
	map_info->player_r->player_02 = NULL;
	map_info->player_r->player_03 = NULL;
	map_info->player_r->player_04 = NULL;
	map_info->player_r->player_05 = NULL;
	map_info->player_r->player_01_t = NULL;
	map_info->player_r->player_02_t = NULL;
	map_info->player_r->player_03_t = NULL;
	map_info->player_r->player_04_t = NULL;
	map_info->player_r->player_05_t = NULL;
}

void	new_player_render(t_map_info *map_info)
{
	t_player_render	*player_render;

	player_render = malloc(sizeof(t_player_render));
	if (!player_render)
		print_error("failure while mem_alloc(map_info->player_r)", map_info);
	map_info->player_r = player_render;
}

t_map_info	*new_map_info(void)
{
	t_map_info	*map_info;

	map_info = malloc(sizeof(t_map_info));
	if (!map_info)
		print_error("failure while mem_alloc(map_info)", map_info);
	map_info->collectables = 0;
	map_info->exits = 0;
	map_info->players = 0;
	map_info->x_size = 0;
	map_info->y_size = 0;
	map_info->map = malloc(sizeof(char *) * 100);
	if (!(map_info->map))
		print_error("failure while mem_alloc(map_info->map)", map_info);
	map_info->p_pos_x = 0;
	map_info->p_pos_y = 0;
	map_info->ff_collec = 0;
	map_info->ff_exits = 0;
	map_info->fd = 0;
	map_info->steps = 0;
	set_mapvalues_null(map_info);
	new_player_render(map_info);
	new_tfly_render(map_info);
	new_rfly_render(map_info);
	initialize_textures(map_info);
	return (map_info);
}
