/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juan-aga <juan_aga@student.42malaga.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 09:03:13 by juan-aga          #+#    #+#             */
/*   Updated: 2023/03/05 17:16:13 by juan-aga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include <stdlib.h>

static void	ft_free_phi(t_table *table);

int	main(int argc, char **argv)
{
	t_table	table;

	if (argc != 5 && argc != 6)
		return (ft_error(0));
	if (!ft_check_args(argv))
		return (ft_error(1));
	if (ft_init(&argv[1], &table))
	{
		ft_free_phi(&table);
		return (1);
	}
	ft_free_phi(&table);
	return (0);
}

static void	ft_free_phi(t_table *table)
{
	if (table->philo)
		free(table->philo);
}
