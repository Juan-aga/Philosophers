/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juan-aga <juan-aga@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/04 11:16:27 by juan-aga          #+#    #+#             */
/*   Updated: 2023/03/05 17:19:48 by juan-aga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include <pthread.h>

static void	ft_eat_r(t_philo *philo);
static void	ft_sleep_r(t_philo *philo);
static void	ft_think_r(t_philo *philo, int p);
static void	*ft_is_finish(void *phi);

void	*ft_routine(void *phi)
{
	t_philo	*philo;
	t_table	*table;

	philo = (t_philo *) phi;
	table = philo->table;
	philo->last_eat = table->t_start;
	pthread_create(&philo->finish, NULL, ft_is_finish, phi);
	if (philo->philo_id % 2)
		ft_think_r(philo, 0);
	while (!(table->stop))
	{
		ft_eat_r(philo);
		if (table->max_tte != -1 && philo->eat_num <= table->max_tte)
			break ;
		ft_sleep_r(philo);
		ft_think_r(philo, 1);
	}
	pthread_join(philo->finish, NULL);
	if (table->stop)
		exit(1);
	exit(0);
}

static void	ft_eat_r(t_philo *philo)
{
	t_table	*table;

	table = philo->table;
	sem_wait(table->fork_lock);
	ft_print_phi(table, philo->philo_id, FORK_STR);
	if (table->num_phi == 1)
		ft_sleep(table, table->ttd + 1);
	sem_wait(table->fork_lock);
	ft_print_phi(table, philo->philo_id, FORK_STR);
	sem_wait(table->stop_lock);
	ft_print_phi(table, philo->philo_id, EAT_STR);
	philo->last_eat = ft_now();
	sem_post(table->stop_lock);
	ft_sleep(table, table->tte);
	philo->eat_num += 1;
	sem_post(table->fork_lock);
	sem_post(table->fork_lock);
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

	ttt = (philo->table->ttd - ft_time_diff(philo->last_eat, ft_now()) - \
		philo->table->tte) / 2;
	if (ttt <= 0 && !p)
		ttt = 1;
	else if (ttt < 0)
		ttt = 0;
	if (p)
		ft_print_phi(philo->table, philo->philo_id, THINK_STR);
	ft_sleep(philo->table, ttt);
}

static void	*ft_is_finish(void *phi)
{
	t_philo	*philo;
	t_table	*table;

	philo = (t_philo *) phi;
	table = philo->table;
	ft_sleep(table, table->ttd);
	while (!table->stop)
	{
		sem_wait(table->stop_lock);
		if (ft_time_diff(philo->last_eat, ft_now()) > table->ttd)
		{
			ft_print_phi(table, philo->philo_id, DIED_STR);
			table->stop = 1;
			free(table->fork_lock);
			free(table->philo);
			exit(1);
		}
		sem_post(table->stop_lock);
		if (table->max_tte != -1 && philo->eat_num >= table->max_tte)
			break ;
	}
	return (NULL);
}
