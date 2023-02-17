/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rakhsas <rakhsas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 09:18:43 by rakhsas           #+#    #+#             */
/*   Updated: 2023/02/17 12:15:36 by rakhsas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philosophers.h"

void	initialize_args(int ac, char **av, t_main *data)
{
	data->nbr_philo = ft_atoi(av[1]);
	data->time_to_die = ft_atoi(av[2]);
	data->time_to_eat = ft_atoi(av[3]);
	data->time_to_sleep = ft_atoi(av[4]);
	if (ac == 6)
		data->nbr_eat = ft_atoi(av[5]);
}

int	error_occur(int ac, char **av, t_main *data)
{
	initialize_args(ac, av, data);
	if (data->nbr_philo <= 0 || data->time_to_die <= 0
		|| data->time_to_eat <= 0 || data->time_to_sleep <= 0
		|| (ac == 6 && data->nbr_eat <= 0))
	{
		write(2, "Invalid ARGS\n", 13);
		return (-1);
	}
	return (1);
}
