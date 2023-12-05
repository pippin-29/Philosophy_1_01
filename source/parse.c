/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhadding <operas.referee.0e@icloud.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 10:06:19 by dhadding          #+#    #+#             */
/*   Updated: 2023/12/05 11:35:51 by dhadding         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	check_input(char **argv)
{
	int	i;
	int	j;

	i = 0;
	while (argv[i])
	{
		j = 0;
		while (argv[i][j])
		{
			if (!digit(argv[i][j]))
			{
				error_message();
				exit(1);
			}
			j++;
		}
		i++;
	}
	return (1);
}