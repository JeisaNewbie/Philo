/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fork.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhwang2 <jhwang2@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 14:14:07 by jhwang2           #+#    #+#             */
/*   Updated: 2023/05/06 11:17:13 by jhwang2          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

int	fork_proc(t_data *philos)
{
	if (fork_child (philos))
		return (1);
	if (philos->pid > 0)
		wait_and_kill (philos);
	else
		start (philos);
	return (0);
}

int	fork_child(t_data *philos)
{
	int		i;

	i = 0;
	while (i < (philos->num_of_philos % 2) + 2)
	{
		if (start_philo (philos, i++))
			return (1);
		if (philos->pid == 0)
			return (0);
		usleep (100);
	}
	return (0);
}

int	start_philo(t_data *philos, int i)
{
	if (i == 0)
		init_time (philos);
	while (i < philos->num_of_philos)
	{
		philos->pid = fork ();
		if (philos->pid < 0)
			return (kill_proc (philos, i));
		if (philos->pid == 0)
		{
			philos->id = i;
			return (0);
		}
		philos->philos[i] = philos->pid;
		i += (philos->num_of_philos % 2) + 2;
	}
	return (0);
}

void	start(t_data *philos)
{
	t_philo		philo;

	philos->philo = &philo;
	init_philo (philos->philo, philos->argv);
	if (philos->num_of_philos % 2)
		do_routine_odd (philos);
	do_routine (philos);
}
