/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksaelim <ksaelim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 00:29:46 by ksaelim           #+#    #+#             */
/*   Updated: 2023/05/25 16:41:48 by ksaelim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_perror(int code)
{
	if (code == ARG_ERROR)
	{
		printf(FRED"Error:	"NONE);
		printf(FWHITE"Invalid argument(s)!\n"NONE);
		printf(FYELLOW"Usage:"NONE);
		printf(FWHITE"	./philo [num of philo] [time to die] [time to eat] ");
		printf("[time to sleep] {option: num of meal}\n"NONE);
	}
	return (EXIT_FAILURE);
}

int	print_action(t_philo *philo, int code)
{
	long	time;

	pthread_mutex_lock(&philo->data->print);
	time = time_diff_from_start(philo->data->start_time);
	printf(BWHITE"\t %ld "NONE FPURPLE"ms\t\t", time_diff_from_start(philo->data->start_time));
	if (code == EAT)
	{
		if (philo->n_eated < philo->data->n_meal || philo->data->n_meal == -1)
			printf(FWHITE"[%d]" FGREEN" %s", philo->id, PRINT_EAT);
		else if (philo->n_eated == philo->data->n_meal)
		{
			printf(FWHITE"[%d]" FGREEN" %s\n"NONE, philo->id, PRINT_EAT_FULL);
			return (EXIT_FAILURE);
		}
	}
	else if (code == SLEEP)
		printf(FWHITE"[%d]" FCYAN" %s", philo->id, PRINT_SLEEP);
	else if (code == THINK)
		printf(FWHITE"[%d]" PINK" %s", philo->id, PRINT_THINK);
	else if (code == FORK_R)
		printf(FWHITE"[%d]" SYELLOW" %s", philo->id, PRINT_FORK_R);
	else if (code == FORK_L)
		printf(FWHITE"[%d]" FYELLOW" %s", philo->id, PRINT_FORK_L);
	else if (code == DIED)
		printf(FWHITE"[%d]" FRED" %s"NONE, philo->id, PRINT_DIE);
	printf("\n");
	pthread_mutex_unlock(&philo->data->print);
	return (EXIT_SUCCESS);
}