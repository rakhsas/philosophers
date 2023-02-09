/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rakhsas <rakhsas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 17:29:16 by rakhsas           #+#    #+#             */
/*   Updated: 2023/02/08 21:14:01 by rakhsas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include "stdio.h"
# include "string.h"
# include "stdlib.h"
# include "unistd.h"

typedef struct t_vars
{
	int	nb_of_phils;
	int	time_to_die;
	int	time_to_eat;
	int	number_of_time_eating;
	int	number_of_philosophers;
}	t_phils;

#endif