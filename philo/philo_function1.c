/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_function1.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhwang2 <jhwang2@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 10:01:52 by jhwang2           #+#    #+#             */
/*   Updated: 2023/05/06 17:01:43 by jhwang2          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	print_takef(t_data *data, t_philo *philo, int id, char *str)
{
	pthread_mutex_lock (&data->mutex->print_mutex);
	printf ("%llu %d %s\n", get_gtd () - data->time_to_start, id + 1, str);
	printf ("%llu %d %s\n", get_gtd () - data->time_to_start, id + 1, str);
	pthread_mutex_unlock (&data->mutex->print_mutex);
	philo->usec_before = get_gtd ();
}

void	print_status(t_data *data, t_philo *philo, int id, char *str)
{
	pthread_mutex_lock (&data->mutex->print_mutex);
	printf ("%llu %d %s\n", get_gtd () - data->time_to_start, id + 1, str);
	pthread_mutex_unlock (&data->mutex->print_mutex);
	philo->usec_before = get_gtd ();
}

void	rm_mutex_all(t_data *data, int end)
{
	int	i;

	i = 0;
	while (i < end)
		pthread_mutex_destroy (&data->mutex->fork_mutex[i++]);
	i = 0;
	pthread_mutex_destroy (&data->mutex->print_mutex);
	pthread_mutex_destroy (&data->mutex->setting_mutex);
	pthread_mutex_destroy (&data->mutex->end_mutex);
	free (data->mutex->fork_mutex);
	free (data->mutex);
	if (data->forks)
		free (data->forks);
}
