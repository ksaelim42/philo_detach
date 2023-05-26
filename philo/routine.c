/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksaelim <ksaelim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 00:26:50 by ksaelim           #+#    #+#             */
/*   Updated: 2023/05/26 17:42:07 by ksaelim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	philo_fork_and_check_end(t_philo *philo, pthread_mutex_t *fork, int code)
{
	if (code == TAKE)
	{
		if (philo->data->philo_end || pthread_mutex_lock(&fork[philo->right]))
			return (EXIT_FAILURE);
		print_action(philo, FORK_R);
		if (philo->data->philo_end || pthread_mutex_lock(&fork[philo->left]))
			return (EXIT_FAILURE);
		print_action(philo, FORK_L);
	}
	else if (code == DROP)
	{
		if (philo->data->philo_end || pthread_mutex_unlock(&fork[philo->right]))
			return (EXIT_FAILURE);
		if (philo->data->philo_end || pthread_mutex_unlock(&fork[philo->left]))
			return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}

int	philo_eat(t_philo *philo, pthread_mutex_t *fork)
{
	if (philo_fork_and_check_end(philo, fork, TAKE))
		return (EXIT_FAILURE);
	philo->n_eated++;
	print_action(philo, EAT);
	philo->last_meal = current_time();
	if (time_use_and_check_end(philo->data->t_eat, &philo->data->philo_end))
		return (EXIT_FAILURE);
	if (philo_fork_and_check_end(philo, fork, DROP))
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

int	philo_sleep_and_think(t_philo *philo)
{
	print_action(philo, SLEEP);
	if (time_use_and_check_end(philo->data->t_sleep, &philo->data->philo_end))
		return (EXIT_FAILURE);
	print_action(philo, THINK);
	return (EXIT_SUCCESS);
}

void	*ft_routine(void *arg)
{
	int			index;
	t_doctor	*doctor;

	doctor = (t_doctor *)arg;
	index = doctor->index;
	doctor->philo[index].last_meal = doctor->data.start_time;
	while (!doctor->data.philo_end)
	{
		if (philo_eat(&doctor->philo[index], doctor->fork))
			break ;
		if (philo_sleep_and_think(&doctor->philo[index]))
			break ;
	}
	return (NULL);
}

int	create_thread(t_doctor *doctor)
{
	int	i;

	i = 0;
	doctor->data.start_time = current_time();
	while (i < doctor->data.n_philo)
	{
		doctor->index = i;
		if (pthread_create(&doctor->philo[i].t, NULL, &ft_routine, doctor))
			return (EXIT_FAILURE);
		if (pthread_detach(doctor->philo[i].t))
			return (EXIT_FAILURE);
		usleep (10);
		i += 2;
		if (i >= doctor->data.n_philo && i % 2 == 0)
		{
			i = 1;
			usleep(50);
		}
	}
	return (EXIT_SUCCESS);
}
