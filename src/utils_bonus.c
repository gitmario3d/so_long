/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malena-b <mario3d93@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 14:11:15 by malena-b          #+#    #+#             */
/*   Updated: 2024/01/30 12:50:24 by malena-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long_bonus.h"

void	free_mat(char	**mat)
{
	int	i;

	i = 0;
	while (mat[i])
	{
		free(mat[i]);
		i++;
	}
	free(mat);
}

char	**matdup(char	**mat)
{
	char	**copy;
	int		size;

	size = 0;
	while (mat[size])
		size++;
	copy = malloc(sizeof(char *) * size + 1);
	if (!copy)
		return (NULL);
	size = 0;
	while (mat[size])
	{
		copy[size] = strdup(mat[size]);
		if (!copy[size])
		{
			free_mat(copy);
			return (NULL);
		}
		size++;
	}
	copy[size] = NULL;
	return (copy);
}

char	*create_path(t_map_info *map_info, char *str, char *path)
{
	int		size;

	if (path)
	{
		free (path);
		path = NULL;
	}
	size = ft_strlen(map_info->path_name) + ft_strlen(str) + 1;
	path = ft_strdup(map_info->path_name);
	if (!path)
		print_error("problem mem_aloc while ft_strdup of path_name", map_info);
	ft_strlcat(path, str, size);
	return (path);
}

void	reload_count(t_map_info *m_i)
{
	int		x;
	int		y;

	if (m_i->moves_img)
	{
		mlx_delete_image(m_i->mlx, m_i->moves_img);
		m_i->moves_img = NULL;
		free (m_i->count);
		m_i->count = NULL;
	}
	x = (m_i->p_pos_x * 64) - 5;
	y = (m_i->p_pos_y * 64) - 6;
	m_i->count = ft_itoa(m_i->steps);
	m_i->moves_img = mlx_put_string(m_i->mlx, m_i->count, x, y);
}

void	print_error(char *errormsg, t_map_info *map_info)
{
	free_all(map_info);
	ft_printf("Error, %s\n", errormsg);
	exit(0);
}
