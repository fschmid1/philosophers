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

static void	*handle_waitress_thread(void *arg)
{
	t_waitress	*waitress;

	waitress = (t_waitress *) arg;
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
