/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wahasni <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/28 15:08:30 by wahasni           #+#    #+#             */
/*   Updated: 2019/01/05 14:15:28 by mpivet-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H
# include "libft/libft.h"
# include <fcntl.h>
# include <stdio.h>

typedef struct	s_tetri
{
	char		*tetri[4];
	int			x[4];
	int			y[4];
}				t_tetri;

int				check_x(t_tetri *tetri, int map_size);
int				check_y(t_tetri *tetri, int map_size);
int				check_collision(t_list *lst, t_tetri *tetrimino);
void			clear_rest(t_list *lst);
t_list			*cleaning(t_list *ptr);
char			**get_filled_tab(char c, int size);
void			print_solved_tetri(t_list *ptr, int sizemap);
void			ft_reset_x(t_tetri *tetri);
void			ft_reset_y(t_tetri *tetri);
void			ft_move_right(t_tetri *tetri);
void			ft_move_down(t_tetri *tetri);
void			move_line(t_tetri *ptr);
t_list			*get_tetriminos(const int fd, int k, int j, char *line);
t_list			*fix_list(t_list *ptr);
void			move_column(t_tetri *ptr);
void			move_tetri(t_list *tetri, int x, int y, t_tetri *ptr);
t_tetri			*add_link(t_list **ptr);
int				backtracking(t_list *list, int size_map, t_list *head);
int				size_maps(int nbtetri);
int				ft_solver(t_list *tetriminos);
int				ft_count_connections(t_tetri *ptr, int y, int x);
int				validation(t_list *tetri);
int				count_occurence_tetri(t_tetri *ptr, char c);
int				check_tetriminos_validity(t_list *list);
t_list			*check_parameters_validity(char *path);

#endif
