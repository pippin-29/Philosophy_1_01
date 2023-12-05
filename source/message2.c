/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   message2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhadding <operas.referee.0e@icloud.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 11:14:10 by dhadding          #+#    #+#             */
/*   Updated: 2023/12/05 16:36:28 by dhadding         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void print_sleeping_message(t_args *args)
{
	char *sleeping_message;	

	sleeping_message = strjoin_e(4, args->program->ts, " ",
			args->program->n, " is sleeping.");
	printf("%s\n", sleeping_message);
}

void print_progression_message(t_args *args)
{
	char *progression_message;

	progression_message = strjoin_e(4, args->program->ts, " ",
			args->program->n, " has progressed.");
	printf("%s\n", progression_message);
}

void print_thinking_message(t_args *args)
{
	char *thinking_message;

	thinking_message = strjoin_e(4, args->program->ts, " ",
			args->program->n, " is thinking.");
	printf("%s\n", thinking_message);
}

void print_requisition_message(t_args *args)
{
	char *requisition_message;

	requisition_message = strjoin_e(4, args->program->ts, " ",
			args->program->n, " has taken a fork.");
	printf("%s\n", requisition_message);
}

void print_eating_message(t_args *args)
{
	char *eating_message;

	eating_message = strjoin_e(4, args->program->ts, " ",
				args->program->n, " is eating.");
	printf("%s\n",eating_message);
}