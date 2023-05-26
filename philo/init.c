/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksaelim <ksaelim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 23:15:21 by ksaelim           #+#    #+#             */
/*   Updated: 2023/05/26 17:08:13 by ksaelim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	ft_atoi(char *s)
{
	long	num;

	num = 0;
	while (*s)
		num = (num * 10) + (*s++ - '0');
	if (num > 2147483647)
	{
		ft_perror(ARG_ERROR);
		exit(1);
	}
	return (num);
}

void	init_data(t_data *data, int ac, char **av)
{
	data->n_philo = ft_atoi(av[1]);
	data->t_die = ft_atoi(av[2]);
	data->t_eat = ft_atoi(av[3]);
	data->t_sleep = ft_atoi(av[4]);
	if (ac == 6)
		data->n_meal = ft_atoi(av[5]);
	else
		data->n_meal = -1;
	data->philo_end = 0;
}

t_philo	*init_philo(t_data *data)
{
	int		i;
	t_philo	*philo;

	philo = NULL;
	philo = malloc(sizeof(t_philo) * data->n_philo);
	if (!philo)
		return (NULL);
	i = -1;
	while (++i < data->n_philo)
	{
		philo[i].id = i + 1;
		philo[i].n_eated = 0;
		philo[i].data = data;
		philo[i].left = i;
		philo[i].right = (i + 1) % data->n_philo;
	}
	return (philo);
}

pthread_mutex_t	*init_fork(t_data *data)
{
	int				i;
	pthread_mutex_t	*fork;

	fork = malloc(sizeof(pthread_mutex_t) * data->n_philo);
	if (!fork)
		return (NULL);
	i = 0;
	while (i < data->n_philo)
		pthread_mutex_init(&fork[i++], NULL);
	return (fork);
}

int	ft_init(t_doctor *doctor, int ac, char **av)
{
	init_data(&doctor->data, ac, av);
	if (!doctor->data.n_philo || !doctor->data.t_die)
		return (ft_perror(ZERO));
	doctor->philo = init_philo(&doctor->data);
	if (!doctor->philo)
		return (EXIT_FAILURE);
	doctor->fork = init_fork(&doctor->data);
	if (!doctor->philo)
		return (EXIT_FAILURE);
	pthread_mutex_init(&doctor->data.print, NULL);
	return (EXIT_SUCCESS);
}
