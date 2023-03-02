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

static bool	is_dead(t_philo *philo)
{
	pthread_mutex_lock(&philo->eat_mutex);
	if (philo->last_eating + philo->rules->time_to_eat < current_time())
		return (true);
	pthread_mutex_unlock(&philo->eat_mutex);
	return (false);
}

static void	*handle_waitress_thread(void *arg)
{
	t_waitress	*waitress;
	int			i;

	waitress = (t_waitress *) arg;
	while (true)
	{
		i = -1;
		while (++i < waitress->rules->amount)
		{
			pthread_mutex_lock(&waitress->philos[i]->check);
			if (is_dead(waitress->philos[i]))
				waitress->philos[i]->dead = true;
			pthread_mutex_unlock(&waitress->philos[i]->check);
		}
	}
	return (NULL);
}

void	start_waitress(t_philo **philos,  t_rules  *rules)
{
	t_waitress	*waitress;
	void		*out;

	waitress = malloc(sizeof(t_waitress));
	waitress->philos = philos;
	waitress->rules = rules;
	pthread_create(&waitress->id, NULL, handle_waitress_thread, waitress);
	pthread_join(waitress->id, &out);
	pthread_mutex_lock(&rules->print_mutex);
	detach_threads(rules, philos);
	if (out)
		printf("%s%ld\t%d\t%s%s\n", RED, current_time() - rules->start,
			((t_philo *)  out)->number + 1, "died", DEFAULT);
	free(waitress);
}
