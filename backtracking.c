/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   backtracking.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osapon <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/11 16:22:59 by osapon            #+#    #+#             */
/*   Updated: 2018/01/11 16:23:09 by osapon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	ft_backtracking(t_global *global)
{
	int	i;

	i = -1;
	while (++i < global->i)
		ft_zero_coord(global, i);
	global->map->map_size = 2;
	while (global->map->map_size *
		global->map->map_size < global->i * 4)
		global->map->map_size++;
	global->map->map = ft_create_map(global->map->map_size);
	while (!(ft_sorting(global, 0)))
	{
		global->map->map_size++;
		global->map->map = ft_create_map(global->map->map_size);
	}
	ft_print_map(global->map->map);
}

int		ft_sorting(t_global *global, int num_fig)
{
	int x;
	int y;

	if (num_fig == global->i)
		return (1);
	y = 0;
	while (y < global->map->map_size)
	{
		x = 0;
		while (x < global->map->map_size)
		{
			if (ft_freespace(global, num_fig, x, y))
			{
				ft_putfig(global, num_fig, x, y);
				if (ft_sorting(global, num_fig + 1))
					return (1);
				ft_delfig(global, num_fig, x, y);
			}
			x++;
		}
		y++;
	}
	return (0);
}

int		ft_freespace(t_global *global, int num_fig, int x, int y)
{
	if (global->memory[num_fig].tetrimino[2].x + x < global->map->map_size
		&& global->memory[num_fig].tetrimino[2].y + y < global->map->map_size
		&& global->memory[num_fig].tetrimino[3].x + x < global->map->map_size
		&& global->memory[num_fig].tetrimino[3].y + y < global->map->map_size
		&& global->map->map[global->memory[num_fig].tetrimino[0].y + y]
		[global->memory[num_fig].tetrimino[0].x + x] == '.'
		&& global->map->map[global->memory[num_fig].tetrimino[1].y + y]
		[global->memory[num_fig].tetrimino[1].x + x] == '.'
		&& global->map->map[global->memory[num_fig].tetrimino[2].y + y]
		[global->memory[num_fig].tetrimino[2].x + x] == '.'
		&& global->map->map[global->memory[num_fig].tetrimino[3].y + y]
		[global->memory[num_fig].tetrimino[3].x + x] == '.')
		return (1);
	return (0);
}

void	ft_delfig(t_global *global, int num_fig, int x, int y)
{
	y = 0;
	while (y < global->map->map_size)
	{
		x = 0;
		while (x < global->map->map_size)
		{
			if (global->map->map[y][x] == global->memory[num_fig].c)
				global->map->map[y][x] = '.';
			x++;
		}
		y++;
	}
}

void	ft_putfig(t_global *global, int num_fig, int x, int y)
{
	global->map->map[y][x] = global->memory[num_fig].c;
	global->map->map[global->memory[num_fig].tetrimino[1].y + y]
	[global->memory[num_fig].tetrimino[1].x + x] = global->memory[num_fig].c;
	global->map->map[global->memory[num_fig].tetrimino[2].y + y]
	[global->memory[num_fig].tetrimino[2].x + x] = global->memory[num_fig].c;
	global->map->map[global->memory[num_fig].tetrimino[3].y + y]
	[global->memory[num_fig].tetrimino[3].x + x] = global->memory[num_fig].c;
}
