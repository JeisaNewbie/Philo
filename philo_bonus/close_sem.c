/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close_sem.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhwang2 <jhwang2@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/30 01:52:51 by jhwang2           #+#    #+#             */
/*   Updated: 2023/05/06 13:40:48 by jhwang2          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

int	close_sem(t_data *philos, int i)
{
	if (i == 2)
		sem_close (philos->sem->forks);
	else if (i == 3)
	{
		sem_close (philos->sem->forks);
		sem_close (philos->sem->sem_print);
	}
	else if (i == 4)
	{
		sem_close (philos->sem->forks);
		sem_close (philos->sem->sem_print);
		sem_close (philos->sem->sem_eaten);
	}
	else if (i == 5)
	{
		sem_close (philos->sem->forks);
		sem_close (philos->sem->sem_print);
		sem_close (philos->sem->sem_eaten);
		sem_close (philos->sem->sem_setting);
	}
	return (1);
}
