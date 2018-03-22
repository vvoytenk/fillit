/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvoytenk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/28 20:14:38 by vvoytenk          #+#    #+#             */
/*   Updated: 2017/11/28 20:14:40 by vvoytenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		ft_conditions(t_global *global, int res)
{
	if (global->memory[global->i].tetrimino[global->coord].x == 0
		&& global->memory[global->i].tetrimino[global->coord].y == 0)
		res += checkright(global) + checkdown(global);
	else if (global->memory[global->i].tetrimino[global->coord].x == 0
			&& global->memory[global->i].tetrimino[global->coord].y == 3)
		res += checkright(global) + checkup(global);
	else if (global->memory[global->i].tetrimino[global->coord].x == 0)
		res += checkright(global) + checkdown(global) + checkup(global);
	else if (global->memory[global->i].tetrimino[global->coord].x == 3
			&& global->memory[global->i].tetrimino[global->coord].y == 0)
		res += checkdown(global) + checkleft(global);
	else if (global->memory[global->i].tetrimino[global->coord].y == 0)
		res += checkdown(global) + checkright(global) + checkleft(global);
	else if (global->memory[global->i].tetrimino[global->coord].x == 3
			&& global->memory[global->i].tetrimino[global->coord].y == 3)
		res += checkleft(global) + checkup(global);
	else if (global->memory[global->i].tetrimino[global->coord].x == 3)
		res += checkup(global) + checkleft(global) + checkdown(global);
	else if (global->memory[global->i].tetrimino[global->coord].y == 3)
		res += checkleft(global) + checkright(global) + checkup(global);
	else
		res += checkright(global) + checkup(global) + checkdown(global)
		+ checkleft(global);
	return (res);
}

int		checkup(t_global *global)
{
	int	i;
	int	touch;

	i = 0;
	touch = 0;
	while (i < 4)
	{
		if (global->memory[global->i].tetrimino[global->coord].y - 1
			== global->memory[global->i].tetrimino[i].y
			&& global->memory[global->i].tetrimino[global->coord].x
			== global->memory[global->i].tetrimino[i].x)
			touch++;
		i++;
	}
	return (touch);
}

int		checkleft(t_global *global)
{
	int	i;
	int	touch;

	i = 0;
	touch = 0;
	while (i < 4)
	{
		if (global->memory[global->i].tetrimino[global->coord].x - 1
			== global->memory[global->i].tetrimino[i].x
			&& global->memory[global->i].tetrimino[global->coord].y
			== global->memory[global->i].tetrimino[i].y)
			touch++;
		i++;
	}
	return (touch);
}

int		checkright(t_global *global)
{
	int	i;
	int	touch;

	i = 0;
	touch = 0;
	while (i < 4)
	{
		if (global->memory[global->i].tetrimino[global->coord].x + 1
			== global->memory[global->i].tetrimino[i].x
			&& global->memory[global->i].tetrimino[global->coord].y
			== global->memory[global->i].tetrimino[i].y)
			touch++;
		i++;
	}
	return (touch);
}

int		checkdown(t_global *global)
{
	int	i;
	int	touch;

	i = -1;
	touch = 0;
	while (++i < 4)
		if (global->memory[global->i].tetrimino[global->coord].y + 1
			== global->memory[global->i].tetrimino[i].y
			&& global->memory[global->i].tetrimino[global->coord].x
			== global->memory[global->i].tetrimino[i].x)
			touch++;
	return (touch);
}
