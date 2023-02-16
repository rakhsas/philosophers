/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rakhsas <rakhsas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 17:28:51 by rakhsas           #+#    #+#             */
/*   Updated: 2023/02/16 15:17:26 by rakhsas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philosophers.h"

void	*routine(void *arg)
{
	t_main dt = *(t_main *)arg;
	printf("Philosopher is Eating\n");
	printf("index of number: %d\n", dt.state->id);
	return (NULL);
}

void	create(t_main *dt)
{
	int	i;

	i = 0;
	while (i < dt->number_of_philosophers)
	{
		pthread_mutex_lock(dt->state->print);
		if (pthread_create(&dt->state->philo[i], NULL, &routine, dt) != 0)
		{
			return ;
		}
		dt->state->id = i;
		pthread_mutex_unlock(dt->state->print);
		i++;
	}
	i = 0;
	while (i < dt->number_of_philosophers)
	{
		pthread_mutex_lock(dt->state->print);
		if (pthread_join(dt->state->philo[i], NULL))
			return ;
		pthread_mutex_unlock(dt->state->print);
		i++;
	}
}

void	create_philosophers(t_main *dt)
{
	int	i;

	dt->state = malloc(sizeof(t_phils) * dt->number_of_philosophers);
	dt->state->philo = malloc(sizeof(t_phils) * dt->number_of_philosophers);
	dt->state->forks = malloc(sizeof(pthread_mutex_t) * dt->number_of_philosophers);
	dt->state->print = malloc(sizeof(pthread_mutex_t) * dt->number_of_philosophers);
	i = -1;
	pthread_mutex_lock(dt->state->print);
	while (++i < dt->number_of_philosophers)
		pthread_mutex_init(&dt->state->forks[i], NULL);
	pthread_mutex_unlock(dt->state->print);
	create(dt);
	free(dt->state->print);
	free(dt->state->forks);
	free(dt->state->philo);
	free(dt->state);
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
