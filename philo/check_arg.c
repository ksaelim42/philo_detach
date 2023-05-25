/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_arg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksaelim <ksaelim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 23:42:03 by ksaelim           #+#    #+#             */
/*   Updated: 2023/05/25 10:56:43 by ksaelim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_isdigit(char c)
{
	return (c >= '0' && c <= '9');
}

int	check_format(char **av)
{
	int	i;
	int	j;

	i = 1;
	while (av[i])
	{
		j = 0;
		if (!av[i][j])
			return (EXIT_FAILURE);
		while (av[i][j])
			if (!ft_isdigit(av[i][j++]))
				return (EXIT_FAILURE);
		i++;
	}
	return (EXIT_SUCCESS);
}

int	check_arg(int ac, char **av)
{
	if (ac != 5 && ac != 6)
		return (EXIT_FAILURE);
	if (check_format(av))
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}
