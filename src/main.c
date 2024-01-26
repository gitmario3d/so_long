/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malena-b <mario3d93@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/27 11:55:49 by malena-b          #+#    #+#             */
/*   Updated: 2024/01/26 10:42:49 by malena-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	leak(void)
{
	system("leaks so_long");
}

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
	map_info->steps = 0;
	return (map_info);
}

void	print_error(char *errormsg, t_map_info *map_info)
{
	free_all(map_info);
	ft_printf("Error, %s\n", errormsg);
	exit(0);
}

void	my_keyhook(mlx_key_data_t keydata, void *param)
{
	t_map_info	*map_info;
	mlx_image_t	*img;
	char		**map;
	int			*xp;
	int			*yp;

	map_info = param;
	img = map_info->player;
	map = map_info->map;
	xp = &(map_info->p_pos_x);
	yp = &(map_info->p_pos_y);
	if (keydata.key == MLX_KEY_UP && keydata.action == MLX_PRESS)
		check_move(map_info, 1, map_info->p_pos_y - 1, map_info->p_pos_x);
	if (keydata.key == MLX_KEY_RIGHT && keydata.action == MLX_PRESS)
		check_move(map_info, 2, map_info->p_pos_y, map_info->p_pos_x + 1);
	if (keydata.key == MLX_KEY_DOWN && keydata.action == MLX_PRESS)
		check_move(map_info, 3, map_info->p_pos_y + 1, map_info->p_pos_x);
	if (keydata.key == MLX_KEY_LEFT && keydata.action == MLX_PRESS)
		check_move(map_info, 4, map_info->p_pos_y, map_info->p_pos_x - 1);
	if (keydata.key == MLX_KEY_ESCAPE && keydata.action == MLX_PRESS)
	{
		free_all(map_info);
		exit (0);
	}
}

int	main(int argc, char **argv)
{
	t_map_info		*map_info;

	atexit(leak);
	map_info = new_map_info();
	if (!map_info)
		print_error("failure at mem_alloc(map_info)", map_info);
	check_map(argc, argv, map_info);
	if (map_info->x_size % 2 == 0)
		map_info->path_name = "./sprites/Baseme/";
	else
		map_info->path_name = "./sprites/Depths/";
	load_textures_imgs(map_info);
	set_tiles(map_info);
	mlx_key_hook(map_info->mlx, &my_keyhook, map_info);
	mlx_loop(map_info->mlx);
}
