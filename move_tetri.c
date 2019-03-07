/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_tetri.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wahasni <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/07 17:24:11 by wahasni           #+#    #+#             */
/*   Updated: 2019/01/05 11:50:02 by mpivet-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	ft_reset_x(t_tetri *tetri)
{
	while (tetri->x[0] && tetri->x[1] && tetri->x[2] && tetri->x[3])
	{
		tetri->x[0]--;
		tetri->x[1]--;
		tetri->x[2]--;
		tetri->x[3]--;
	}
}

void	ft_reset_y(t_tetri *tetri)
{
	while (tetri->y[0] && tetri->y[1] && tetri->y[2] && tetri->y[3])
	{
		tetri->y[0]--;
		tetri->y[1]--;
		tetri->y[2]--;
		tetri->y[3]--;
	}
}

void	ft_move_right(t_tetri *tetri)
{
	tetri->x[0]++;
	tetri->x[1]++;
	tetri->x[2]++;
	tetri->x[3]++;
}

void	ft_move_down(t_tetri *tetri)
{
	tetri->y[0]++;
	tetri->y[1]++;
	tetri->y[2]++;
	tetri->y[3]++;
}

void	move_line(t_tetri *ptr)
{
	char	*tmp;

	tmp = ptr->tetri[0];
	ptr->tetri[0] = ptr->tetri[1];
	ptr->tetri[1] = ptr->tetri[2];
	ptr->tetri[2] = ptr->tetri[3];
	ptr->tetri[3] = tmp;
}
