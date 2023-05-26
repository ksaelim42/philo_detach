/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear_memory.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksaelim <ksaelim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 23:50:40 by ksaelim           #+#    #+#             */
/*   Updated: 2023/05/26 17:23:44 by ksaelim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	check_eat(t_philo *philo)
{
	int	index;

	index = 0;
	while (index < philo->data->n_philo)
	{
		if (philo[index].n_eated < philo->data->n_meal || \
		philo->data->n_meal == -1)
			return (0);
		index++;
	}
	return (1);
}

int	check_die(t_philo *philo)
{
	if (philo->n_eated < philo->data->n_meal || philo->data->n_meal == -1)
		return (time_diff_from_start(philo->last_meal) > philo->data->t_die);
	return (0);
}

void	check_end(t_philo *philo)
{
	int	index;

	index = 0;
	while (!philo->data->philo_end)
	{
		if (index >= philo->data->n_philo)
			index = 0;
		if (check_eat(philo))
		{	
			philo->data->philo_end = 1;
			return ;
		}
		if (check_die(&philo[index]))
		{
			philo->data->philo_end = 1;
			print_action(&philo[index], DIED);
			return ;
		}
		index++;
	}
}

void	destory_mutex(t_doctor *doctor)
{
	int	i;

	i = 0;
	while (i < doctor->data.n_philo)
		pthread_mutex_destroy(&doctor->fork[i++]);
	pthread_mutex_destroy(&doctor->data.print);
}

void	clear_memory(t_doctor *doctor)
{
	check_end(doctor->philo);
	destory_mutex(doctor);
	free (doctor->philo);
	free (doctor->fork);
}
