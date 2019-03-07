/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpivet-p <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/11 13:34:21 by mpivet-p          #+#    #+#             */
/*   Updated: 2018/11/13 15:15:17 by mpivet-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_fill_result(char *result, int n, int i)
{
	result[i--] = '\0';
	while (n > 0 || (n == 0 && result[i + 1] == '\0'))
	{
		result[i--] = ((n % 10) + 48);
		n = n / 10;
	}
	return (result);
}

char		*ft_itoa(int n)
{
	char	*result;
	int		size;
	int		i;

	size = 1;
	i = ft_base_size(n, 10);
	if (n < 0)
		size++;
	if (!(result = (char*)malloc(sizeof(char) * (i + size))))
		return (NULL);
	if (n < 0)
	{
		result[0] = '-';
		if (n == -2147483648)
		{
			n = -147483648;
			result[1] = '2';
			size = 3;
		}
		n *= -1;
		i++;
	}
	result = ft_fill_result(result, n, i);
	return (result);
}
