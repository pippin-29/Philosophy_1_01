/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   message2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhadding <operas.referee.0e@icloud.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 11:14:10 by dhadding          #+#    #+#             */
/*   Updated: 2023/12/05 11:21:23 by dhadding         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

char *sleeping_message(t_args *args)
{
	args->program->sleeping_message = strjoin_e(4, args->program->ts, " ",
			args->program->n, " is sleeping.");
	return (args->program->sleeping_message);
}

char *progression_message(t_args *args)
{
	args->program->progression_message = strjoin_e(4, args->program->ts, " ",
			args->program->n, " has progressed.");
	return (args->program->progression_message);
}

char *thinking_message(t_args *args)
{
	args->program->thinking_message = strjoin_e(4, args->program->ts, " ",
			args->program->n, " is thinking.");
	return(args->program->thinking_message);
}

char *requisition_message(t_args *args)
{
	args->program->requisiton_message = strjoin_e(4, args->program->ts, " ",
			args->program->n, " has taken a fork.");
	return(args->program->requisiton_message);
}

char *eating_message(t_args *args)
{
	args->program->eating_message = strjoin_e(4, args->program->ts, " ",
				args->program->n, " is eating.");
	return (args->program->eating_message);
}