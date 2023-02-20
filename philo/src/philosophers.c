/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rakhsas <rakhsas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 17:28:51 by rakhsas           #+#    #+#             */
/*   Updated: 2023/02/19 18:49:29 by rakhsas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void	*philosoph(void	*argument)
{
	t_philo	*philo;

	philo = (t_philo *)argument;
	while (1)
	{
		eat_philo(philo);
		print_msg(PINK, philo, "is Sleeping");
		ft_sleep(philo->status->time_to_sleep);
		print_msg(G_CYAN, philo, "is Thinking");
	}
	return (NULL);
}

void	ft_clear(t_main *dt)
{
	int	i;

	i = -1;
	while (++i < dt->nbr_philo)
		pthread_detach(dt->philos[i].thread);
}

void	create_philosophers(t_main *dt)
{
	int	i;

	dt->philos = malloc(sizeof(t_philo) * dt->nbr_philo);
	dt->forks = malloc(sizeof(pthread_mutex_t) * dt->nbr_philo);
	pthread_mutex_init(&dt->m_print, NULL);
	pthread_mutex_init(&dt->m_protect, NULL);
	i = -1;
	while (++i < dt->nbr_philo)
		pthread_mutex_init(&dt->forks[i], NULL);
	dt->time = get_time();
	initialize(dt, 0);
	if (check_for_death(dt) == 0)
		return ;
	i = -1;
	while (++i < dt->nbr_philo)
		pthread_join(dt->philos[i].thread, NULL);
}

int	main(int ac, char **av)
{
	int		i;
	t_main	*data;

	data = malloc(sizeof(t_main));
	if (ac > 4 && ac <= 6)
	{
		if (error_occur(ac, av, data) == -1)
			return (1);
		create_philosophers(data);
		i = -1;
		while (++i < data->nbr_philo)
			pthread_mutex_destroy(&data->forks[i]);
		pthread_mutex_destroy(&data->m_print);
	}
	else
		write(2, "Invalide Number of args!\n", 25);
	return (0);
}
