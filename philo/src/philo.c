/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fschmid <fschmid@student.42heilbronn.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 16:20:48 by fschmid           #+#    #+#             */
/*   Updated: 2023/03/02 10:52:19 by fschmid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"
#include <pthread.h>

static void	use_right_fork(t_philo *philo)
{
	pthread_mutex_lock(philo->right);
	print_philo(philo, GREEN, "has taken a fork");
}

static void	use_left_fork(t_philo *philo)
{
	pthread_mutex_lock(&philo->left);
	print_philo(philo, GREEN, "has taken a fork");
}

void eating(t_philo *philo)
{
	if (philo->number % 2)
	{
		use_left_fork(philo);
		use_right_fork(philo);
	}
	else
	{
		use_right_fork(philo);
		use_left_fork(philo);
	}
	pthread_mutex_lock(&philo->eat_mutex);
	philo->last_eating = current_time();
	print_philo(philo, CYAN, "is eating");
	pthread_mutex_unlock(&philo->eat_mutex);
	pthread_mutex_lock(&philo->check);
	philo->times_to_eat -= 1;
	pthread_mutex_unlock(&philo->check);
	ft_sleep(philo->rules->time_to_eat);
	pthread_mutex_unlock(&philo->left);
	pthread_mutex_unlock(philo->right);
}

void sleeping(t_philo *philo)
{
	print_philo(philo, PURPLE, "is sleeping");
	ft_sleep(philo->rules->time_to_sleep);
}

void thinking(t_philo *philo)
{

	print_philo(philo, PURPLE, "is thinking");
}
