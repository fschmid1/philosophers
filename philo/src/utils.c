/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fschmid <fschmid@student.42heilbronn.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 14:19:31 by fschmid           #+#    #+#             */
/*   Updated: 2023/03/03 18:59:32 by fschmid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

long	ft_atol(const char *str)
{
	int		i;
	long	out;
	int		vz;

	i = 0;
	out = 0;
	vz = 1;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			vz = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		out += str[i] - '0';
		if (str[i + 1] >= '0' && str[i + 1] <= '9')
			out *= 10;
		i++;
	}
	return (out * vz);
}

bool	ft_isdigit(int arg)
{
	if (arg >= '0' && arg <= '9')
		return (true);
	else
		return (false);
}

size_t	ft_strlen(const char *str)
{
	size_t	len;
	int		i;

	i = 0;
	len = 0;
	while (str[i] == '0')
		i++;
	while (str[i])
	{
		i++;
		len++;
	}
	return (len);
}

void	free_all(t_rules *rules, t_philo **philos)
{
	int	i;

	free(rules);
	i = -1;
	while (philos && philos[++i])
	{
		pthread_mutex_destroy(&philos[i]->left);
		free(philos[i]);
	}
	free(philos);
}

void	print_philo(t_philo *philo, char *color, char *state)
{
	pthread_mutex_lock(&philo->rules->print_mutex);
	printf("%s%ld\t%d\t%s%s\n", color, current_time() - philo->rules->start,
		philo->number, state, DEFAULT);
	pthread_mutex_unlock(&philo->rules->print_mutex);
}
