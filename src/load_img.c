/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_img.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malena-b <mario3d93@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 11:01:40 by malena-b          #+#    #+#             */
/*   Updated: 2024/01/26 13:12:10 by malena-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	load_extcorner_textimg(t_map_info *m_i)
{
	char	*path;

	path = NULL;
	path = create_path(m_i, "bl_corner.png", path);
	m_i->corner_bl_t = mlx_load_png(path);
	m_i->corner_bl = mlx_texture_to_image(m_i->mlx, m_i->corner_bl_t);
	path = create_path(m_i, "br_corner.png", path);
	m_i->corner_br_t = mlx_load_png(path);
	m_i->corner_br = mlx_texture_to_image(m_i->mlx, m_i->corner_br_t);
	path = create_path(m_i, "tl_corner.png", path);
	m_i->corner_tl_t = mlx_load_png(path);
	m_i->corner_tl = mlx_texture_to_image(m_i->mlx, m_i->corner_tl_t);
	path = create_path(m_i, "tr_corner.png", path);
	m_i->corner_tr_t = mlx_load_png(path);
	m_i->corner_tr = mlx_texture_to_image(m_i->mlx, m_i->corner_tr_t);
	free(path);
	if (!m_i->corner_tr || !m_i->corner_br || !m_i->corner_tl
		|| !m_i->corner_bl)
		print_error("problem creating the corners imgs.", m_i);
}

void	load_extwall_textimg(t_map_info *m_i)
{
	char	*path;

	path = NULL;
	path = create_path(m_i, "t_wall.png", path);
	m_i->t_wall_t = mlx_load_png(path);
	m_i->t_wall = mlx_texture_to_image(m_i->mlx, m_i->t_wall_t);
	path = create_path(m_i, "b_wall.png", path);
	m_i->b_wall_t = mlx_load_png(path);
	m_i->b_wall = mlx_texture_to_image(m_i->mlx, m_i->b_wall_t);
	path = create_path(m_i, "l_wall.png", path);
	m_i->l_wall_t = mlx_load_png(path);
	m_i->l_wall = mlx_texture_to_image(m_i->mlx, m_i->l_wall_t);
	path = create_path(m_i, "r_wall.png", path);
	m_i->r_wall_t = mlx_load_png(path);
	m_i->r_wall = mlx_texture_to_image(m_i->mlx, m_i->r_wall_t);
	free(path);
	if (!m_i->r_wall || !m_i->l_wall || !m_i->b_wall || !m_i->t_wall)
		print_error("problem creating the sides walls imgs.", m_i);
}

void	load_textures_imgs(t_map_info *m_i)
{
	char	*path;

	path = NULL;
	m_i->mlx = mlx_init(m_i->x_size * 64, m_i->y_size * 64, "Window", true);
	path = create_path(m_i, "rock.png", path);
	m_i->stone_t = mlx_load_png(path);
	m_i->stone = mlx_texture_to_image(m_i->mlx, m_i->stone_t);
	path = create_path(m_i, "ground.png", path);
	m_i->ground_t = mlx_load_png(path);
	m_i->ground = mlx_texture_to_image(m_i->mlx, m_i->ground_t);
	path = create_path(m_i, "coin_01.png", path);
	m_i->coin_t = mlx_load_png(path);
	m_i->coin = mlx_texture_to_image(m_i->mlx, m_i->coin_t);
	path = create_path(m_i, "o_exit.png", path);
	m_i->exit_t = mlx_load_png(path);
	m_i->exit = mlx_texture_to_image(m_i->mlx, m_i->exit_t);
	path = create_path(m_i, "c_exit.png", path);
	m_i->c_exit_t = mlx_load_png(path);
	m_i->c_exit = mlx_texture_to_image(m_i->mlx, m_i->c_exit_t);
	free (path);
	if (!m_i->c_exit || !m_i->exit || !m_i->mlx || !m_i->stone || !m_i->ground
		|| !m_i->coin)
		print_error("problem creating the c_exit img.", m_i);
	load_extwall_textimg(m_i);
	load_extcorner_textimg(m_i);
}

void	reload_player(t_map_info *m_i)
{
	mlx_delete_texture(m_i->player_t);
	mlx_delete_image(m_i->mlx, m_i->player);
	set_player_t(m_i);
}
