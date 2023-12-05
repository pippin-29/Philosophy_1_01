/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhadding <operas.referee.0e@icloud.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 10:05:39 by dhadding          #+#    #+#             */
/*   Updated: 2023/12/05 16:35:31 by dhadding         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	init_philos(t_args *args)
{
	int	i;

	i = 0;
	args->philos = malloc(sizeof(t_philos) * (args->num_of_philos + 1));
	while (i < args->num_of_philos)
	{
		args->philos[i] = malloc(sizeof(t_philos));
		args->philos[i]->fork_c = 0;
		args->philos[i]->fork_id[0] = -1;
		args->philos[i]->fork_id[1] = -1;
		args->philos[i]->state = 0;
		args->philos[i]->ego = i + 1;
		i++;
	}
	args->philos[i] = NULL;
}

void	init_program(t_args *args)
{
	int i;

	i = 0;
	args->program = malloc(sizeof(t_program));
	args->program->forks = malloc(sizeof(pthread_mutex_t) * args->num_of_philos);
	while (i < args->num_of_philos)
		pthread_mutex_init(&args->program->forks[i++], NULL);

	args->program->n = NULL;
	args->program->ts = NULL;
	args->program->timestamp = 0;
}

void	init_structs(t_args *args, char **argv)
{
	check_input(&argv[1]);
	args->num_of_philos = ascii_2_int(argv[1]);
	args->lifetime_in_ms = ascii_2_int(argv[2]);
	args->hunger = ascii_2_int(argv[3]);
	args->fatigue = ascii_2_int(argv[4]);
	if (argv[5])
		args->goal = ascii_2_int(argv[5]);
	init_program(args);
	init_philos(args);
}