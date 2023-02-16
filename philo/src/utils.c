#include "../include/philo.h"

long	ft_atol(const char *str)
{
	int		i;
	long	out;
	int		vz;

	i = 0;
	out = 0;
	vz = 1;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			vz = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		out += str[i] - '0';
		if (str[i + 1] >= '0' && str[i + 1] <= '9')
			out *= 10;
		i++;
	}
	return (out * vz);
}

int	ft_isdigit(int arg)
{
	if (arg >= '0' && arg <= '9')
		return (1);
	else
		return (0);
}

size_t	ft_strlen(const char *str)
{
	size_t	len;
	int		i;

	i = 0;
	len = 0;
	while (str[i] == '0')
		i++;
	while (str[i])
	{
		i++;
		len++;
	}
	return (len);
}

void	free_all(t_rules *rules, t_philo **philos)
{
	int	i;

	free(rules);
	i = -1;
	while (philos && philos[++i])
		free(philos[i]);
	free(philos);
}

void	print_philo(t_philo *philo, char *color, char *state)
{
	struct timeval	current_time;

	gettimeofday(&current_time, NULL);
	printf("%s%ld %d %s%s", color, current_time.tv_sec * 1000,
		philo->number, state, DEFAULT);
}
