/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rakhsas <rakhsas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 17:29:16 by rakhsas           #+#    #+#             */
/*   Updated: 2023/02/17 15:25:28 by rakhsas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include "stdio.h"
# include "string.h"
# include "stdlib.h"
# include "unistd.h"
# include "sys/time.h"
# include "limits.h"
# include "pthread.h"

typedef struct s_philo
{
	int				id;
	pthread_t		thread;
	long long		last_eat;
	long long		limit_eat;
	int				nbr_eat;
	pthread_mutex_t	m_eating;
	int				l_fork;
	int				r_fork;
	struct s_main	*status;
}	t_philo;

typedef struct s_main
{
	int				nbr_philo;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				nbr_eat;
	long long		time;
	t_philo			*philos;
	pthread_mutex_t	*forks;
	pthread_mutex_t	m_print;
}	t_main;

typedef struct s_args
{
	t_main	*status;
	t_philo	*philo;
}	t_args;

long	get_time(void);
int		ft_atoi(char *c);
int		error_occur(int ac, char **av, t_main *data);
void		initialize_args(int ac, char **av, t_main *data);
#endif