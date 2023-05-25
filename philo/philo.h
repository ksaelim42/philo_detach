/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksaelim <ksaelim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 01:55:01 by ksaelim           #+#    #+#             */
/*   Updated: 2023/05/25 16:39:15 by ksaelim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

//ERROR
// # define ARG_ERROR 1
// # define ALLOC_ERROR 2
// # define INIT_ERROR 3

//PHILO MESSAGE
// # define EAT 1
// # define SLEEP 2
// # define THINK 3
// # define DIED 4
// # define FORK_L 5
// # define FORK_R 6

# include <pthread.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <sys/time.h>
# include "color.h"

# define PRINT_FORK_R "has taken a fork (1/2)"
# define PRINT_FORK_L "has taken a fork (Ready!)"
# define PRINT_EAT "is eating"
# define PRINT_EAT_FULL "-- is full --"
# define PRINT_SLEEP "is sleeping"
# define PRINT_THINK "is thinking"
# define PRINT_DIE "died"

enum e_error
{
	ARG_ERROR,
	ALLOC_ERROR,
	INIT_ERROR,
};

enum e_philo_status
{
	EAT,
	SLEEP,
	THINK,
	FORK_L,
	FORK_R,
	DIED,
};

enum e_fork_stats
{
	TAKE,
	DROP,
};

typedef struct s_data
{
	int		n_philo;
	int		t_die;
	int		t_eat;
	int		t_sleep;
	int		n_meal;
	int		philo_died;
	long	start_time;
	pthread_mutex_t	print;
}	t_data;

typedef struct s_philo
{
	int			id;
	pthread_t	t;
	int			left;
	int			right;
	int			n_eated;
	long		last_meal;
	t_data		*data;
}	t_philo;

typedef struct s_doctor
{
	int				index;
	t_philo			*philo;
	t_data			data;
	pthread_mutex_t	*fork;
}	t_doctor;

int		check_arg(int ac, char **av);
int		ft_init(t_doctor *doctor, int ac, char **av);
int		create_thread(t_doctor *doctor);
void	clear_memory();
int		print_action(t_philo *philo, int code);
int		ft_perror(int code);
long	time_diff_from_start(long start);
long	current_time(void);
int		time_use_and_check_die(long time_use, int *died);

#endif
