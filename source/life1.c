/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   life1.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhadding <operas.referee.0e@icloud.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 12:42:15 by dhadding          #+#    #+#             */
/*   Updated: 2023/12/05 16:40:37 by dhadding         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	life(t_args *args)
{
	int	i;

	i = 0;
 	while (args->philos[i])
	{
		if (pthread_create(&args->philos[i]->id, NULL, run, args) != 0)
		{
			printf("Failed To Create Thread For Philosopher %d\n",
					args->philos[i]->ego);
		}
		if (i % 2)
			sleepy_bee(10);
		i++;
	}
}

void	*run(void *arg)
{
	t_args *args;
	int	thread_ego;
	pthread_t current_thread;

	current_thread = pthread_self();
	args = (t_args *)arg;
	thread_ego = find_ego(args, current_thread);
	while (1)
	{
		think(args, thread_ego);
		eat(args, thread_ego);
		sleeper(args, thread_ego);
	}
	return NULL;
}

int	find_ego(t_args *args, pthread_t current_thread)
{
	int	i;

	i = 0;
	while (i < args->num_of_philos)
	{
		if (pthread_equal(current_thread, args->philos[i]->id))
			return (i + 1);
		i++;
	}
	printf("Thread_IDs not present.\n");
	exit_philo(args);
	return (-1);
}

int	find_fork(t_args *args, int thread_ego)
{
	int i;

	i = 0;
	while (1)
	{
		if (pthread_mutex_trylock(&args->program->forks[i]) == 0)
		{
			create_message(thread_ego, REQUISITION, args);
			if (args->philos[thread_ego]->fork_id[0] == -1)
				args->philos[thread_ego]->fork_id[0] = i;
			else if (args->philos[thread_ego]->fork_id[1] == -1)
				args->philos[thread_ego]->fork_id[1] = i;
			return (1);
		}
		i++;
		if (i == args->num_of_philos)
			i = 0;
	}
	return(0);
}

