/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juan-aga <juan_aga@student.42malaga.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 12:00:29 by juan-aga          #+#    #+#             */
/*   Updated: 2023/03/05 18:58:44 by juan-aga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include <pthread.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/wait.h>
#include <unistd.h>

static int	ft_philosophers(t_table *table);
static int	ft_semaphore(t_table *table);
static int	ft_start(t_table *table);
static void	ft_exit_phi(t_table *table);

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
	if (ft_semaphore(table))
		return (1);
	if (ft_start(table))
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
	}
	table->philo = philo;
	return (0);
}

static int	ft_semaphore(t_table *table)
{
	sem_unlink("/print_lock");
	sem_unlink("/stop_lock");
	sem_unlink("/fork_lock");
	table->print_lock = sem_open("/print_lock", O_CREAT, S_IRWXU, 1);
	table->stop_lock = sem_open("/stop_lock", O_CREAT, S_IRWXU, 1);
	table->fork_lock = sem_open("/fork_lock", O_CREAT, S_IRWXU, \
		table->num_phi);
	if (table->print_lock == 0 || table->stop_lock == 0 || \
		table->fork_lock == 0)
		return (1);
	return (0);
}

static int	ft_start(t_table *table)
{
	int		i;
	t_philo	*philo;

	philo = table->philo;
	table->t_start = ft_now();
	i = -1;
	while (++i < table->num_phi)
	{
		philo[i].pid = fork();
		if (philo[i].pid < 0)
			return (1);
		if (philo[i].pid == 0)
			ft_routine(&philo[i]);
	}
	ft_exit_phi(table);
	return (0);
}

static void	ft_exit_phi(t_table *table)
{
	int	i;
	int	status;

	i = -1;
	while (++i < table->num_phi)
	{
		waitpid(-1, &status, 0);
		if (status != 0)
		{
			i = -1;
			while (++i < table->num_phi)
				kill(table->philo[i].pid, SIGTERM);
			break ;
		}
	}
	sem_close(table->print_lock);
	sem_close(table->stop_lock);
	sem_close(table->fork_lock);
	sem_unlink("/print_lock");
	sem_unlink("/stop_lock");
	sem_unlink("/fork_lock");
}
