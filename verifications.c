/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verifications.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpivet-p <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/06 16:27:44 by mpivet-p          #+#    #+#             */
/*   Updated: 2019/01/09 18:50:12 by wahasni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		count_occurence_tetri(t_tetri *ptr, char c)
{
	int i;
	int x;
	int y;

	i = 0;
	y = 0;
	while (y < 4)
	{
		x = 0;
		while (x < 4)
		{
			if (i < 4 && c == '#' && ptr->tetri[y][x] == c)
			{
				ptr->x[i] = x;
				ptr->y[i] = y;
			}
			if (ptr->tetri[y][x] == c)
				i++;
			else if (ptr->tetri[y][x] != '.' && ptr->tetri[y][x] != '#')
				return (-1);
			x++;
		}
		y++;
	}
	return (i);
}

int		check_tetriminos_validity(t_list *list)
{
	t_tetri	*ptr;

	while (list != NULL)
	{
		ptr = list->content;
		if ((count_occurence_tetri(ptr, '.') != 12) || \
				(count_occurence_tetri(ptr, '#') != 4))
			return (-1);
		list = list->next;
	}
	return (0);
}

t_list	*check_parameters_validity(char *path)
{
	int		fd;
	t_list	*ptr;

	fd = 0;
	if ((fd = open(path, O_RDONLY)) != -1)
	{
		if ((ptr = get_tetriminos(fd, 0, 0, NULL)) != NULL)
		{
			if (check_tetriminos_validity(ptr) == 0)
			{
				move_tetri(ptr, 0, 0, NULL);
				if (validation(ptr) == 0)
					return (cleaning(ptr));
				return (ptr);
			}
			return (cleaning(ptr));
		}
		return (cleaning(ptr));
	}
	return (NULL);
}
