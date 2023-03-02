/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fschmid <fschmid@student.42heilbronn.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 14:19:10 by fschmid           #+#    #+#             */
/*   Updated: 2023/03/02 11:04:20 by fschmid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

int	main(int argc, char **argv)
{
	t_rules	*rules;
	t_philo	**philos;

	rules = parse_input(argc, argv);
	philos = NULL;
	if (!rules)
		return (1);
	philos = create_philos(rules);
	create_threads(philos);
	start_waitress(philos);
	free_all(rules, philos);
	return (0);
}
