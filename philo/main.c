/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksaelim <ksaelim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 01:53:32 by ksaelim           #+#    #+#             */
/*   Updated: 2023/05/25 16:04:35 by ksaelim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int ac, char **av)
{
	t_doctor	doctor;

	if (check_arg(ac, av))
		return (ft_perror(ARG_ERROR));
	if (ft_init(&doctor, ac, av))
		return (EXIT_FAILURE);
	if (create_thread(&doctor))
		return (EXIT_FAILURE);
	clear_memory(&doctor);
	return (EXIT_SUCCESS);
}