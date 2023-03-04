/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juan-aga <juan_aga@student.42malaga.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 09:03:13 by juan-aga          #+#    #+#             */
/*   Updated: 2023/03/04 10:54:18 by juan-aga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include <stdlib.h>

int	main(int argc, char **argv)
{
	t_table	table;
	char	*test;

	test = calloc(sizeof(char *), 2);
	(void) test;
	if (argc != 5 && argc != 6)
		return (ft_error(0));
	if (!ft_check_args(argv))
		return (ft_error(1));
	if (ft_init(&argv[1], &table))
		return (1);
	return (0);
}
