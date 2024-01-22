/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setmap.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malena-b <mario3d93@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 10:47:58 by malena-b          #+#    #+#             */
/*   Updated: 2024/01/22 12:18:57 by malena-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

mlx_image_t	*check_walls_spr(t_map_info *map_info, char content, int y, int x)
{
	int	x_size;
	int	y_size;

	x_size = map_info->x_size;
	y_size = map_info->y_size;
	if (content == '1' && y == 0 && x == 0)
		return (map_info->corner_tl);
	else if (content == '1' && y == 0 && x == (x_size - 1))
		return (map_info->corner_tr);
	else if (content == '1' && y == (y_size - 1) && x == 0)
		return (map_info->corner_bl);
	else if (content == '1' && y == (y_size - 1) && x == (x_size - 1))
		return (map_info->corner_br);
	else if (content == '1' && y == 0)
		return (map_info->t_wall);
	else if (content == '1' && x == 0)
		return (map_info->l_wall);
	else if (content == '1' && y == (y_size - 1))
		return (map_info->b_wall);
	else if (content == '1' && x == (x_size - 1))
		return (map_info->r_wall);
	return (NULL);
}

mlx_image_t	*check_sprites(t_map_info *map_info, int y, int x)
{
	mlx_image_t	*return_value;
	char		content;

	content = map_info->map[y][x];
	return_value = check_walls_spr(map_info, content, y, x);
	if (return_value)
		return (return_value);
	if (content == '1')
		return (map_info->wall);
	else if (content == '0' || content == 'P')
		return (map_info->ground);
	else if (content == 'C')
		return (map_info->coin);
	else if (content == 'E')
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
		while (x < map_info->x_size)
		{
			img = check_sprites(map_info, y, x);
			if (mlx_image_to_window(mlx, img, (x++) * 64, y * 64) < 0)
				print_error("problem rendering wall_t", map_info);
		}
		y++;
	}
}
