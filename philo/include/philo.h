/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fschmid <fschmid@student.42heilbronn.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 14:19:19 by fschmid           #+#    #+#             */
/*   Updated: 2023/03/02 13:10:33 by fschmid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/time.h>
# include <unistd.h>

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
	long			times_to_eat;
	long			start;
	pthread_mutex_t	print_mutex;
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

typedef struct s_waitress
{
	t_philo		**philos;
	t_rules		*rules;
	pthread_t	id;
}	t_waitress;

t_rules	*parse_input(int argc, char **argv);
long	ft_atol(const char *str);
bool	ft_isdigit(int arg);
size_t	ft_strlen(const char *str);
void	free_all(t_rules *rules, t_philo **philos);
void	print_philo(t_philo *philo, char *color, char *state);
void	ft_sleep(long ms);
long	current_time(void);
t_philo	**create_philos(t_rules *rules);
void	*handle_thread(void *arg);
void	create_threads(t_philo **philos);
void	thinking(t_philo *philo);
void	eating(t_philo *philo);
void	sleeping(t_philo *philo);
void	start_waitress(t_philo **philos, t_rules *rules);
void	detach_threads(t_rules *rules, t_philo **philos);

#endif
