/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juan-aga <juan-aga@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/04 11:16:27 by juan-aga          #+#    #+#             */
/*   Updated: 2023/03/04 19:05:21 by juan-aga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include <pthread.h>

static void	ft_eat_r(t_philo *philo);
static void	ft_sleep_r(t_philo *philo);
static void	ft_think_r(t_philo *philo, int p);

void	*ft_routine(void *phi)
{
	t_philo	*philo;
	t_table	*table;

	philo = (t_philo *) phi;
	table = philo->table;
	if (philo->philo_id % 2)
		ft_think_r(philo, 0);
	while (!(table->stop))
	{
		ft_eat_r(philo);
		ft_sleep_r(philo);
		ft_think_r(philo, 1);
	}
	return (NULL);
}

static void	ft_eat_r(t_philo *philo)
{
	t_table	*table;

	table = philo->table;
	pthread_mutex_lock(&table->fork_lock[philo->fork[0]]);
	ft_print_phi(table, philo->philo_id, FORK_STR);
	if (table->num_phi == 1)
		ft_sleep(table, table->ttd + 1);
	pthread_mutex_lock(&table->fork_lock[philo->fork[1]]);
	ft_print_phi(table, philo->philo_id, FORK_STR);
	ft_print_phi(table, philo->philo_id, EAT_STR);
	pthread_mutex_lock(&philo->eat_lock);
	philo->last_eat = ft_now();
	pthread_mutex_unlock(&philo->eat_lock);
	ft_sleep(table, table->tte);
	pthread_mutex_lock(&philo->eat_lock);
	philo->eat_num += 1;
	pthread_mutex_unlock(&philo->eat_lock);
	pthread_mutex_unlock(&table->fork_lock[philo->fork[1]]);
	pthread_mutex_unlock(&table->fork_lock[philo->fork[0]]);
}

static void	ft_sleep_r(t_philo *philo)
{
	if (!philo->table->stop)
	{
		ft_print_phi(philo->table, philo->philo_id, SLEEP_STR);
		ft_sleep(philo->table, philo->table->tts);
	}
}

static void	ft_think_r(t_philo *philo, int p)
{
	time_t	ttt;

	pthread_mutex_lock(&philo->eat_lock);
	ttt = (philo->table->ttd - ft_time_diff(philo->last_eat, ft_now()) - \
		philo->table->tte) / 2;
	pthread_mutex_unlock(&philo->eat_lock);
	if (ttt <= 0 && !p)
		ttt = 1;
	else if (ttt < 0)
		ttt = 0;
	if (p)
		ft_print_phi(philo->table, philo->philo_id, THINK_STR);
	ft_sleep(philo->table, ttt);
}
