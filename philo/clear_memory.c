/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear_memory.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksaelim <ksaelim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 23:50:40 by ksaelim           #+#    #+#             */
/*   Updated: 2023/05/25 16:42:56 by ksaelim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	check_die(t_philo *philo)
{
	int	index;

	index = 0;
	while (!philo->data->philo_died)
	{
		if (index >= philo->data->n_meal)
			index = 0;
		if (time_diff_from_start(philo[index].last_meal) > philo->data->t_die)
		{
			philo->data->philo_died = 1;
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
	check_die(doctor->philo);
	destory_mutex(doctor);
	free (doctor->philo);
	free (doctor->fork);
}
