/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antgalan <antgalan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 00:44:51 by antgalan          #+#    #+#             */
/*   Updated: 2022/11/09 02:09:20 by antgalan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_str.h"
#include "square.h"
#include "map.h"
#include <stdlib.h>

void	print_map_cheat(int **map, int dim)
{
	char	n;
	int		i;
	int		j;

	i = 0;
	while (i < dim)
	{
		j = 0;
		while (j < dim)
		{
			n = '0' + map[i][j];
			ft_putchar(n);
			ft_putchar(' ');
			j++;
		}
		ft_putchar('\n');
		i++;
	}
	ft_putchar('\n');
}

void	print_solution(int **map, t_square sol, t_caption cap)
{
	int	i;
	int	j;

	i = 0;
	while (i < cap.rows)
	{
		j = 0;
		while (j < cap.cols)
		{
			if (sol.x <= i && i < sol.x + sol.d
				&& sol.y <= j && j < sol.y + sol.d)
				ft_putchar(cap.full);
			else if (map[i][j] == 1)
				ft_putchar(cap.obst);
			else
				ft_putchar(cap.empty);
			ft_putchar(' ');
			j++;
		}
		ft_putchar('\n');
		i++;
	}
	ft_putchar('\n');
}

t_square	*find_max_square(int **map, t_caption cap)
{
	t_square	*sol;
	t_square	*new;
	t_square	*end;
	int			i;
	int			j;

	sol = init_square(0, 0);
	end = init_square(cap.rows - 1, cap.cols - 1);
	i = -1;
	while (++i < cap.rows - 1)
	{
		j = -1;
		while (++j < cap.cols - 1)
		{
			if (map[i][j] != 1)
			{
				new = grow_square(map, init_square(i, j), cap);
				if (sol->d < new->d)
					*sol = *new;
				free(new);
			}
		}
	}
	free(end);
	return (sol);
}
