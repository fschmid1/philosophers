#include  "../include/philo.h"
#include <pthread.h>

bool	check_life(t_philo **philos)
{
	int	i;

	i = -1;
	while (philos[++i])
	{
		pthread_mutex_lock(&philos[i]->check);
		if (philos[i]->dead)
			return (false);
		pthread_mutex_unlock(&philos[i]->check);
	}
	return (true);
}

bool	check_finished(t_philo **philos)
{
	int	i;

	i = -1;
	while (philos[++i])
	{
		pthread_mutex_lock(&philos[i]->check);
		if (!philos[i]->finished)
			return (false);
		pthread_mutex_unlock(&philos[i]->check);
	}
	return (true);
}

