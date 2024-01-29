/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malena-b <mario3d93@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 14:11:26 by malena-b          #+#    #+#             */
/*   Updated: 2024/01/29 13:20:54 by malena-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long_bonus.h"

void	flood_fill(t_map_info *map_info, int x, int y)
{
	if (map_info->ff_map[y][x] == '1')
		return ;
	if (map_info->ff_map[y][x] == 'C')
		map_info->ff_collec++;
	if (map_info->ff_map[y][x] == 'E')
		map_info->ff_exits++;
	map_info->ff_map[y][x] = '1';
	flood_fill(map_info, x, y - 1);
	flood_fill(map_info, x, y + 1);
	flood_fill(map_info, x - 1, y);
	flood_fill(map_info, x + 1, y);
}

void	check_floodfill(t_map_info *map_info)
{
	int	i;

	i = 0;
	map_info->ff_map = matdup(map_info->map);
	flood_fill(map_info, map_info->p_pos_x, map_info->p_pos_y);
	if (map_info->collectables != map_info->ff_collec)
		print_error ("couldn't reach all the collectables.", map_info);
	if (map_info->ff_exits != map_info->exits)
		print_error ("couldn't reach the exit.", map_info);
}
