/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_fts.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malena-b <mario3d93@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 08:56:03 by malena-b          #+#    #+#             */
/*   Updated: 2024/01/26 11:04:20 by malena-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

/*void	check_text2free(mlx_texture_t *texture)
{
	if (texture != NULL)
	{
		ft_printf("Aquí si llega.\n");
		mlx_delete_texture(texture);
	}
}

void	check_imgs2free(t_map_info *map_info, mlx_image_t *image)
{
	if (image)
	{
		ft_printf("aquí entra");
		mlx_delete_image(map_info->mlx, image);
	}
}*/

void	free_all_images(t_map_info *map_info)
{
	check_imgs2free(map_info, map_info->wall);
	check_imgs2free(map_info, map_info->ground);
	check_imgs2free(map_info, map_info->coin);
	check_imgs2free(map_info, map_info->exit);
	check_imgs2free(map_info, map_info->b_wall);
	check_imgs2free(map_info, map_info->t_wall);
	check_imgs2free(map_info, map_info->r_wall);
	check_imgs2free(map_info, map_info->l_wall);
	check_imgs2free(map_info, map_info->corner_bl);
	check_imgs2free(map_info, map_info->corner_br);
	check_imgs2free(map_info, map_info->corner_tl);
	check_imgs2free(map_info, map_info->corner_tr);
	check_imgs2free(map_info, map_info->player);
	check_imgs2free(map_info, map_info->c_exit);
}

void	free_all_texture(t_map_info *map_info)
{
	check_text2free(map_info->b_wall_t);
	check_text2free(map_info->t_wall_t);
	check_text2free(map_info->l_wall_t);
	check_text2free(map_info->r_wall_t);
	check_text2free(map_info->corner_bl_t);
	check_text2free(map_info->corner_br_t);
	check_text2free(map_info->corner_tl_t);
	check_text2free(map_info->corner_tr_t);
	check_text2free(map_info->wall_t);
	check_text2free(map_info->ground_t);
	check_text2free(map_info->coin_t);
	check_text2free(map_info->exit_t);
	check_text2free(map_info->c_exit_t);
	check_text2free(map_info->player_t);
}

void	free_all(t_map_info *map_info)
{
	int	i;

	i = 0;
	if (map_info)
	{
		if (map_info->map)
			free_mat(map_info->map);
		if (map_info->ff_map)
			free_mat(map_info->ff_map);
		free_all_texture(map_info);
		ft_printf("Aquí si llega.\n");
		free_all_images(map_info);
		mlx_terminate(map_info->mlx);
		close (map_info->fd);
		free(map_info);
	}
}
