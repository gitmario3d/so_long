/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malena-b <mario3d93@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/27 11:55:49 by malena-b          #+#    #+#             */
/*   Updated: 2024/02/02 14:11:29 by malena-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long_bonus.h"

/*void	leak(void)
{
	system("leaks so_long");
}*/
//Función que genera un random entre dos números
int	fifty_fifty(int a, int b, int random_generator)
{
	if (random_generator % 2 == 0)
		return (a);
	else
		return (b);
}

int	main(int argc, char **argv)
{
	t_map_info		*m_i;

	m_i = new_map_info();
	if (!m_i)
		print_error("failure at mem_alloc(map_info)", m_i);
	check_map(argc, argv, m_i);
	if (m_i->x_size % 2 == 0)
		m_i->path_name = "./sprites/Baseme/";
	else
		m_i->path_name = "./sprites/Depths/";
	m_i->mlx = mlx_init(m_i->x_size * 64, m_i->y_size * 64, "Window", true);
	load_textures_imgs(m_i);
	save_player_t(m_i);
	set_tiles(m_i);
	mlx_key_hook(m_i->mlx, &my_keyhook, m_i);
	if (mlx_loop_hook(m_i->mlx, &main_hook, m_i) == false)
		print_error("failure starting the main hook", m_i);
	mlx_loop(m_i->mlx);
	return (0);
}
