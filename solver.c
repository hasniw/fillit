/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wahasni <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/07 15:59:29 by wahasni           #+#    #+#             */
/*   Updated: 2019/01/05 14:59:41 by wahasni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int	backtracking(t_list *list, int size_map, t_list *head)
{
	t_tetri		*tetriminos;

	if (list == NULL)
		return (1);
	tetriminos = list->content;
	clear_rest(list);
	while (check_y(tetriminos, size_map))
	{
		ft_reset_x(tetriminos);
		while (check_x(tetriminos, size_map))
		{
			if (check_collision(head, tetriminos))
			{
				if (backtracking(list->next, size_map, head))
					return (1);
			}
			ft_move_right(tetriminos);
		}
		ft_move_down(tetriminos);
	}
	return (0);
}

int	size_maps(int nbtetri)
{
	int	size;

	size = ft_sqrt(nbtetri * 4);
	return (size);
}

int	ft_solver(t_list *tetriminos)
{
	int		sizemap;
	int		nbtetris;

	sizemap = 0;
	nbtetris = ft_lstlen(tetriminos);
	sizemap = size_maps(nbtetris);
	while (backtracking(tetriminos, sizemap, tetriminos) == 0)
	{
		sizemap++;
	}
	return (sizemap);
}
