/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_img_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malena-b <mario3d93@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 11:01:40 by malena-b          #+#    #+#             */
/*   Updated: 2024/02/02 13:51:04 by malena-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long_bonus.h"

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
	free(path);
	if (!m_i->c_exit || !m_i->exit || !m_i->mlx || !m_i->stone || !m_i->ground
		|| !m_i->coin)
		print_error("problem creating the imgs (load_texture_imgs).", m_i);
	load_extwall_textimg(m_i);
	load_extcorner_textimg(m_i);
}

void	reload_anims(t_map_info *m_i)
{
	mlx_delete_image(m_i->mlx, m_i->player_r->player_01);
	mlx_delete_image(m_i->mlx, m_i->player_r->player_02);
	mlx_delete_image(m_i->mlx, m_i->player_r->player_03);
	mlx_delete_image(m_i->mlx, m_i->player_r->player_04);
	mlx_delete_image(m_i->mlx, m_i->player_r->player_05);
	set_player_t(m_i);
	if (m_i->tflies)
	{
		mlx_delete_image(m_i->mlx, m_i->tfly_r->tfly_01);
		mlx_delete_image(m_i->mlx, m_i->tfly_r->tfly_02);
		mlx_delete_image(m_i->mlx, m_i->tfly_r->tfly_03);
		mlx_delete_image(m_i->mlx, m_i->tfly_r->tfly_04);
		init_tfly_imgs(m_i->tfly_r, m_i->mlx, m_i);
	}
	if (m_i->rflies)
	{
		mlx_delete_image(m_i->mlx, m_i->rfly_r->rfly_01);
		mlx_delete_image(m_i->mlx, m_i->rfly_r->rfly_02);
		mlx_delete_image(m_i->mlx, m_i->rfly_r->rfly_03);
		mlx_delete_image(m_i->mlx, m_i->rfly_r->rfly_04);
		init_rfly_imgs(m_i->rfly_r, m_i->mlx, m_i);
	}
	render_flies_onmap(m_i, m_i->tfly_r, m_i->rfly_r);
	disable_anim_imgs(m_i);
}

void	set_player_t(t_map_info *map_info)
{
	int				pos_y;
	int				pos_x;
	t_player_render	*p_r;

	p_r = map_info->player_r;
	pos_y = map_info->p_pos_y * 64;
	pos_x = map_info->p_pos_x * 64;
	p_r->player_01 = init_pl_img(map_info, p_r->player_01_t);
	p_r->player_02 = init_pl_img(map_info, p_r->player_02_t);
	p_r->player_03 = init_pl_img(map_info, p_r->player_03_t);
	p_r->player_04 = init_pl_img(map_info, p_r->player_04_t);
	p_r->player_05 = init_pl_img(map_info, p_r->player_05_t);
	if (!p_r->player_01 || !p_r->player_02 || !p_r->player_03 || !p_r->player_04
		|| !p_r->player_05)
		print_error("problem creating the player images.", map_info);
	if ((mlx_image_to_window(map_info->mlx, p_r->player_01, pos_x, pos_y) < 0))
		print_error("problem rendering the player_01 image.", map_info);
	if ((mlx_image_to_window(map_info->mlx, p_r->player_02, pos_x, pos_y) < 0))
		print_error("problem rendering the player_02 image.", map_info);
	if ((mlx_image_to_window(map_info->mlx, p_r->player_03, pos_x, pos_y) < 0))
		print_error("problem rendering the player_03 image.", map_info);
	if ((mlx_image_to_window(map_info->mlx, p_r->player_04, pos_x, pos_y) < 0))
		print_error("problem rendering the player_04 image.", map_info);
	if ((mlx_image_to_window(map_info->mlx, p_r->player_05, pos_x, pos_y) < 0))
		print_error("problem rendering the player_05 image.", map_info);
}
