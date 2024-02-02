/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flies_movement_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malena-b <mario3d93@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 08:41:23 by malena-b          #+#    #+#             */
/*   Updated: 2024/02/02 14:01:39 by malena-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long_bonus.h"

void	move_tflie(t_tfly_rend *tfly_rend, int direction, int move)
{
	int	i;

	i = 0;
	if (direction == 1 || direction == 3)
	{
		tfly_rend->y += move;
		tfly_rend->tfly_01->instances[0].y += (move * 64);
		tfly_rend->tfly_02->instances[0].y += (move * 64);
		tfly_rend->tfly_03->instances[0].y += (move * 64);
		tfly_rend->tfly_04->instances[0].y += (move * 64);
	}
	else if (direction == 2 || direction == 4)
	{
		tfly_rend->x += move;
		tfly_rend->tfly_01->instances[0].x += (move * 64);
		tfly_rend->tfly_02->instances[0].x += (move * 64);
		tfly_rend->tfly_03->instances[0].x += (move * 64);
		tfly_rend->tfly_04->instances[0].x += (move * 64);
	}
}

int	tfly_checkdirection(t_map_info *m_i, t_tfly_rend *tfly_r, int random)
{
	int	direction;

	direction = 0;
	if (m_i->p_pos_x == tfly_r->x && m_i->p_pos_y < tfly_r->y)
		direction = 1;
	else if (m_i->p_pos_x > tfly_r->x && m_i->p_pos_y == tfly_r->y)
		direction = 2;
	else if (m_i->p_pos_x == tfly_r->x && m_i->p_pos_y > tfly_r->y)
		direction = 3;
	else if (m_i->p_pos_x < tfly_r->x && m_i->p_pos_y == tfly_r->y)
		direction = 4;
	else if (m_i->p_pos_x > tfly_r->x && m_i->p_pos_y < tfly_r->y)
		direction = fifty_fifty(1, 2, random);
	else if (m_i->p_pos_x > tfly_r->x && m_i->p_pos_y > tfly_r->y)
		direction = fifty_fifty(2, 3, random);
	else if (m_i->p_pos_x < tfly_r->x && m_i->p_pos_y > tfly_r->y)
		direction = fifty_fifty(3, 4, random);
	else if (m_i->p_pos_x < tfly_r->x && m_i->p_pos_y < tfly_r->y)
		direction = fifty_fifty(4, 1, random);
	return (direction);
}

int	tflie_movement(t_map_info *m_i, t_tfly_rend	*tfly, int random)
{
	int	direction;

	direction = 0;
	direction = tfly_checkdirection(m_i, tfly, random);
	if (direction == 1)
		move_tflie(tfly, direction, -1);
	else if (direction == 2)
		move_tflie(tfly, direction, 1);
	else if (direction == 3)
		move_tflie(tfly, direction, 1);
	else if (direction == 4)
		move_tflie(tfly, direction, -1);
	kill_check(m_i);
	return (1);
}

void	move_rflie(t_rfly_rend *rfly_rend, int direction, int move)
{
	int	i;

	i = 0;
	if (direction == 1 || direction == 3)
	{
		rfly_rend->y += move;
		rfly_rend->rfly_01->instances[0].y += (move * 64);
		rfly_rend->rfly_02->instances[0].y += (move * 64);
		rfly_rend->rfly_03->instances[0].y += (move * 64);
		rfly_rend->rfly_04->instances[0].y += (move * 64);
	}
	else if (direction == 2 || direction == 4)
	{
		rfly_rend->x += move;
		rfly_rend->rfly_01->instances[0].x += (move * 64);
		rfly_rend->rfly_02->instances[0].x += (move * 64);
		rfly_rend->rfly_03->instances[0].x += (move * 64);
		rfly_rend->rfly_04->instances[0].x += (move * 64);
	}
}

int	rflie_movement(t_map_info *m_i, t_rfly_rend	*rfly, int r1)
{
	int	axis;
	int	direction;

	axis = 0;
	direction = 0;
	axis = fifty_fifty(1, 2, r1);
	if (axis == 1)
	{
		direction = fifty_fifty(1, 3, m_i->p_pos_x);
		if (direction == 1 && rfly->y > 1)
			move_rflie(rfly, direction, -1);
		else if (direction == 3 && rfly->y < m_i->y_size - 2)
			move_rflie(rfly, direction, 1);
	}
	else if (axis == 2)
	{
		direction = fifty_fifty(2, 4, m_i->p_pos_x);
		if (direction == 2 && rfly->x < m_i->x_size - 2)
			move_rflie(rfly, direction, 1);
		else if (direction == 4 && rfly->x > 1)
			move_rflie(rfly, direction, -1);
	}
	kill_check(m_i);
	return (1);
}
