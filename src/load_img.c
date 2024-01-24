/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_img.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malena-b <mario3d93@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 11:01:40 by malena-b          #+#    #+#             */
/*   Updated: 2024/01/24 11:43:22 by malena-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	load_extcorner_textimg(t_map_info *m_i)
{
	m_i->corner_bl_t = mlx_load_png(create_path(m_i, "bl_corner.png"));
	m_i->corner_bl = mlx_texture_to_image(m_i->mlx, m_i->corner_bl_t);
	if (!m_i->corner_bl)
		print_error("problem creating the corner_bl img.", m_i);
	m_i->corner_br_t = mlx_load_png(create_path(m_i, "br_corner.png"));
	m_i->corner_br = mlx_texture_to_image(m_i->mlx,
			m_i->corner_br_t);
	if (!m_i->corner_br)
		print_error("problem creating the corner_br img.", m_i);
	m_i->corner_tl_t = mlx_load_png(create_path(m_i, "tl_corner.png"));
	m_i->corner_tl = mlx_texture_to_image(m_i->mlx,
			m_i->corner_tl_t);
	if (!m_i->corner_tl)
		print_error("problem creating the corner_tl img.", m_i);
	m_i->corner_tr_t = mlx_load_png(create_path(m_i, "tr_corner.png"));
	m_i->corner_tr = mlx_texture_to_image(m_i->mlx,
			m_i->corner_tr_t);
	if (!m_i->corner_tr)
		print_error("problem creating the corner_tr img.", m_i);
}

void	load_extwall_textimg(t_map_info *map_info)
{
	map_info->t_wall_t = mlx_load_png(create_path(map_info, "t_wall.png"));
	map_info->t_wall = mlx_texture_to_image(map_info->mlx, map_info->t_wall_t);
	if (!map_info->t_wall)
		print_error("problem creating the t_wall img.", map_info);
	map_info->b_wall_t = mlx_load_png(create_path(map_info, "b_wall.png"));
	map_info->b_wall = mlx_texture_to_image(map_info->mlx, map_info->b_wall_t);
	if (!map_info->b_wall)
		print_error("problem creating the b_wall img.", map_info);
	map_info->l_wall_t = mlx_load_png(create_path(map_info, "l_wall.png"));
	map_info->l_wall = mlx_texture_to_image(map_info->mlx, map_info->l_wall_t);
	if (!map_info->l_wall)
		print_error("problem creating the l_wall img.", map_info);
	map_info->r_wall_t = mlx_load_png(create_path(map_info, "r_wall.png"));
	map_info->r_wall = mlx_texture_to_image(map_info->mlx, map_info->r_wall_t);
	if (!map_info->r_wall)
		print_error("problem creating the r_wall img.", map_info);
}

void	load_textures_imgs(t_map_info *map_info)
{
	map_info->mlx = mlx_init(map_info->x_size * 64, map_info->y_size * 64,
			"Test", true);
	if (!map_info->mlx)
		print_error("problem creating the window.", map_info);
	map_info->wall_t = mlx_load_png(create_path(map_info, "rock.png"));
	map_info->wall = mlx_texture_to_image(map_info->mlx, map_info->wall_t);
	if (!map_info->wall)
		print_error("problem creating the wall img.", map_info);
	map_info->ground_t = mlx_load_png(create_path(map_info, "ground.png"));
	map_info->ground = mlx_texture_to_image(map_info->mlx, map_info->ground_t);
	if (!map_info->ground)
		print_error("problem creating the ground img.", map_info);
	map_info->coin_t = mlx_load_png(create_path(map_info, "coin_01.png"));
	map_info->coin = mlx_texture_to_image(map_info->mlx, map_info->coin_t);
	if (!map_info->coin)
		print_error("problem creating the coin img.", map_info);
	map_info->exit_t = mlx_load_png(create_path(map_info, "o_exit.png"));
	map_info->exit = mlx_texture_to_image(map_info->mlx, map_info->exit_t);
	if (!map_info->exit)
		print_error("problem creating the exit img.", map_info);
	load_extwall_textimg(map_info);
	load_extcorner_textimg(map_info);
}

void	reload_player(t_map_info *map_info)
{
	mlx_delete_texture(map_info->player_t);
	mlx_delete_image(map_info->mlx, map_info->player);
	set_player_t(map_info);
}