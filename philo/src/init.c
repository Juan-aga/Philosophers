/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juan-aga <juan_aga@student.42malaga.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 12:00:29 by juan-aga          #+#    #+#             */
/*   Updated: 2023/02/24 16:05:22 by juan-aga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_init(char **str, t_phi *phi)
{
	phi->num_phi = ft_atoll_phi(str[0]);
	phi->ttd = ft_atoll_phi(str[1]);
	phi->tte = ft_atoll_phi(str[2]);
	phi->tts = ft_atoll_phi(str[3]);
	if (str[4])
		phi->num_te = ft_atoll_phi(str[4]);
	else
		phi->num_te = 0;
}
