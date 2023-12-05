/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   life2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhadding <operas.referee.0e@icloud.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 14:52:46 by dhadding          #+#    #+#             */
/*   Updated: 2023/12/05 16:35:19 by dhadding         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void eat(t_args *args, int thread_ego)
{
	int one;
	int two;

	args->philos[thread_ego]->state = EATING;
	usleep(args->hunger);
	create_message(thread_ego, EATING, args);

	one = args->philos[thread_ego]->fork_id[0];
	two = args->philos[thread_ego]->fork_id[1];
	pthread_mutex_unlock(&args->program->forks[one]);
	args->philos[thread_ego]->fork_id[0] = -1;
	pthread_mutex_unlock(&args->program->forks[two]);
	args->philos[thread_ego]->fork_id[1] = -1;
}

void sleeper(t_args *args, int thread_ego)
{
	args->philos[thread_ego]->state = SLEEPING;
	create_message(thread_ego, SLEEPING, args);
	sleepy_bee(args->fatigue);
}

void	think(t_args *args, int thread_ego)
{
	args->philos[thread_ego]->state = THINKING;
	create_message(thread_ego, THINKING, args);
	while (args->philos[thread_ego]->fork_c != 2)
	{
		if (find_fork(args, thread_ego))
			args->philos[thread_ego]->fork_c++;
	}
}