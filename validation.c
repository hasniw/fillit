/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpivet-p <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/10 10:50:56 by mpivet-p          #+#    #+#             */
/*   Updated: 2019/01/09 18:49:08 by wahasni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		ft_count_connections(t_tetri *ptr, int y, int x)
{
	int i;

	i = 0;
	if (x < 3 && ptr->tetri[y][x] == '#' && \
			ptr->tetri[y][x + 1] == '#')
		i++;
	if (x > 0 && ptr->tetri[y][x] == '#' && \
			ptr->tetri[y][x - 1] == '#')
		i++;
	if (y < 3 && ptr->tetri[y][x] == '#' && \
			ptr->tetri[y + 1][x] == '#')
		i++;
	if (y > 0 && ptr->tetri[y][x] == '#' && \
			ptr->tetri[y - 1][x] == '#')
		i++;
	return (i);
}

int		validation(t_list *tetri)
{
	int		i;
	int		x;
	int		y;
	t_tetri	*ptr;

	while (tetri != NULL)
	{
		ptr = tetri->content;
		y = -1;
		i = 0;
		while (++y < 4)
		{
			x = -1;
			while (++x < 4)
			{
				i += ft_count_connections(ptr, y, x);
				if ((y == 3 && x == 3 && i < 6) ||\
						(ft_count_connections(ptr, y, x) < 1\
						&& ptr->tetri[y][x] == '#'))
					return (0);
			}
		}
		tetri = tetri->next;
	}
	return (1);
}
