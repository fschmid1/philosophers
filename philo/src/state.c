#include  "../include/philo.h"
#include <stdio.h>

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

