/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rakhsas <rakhsas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 17:28:51 by rakhsas           #+#    #+#             */
/*   Updated: 2023/02/16 13:13:43 by rakhsas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philosophers.h"

void	*routine(void *arg)
{
	printf("Philosopher is Eating\n");
	return (NULL);
}

void	create(t_main *dt)
{
	int	i;

	i = 0;
	while (i < dt->number_of_philosophers)
	{
		if (pthread_create(&dt->state->philo[i], NULL, &routine, NULL) != 0)
			return ;
		i++;
	}
	i = 0;
	while (i < dt->number_of_philosophers)
	{
		if (pthread_join(dt->state->philo[i], NULL))
			return ;
		i++;
	}
}

void	create_philosophers(t_main *dt)
{
	int	i;

	dt->state = malloc(sizeof(t_phils) * dt->number_of_philosophers);
	dt->state->philo = malloc(sizeof(t_phils) * dt->number_of_philosophers);
	dt->state->forks = malloc(
			sizeof(pthread_mutex_t) * dt->number_of_philosophers);
	i = -1;
	while (++i < dt->number_of_philosophers)
		pthread_mutex_init(&dt->state->forks[i], NULL);
	create(dt);
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
