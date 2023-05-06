/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   take_fork.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhwang2 <jhwang2@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 14:14:27 by jhwang2           #+#    #+#             */
/*   Updated: 2023/05/06 10:58:50 by jhwang2          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	take_fork(t_data *philos)
{
	sem_wait (philos->sem->forks);
	sem_wait (philos->sem->forks);
	print_status (philos, philos->philo, philos->id, "has taken a fork");
	print_status (philos, philos->philo, philos->id, "has taken a fork");
}

void	put_fork(t_data *philos)
{
	sem_post (philos->sem->forks);
	sem_post (philos->sem->forks);
}
