#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <sys/time.h>
# include <stdbool.h>

# define INT_MAX 2147483647
# define INT_MIN -2147483648

# define RED "\033[0;31m"
# define DEFAULT "\033[0m"
# define YELLOW "\33[0;33m"
# define BLUE "\033[0;34m"
# define PURPLE "\033[0;35m"
# define CYAN "\033[0;36m"
# define GREEN "\033[32m"

typedef struct s_rules
{
	long			amount;
	long			time_to_die;
	long			time_to_eat;
	long			time_to_sleep;
	long			number_of_eat;
	long			start;
	pthread_mutex_t	global_print;
}	t_rules;

t_rules	*parse_input(int argc, char **argv);
long	ft_atol(const char *str);
int		ft_isdigit(int arg);
size_t	ft_strlen(const char *str);
void	free_all(t_rules *rules);

#endif
