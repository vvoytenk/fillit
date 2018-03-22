/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osapon <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/11 18:20:53 by osapon            #+#    #+#             */
/*   Updated: 2018/01/17 17:19:02 by osapon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char		**ft_create_map(int min_map_size)
{
	int		i;
	char	**map;

	if (!(map = (char **)malloc(sizeof(char *) * min_map_size + 1)))
		return (NULL);
	map[min_map_size + 1] = NULL;
	i = -1;
	while (++i < min_map_size)
		if (!(map[i] = (char *)malloc(sizeof(char) * min_map_size + 1)))
			return (NULL);
	i = -1;
	while (++i < min_map_size)
		map[i] = ft_memset(map[i], '.', (size_t)min_map_size);
	return (map);
}

void		ft_print_map(char **map)
{
	int		i;

	i = -1;
	while (map[++i])
	{
		ft_putstr(map[i]);
		ft_putchar('\n');
	}
}

void		ft_zero_coord(t_global *global, int num_fig)
{
	int		i;
	int		x;
	int		y;

	x = global->memory[num_fig].tetrimino[0].x;
	y = global->memory[num_fig].tetrimino[0].y;
	i = -1;
	while (++i < 4)
	{
		global->memory[num_fig].tetrimino[i].x -= x;
		global->memory[num_fig].tetrimino[i].y -= y;
	}
}
