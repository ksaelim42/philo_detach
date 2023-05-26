/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksaelim <ksaelim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 00:29:46 by ksaelim           #+#    #+#             */
/*   Updated: 2023/05/26 16:57:51 by ksaelim          ###   ########.fr       */
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
	if (code == ZERO)
	{
		printf(SBROWN"that argument shoud not be zero\n"NONE);
	}
	return (EXIT_FAILURE);
}

void	print_action(t_philo *philo, int code)
{
	long	time;

	pthread_mutex_lock(&philo->data->print);
	time = time_diff_from_start(philo->data->start_time);
	printf(BWHITE"\t %ld "NONE FPURPLE"ms\t\t", time_diff_from_start(philo->data->start_time));
	if (code == EAT)
		printf(FWHITE"[%d]" FGREEN" is eating", philo->id);
	else if (code == SLEEP)
		printf(FWHITE"[%d]" FCYAN" is sleeping", philo->id);
	else if (code == THINK)
		printf(FWHITE"[%d]" PINK" is thinking", philo->id);
	else if (code == FORK_R)
		printf(FWHITE"[%d]" SYELLOW" has taken a fork (1/2)", philo->id);
	else if (code == FORK_L)
		printf(FWHITE"[%d]" FYELLOW" has taken a fork (Ready!)", philo->id);
	else if (code == DIED)
		printf(FWHITE"[%d]" FRED" died"NONE, philo->id);
	printf("\n");
	pthread_mutex_unlock(&philo->data->print);
}