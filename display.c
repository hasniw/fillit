/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpivet-p <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/31 12:44:14 by mpivet-p          #+#    #+#             */
/*   Updated: 2019/01/04 16:51:30 by mpivet-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char	**get_filled_tab(char c, int size)
{
	int		x;
	int		y;
	char	**tab;

	tab = (char**)malloc(sizeof(char*) * (size + 1));
	y = -1;
	while (++y < size && (x = -1) >= -1)
	{
		tab[y] = (char*)malloc(sizeof(char) * (size + 1));
		while (++x < size)
			tab[y][x] = c;
		tab[y][size] = 0;
	}
	tab[size] = 0;
	return (tab);
}

void	print_solved_tetri(t_list *ptr, int sizemap)
{
	int		i;
	int		c;
	char	**tab;
	t_tetri	*content;

	c = 0;
	tab = get_filled_tab('.', sizemap);
	while (ptr != NULL && ++c)
	{
		content = ptr->content;
		i = -1;
		while (++i < 4)
			tab[content->y[i]][content->x[i]] = c + 64;
		ptr = ptr->next;
	}
	ft_print_char_tab(tab);
	i = -1;
	while (tab[++i])
		ft_strdel(&tab[i]);
	free(tab);
}
