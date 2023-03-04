/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juan-aga <juan_aga@student.42malaga.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 12:00:29 by juan-aga          #+#    #+#             */
/*   Updated: 2023/03/04 19:10:48 by juan-aga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include <pthread.h>
#include <stdlib.h>

static int	ft_philosophers(t_table *table);
static int	ft_threads(t_table *table);
static void	ft_is_finish(t_table *table);
static void	ft_finish(t_table *table);

int	ft_init(char **str, t_table *table)
{
	table->num_phi = ft_atoll_phi(str[0]);
	if (table->num_phi == 0)
		return (ft_error(2));
	table->ttd = ft_atoll_phi(str[1]);
	table->tte = ft_atoll_phi(str[2]);
	table->tts = ft_atoll_phi(str[3]);
	table->stop = 0;
	if (str[4])
		table->max_tte = ft_atoll_phi(str[4]);
	else
		table->max_tte = -1;
	if (ft_philosophers(table))
		return (ft_error(3));
	if (ft_threads(table))
		return (1);
	return (0);
}

static int	ft_philosophers(t_table *table)
{
	t_philo	*philo;
	int		i;

	philo = malloc(sizeof(t_philo) * table->num_phi);
	philo->table = table;
	philo->table->fork_lock = malloc(sizeof(pthread_mutex_t) * \
		philo->table->num_phi);
	if (!philo || !table->fork_lock)
		return (1);
	i = -1;
	while (++i < table->num_phi)
	{
		philo[i].philo_id = i;
		philo[i].eat_num = 0;
		philo[i].table = table;
		pthread_mutex_init(&table->fork_lock[i], 0);
		philo[i].fork[0] = i;
		philo[i].fork[1] = (i + 1) % philo->table->num_phi;
		pthread_mutex_init(&philo[i].eat_lock, 0);
	}
	pthread_mutex_init(&table->print_lock, 0);
	pthread_mutex_init(&table->stop_lock, 0);
	table->philo = philo;
	return (0);
}

static int	ft_threads(t_table *table)
{
	int	i;

	i = -1;
	table->t_start = ft_now();
	table->pth_id = malloc(sizeof(pthread_t) * table->num_phi);
	if (!table->pth_id)
		return (1);
	while (++i < table->num_phi)
	{
		table->philo[i].last_eat = table->t_start;
		if (pthread_create(&table->pth_id[i], 0, ft_routine,
				&table->philo[i]))
			return (1);
	}
	ft_is_finish(table);
	ft_finish(table);
	return (0);
}

static void	ft_is_finish(t_table *table)
{
	int	i;

	ft_sleep(table, table->ttd);
	while (!table->stop)
	{
		i = -1;
		while (++i < table->num_phi && !table->stop)
		{
			pthread_mutex_lock(&table->philo[i].eat_lock);
			if (ft_time_diff(table->philo[i].last_eat, ft_now()) > table->ttd)
			{
				ft_print_phi(table, i, DIED_STR);
				table->stop = 1;
			}
			pthread_mutex_unlock(&table->philo[i].eat_lock);
		}
		if (table->stop)
			break ;
		i = 0;
		while (table->max_tte != -1 && i < table->num_phi && \
				table->philo[i].eat_num >= table->max_tte)
			i++;
		if (i == table->num_phi)
			table->stop = 1;
	}
}

static void	ft_finish(t_table *table)
{
	int	i;

	i = -1;
	while (++i < table->num_phi)
	{
		pthread_mutex_destroy(&table->philo[i].eat_lock);
		pthread_mutex_destroy(&table->fork_lock[i]);
		pthread_join(table->pth_id[i], 0);
	}
	pthread_mutex_destroy(&table->print_lock);
	pthread_mutex_destroy(&table->stop_lock);
}
