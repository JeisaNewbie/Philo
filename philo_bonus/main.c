/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhwang2 <jhwang2@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 14:13:59 by jhwang2           #+#    #+#             */
/*   Updated: 2023/05/06 17:05:01 by jhwang2          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

int	main(int argc, char *argv[])
{
	t_data	philos;

	if (check_vaild (argc, argv))
		exit (1);
	init_philos (&philos, argv);
	if (fork_proc(&philos))
	{
		printf ("fork failure!!!\n");
		exit (1);
	}
}
