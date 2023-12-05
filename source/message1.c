/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   message1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhadding <operas.referee.0e@icloud.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 10:34:44 by dhadding          #+#    #+#             */
/*   Updated: 2023/12/05 11:21:04 by dhadding         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

char	*create_message(int id, int state, t_args *args)
{
	args->program->ts = u64_to_ascii(args->program->timestamp);
	args->program->n = u32_to_ascii(id);
	if (state = EATING)
		return (eating_message(args));
	else if (state = SLEEPING)
		return(sleeping_message(args));
	else if (state = PROGRESSED)
		return (progression_message(args));
	else if (state = THINKING)
		return (thinking_message(args));
	return (NULL);
}

