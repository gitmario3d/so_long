/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_move.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malena-b <mario3d93@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 13:37:41 by malena-b          #+#    #+#             */
/*   Updated: 2024/01/26 12:22:31 by malena-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	move_player(t_map_info *map_info, int direction)
{
	if (direction == 1)
	{
		map_info->p_pos_y--;
		(map_info->player)->instances[0].y -= 64;
	}
	if (direction == 2)
	{
		map_info->p_pos_x++;
		(map_info->player)->instances[0].x += 64;
	}
	if (direction == 3)
	{
		map_info->p_pos_y++;
		(map_info->player)->instances[0].y += 64;
	}
	if (direction == 4)
	{
		map_info->p_pos_x--;
		(map_info->player)->instances[0].x -= 64;
	}
	ft_printf("You moved %d times!\n", ++(map_info->steps));
}

void	check_exit_move(t_map_info *map_info, int direction)
{
	if (map_info->collectables == 0)
	{
		move_player(map_info, direction);
		free_all(map_info);
		exit (0);
	}
}

void	check_move(t_map_info *map_info, int direction, int y, int x)
{
	char		next_pos;
	mlx_image_t	*ground;

	ground = map_info->ground;
	next_pos = map_info->map[y][x];
	if (next_pos != '1')
	{
		if (next_pos == 'C')
		{
			map_info->map[y][x] = '0';
			map_info->collectables--;
			if (mlx_image_to_window(map_info->mlx, ground, x * 64, y * 64) < 0)
				print_error("problem rendering coin reached", map_info);
			if (map_info->collectables == 0)
				map_info->c_exit->enabled = false;
			reload_player(map_info);
			move_player(map_info, direction);
		}
		else if (next_pos == 'E')
			check_exit_move(map_info, direction);
		else
			move_player(map_info, direction);
	}
}
