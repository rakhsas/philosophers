/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philos.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rakhsas <rakhsas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 17:29:16 by rakhsas           #+#    #+#             */
/*   Updated: 2023/02/19 18:27:57 by rakhsas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include "stdio.h"
# include "string.h"
# include "stdlib.h"
# include "unistd.h"
# include "sys/time.h"
# include "limits.h"
# include "pthread.h"

# define RESET "\e[0m"
# define PINK "\e[0;38;5;199m"
# define GREEN "\e[0;32m"
# define BLUE "\e[0;34m"
# define G_BLUE "\e[0;38;5;24m"
# define B_BLUE "\e[1;34m"
# define G_CYAN "\e[0;38;5;44m"
# define DIED "died ☠️"
# define RED "\033[0;31m"

typedef struct s_philo
{
	pthread_t		thread;
	int				id;
	long long		last_eat;
	int				l_fork;
	int				r_fork;
	long long		limit_eat;
	int				count;
	pthread_mutex_t	m_eating;
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
	pthread_mutex_t	m_protect;
}	t_main;

typedef struct s_args
{
	t_main	*status;
	t_philo	*philo;
}	t_args;

long		get_time(void);
int			ft_strcmp(const char *s1, const char *s2);
int			error_occur(int ac, char **av, t_main *data);
int		check_for_death(t_main *dt);
void		ft_sleep(int stop);
void		ft_clear(t_main *dt);
void		*philosoph(void	*argument);
void		eat_philo(t_philo *philo);
void		initialize(t_main *dt, int i);
void		print_msg(char *color, t_philo *philo, char *str);
void		initialize_args(int ac, char **av, t_main *data);
long long	ft_atoi(char *c);
#endif