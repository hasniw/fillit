/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoll.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdescler <jdescler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/24 20:20:49 by jdescler          #+#    #+#             */
/*   Updated: 2019/07/01 16:14:27 by jdescler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

long long		ft_atoll(const char *s)
{
	int			i;
	int			pos;
	long long	res;

	i = 0;
	pos = 1;
	res = 0;
	while (ft_isspace(s[i]))
		i++;
	if (s[i] == '-')
	{
		i++;
		pos = -1;
	}
	if (s[i] == '+' && s[i - 1] != '-')
		i++;
	while (s[i] >= '0' && s[i] <= '9')
	{
		res = res * 10 + (s[i] - '0');
		i++;
	}
	return (res * pos);
}
