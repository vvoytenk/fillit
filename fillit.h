/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osapon <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/20 11:47:35 by osapon            #+#    #+#             */
/*   Updated: 2017/11/20 11:47:37 by osapon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include <unistd.h>
# include <fcntl.h>
# include <sys/stat.h>
# include "libft/libft.h"

typedef struct	s_tetrimino
{
	int			x;
	int			y;
}				t_tetrimino;

typedef struct	s_fig
{
	int			hesh;
	int			dot;
	int			new_line;
	char		c;
	t_tetrimino *tetrimino;
}				t_fig;

typedef struct	s_map
{
	int			map_size;
	char		**map;
}				t_map;

typedef struct	s_global
{
	char		*buf;
	int			fd;
	int			i;
	int			coord;
	int			x;
	int			y;
	t_fig		*memory;
	t_map		*map;
}				t_global;

void			ft_memory(t_global *global);
void			ft_bust(t_global *global);
void			check_pos(t_global *global);
int				ft_valid(t_global *global);
int				checkdown(t_global *global);
int				checkright(t_global *global);
int				checkleft(t_global *global);
int				checkup(t_global *global);
int				ft_conditions(t_global *global, int res);
void			ft_backtracking(t_global *global);
int				ft_sorting(t_global *global, int num_fig);
char			**ft_create_map(int min_map_size);
void			ft_print_map(char **map);
int				ft_freespace(t_global *global, int num_fig, int x, int y);
void			ft_delfig(t_global *global, int num_fig, int x, int y);
void			ft_putfig(t_global *global, int num_fig, int x, int y);
void			ft_zero_coord(t_global *global, int num_fig);
void			ft_symbol(t_global *global);

#endif
