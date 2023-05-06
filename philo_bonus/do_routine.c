/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_routine.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhwang2 <jhwang2@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 14:14:22 by jhwang2           #+#    #+#             */
/*   Updated: 2023/05/06 11:09:10 by jhwang2          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	do_routine(t_data *philos)
{
	while (1)
	{
		take_fork (philos);
		eating (philos);
		put_fork (philos);
		sleeping (philos);
		thinking (philos);
	}
}

void	eating(t_data *philos)
{
	philos->philo->time_to_die = 0;
	if (philos->philo->num_of_time_to_eat != -1)
	{
		philos->philo->num_of_time_to_eat--;
		if (philos->philo->num_of_time_to_eat == 0)
			sem_post (philos->sem->sem_eaten);
	}
	print_status (philos, philos->philo, philos->id, "is eating");
	p_usleep (philos, philos->philo, philos->philo->time_to_eat);
}

void	sleeping(t_data *philos)
{
	print_status (philos, philos->philo, philos->id, "is sleeping");
	p_usleep (philos, philos->philo, philos->philo->time_to_sleep);
}

void	thinking(t_data *philos)
{
	print_status (philos, philos->philo, philos->id, "is thinking");
	if (philos->philo->time_to_eat > philos->philo->time_to_sleep)
		p_usleep (philos, philos->philo,
			philos->philo->time_to_eat - philos->philo->time_to_sleep);
}
