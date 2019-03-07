/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpivet-p <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/27 20:05:19 by mpivet-p          #+#    #+#             */
/*   Updated: 2019/01/09 18:48:56 by wahasni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		main(int argc, char **argv)
{
	t_list	*ptr;
	int		ret;

	ret = 0;
	ptr = NULL;
	(void)argv;
	if (argc != 2)
	{
		ft_putstr_fd("usage : ./fillit file\n", 2);
		return (0);
	}
	else
	{
		if ((ptr = check_parameters_validity(argv[1])) == NULL)
		{
			ft_putstr("error\n");
			return (-1);
		}
		ret = ft_solver(ptr);
		print_solved_tetri(ptr, ret);
		cleaning(ptr);
	}
	return (0);
}
