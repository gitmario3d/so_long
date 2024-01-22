/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setmap.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malena-b <mario3d93@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 10:47:58 by malena-b          #+#    #+#             */
/*   Updated: 2024/01/18 14:34:58 by malena-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

mlx_image_t	*check_sprites(t_map_info *map_info, mlx_t *mlx, int y, int x)
{
	if (map_info->map[y][x] == '1')
		return (map_info->wall);
	else if (map_info->map[y][x] == '0')
		return (map_info->ground);
	else if (map_info->map[y][x] == 'C')
		return (map_info->coin);
	else if (map_info->map[y][x] == 'E')
		return (map_info->exit);
	return (NULL);
}

void	set_tiles(t_map_info *map_info)
{
	mlx_image_t	*img;
	mlx_t		*mlx;
	int			y;
	int			x;

	mlx = map_info->mlx;
	y = 0;
	while (y < map_info->y_size)
	{
		x = 0;
		while (x <= map_info->x_size)
		{
			comprobar si lo de los muros funciona
			img = check_sprites(map_info, mlx, y, x);
			if (mlx_image_to_window(mlx, img, (x++) * 64, y * 64) < 0)
				print_error("problem rendering wall_t", map_info);
		}
		y++;
	}
}
