/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_fts_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malena-b <mario3d93@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 08:56:03 by malena-b          #+#    #+#             */
/*   Updated: 2024/01/30 13:20:19 by malena-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long_bonus.h"

void	free_map_textures(t_map_info *map_info)
{
	if (map_info->b_wall_t)
		mlx_delete_texture(map_info->b_wall_t);
	if (map_info->t_wall_t)
		mlx_delete_texture(map_info->t_wall_t);
	if (map_info->l_wall_t)
		mlx_delete_texture(map_info->l_wall_t);
	if (map_info->r_wall_t)
		mlx_delete_texture(map_info->r_wall_t);
	if (map_info->corner_bl_t)
		mlx_delete_texture(map_info->corner_bl_t);
	if (map_info->corner_br_t)
		mlx_delete_texture(map_info->corner_br_t);
	if (map_info->corner_tl_t)
		mlx_delete_texture(map_info->corner_tl_t);
	if (map_info->corner_tr_t)
		mlx_delete_texture(map_info->corner_tr_t);
	if (map_info->stone_t)
		mlx_delete_texture(map_info->stone_t);
	if (map_info->ground_t)
		mlx_delete_texture(map_info->ground_t);
	if (map_info->exit_t)
		mlx_delete_texture(map_info->exit_t);
	if (map_info->c_exit_t)
		mlx_delete_texture(map_info->c_exit_t);
}

void	free_items_texture(t_map_info *map_info)
{
	if (map_info->coin_t)
		mlx_delete_texture(map_info->coin_t);
	if (map_info->player_r->player_01_t)
		mlx_delete_texture(map_info->player_r->player_01_t);
	if (map_info->player_r->player_02_t)
		mlx_delete_texture(map_info->player_r->player_02_t);
	if (map_info->player_r->player_03_t)
		mlx_delete_texture(map_info->player_r->player_03_t);
	if (map_info->player_r->player_04_t)
		mlx_delete_texture(map_info->player_r->player_04_t);
	if (map_info->player_r->player_05_t)
		mlx_delete_texture(map_info->player_r->player_05_t);
}

void	free_all(t_map_info *map_info)
{
	if (map_info)
	{
		if (map_info->map)
			free_mat(map_info->map);
		if (map_info->ff_map)
			free_mat(map_info->ff_map);
		if (map_info->count)
			free (map_info->count);
		free_map_textures(map_info);
		free_items_texture(map_info);
		if (map_info->mlx)
			mlx_terminate(map_info->mlx);
		close (map_info->fd);
		if (map_info->player_r)
			free(map_info->player_r);
		free(map_info);
	}
}
