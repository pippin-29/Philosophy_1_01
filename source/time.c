/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhadding <operas.referee.0e@icloud.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 10:12:06 by dhadding          #+#    #+#             */
/*   Updated: 2023/12/05 16:02:29 by dhadding         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

u64 get_time(void) {
    struct timeval time;
    if (gettimeofday(&time, NULL) == -1)
        return 0;
    return (time.tv_sec * (u64)1000) + (time.tv_usec / 1000);
}

u64 counter(t_args *args) {
    u64 now = get_time();
    u64 elapsed = now - args->program->timestamp;

    return elapsed;
}

void sleepy_bee(int milliseconds)
{
	usleep(milliseconds * 1000);
}