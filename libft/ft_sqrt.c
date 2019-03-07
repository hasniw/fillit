/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wahasni <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/05 17:26:52 by wahasni           #+#    #+#             */
/*   Updated: 2018/12/09 17:04:54 by wahasni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_sqrt(int nb)
{
	int racine;

	racine = 0;
	if (nb <= 0)
		return (0);
	if (nb == 1)
		return (1);
	while (racine * racine < nb)
		racine++;
	if (racine * racine == nb)
		return (racine);
	else
		return (racine);
}
