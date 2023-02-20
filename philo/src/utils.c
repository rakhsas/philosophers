/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rakhsas <rakhsas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 09:58:56 by rakhsas           #+#    #+#             */
/*   Updated: 2023/02/19 22:01:08 by rakhsas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

long long	ft_atoi(char *c)
{
	long long	res;
	int			i;

	i = 0;
	res = 0;
	if (!c)
		return (0);
	while (i[c])
	{
		if (!(i[c] >= '0' && i[c] <= '9'))
			return (-1);
		i++;
	}
	i = 0;
	while (c[i] && c[i] >= '0' && c[i] <= '9')
	{
		res = 10 * res + c[i] - '0';
		i++;
	}
	if (res < 0 || res > 2147483647)
		return (-1);
	return (res);
}

int	ft_strcmp(const char *s1, const char *s2)
{
	size_t	i;

	i = 0;
	while (s1[i] != '\0' && s2[i] != '\0')
	{
		if ((unsigned char)s1[i] != (unsigned char)s2[i])
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
		i++;
	}
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}

void	print_msg(char *color, t_philo *philo, char *str)
{
	pthread_mutex_lock(&philo->status->m_print);
	printf("%s%-7lldms %-3d %-30s%s\n", color,
		get_time() - philo->status->time, philo->id + 1, str, RESET);
	if (ft_strcmp("died ☠️", str) != 0)
		pthread_mutex_unlock(&philo->status->m_print);
}

void	eat_philo(t_philo *philo)
{
	pthread_mutex_lock(&philo->status->forks[philo->id]);
	print_msg(BLUE, philo, "has Taken a Fork");
	pthread_mutex_lock(&philo->status->forks[(philo->id + 1)
		% philo->status->nbr_philo]);
	print_msg(BLUE, philo, "Has Taken a Fork");
	print_msg(GREEN, philo, "is eating");
	philo->count++;
	pthread_mutex_lock(&philo->status->m_protect);
	philo->last_eat = get_time();
	pthread_mutex_unlock(&philo->status->m_protect);
	ft_sleep(philo->status->time_to_eat);
	pthread_mutex_unlock(&philo->status->forks[philo->id]);
	pthread_mutex_unlock(&philo->status->forks[
		(philo->id + 1) % philo->status->nbr_philo]);
}

void	initialize(t_main *dt, int i)
{
	while (i < dt->nbr_philo)
	{
		dt->philos[i].status = dt;
		dt->philos[i].id = i;
		dt->philos[i].last_eat = dt->time;
		dt->philos[i].limit_eat = dt->time + dt->time_to_die;
		dt->philos[i].count = 0;
		pthread_mutex_init(&dt->philos[i].m_eating, NULL);
		pthread_create(&dt->philos[i].thread, NULL,
			philosoph, &dt->philos[i]);
		usleep(100);
		i++;
	}
}
