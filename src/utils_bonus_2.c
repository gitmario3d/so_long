/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus_2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malena-b <mario3d93@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 13:09:26 by malena-b          #+#    #+#             */
/*   Updated: 2024/02/01 14:06:54 by malena-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long_bonus.h"

mlx_image_t	*init_pl_img(t_map_info *m_i, mlx_texture_t *texture)
{
	mlx_image_t	*image;

	image = mlx_texture_to_image(m_i->mlx, texture);
	if (!image)
		print_error("problem creating player image (init_pl_img)", m_i);
	return (image);
}

void	disable_anim_imgs(t_player_render *player_r)
{
	player_r->player_01->instances[0].enabled = false;
	player_r->player_02->instances[0].enabled = false;
	player_r->player_03->instances[0].enabled = false;
	player_r->player_04->instances[0].enabled = false;
	player_r->player_05->instances[0].enabled = false;
}

void	set_mapvalues_null(t_map_info *map_info)
{
	map_info->ff_map = NULL;
	map_info->moves_img = NULL;
	map_info->count = NULL;
	map_info->tfly_r = NULL;
	map_info->rfly_r = NULL;
	map_info->rflies = 0;
	map_info->tflies = 0;
}

void	init_enemies_imgs(t_map_info *m_i)
{
	init_tfly_imgs(m_i->tfly_r, m_i->mlx, m_i);
	init_rfly_imgs(m_i->rfly_r, m_i->mlx, m_i);
}

void	kill_check(t_map_info *m_i)
{
	if ((m_i->p_pos_x == m_i->tfly_r->x && m_i->p_pos_y == m_i->tfly_r->y)
		|| (m_i->p_pos_x == m_i->rfly_r->x && m_i->p_pos_y == m_i->rfly_r->y))
	{
		ft_printf("YOU DIED!\n");
		free_all(m_i);
		exit (0);
	}
}
