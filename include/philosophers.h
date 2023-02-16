/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rakhsas <rakhsas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 17:29:16 by rakhsas           #+#    #+#             */
/*   Updated: 2023/02/16 15:10:47 by rakhsas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include "stdio.h"
# include "string.h"
# include "stdlib.h"
# include "unistd.h"
# include "limits.h"
# include "pthread.h"

typedef struct t_philo
{
	int				id;
	int				last_eat;
	int				index_l_fork;
	int				index_r_fork;
	struct t_vars	*p;
	pthread_t		*philo;
	pthread_mutex_t	*print;
	pthread_mutex_t	*forks;
}	t_phils;
typedef struct t_vars
{
	int			time_to_die;
	int			time_to_eat;
	int			time_to_sleep;
	int			number_of_time_eating;
	int			number_of_philosophers;
	long long	time;
	t_phils		*state;
}	t_main;

int		ft_atoi(char *c);
int		error_occur(int ac, char **av, t_main *data);
void	initialize_args(int ac, char **av, t_main *data);
#endif