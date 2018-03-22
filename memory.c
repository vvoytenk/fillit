/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memory.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvoytenk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/27 17:53:37 by vvoytenk          #+#    #+#             */
/*   Updated: 2017/11/27 17:53:39 by vvoytenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	ft_memory(t_global *global)
{
	int i;

	global->i = 0;
	global->coord = 0;
	global->x = 0;
	global->y = 0;
	i = 0;
	global->memory = (t_fig *)malloc(sizeof(t_fig) * 26);
	global->buf = (char *)malloc(sizeof(char) * 546);
	global->map = (t_map *)malloc(sizeof(t_map));
	while (i < 26)
	{
		global->memory[i].tetrimino = (t_tetrimino *)malloc(sizeof(t_tetrimino)
															* 4);
		i++;
	}
}

void	ft_bust(t_global *global)
{
	int full;

	global->y = 0;
	global->coord = 0;
	full = 21;
	while (full > 0)
	{
		global->x = 0;
		while (global->x < 5 && full--)
		{
			check_pos(global);
			global->x++;
			global->buf++;
		}
		global->y++;
	}
}

void	check_pos(t_global *global)
{
	if (*global->buf == '.')
		global->memory[global->i].dot++;
	if (*global->buf == '\n')
		global->memory[global->i].new_line++;
	if (*global->buf == '#')
	{
		global->memory[global->i].hesh++;
		global->memory[global->i].tetrimino[global->coord].x = global->x;
		global->memory[global->i].tetrimino[global->coord++].y = global->y;
	}
}

int		ft_valid(t_global *global)
{
	int	res;

	global->coord = 0;
	res = 0;
	while (global->coord < 4)
	{
		res = ft_conditions(global, res);
		global->coord++;
	}
	if (res == 6 || res == 8)
		return (1);
	return (0);
}

void	ft_symbol(t_global *global)
{
	int i;

	i = -1;
	while (++i < global->i)
		global->memory[i].c = (char)('A' + i);
}
