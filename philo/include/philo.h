/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juan-aga <juan_aga@student.42malaga.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 09:04:48 by juan-aga          #+#    #+#             */
/*   Updated: 2023/02/24 13:32:26 by juan-aga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

typedef struct s_phi
{
	int	num_phi;
	int	ttd;
	int	tte;
	int	tts;
	int	num_te;
}	t_phi;

int			ft_check_args(char **str);
long long	ft_atoll_phi(char *num);
void		ft_init(char **str, t_phi *phi);

#endif
