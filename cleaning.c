/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleaning.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpivet-p <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/29 19:00:00 by mpivet-p          #+#    #+#             */
/*   Updated: 2019/01/05 14:57:18 by wahasni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

t_list	*cleaning(t_list *ptr)
{
	t_list	*next;
	t_tetri	*tetri;
	int		i;

	next = NULL;
	tetri = NULL;
	while (ptr != NULL)
	{
		next = ptr->next;
		if (ptr->content != NULL)
			tetri = ptr->content;
		else
			tetri = NULL;
		i = -1;
		while (++i < 4)
			if (tetri != NULL && tetri->tetri[i] != NULL)
				ft_strdel(&tetri->tetri[i]);
		if (tetri != NULL)
			free(tetri);
		if (ptr != NULL)
			free(ptr);
		ptr = next;
	}
	return (NULL);
}
