/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juan-aga <juan-aga@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 20:06:26 by juan-aga          #+#    #+#             */
/*   Updated: 2023/02/28 20:23:22 by juan-aga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_error(int error)
{
	if (error == 0)
		printf("philo: invalid number of arguments.\n");
	else if (error == 1)
		printf("philo: not a valid number (between 0 and 2147483647)\n");
	else if (error == 2)
		printf("philo: must be almost 1 philosopher.\n");
	return (1);
}
