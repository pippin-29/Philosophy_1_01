/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   message1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhadding <operas.referee.0e@icloud.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 10:34:44 by dhadding          #+#    #+#             */
/*   Updated: 2023/12/05 16:38:12 by dhadding         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	create_message(int id, int state, t_args *args)
{
	args->program->ts = u64_to_ascii(counter(args));
	args->program->n = u32_to_ascii(id);
	if (state == EATING)
		print_eating_message(args);
	else if (state == SLEEPING)
		print_sleeping_message(args);
	else if (state == PROGRESSED)
		print_progression_message(args);
	else if (state == THINKING)
		print_thinking_message(args);
	else if (state == REQUISITION)
		print_requisition_message(args);
	else if (state == DISPOSE)
		print_dispose_message(args);
}

void print_dispose_message(t_args *args)
{
	char *dispose_message;

	dispose_message = strjoin_e(4, args->program->ts, " ",
			args->program->n, " has dropped a fork.");
	printf("%s\n", dispose_message);
}
