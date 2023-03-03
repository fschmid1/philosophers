/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   waitress.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fschmid <fschmid@student.42heilbronn.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 11:05:00 by fschmid           #+#    #+#             */
/*   Updated: 2023/03/02 13:07:48 by fschmid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"
#include <pthread.h>
#include <stdio.h>

static bool	is_dead(t_philo *philo)
{
	pthread_mutex_lock(&philo->eat_mutex);
	if (philo->last_eating + philo->rules->time_to_die <= current_time())
		return (true);
	pthread_mutex_unlock(&philo->eat_mutex);
	return (false);
}

static void	*handle_waitress_thread(void *arg)
{
	t_waitress	*waitress;
	int			i;

	waitress = (t_waitress *) arg;
	i =  0;
	while (check_life(waitress->philos))
	{
		if (!waitress->philos[i])
			i = 0;
		pthread_mutex_lock(&waitress->rules->print_mutex);
		if (check_finished(waitress->philos))
		{
			printf("finished\n");
			break ;
		}
		if (is_dead(waitress->philos[i]))
		{
			printf("dead\n");
			pthread_mutex_destroy(&waitress->rules->print_mutex);
			break ;
		}
		pthread_mutex_unlock(&waitress->rules->print_mutex);
		i++;
	}
	return (NULL);
}

void	start_waitress(t_philo **philos,  t_rules  *rules)
{
	t_waitress	*waitress;

	waitress = malloc(sizeof(t_waitress));
	waitress->philos = philos;
	waitress->rules = rules;
	pthread_create(&waitress->id, NULL, handle_waitress_thread, waitress);
	pthread_join(waitress->id, NULL);
	pthread_mutex_destroy(&rules->print_mutex);
	detach_threads(philos);
	free(waitress);
}
