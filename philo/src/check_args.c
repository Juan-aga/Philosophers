/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juan-aga <juan_aga@student.42malaga.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 12:15:07 by juan-aga          #+#    #+#             */
/*   Updated: 2023/02/24 13:32:53 by juan-aga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	ft_check_number(char *str);
static int	ft_isnumber_phi(char *c);
static int	ft_limits_phi(char *num);

int	ft_check_args(char **str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (!ft_check_number(str[i]))
			return (0);
	}
	return (1);
}

static int	ft_check_number(char *str)
{
	int	i;

	i = 0;
	if (ft_isnumber_phi(str))
		return (0);
	if (ft_limits_phi(str))
		return (0);
	return (1);
}

static int	ft_isnumber_phi(char *c)
{
	int	i;

	i = 0;
	if (c[i] == '-' || c[i] == '+')
		i++;
	while (c[i] >= '0' && c[i] <= '9')
		i++;
	if (c[i] != '\0' || c[i - 1] == '-' || c[i - 1] == '+')
		return (1);
	return (0);
}

static int	ft_limits_phi(char *num)
{
	long long	tmp;

	tmp = ft_atoll_phi(num);
	if (tmp < 1 || tmp > 2147483647)
		return (1);
	return (0);
}

long long	ft_atoll_phi(char *num)
{
	int			i;
	int			sign;
	long long	result;

	sign = 1;
	result = 0;
	i = 0;
	if (num[i] == '-' || num[i] == '+')
	{
		if (num[i] == '-')
			sign *= -1;
		i++;
	}
	while (num[i] >= '0' && num[i] <= '9')
	{
		result = result * 10 + num[i] - '0';
		i++;
	}
	return (result * sign);
}
