/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malena-b <mario3d93@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 11:11:04 by malena-b          #+#    #+#             */
/*   Updated: 2024/02/02 13:55:43 by malena-b         ###   ########.fr       */
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

void	tflie_anim(t_tfly_rend *tflie_r, int timer)
{
	if (timer == 0 || timer == 12)
	{
		tflie_r->tfly_04->instances[0].enabled = false;
		tflie_r->tfly_01->instances[0].enabled = true;
	}
	else if (timer == 3 || timer == 15)
	{
		tflie_r->tfly_01->instances[0].enabled = false;
		tflie_r->tfly_02->instances[0].enabled = true;
	}
	else if (timer == 6 || timer == 18)
	{
		tflie_r->tfly_02->instances[0].enabled = false;
		tflie_r->tfly_03->instances[0].enabled = true;
	}
	else if (timer == 9 || timer == 21)
	{
		tflie_r->tfly_03->instances[0].enabled = false;
		tflie_r->tfly_04->instances[0].enabled = true;
	}
}

void	rflie_anim(t_rfly_rend *rflie_r, int timer)
{
	if (timer == 0 || timer == 12)
	{
		rflie_r->rfly_04->instances[0].enabled = false;
		rflie_r->rfly_01->instances[0].enabled = true;
	}
	else if (timer == 3 || timer == 15)
	{
		rflie_r->rfly_01->instances[0].enabled = false;
		rflie_r->rfly_02->instances[0].enabled = true;
	}
	else if (timer == 6 || timer == 18)
	{
		rflie_r->rfly_02->instances[0].enabled = false;
		rflie_r->rfly_03->instances[0].enabled = true;
	}
	else if (timer == 9 || timer == 21)
	{
		rflie_r->rfly_03->instances[0].enabled = false;
		rflie_r->rfly_04->instances[0].enabled = true;
	}
}

void	main_hook(void *map_info)
{
	t_map_info		*m_i;
	static int		anim_timer;
	static int		move_timer;
	static int		random_generator;

	m_i = map_info;
	player_anim(m_i->player_r, anim_timer);
	if (m_i->tflies)
		tflie_anim(m_i->tfly_r, anim_timer);
	if (m_i->rflies)
		rflie_anim(m_i->rfly_r, anim_timer);
	anim_timer++;
	move_timer++;
	random_generator++;
	if (anim_timer >= 25)
		anim_timer = 0;
	if (random_generator >= 9)
		random_generator = 0;
	if ((move_timer == 20 || move_timer >= 50))
		rflie_movement(m_i, m_i->rfly_r, random_generator);
	if (move_timer >= 50 && m_i->tflies)
		tflie_movement(m_i, m_i->tfly_r, random_generator);
	if (move_timer >= 50)
		move_timer = 0;
}
