/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhadding <operas.referee.0e@icloud.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 10:12:06 by dhadding          #+#    #+#             */
/*   Updated: 2023/12/05 10:45:07 by dhadding         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

u64	get_timestamp_ms()
{
	long long		seconds;
	long long		useconds;
	struct timeval	fun;

	gettimeofday(&fun, NULL);
	seconds = fun.tv_sec * 1000;
	useconds = fun.tv_usec / 1000;
	return (seconds + useconds);
}