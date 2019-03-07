/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpivet-p <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/06 16:26:30 by mpivet-p          #+#    #+#             */
/*   Updated: 2019/01/06 22:55:59 by wahasni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

t_list	*get_tetriminos(const int fd, int k, int j, char *line)
{
	t_list	*newlist;
	t_tetri	*ptr;

	ptr = NULL;
	newlist = ft_lstnew(NULL, 0);
	while (get_next_line(fd, &line) > 0)
	{
		if (ptr == NULL && j == 0)
			ptr = add_link(&newlist);
		if (j < 4 && (ft_strlen(line) == 4))
			ptr->tetri[j++] = ft_strdup(line);
		else
		{
			if (ft_strlen(line) == 0 && j == 4 && k++ > -1 && (j = 0) > -1)
				ptr = NULL;
			if (ptr != NULL)
				ft_strdel(&line);
			if (ptr != NULL)
				return (cleaning(newlist));
		}
		ft_strdel(&line);
	}
	if (j != 4)
		return (cleaning(newlist));
	return (fix_list(newlist));
}

t_list	*fix_list(t_list *ptr)
{
	t_list	*previous;
	t_list	*next;

	previous = NULL;
	while (ptr->next != NULL)
	{
		next = ptr->next;
		ptr->next = previous;
		previous = ptr;
		if (next != NULL)
			ptr = next;
	}
	free(ptr);
	return (previous);
}

void	move_column(t_tetri *ptr)
{
	char	*tmp;
	int		i;
	int		x;
	int		y;

	i = 0;
	y = 0;
	while (y < 4)
	{
		x = 0;
		tmp = ptr->tetri[y];
		i = 1;
		while (x < 3)
		{
			ptr->tetri[y][x] = tmp[i];
			x++;
			i++;
		}
		ptr->tetri[y][x] = '.';
		y++;
	}
}

void	move_tetri(t_list *tetri, int x, int y, t_tetri *ptr)
{
	while (tetri != NULL)
	{
		ptr = tetri->content;
		y = 0;
		while (y < 3)
		{
			x = 0;
			while (x < 4 && ptr->tetri[y][x] != '#')
				x++;
			if (x == 4 && (y = -1) != -7)
				move_line(ptr);
			else
				y = 3;
			y++;
		}
		y = 0;
		while (ptr->tetri[y][0] != '#' && y < 4)
		{
			if (y == 3 && (y = -1) != -7)
				move_column(ptr);
			y++;
		}
		tetri = tetri->next;
	}
}

t_tetri	*add_link(t_list **ptr)
{
	t_list	*newlink;
	t_tetri	*new;

	if (!(new = (t_tetri*)malloc(sizeof(t_tetri))))
		return (NULL);
	if (!(newlink = (t_list*)malloc(sizeof(t_list))))
		return (NULL);
	new->tetri[0] = NULL;
	new->tetri[1] = NULL;
	new->tetri[2] = NULL;
	new->tetri[3] = NULL;
	newlink->content = new;
	ft_lstadd(&(*ptr), newlink);
	return ((*ptr)->content);
}
