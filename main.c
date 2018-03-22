/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osapon <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/19 15:44:48 by osapon            #+#    #+#             */
/*   Updated: 2018/01/17 16:50:36 by osapon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		ft_fillit(char *file, t_global *global)
{
	global->fd = open(file, O_RDONLY);
	read(global->fd, global->buf, 546);
	close(global->fd);
	while (*global->buf)
	{
		ft_bust(global);
		if (!((global->memory[global->i].hesh == 4)
		&& (global->memory[global->i].dot == 12) &&
		((global->memory[global->i].new_line == 5)
		|| ((global->memory[global->i].new_line == 4)
			&& (*(global->buf + 1) == '\0')))))
			return (0);
		if (!ft_valid(global))
			return (0);
		global->i++;
	}
	if (global->memory[global->i - 1].new_line != 4 || global->i > 26)
		return (0);
	return (1);
}

int		main(int ac, char **av)
{
	t_global	*global;

	if (!(global = (t_global *)malloc(sizeof(t_global))))
		return (0);
	if (ac == 2)
	{
		ft_memory(global);
		if (ft_fillit(av[1], global) == 0)
		{
			ft_putstr("error\n");
			return (0);
		}
		ft_symbol(global);
		ft_backtracking(global);
	}
	else
		ft_putstr("usage: ./fillit [file name]\n");
	return (0);
}
