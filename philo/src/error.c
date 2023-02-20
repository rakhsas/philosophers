/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rakhsas <rakhsas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 09:18:43 by rakhsas           #+#    #+#             */
/*   Updated: 2023/02/19 19:04:35 by rakhsas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void	initialize_args(int ac, char **av, t_main *data)
{
	data->nbr_philo = ft_atoi(av[1]);
	data->time_to_die = ft_atoi(av[2]);
	data->time_to_eat = ft_atoi(av[3]);
	data->time_to_sleep = ft_atoi(av[4]);
	if (ac == 6)
		data->nbr_eat = ft_atoi(av[5]);
	else
		data->nbr_eat = -1;
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

int	check_for_death(t_main *dt)
{
	int	i;

	while (1)
	{
		i = -1;
		while (++i < dt->nbr_philo)
		{
			pthread_mutex_lock(&dt->m_protect);
			if (get_time() - dt->philos[i].last_eat
				> dt->time_to_die)
			{
				pthread_mutex_unlock(&dt->m_protect);
				// printf("%lld\n", get_time() - dt->philos[i].last_eat);
				print_msg(RED, &dt->philos[i], DIED);
				ft_clear(dt);
				return (0);
			}
			if (dt->nbr_eat != -1 && dt->philos[i].count > dt->nbr_eat)
				return (0);
			pthread_mutex_unlock(&dt->m_protect);
		}
	}
}
