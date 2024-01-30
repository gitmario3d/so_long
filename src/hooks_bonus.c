/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malena-b <mario3d93@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 11:11:04 by malena-b          #+#    #+#             */
/*   Updated: 2024/01/30 14:17:50 by malena-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long_bonus.h"

void	my_keyhook(mlx_key_data_t keydata, void *param)
{
	t_map_info	*m_i;
	int			moved;

	moved = 0;
	m_i = param;
	if (keydata.key == MLX_KEY_UP && keydata.action == MLX_PRESS)
		moved = check_move(m_i, 1, m_i->p_pos_y - 1, m_i->p_pos_x);
	else if (keydata.key == MLX_KEY_RIGHT && keydata.action == MLX_PRESS)
		moved = check_move(m_i, 2, m_i->p_pos_y, m_i->p_pos_x + 1);
	else if (keydata.key == MLX_KEY_DOWN && keydata.action == MLX_PRESS)
		moved = check_move(m_i, 3, m_i->p_pos_y + 1, m_i->p_pos_x);
	else if (keydata.key == MLX_KEY_LEFT && keydata.action == MLX_PRESS)
		moved = check_move(m_i, 4, m_i->p_pos_y, m_i->p_pos_x - 1);
	else if (keydata.key == MLX_KEY_ESCAPE && keydata.action == MLX_PRESS)
	{
		free_all(m_i);
		exit (0);
	}
	if (moved)
		reload_count(m_i);
}

void	player_anim(t_player_render *player_r, int timer)
{
	if (timer == 0)
	{
		player_r->player_05->instances[0].enabled = false;
		player_r->player_01->instances[0].enabled = true;
	}
	else if (timer == 5)
	{
		player_r->player_01->instances[0].enabled = false;
		player_r->player_02->instances[0].enabled = true;
	}
	else if (timer == 10)
	{
		player_r->player_02->instances[0].enabled = false;
		player_r->player_03->instances[0].enabled = true;
	}
	else if (timer == 15)
	{
		player_r->player_03->instances[0].enabled = false;
		player_r->player_04->instances[0].enabled = true;
	}
	else if (timer == 20)
	{
		player_r->player_04->instances[0].enabled = false;
		player_r->player_05->instances[0].enabled = true;
	}
}

void	main_hook(void *map_info)
{
	t_map_info		*m_i;
	static int		timer;

	m_i = map_info;
	player_anim(m_i->player_r, timer);
	timer++;
	if (timer >= 25)
		timer = 0;
}
