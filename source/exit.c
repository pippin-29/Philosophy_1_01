/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhadding <operas.referee.0e@icloud.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 13:54:00 by dhadding          #+#    #+#             */
/*   Updated: 2023/12/05 16:38:45 by dhadding         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	exit_philo(t_args *args)
{
	free_struct(args);
	exit(1);
}

void	free_struct(t_args *args)
{
	free_philos(args->philos);
	free_program(args->program);
	free(args);
}

void	free_philos(t_philos **philos)
{
	int i;

	i = 0;
	while (philos[i])
		free(philos[i++]);
	free(philos);
}

void	free_program(t_program *program)
{
	free(program->ts);
	free(program->n);
	free(program);
}