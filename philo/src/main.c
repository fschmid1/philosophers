#include "../include/philo.h"

int	main(int argc, char **argv)
{
	t_rules	*rules;

	rules = parse_input(argc, argv);
	free_all(rules);
	return (0);
}
