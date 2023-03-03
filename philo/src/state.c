/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   state.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fschmid <fschmid@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 19:27:18 by fschmid           #+#    #+#             */
/*   Updated: 2023/03/03 19:27:26 by fschmid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include  "../include/philo.h"

bool	check_life(t_philo **philos)
{
	int	i;

	i = -1;
	while (philos[++i])
	{
		if (philos[i]->dead)
			return (false);
	}
	return (true);
}

bool	check_finished(t_philo **philos)
{
	int	i;

	i = -1;
	while (philos[++i])
	{
		if (!philos[i]->finished)
			return (false);
	}
	return (true);
}
