/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_fts.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malena-b <mario3d93@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 08:56:03 by malena-b          #+#    #+#             */
/*   Updated: 2024/01/26 12:09:15 by malena-b         ###   ########.fr       */
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

void	free_map_images(t_map_info *map_info)
{
	if (map_info->wall)
		mlx_delete_image(map_info->mlx, map_info->wall);
	if (map_info->ground)
		mlx_delete_image(map_info->mlx, map_info->ground);
	if (map_info->exit)
		mlx_delete_image(map_info->mlx, map_info->exit);
	if (map_info->b_wall)
		mlx_delete_image(map_info->mlx, map_info->b_wall);
	if (map_info->t_wall)
		mlx_delete_image(map_info->mlx, map_info->t_wall);
	if (map_info->r_wall)
		mlx_delete_image(map_info->mlx, map_info->r_wall);
	if (map_info->l_wall)
		mlx_delete_image(map_info->mlx, map_info->l_wall);
	if (map_info->corner_bl)
		mlx_delete_image(map_info->mlx, map_info->corner_bl);
	if (map_info->corner_br)
		mlx_delete_image(map_info->mlx, map_info->corner_br);
	if (map_info->corner_tl)
		mlx_delete_image(map_info->mlx, map_info->corner_tl);
	if (map_info->corner_tr)
		mlx_delete_image(map_info->mlx, map_info->corner_tr);
	if (map_info->c_exit)
		mlx_delete_image(map_info->mlx, map_info->c_exit);
}

void	free_items_images(t_map_info *map_info)
{
	if (map_info->coin)
		mlx_delete_image(map_info->mlx, map_info->coin);
	if (map_info->player)
		mlx_delete_image(map_info->mlx, map_info->player);
}

void	free_map_textures(t_map_info *map_info)
{
	if (map_info->b_wall_t)
		mlx_delete_texture(map_info->b_wall_t);
	if (map_info->t_wall_t)
		mlx_delete_texture(map_info->t_wall_t);
	if (map_info->l_wall_t)
		mlx_delete_texture(map_info->l_wall_t);
	if (map_info->r_wall_t)
		mlx_delete_texture(map_info->r_wall_t);
	if (map_info->corner_bl_t)
		mlx_delete_texture(map_info->corner_bl_t);
	if (map_info->corner_br_t)
		mlx_delete_texture(map_info->corner_br_t);
	if (map_info->corner_tl_t)
		mlx_delete_texture(map_info->corner_tl_t);
	if (map_info->corner_tr_t)
		mlx_delete_texture(map_info->corner_tr_t);
	if (map_info->wall_t)
		mlx_delete_texture(map_info->wall_t);
	if (map_info->ground_t)
		mlx_delete_texture(map_info->ground_t);
	if (map_info->exit_t)
		mlx_delete_texture(map_info->exit_t);
	if (map_info->c_exit_t)
		mlx_delete_texture(map_info->c_exit_t);
}

void	free_items_texture(t_map_info *map_info)
{
	if (map_info->coin_t)
		mlx_delete_texture(map_info->coin_t);
	if (map_info->player_t)
		mlx_delete_texture(map_info->player_t);
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
		free_map_images(map_info);
		free_items_images(map_info);
		free_map_textures(map_info);
		free_items_texture(map_info);
		if (map_info->mlx)
		{
			mlx_close_window(map_info->mlx);
			mlx_terminate(map_info->mlx);
		}
		ft_printf("Aquí si llega.\n");
		close (map_info->fd);
		free(map_info);
	}
}
