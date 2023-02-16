#include "../include/philo.h"

int	main(int argc, char **argv)
{
	t_rules	*rules;
	t_philo	**philos;

	rules = parse_input(argc, argv);
	philos = NULL;
	if (!rules)
		return (1);
	free_all(rules, philos);
	return (0);
}
