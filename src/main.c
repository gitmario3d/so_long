/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malena-b <mario3d93@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/27 11:55:49 by malena-b          #+#    #+#             */
/*   Updated: 2024/01/22 12:21:51 by malena-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

t_map_info	*new_map_info(void)
{
	t_map_info	*map_info;

	map_info = malloc(sizeof(t_map_info));
	if (!map_info)
		return (NULL);
	map_info->collectables = 0;
	map_info->exits = 0;
	map_info->players = 0;
	map_info->x_size = 0;
	map_info->y_size = 0;
	map_info->map = malloc(sizeof(char *) * 100);
	if (!(map_info->map))
		print_error("failure while mem_alloc(map_info->map)", map_info);
	map_info->p_pos_x = 0;
	map_info->p_pos_y = 0;
	map_info->ff_collec = 0;
	map_info->ff_exits = 0;
	map_info->ff_map = NULL;
	map_info->fd = 0;
	return (map_info);
}

void	print_error(char *errormsg, t_map_info *map_info)
{
	int	i;

	i = 0;
	if (map_info)
	{
		if (map_info->map)
		{
			while (map_info->map[i])
				free(map_info->map[i++]);
			free(map_info->map);
		}
		if (map_info->ff_map)
		{
			while (map_info->ff_map[i])
				free(map_info->ff_map[i++]);
			free(map_info->ff_map);
		}
		free(map_info);
	}
	ft_printf("Error, %s\n", errormsg);
	exit(0);
}

void	my_keyhook(mlx_key_data_t keydata, void *param)
{
	mlx_image_t	*img;

	img = param;
	if (keydata.key == MLX_KEY_RIGHT && keydata.action == MLX_PRESS)
		img->instances[0].x += 64;
	if (keydata.key == MLX_KEY_LEFT && keydata.action == MLX_PRESS)
		img->instances[0].x -= 64;
	if (keydata.key == MLX_KEY_DOWN && keydata.action == MLX_PRESS)
		img->instances[0].y += 64;
	if (keydata.key == MLX_KEY_UP && keydata.action == MLX_PRESS)
		img->instances[0].y -= 64;
}

int	main(int argc, char **argv)
{
	t_map_info		*map_info;
	mlx_t			*mlx;
	mlx_image_t		*player;
	mlx_texture_t	*texture;

	map_info = new_map_info();
	if (!map_info)
		print_error("failure at mem_alloc(map_info)", map_info);
	check_map(argc, argv, map_info);
	load_textures_imgs(map_info);
	set_tiles(map_info);
	texture = mlx_load_png("./sprites/purple.png");
	mlx = map_info->mlx;
	player = mlx_texture_to_image(mlx, texture);
	if (!player || (mlx_image_to_window(mlx, player, 64, 64) < 0))
		print_error("problem creating the player.", map_info);
	mlx_key_hook(mlx, &my_keyhook, player);
	mlx_loop(map_info->mlx);
}
// memset(img->pixels, 125, img->width * img->height * sizeof(int32_t));
