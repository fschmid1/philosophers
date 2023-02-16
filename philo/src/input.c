#include "../include/philo.h"

static bool	check_input(int argc, char **argv)
{
	(void)argv;
	if (argc != 6)
		return (printf("%sWrong arguments%s\n", RED, DEFAULT), false);
	return (true);
}

static void	set_rules(t_rules *rules, char **argv)
{
	rules->amount = ft_atol(argv[1]);
	rules->time_to_die = ft_atol(argv[2]);
	rules->time_to_eat = ft_atol(argv[3]);
	rules->time_to_sleep = ft_atol(argv[4]);
	rules->number_of_eat = ft_atol(argv[5]);
	rules->start = 0;
}

t_rules	*parse_input(int argc, char **argv)
{
	t_rules	*rules;

	if (!check_input(argc, argv))
		return (NULL);
	rules = malloc(sizeof(t_rules));
	if (!rules)
		return (NULL);
	set_rules(rules, argv);
	return (rules);
}
