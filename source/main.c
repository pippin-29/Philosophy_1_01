/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhadding <operas.referee.0e@icloud.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 08:58:34 by dhadding          #+#    #+#             */
/*   Updated: 2023/12/05 16:01:36 by dhadding         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	main(int argc, char **argv)
{
	t_args	*args;

	args = malloc(sizeof(t_args));
	if (argc == 5 || argc == 6)
		init_structs(args, argv);
	else
		return (error_message());
	args->program->timestamp = get_time();
	life(args);
	// supervise(args);
}