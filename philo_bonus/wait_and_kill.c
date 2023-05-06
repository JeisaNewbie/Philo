/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wait_and_kill.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhwang2 <jhwang2@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 14:14:31 by jhwang2           #+#    #+#             */
/*   Updated: 2023/05/06 16:14:18 by jhwang2          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	wait_and_kill(t_data *philos)
{
	int		i;

	i = -1;
	if (wait_proc (philos))
	{
		if (philos->argv[5] != NULL)
		{
			philos->flag = 0;
			while (++i < philos->num_of_philos)
				sem_post (philos->sem->sem_eaten);
		}
	}
	close_sem (philos, 5);
	exit (0);
}

int	wait_proc(t_data *philos)
{
	pthread_t	mor_eaten;

	if (philos->argv[5] != NULL)
	{
		pthread_create (&mor_eaten, NULL, check_eaten, (void *)philos);
		pthread_detach (mor_eaten);
	}
	return (check_dead (philos, 0, 0));
}

int	check_dead(t_data *philos, int status, int error)
{
	int	ret;
	int	i;

	ret = 0;
	i = -1;
	ret = waitpid (-1, &status, 0);
	if (WIFSIGNALED (status))
		return (0);
	while (++i < philos->num_of_philos)
	{
		if (ret == philos->philos[i])
		{
			philos->philos[i] = -1;
			return (kill_proc (philos, i));
		}
	}
	return (error);
}

void	*check_eaten(void *arg)
{
	t_data	*philos;
	int		i;

	philos = (t_data *)arg;
	i = 0;
	while (i++ < philos->num_of_philos)
		sem_wait (philos->sem->sem_eaten);
	if (philos->flag == 0)
		return (0);
	sem_wait (philos->sem->sem_print);
	printf ("all philosophers have eaten all\n");
	kill_proc (philos, -1);
	return (0);
}

int	kill_proc(t_data *philos, int i)
{
	int			j;

	j = -1;
	while (++j < philos->num_of_philos)
	{
		if (j == i)
			continue ;
		kill (philos->philos[j], SIGKILL);
	}
	return (1);
}
