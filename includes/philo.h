/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhadding <operas.referee.0e@icloud.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 08:45:02 by dhadding          #+#    #+#             */
/*   Updated: 2023/12/05 16:38:32 by dhadding         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/time.h>
# include <pthread.h>
# include <stdbool.h>
# include "../source_util/includes/source_util.h"

# define EATING		5
# define THINKING	6
# define SLEEPING	7
# define REQUISITION	42
# define PROGRESSED	9
# define DISPOSE 10

typedef struct s_philos
{
	int			ego;
	int			state;
	int			fork_c;
	int			fork_id[0];
	pthread_t	id;
	bool		timeout;

} t_philos;

typedef struct s_program
{
	u64				timestamp;
	pthread_mutex_t	*forks;
	pthread_t		supervisor_id;
	char			*ts;
	char			*n;
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

/// EXIT_C ///
void	exit_philo(t_args *args);
void	free_struct(t_args *args);
void	free_philos(t_philos **philos);
void	free_program(t_program *program);

/// INIT_C ///
void	init_philos(t_args *args);
void	init_program(t_args *args);
void	init_structs(t_args *args, char **argv);

/// LIFE1_C ///
void	life(t_args *args);
void	*run(void *arg);
int		find_ego(t_args *args, pthread_t current_thread);
int		find_fork(t_args *args, int thread_ego);

/// LIFE2_C ///
void	eat(t_args *args, int thread_ego);
void	sleeper(t_args *args, int thread_ego);
void	think(t_args *args, int thread_ego);

/// MESSAGE1_C ///
void	create_message(int id, int STATE_FLAG, t_args *args);
void	print_dispose_message(t_args *args);

/// MESSAGE2_C ///
void	print_sleeping_message(t_args *args);
void	print_progression_message(t_args *args);
void	print_thinking_message(t_args *args);
void	print_requisition_message(t_args *args);
void	print_eating_message(t_args *args);

/// PARSE_C ///
int		digit(char c);
int		check_input(char **argv);

/// SUPERVISOR_C ///
void	supervisor(t_args *args);
void	*supervisor_routine(void *arg);

/// TIME_C ///
u64		get_time();
void	sleepy_bee(int milliseconds);
u64		counter(t_args *args);

#endif