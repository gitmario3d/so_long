/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malena-b <mario3d93@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/27 11:44:21 by malena-b          #+#    #+#             */
/*   Updated: 2024/01/17 11:01:32 by malena-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

#include "my_libft/libft.h"

typedef struct t_map_information
{
	int		collectables;
	int		players;
	int		exits;
	int		x_size;
	int		y_size;
	char	**map;
	int		p_pos_x;
	int		p_pos_y;
	int		ff_collec;
	int		ff_exits;
	char	**ff_map;
	int		fd;
}					t_map_info;

void		check_map(int argc, char **argv, t_map_info	*map_info);
void		print_error(char *errormsg, t_map_info *map_info);
t_map_info	*new_map_info(void);
void		check_floodfill(t_map_info *map_info);
void		free_mat(char	**mat);
char		**matdup(char	**mat);

#endif