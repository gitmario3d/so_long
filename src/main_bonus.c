/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malena-b <mario3d93@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/27 11:55:49 by malena-b          #+#    #+#             */
/*   Updated: 2024/02/01 13:47:25 by malena-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long_bonus.h"

void	leak(void)
{
	system("leaks so_long");
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
	save_player_t(map_info);
	set_tiles(map_info);
	mlx_key_hook(map_info->mlx, &my_keyhook, map_info);
	disable_anim_imgs(map_info->player_r);
	if (mlx_loop_hook(map_info->mlx, &main_hook, map_info) == false)
		print_error("failure starting the main hook", map_info);
	mlx_loop(map_info->mlx);
	return (0);
}
