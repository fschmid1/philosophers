#ifndef PHILO_H
#define PHILO_H

#include <pthread.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <unistd.h>

#define INT_MAX 2147483647
#define INT_MIN -2147483648

#define RED "\033[0;31m"
#define DEFAULT "\033[0m"
#define YELLOW "\33[0;33m"
#define BLUE "\033[0;34m"
#define PURPLE "\033[0;35m"
#define CYAN "\033[0;36m"
#define GREEN "\033[32m"

typedef struct s_rules
{
	long	amount;
	long	time_to_die;
	long	time_to_eat;
	long	time_to_sleep;
	long	number_of_eat;
	long	start;
}	t_rules;

typedef struct s_philo
{
	int				number;
	long			last_eating;
	long			times_to_eat;
	t_rules			*rules;
	pthread_t		id;
	pthread_mutex_t	left;
	pthread_mutex_t	*right;
	pthread_mutex_t	eat_mutex;
	pthread_mutex_t	check;
}	t_philo;

t_rules *parse_input(int argc, char **argv);
long ft_atol(const char *str);
int ft_isdigit(int arg);
size_t ft_strlen(const char *str);
void free_all(t_rules *rules, t_philo **philos);
void	print_philo(t_philo *philo, char *color, char *state)

#endif
