/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wahasni <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/07 15:59:48 by wahasni           #+#    #+#             */
/*   Updated: 2019/01/05 15:01:10 by wahasni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		check_x(t_tetri *tetri, int map_size)
{
	int	i;

	i = 0;
	while (i < 4)
	{
		if (tetri->x[i] >= map_size)
			return (0);
		i++;
	}
	return (1);
}

int		check_y(t_tetri *tetri, int map_size)
{
	int	i;

	i = 0;
	while (i < 4)
	{
		if (tetri->y[i] >= map_size)
			return (0);
		i++;
	}
	return (1);
}

int		check_collision(t_list *lst, t_tetri *tetrimino)
{
	t_tetri	*ptr;
	int		i;
	int		j;

	while (lst != NULL && lst->content != tetrimino)
	{
		i = 0;
		ptr = lst->content;
		while (i < 4 && ptr != tetrimino)
		{
			j = 0;
			while (j < 4)
			{
				if (ptr->x[j] == tetrimino->x[i] &&\
						ptr->y[j] == tetrimino->y[i])
					return (0);
				j++;
			}
			i++;
		}
		lst = lst->next;
	}
	return (1);
}

void	clear_rest(t_list *lst)
{
	t_tetri *ptr;

	while (lst)
	{
		ptr = lst->content;
		ft_reset_y(ptr);
		ft_reset_x(ptr);
		lst = lst->next;
	}
}
