/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fschmid <fschmid@student.42heilbronn.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 14:19:15 by fschmid           #+#    #+#             */
/*   Updated: 2023/02/27 14:19:15 by fschmid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

unsigned long	current_time(void)
{
	long			time;
	struct timeval	current_ts;

	gettimeofday(&current_ts, NULL);
	time = (current_ts.tv_sec * 1000) + (current_ts.tv_usec / 1000);
	return (time);
}

void	ft_sleep(long ms)
{
	unsigned long	end;

	end = current_time() + ms;
	while (current_time() < end)
		usleep(100);
}
