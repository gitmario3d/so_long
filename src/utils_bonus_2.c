/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus_2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malena-b <mario3d93@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 13:09:26 by malena-b          #+#    #+#             */
/*   Updated: 2024/01/30 13:17:38 by malena-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long_bonus.h"

mlx_image_t	*init_pl_img(t_map_info *m_i, mlx_texture_t *texture)
{
	mlx_image_t	*image;

	image = mlx_texture_to_image(m_i->mlx, texture);
	if (!image)
		print_error("problem creating player image (init_pl_img)", m_i);
	return (image);
}
