/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malena-b <mario3d93@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 11:11:04 by malena-b          #+#    #+#             */
/*   Updated: 2024/01/30 13:18:30 by malena-b         ###   ########.fr       */
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

/*void	main_hook(void *map_info)
{
	t_map_info	*m_i;

	m_i = map_info;
}*/