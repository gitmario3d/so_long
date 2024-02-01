/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_flies_render.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malena-b <mario3d93@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 10:31:08 by malena-b          #+#    #+#             */
/*   Updated: 2024/02/01 13:47:18 by malena-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long_bonus.h"

void	init_tfly_imgs(t_tfly_rend *tfly_r, mlx_t *mlx, t_map_info *m_i)
{
	tfly_r->tfly_01_t = mlx_load_png("./sprites/Depths/fly_01.png");
	tfly_r->tfly_02_t = mlx_load_png("./sprites/Depths/fly_02.png");
	tfly_r->tfly_03_t = mlx_load_png("./sprites/Depths/fly_03.png");
	tfly_r->tfly_04_t = mlx_load_png("./sprites/Depths/fly_04.png");
	if (!(tfly_r->tfly_01_t) || !(tfly_r->tfly_02_t) || !(tfly_r->tfly_03_t)
		|| !(tfly_r->tfly_04_t))
		print_error("failure at initiation of tfly_render textures.\n", m_i);
	tfly_r->tfly_01 = mlx_texture_to_image(mlx, tfly_r->tfly_01_t);
	tfly_r->tfly_02 = mlx_texture_to_image(mlx, tfly_r->tfly_02_t);
	tfly_r->tfly_03 = mlx_texture_to_image(mlx, tfly_r->tfly_03_t);
	tfly_r->tfly_04 = mlx_texture_to_image(mlx, tfly_r->tfly_04_t);
	if (!(tfly_r->tfly_01) || !(tfly_r->tfly_02) || !(tfly_r->tfly_03)
		|| !(tfly_r->tfly_04))
		print_error("failure at initiation of tfly_render images.\n", m_i);
}

void	new_tfly_render(t_map_info *map_info)
{
	t_tfly_rend	*tfly_render;

	tfly_render = ft_calloc(1, sizeof(t_tfly_rend));
	if (!tfly_render)
		print_error("failure while mem_alloc(map_info->tfly_render)", map_info);
	map_info->tfly_r = tfly_render;
	map_info->tfly_r->tfly_01 = NULL;
	map_info->tfly_r->tfly_02 = NULL;
	map_info->tfly_r->tfly_03 = NULL;
	map_info->tfly_r->tfly_04 = NULL;
	map_info->tfly_r->tfly_01_t = NULL;
	map_info->tfly_r->tfly_02_t = NULL;
	map_info->tfly_r->tfly_03_t = NULL;
	map_info->tfly_r->tfly_04_t = NULL;
	map_info->tfly_r->x = 0;
	map_info->tfly_r->y = 0;
}

void	init_rfly_imgs(t_rfly_rend *rfly_r, mlx_t *mlx, t_map_info *m_i)
{
	rfly_r->rfly_01_t = mlx_load_png("./sprites/Baseme/fly_01.png");
	rfly_r->rfly_02_t = mlx_load_png("./sprites/Baseme/fly_02.png");
	rfly_r->rfly_03_t = mlx_load_png("./sprites/Baseme/fly_03.png");
	rfly_r->rfly_04_t = mlx_load_png("./sprites/Baseme/fly_04.png");
	if (!(rfly_r->rfly_01_t) || !(rfly_r->rfly_02_t) || !(rfly_r->rfly_03_t)
		|| !(rfly_r->rfly_04_t))
		print_error("failure at initiation of rfly_render textures.\n", m_i);
	rfly_r->rfly_01 = mlx_texture_to_image(mlx, rfly_r->rfly_01_t);
	rfly_r->rfly_02 = mlx_texture_to_image(mlx, rfly_r->rfly_02_t);
	rfly_r->rfly_03 = mlx_texture_to_image(mlx, rfly_r->rfly_03_t);
	rfly_r->rfly_04 = mlx_texture_to_image(mlx, rfly_r->rfly_04_t);
	if (!(rfly_r->rfly_01) || !(rfly_r->rfly_02) || !(rfly_r->rfly_03)
		|| !(rfly_r->rfly_04))
		print_error("failure at initiation of rfly_render images.\n", m_i);
}

void	new_rfly_render(t_map_info *map_info)
{
	t_rfly_rend	*rfly_render;

	rfly_render = malloc(sizeof(t_rfly_rend));
	if (!rfly_render)
		print_error("failure while mem_alloc(map_info->rfly_render)", map_info);
	map_info->rfly_r = rfly_render;
	map_info->rfly_r->rfly_01 = NULL;
	map_info->rfly_r->rfly_02 = NULL;
	map_info->rfly_r->rfly_03 = NULL;
	map_info->rfly_r->rfly_04 = NULL;
	map_info->rfly_r->rfly_01_t = NULL;
	map_info->rfly_r->rfly_02_t = NULL;
	map_info->rfly_r->rfly_03_t = NULL;
	map_info->rfly_r->rfly_04_t = NULL;
	map_info->rfly_r->x = 0;
	map_info->rfly_r->y = 0;
}

void	render_flies_onmap(t_map_info *m, t_tfly_rend *t, t_rfly_rend *r)
{
	if (m->tflies == 1)
	{
		if ((mlx_image_to_window(m->mlx, t->tfly_01, t->x * 64, t->y * 64) < 0))
			print_error("problem rendering the tfly_01 image.", m);
		if ((mlx_image_to_window(m->mlx, t->tfly_02, t->x * 64, t->y * 64) < 0))
			print_error("problem rendering the tfly_02 image.", m);
		if ((mlx_image_to_window(m->mlx, t->tfly_03, t->x * 64, t->y * 64) < 0))
			print_error("problem rendering the tfly_03 image.", m);
		if ((mlx_image_to_window(m->mlx, t->tfly_04, t->x * 64, t->y * 64) < 0))
			print_error("problem rendering the tfly_04 image.", m);
	}
	if (m->rflies == 1)
	{
		if ((mlx_image_to_window(m->mlx, r->rfly_01, r->x * 64, r->y * 64) < 0))
			print_error("problem rendering the rfly_01 image.", m);
		if ((mlx_image_to_window(m->mlx, r->rfly_02, r->x * 64, r->y * 64) < 0))
			print_error("problem rendering the rfly_02 image.", m);
		if ((mlx_image_to_window(m->mlx, r->rfly_03, r->x * 64, r->y * 64) < 0))
			print_error("problem rendering the rfly_03 image.", m);
		if ((mlx_image_to_window(m->mlx, r->rfly_04, r->x * 64, r->y * 64) < 0))
			print_error("problem rendering the rfly_04 image.", m);
	}
}
