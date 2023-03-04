/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juan-aga <juan_aga@student.42malaga.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 09:04:48 by juan-aga          #+#    #+#             */
/*   Updated: 2023/03/04 14:11:01 by juan-aga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

//# include "memory_leaks.h"
# include <pthread.h>

# define FORK_STR " has taken a fork\n"
# define EAT_STR " is eating\n"
# define SLEEP_STR " is sleeping\n"
# define THINK_STR " is thinking\n"
# define DIED_STR " died\n"

typedef struct s_table	t_table;

typedef struct s_philo
{
	int				philo_id;
	time_t			last_eat;
	int				eat_num;
	pthread_mutex_t	eat_lock;
	pthread_mutex_t	fork[2];
	t_table			*table;
}	t_philo;

typedef struct s_table
{
	int				num_phi;
	int				ttd;
	int				tte;
	int				tts;
	int				max_tte;
	int				stop;
	time_t			t_start;
	pthread_t		*pth_id;
	pthread_mutex_t	print_lock;
	pthread_mutex_t	stop_lock;
	t_philo			*philo;
}	t_table;

int			ft_check_args(char **str);
long long	ft_atoll_phi(char *num);
int			ft_init(char **str, t_table *table);

/*		PRINT		*/
int			ft_error(int error);
void		ft_print_phi(t_table *table, int i, char *str);

/*		TIME		*/
time_t		ft_now(void);
time_t		ft_time_diff(time_t past, time_t pre);
void		ft_sleep(t_table *table, time_t sleep);

/*		ROUTINE		*/
void		*ft_routine(void *phi);

#endif
