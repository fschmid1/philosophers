#nclude "../include/philo.h"

long	current_time(void)
{
	long			time;
	struct timeval	current_ts;

	gettimeofday(&current_ts, NULL);
	time = current_ts.tv_sec * 1000 + current_ts.tv_usec / 1000;
	return (time);
}

void	ft_sleep(long ms)
{
	long	end;

	end = current_time() + ms;
	while (current_time() < end)
		usleep(200);
}

