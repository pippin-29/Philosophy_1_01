/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   supervisor.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhadding <operas.referee.0e@icloud.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 12:37:45 by dhadding          #+#    #+#             */
/*   Updated: 2023/12/05 16:35:40 by dhadding         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	supervisor(t_args *args)
{
	if (pthread_create(&args->program->supervisor_id, NULL,
			supervisor_routine, args) != 0)
			printf("Failed To Create Thread For Supervisor\n");

}

void	*supervisor_routine(void *arg)
{
	t_args	*args;
	int		i;

	i = 0;
	args = (t_args *)arg;
	while (1)
	{
		if (args->philos[i]->state == PROGRESSED)
		{
			create_message(args->philos[i]->ego, PROGRESSED, args);
			exit_philo(args);
		}
		i++;
	}
}