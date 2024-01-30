/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_move_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malena-b <mario3d93@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 13:37:41 by malena-b          #+#    #+#             */
/*   Updated: 2024/01/30 12:51:45 by malena-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long_bonus.h"

void	move_player_imgs(t_map_info *map_info, int direction, int move)
{
	t_player_render	*player_render;
	int				i;

	player_render = map_info->player_r;
	i = 0;
	if (direction == 1 || direction == 3)
	{
		map_info->p_pos_y += move;
		(player_render->player_01)->instances[0].y += (move * 64);
		(player_render->player_02)->instances[0].y += (move * 64);
		(player_render->player_03)->instances[0].y += (move * 64);
		(player_render->player_04)->instances[0].y += (move * 64);
		(player_render->player_05)->instances[0].y += (move * 64);
	}
	else if (direction == 2 || direction == 4)
	{
		map_info->p_pos_x += move;
		(player_render->player_01)->instances[0].x += (move * 64);
		(player_render->player_02)->instances[0].x += (move * 64);
		(player_render->player_03)->instances[0].x += (move * 64);
		(player_render->player_04)->instances[0].x += (move * 64);
		(player_render->player_05)->instances[0].x += (move * 64);
	}
}

int	move_player(t_map_info *map_info, int direction)
{
	if (direction == 1)
		move_player_imgs(map_info, direction, -1);
	else if (direction == 2)
		move_player_imgs(map_info, direction, 1);
	else if (direction == 3)
		move_player_imgs(map_info, direction, 1);
	else if (direction == 4)
		move_player_imgs(map_info, direction, -1);
	ft_printf("You moved %d times!\n", ++(map_info->steps));
	return (1);
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

int	check_move(t_map_info *map_info, int direction, int y, int x)
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
			return (move_player(map_info, direction));
		}
		else if (next_pos == 'E')
			check_exit_move(map_info, direction);
		else
			return (move_player(map_info, direction));
	}
	return (0);
}
