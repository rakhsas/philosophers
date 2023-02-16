/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rakhsas <rakhsas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 09:58:56 by rakhsas           #+#    #+#             */
/*   Updated: 2023/02/14 09:59:09 by rakhsas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philosophers.h"

int	ft_atoi(char *c)
{
	int	res;
	int	sym;
	int	i;

	i = 0;
	res = 0;
	sym = 1;
	if (!c)
		return (0);
	if (c[0] == '-' || c[0] == '+')
	{
		if (c[0] == '-')
			sym *= -1;
	}
	while (c[i] && c[i] >= '0' && c[i] <= '9')
	{
		res = 10 * res + c[i] - '0';
		i++;
	}
	if (res * sym > INT_MAX)
		return (-1);
	return (res * sym);
}
