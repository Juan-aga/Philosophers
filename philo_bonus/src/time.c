/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juan-aga <juan-aga@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 18:47:59 by juan-aga          #+#    #+#             */
/*   Updated: 2023/03/04 13:40:54 by juan-aga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include <sys/time.h>

time_t	ft_now(void)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	return ((time.tv_sec * 1000) + (time.tv_usec / 1000));
}

time_t	ft_time_diff(time_t past, time_t pre)
{
	return (pre - past);
}

void	ft_sleep(t_table *table, time_t sleep)
{
	time_t	wake_up;

	wake_up = ft_now();
	while (!(table->stop))
	{
		if (ft_time_diff(wake_up, ft_now()) >= sleep)
			break ;
	}
}
