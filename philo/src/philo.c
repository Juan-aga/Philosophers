/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juan-aga <juan_aga@student.42malaga.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 09:03:13 by juan-aga          #+#    #+#             */
/*   Updated: 2023/02/24 13:32:04 by juan-aga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include <stdlib.h>

static void	ft_leaks(void)
{
	system("leaks -q philo");
}

int	main(int argc, char **argv)
{
	t_phi	phi;

	atexit(ft_leaks);
	if (argc != 5 && argc != 6)
		return (1);
	if (ft_check_args(argv))
		return (1);
	ft_init(argv, &phi);
	return (0);
}
