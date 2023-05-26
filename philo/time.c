/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksaelim <ksaelim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 00:08:15 by ksaelim           #+#    #+#             */
/*   Updated: 2023/05/26 11:19:22 by ksaelim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

long	current_time(void)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	return ((time.tv_sec * 1000) + (time.tv_usec / 1000));
}

long	time_diff_from_start(long start)
{
	return (current_time() - start);
}

int	time_use_and_check_end(long time_use, int *end)
{
	long	start_time;

	start_time = current_time();
	while (!(*end) && current_time() - start_time < time_use)
		usleep(200);
	return (*end);
}