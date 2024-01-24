/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malena-b <mario3d93@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 14:11:15 by malena-b          #+#    #+#             */
/*   Updated: 2024/01/24 11:31:14 by malena-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

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

char	*create_path(t_map_info *map_info, char *str)
{
	char	*path;
	int		size;

	size = ft_strlen(map_info->path_name) + ft_strlen(str) + 1;
	path = ft_strdup(map_info->path_name);
	ft_strlcat(path, str, size);
	return (path);
}
