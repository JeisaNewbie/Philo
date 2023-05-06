/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_routine_odd.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhwang2 <jhwang2@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 14:14:22 by jhwang2           #+#    #+#             */
/*   Updated: 2023/05/06 11:09:05 by jhwang2          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	do_routine_odd(t_data *philos)
{
	if (philos->num_of_philos == 1)
	{
		sem_wait (philos->sem->forks);
		print_status (philos, philos->philo, 0, "has taken a fork");
		p_usleep (philos, philos->philo, philos->philo->time_to_die_origin * 2);
	}
	if (philos->id == philos->num_of_philos - 1)
		p_usleep (philos, philos->philo, philos->philo->time_to_eat * 2);
	while (1)
	{
		take_fork (philos);
		eating (philos);
		put_fork (philos);
		sleeping (philos);
		thinking_odd (philos);
	}
}

void	thinking_odd(t_data *philos)
{
	print_status (philos, philos->philo, philos->id, "is thinking");
	if (philos->philo->time_to_eat * 2 > philos->philo->time_to_sleep)
		p_usleep (philos, philos->philo,
			philos->philo->time_to_eat * 2 - philos->philo->time_to_sleep);
}
