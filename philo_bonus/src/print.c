/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juan-aga <juan-aga@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 20:06:26 by juan-aga          #+#    #+#             */
/*   Updated: 2023/03/05 16:52:17 by juan-aga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
//#include <pthread.h>
#include <stdio.h>
#include <semaphore.h>

int	ft_error(int error)
{
	if (error == 0)
		printf("philo: invalid number of arguments.\n");
	else if (error == 1)
		printf("philo: not a valid number (between 0 and 2147483647)\n");
	else if (error == 2)
		printf("philo: must be almost 1 philosopher.\n");
	else if (error == 3)
		printf("philo: fail to create philosophers.\n");
	return (1);
}

void	ft_print_phi(t_table *table, int i, char *str)
{
	sem_wait(table->print_lock);
	if (!table->stop)
		printf("%ld %d%s", ft_time_diff(table->t_start, ft_now()), i + 1, str);
	sem_post(table->print_lock);
}
