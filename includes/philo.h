/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhadding <operas.referee.0e@icloud.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 08:45:02 by dhadding          #+#    #+#             */
/*   Updated: 2023/12/05 11:23:14 by dhadding         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/time.h>
# include <pthread.h>
# include "source_util.h"

# define EATING 5
# define THINKING 6
# define SLEEPING 7
# define WAITING 8
# define PROGRESSED 9

typedef struct s_philos
{
	int	id;
	int state;
	int fork_c;

} t_philos;

typedef struct s_program
{
	long long	timestamp;
	char		*progression_message;
	char		*eating_message;
	char		*sleeping_message;
	char		*thinking_message;
	char		*requisiton_message;
	char		*ts;
	char		*n;
} t_program;

typedef struct s_args
{
	int			num_of_philos;
	int			lifetime_in_ms;
	int			hunger;
	int			fatigue;
	int			goal;
	t_philos	**philos;
	t_program	*program;
} t_args;

/// ERROR_C///
int		error_message(void);

/// INIT_C ///
void	init_philos(t_args *args);
void	init_program(t_args *args);
void	init_structs(t_args *args, char **argv);

/// MESSAGE1_C ///
char	*create_message(int id, int STATE_FLAG, t_args *args);

/// MESSAGE2_C ///
char	*sleeping_message(t_args *args);
char	*progression_message(t_args *args);
char	*thinking_message(t_args *args);
char	*requisition_message(t_args *args);
char	*eating_message(t_args *args);

/// PARSE_C ///
int		digit(char c);
int		check_input(char **argv);
int		ascii_2_int(char *str);

/// TIME_C ///
u64		get_timestamp_ms();

#endif