/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rakhsas <rakhsas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 17:28:51 by rakhsas           #+#    #+#             */
/*   Updated: 2023/02/17 16:23:17 by rakhsas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philosophers.h"

void	*philosoph(void	*argument)
{
	t_philo	*philo;

	philo = (t_philo *)argument;
	printf("--->%d\n--->left fork : %d\n--->right fork : %d\n\n\n",
		philo->id, philo->l_fork, philo->r_fork);
	return (NULL);
}

void	initialize(t_main *dt, int i)
{
	while (i < dt->nbr_philo)
	{
		dt->philos[i].status = dt;
		dt->philos[i].id = i;
		dt->philos[i].last_eat = dt->time;
		dt->philos[i].limit_eat = dt->time + dt->time_to_die;
		dt->nbr_eat = 0;
		dt->philos[i].r_fork = i;
		if (i == dt->nbr_philo - 1)
			dt->philos[i].l_fork = 0;
		else
			dt->philos[i].l_fork = i + 1;
		pthread_create(&dt->philos[i].thread, NULL,
			philosoph, &dt->philos[i]);
		i++;
	}
}

void	create_philosophers(t_main *dt)
{
	int	i;

	dt->philos = malloc(sizeof(t_philo) * dt->nbr_philo);
	dt->forks = malloc(sizeof(pthread_mutex_t) * dt->nbr_philo);
	pthread_mutex_init(&dt->m_print, NULL);
	i = 0;
	while (i++ < dt->nbr_philo)
		pthread_mutex_init(&dt->forks[i], NULL);
	dt->time = get_time();
	initialize(dt, 0);
}

int	main(int ac, char **av)
{
	t_main	data;

	if (ac > 4 && ac <= 6)
	{
		if (!error_occur(ac, av, &data))
			return (1);
		create_philosophers(&data);
		return (0);
	}
	write(2, "Invalide Number of args!\n", 25);
	return (0);
}
