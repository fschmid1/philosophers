/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fschmid <fschmid@student.42heilbronn.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 14:30:47 by fschmid           #+#    #+#             */
/*   Updated: 2023/02/27 15:44:43 by fschmid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

t_philo	**create_philos(t_rules *rules)
{
	int		i;
	t_philo	**philos;

	philos = malloc(sizeof(t_philo) * rules->amount);
	philos[rules->amount] = NULL;
	i = -1;
	while (++i < rules->amount)
	{
		philos[i] = malloc(sizeof(t_philo));
		philos[i]->number = i;
		philos[i]->rules = rules;
		philos[i]->times_to_eat = rules->time_to_eat;
		philos[i]->last_eating = rules->start;
		pthread_mutex_init(&philos[i]->left, NULL);
		if (i > 0)
			philos[i - 1]->right = &philos[i]->left;
		if (i == rules->amount - 1)
			philos[i]->right = &philos[0]->left;
		pthread_mutex_init(&philos[i]->eat_mutex, NULL);
		pthread_mutex_init(&philos[i]->check, NULL);
	}
	return (philos);
}

void	create_threads(t_philo **philos)
{
	int	i;

	i = -1;
	while (philos && philos[++i])
		pthread_create(&philos[i]->id, NULL, handle_thread, philos[i]);
}

void	*handle_thread(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	pthread_exit(NULL);
}
