/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhwang2 <jhwang2@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 10:01:52 by jhwang2           #+#    #+#             */
/*   Updated: 2023/05/06 17:06:38 by jhwang2          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	check_vaild(int argc, char **argv)
{
	int	i[2];

	i[0] = 0;
	i[1] = -1;
	if (!(5 <= argc && argc <= 6))
	{
		printf ("option failure!!!\n");
		return (1);
	}
	while (argv[++i[0]])
	{
		while (argv[i[0]][++i[1]])
		{
			if (!('0' <= argv[i[0]][i[1]] && argv[i[0]][i[1]] <= '9'))
			{
				printf ("integer failure!!!\n");
				return (1);
			}
		}
		i[1] = -1;
	}
	return (check_argument (argv));
}

int	check_argument(char **argv)
{
	int	error;

	error = 0;
	if (!check_integer (argv))
		return (1);
	if (argv[1][0] == '0' && argv[1][1] == '\0')
		error = 1;
	else if (argv[2][0] == '0' && argv[2][1] == '\0')
		error = 1;
	else if (argv[5] != 0 && argv[5][0] == '0' && argv[5][1] == '\0')
		error = 2;
	else
		return (0);
	if (error == 1)
		printf ("argument failure!!!\n");
	else
		printf ("all philosophers have eaten all\n");
	return (1);
}

int	check_integer(char **argv)
{
	int	i;

	i = 2;
	while (i < 5)
	{
		if (p_atoi (argv[i]) <= 0)
		{
			printf ("integer failure!!!\n");
			return (0);
		}
		printf ("%d\n", p_atoi (argv[i]));
		i++;
	}
	return (1);
}
