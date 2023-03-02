/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   waitress.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fschmid <fschmid@student.42heilbronn.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 11:05:00 by fschmid           #+#    #+#             */
/*   Updated: 2023/03/02 11:34:54 by fschmid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"
#include <pthread.h>

static void	*handle_waitress_thread(void *arg)
{
	t_waitress	*waitress;

	waitress = (t_waitress *) arg;
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
}
