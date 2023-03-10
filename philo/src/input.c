/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fschmid <fschmid@student.42heilbronn.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 14:19:27 by fschmid           #+#    #+#             */
/*   Updated: 2023/03/02 11:39:23 by fschmid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

static bool	check_number(int argc, char **argv)
{
	int	j;
	int	i;

	i = 0;
	while (++i < argc)
	{
		j = -1;
		while (argv[i][++j] != '\0')
		{
			if (!ft_isdigit(argv[i][j]))
				return (false);
		}
	}
	return (true);
}

static bool	check_size(int argc, char **argv)
{
	int			i;

	i = 0;
	while (++i < argc)
	{
		if (ft_atol(argv[i]) < 1)
			return (false);
		if (ft_strlen(argv[i]) > 10)
			return (false);
		if (ft_atol(argv[i]) > INT_MAX)
			return (false);
	}
	return (true);
}

static bool	check_input(int argc, char **argv)
{
	if (argc != 6 && argc != 5)
		return (printf("%sFour arguments are needed%s\n", RED, DEFAULT), false);
	if (!check_number(argc, argv))
		return (printf("%sArguments must all be numbers%s\n",
				RED, DEFAULT), false);
	if (!check_size(argc, argv))
		return (printf("%sOnly numbers between 1 and %d are allowed%s\n",
				RED, INT_MAX, DEFAULT), false);
	return (true);
}

static void	set_rules(t_rules *rules, int argc, char **argv)
{
	rules->times_to_eat = -1;
	rules->amount = ft_atol(argv[1]);
	rules->time_to_die = ft_atol(argv[2]);
	rules->time_to_eat = ft_atol(argv[3]);
	rules->time_to_sleep = ft_atol(argv[4]);
	if (argc == 6)
		rules->times_to_eat = ft_atol(argv[5]);
	rules->start = current_time();
	pthread_mutex_init(&rules->print_mutex, NULL);
}

t_rules	*parse_input(int argc, char **argv)
{
	t_rules	*rules;

	if (!check_input(argc, argv))
		return (NULL);
	rules = malloc(sizeof(t_rules));
	if (!rules)
		return (NULL);
	set_rules(rules, argc, argv);
	return (rules);
}
