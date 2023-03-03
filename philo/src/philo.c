/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fschmid <fschmid@student.42heilbronn.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 16:20:48 by fschmid           #+#    #+#             */
/*   Updated: 2023/03/03 19:01:38 by fschmid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"
#include <pthread.h>

static void	use_right_fork(t_philo *philo)
{
	pthread_mutex_lock(philo->right);
	print_philo(philo, GREEN, "has taken right fork");
}

static void	use_left_fork(t_philo *philo)
{
	pthread_mutex_lock(&philo->left);
	print_philo(philo, GREEN, "has taken left fork");
}

void	eating(t_philo *philo)
{
	if (philo->dead)
		return ;
	use_left_fork(philo);
	use_right_fork(philo);
	print_philo(philo, CYAN, "is eating");
	philo->last_eating = current_time();
	pthread_mutex_lock(&philo->check);
	if (philo->times_to_eat > 0)
		philo->times_to_eat -= 1;
	pthread_mutex_unlock(&philo->check);
	ft_sleep(philo->rules->time_to_eat);
	pthread_mutex_unlock(&philo->left);
	pthread_mutex_unlock(philo->right);
}

void sleeping(t_philo *philo)
{
	if (philo->dead)
		return ;
	print_philo(philo, PURPLE, "is sleeping");
	ft_sleep(philo->rules->time_to_sleep);
}

void thinking(t_philo *philo)
{
	if (philo->dead)
		return ;
	print_philo(philo, PURPLE, "is thinking");
}
