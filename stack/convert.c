/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/23 20:18:32 by marvin            #+#    #+#             */
/*   Updated: 2025/10/23 20:18:32 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	overflow_atoi(const char *nptr, int *error)
{
	int	signal;
	long	res;

	*error = 0;
	signal = 1;
	res = 0;
	while (*nptr == 32 || (*nptr >= 9 && *nptr <= 13))
		nptr++;
	if (*nptr == '-' || *nptr == '+')
	{
		if (*nptr == '-')
			signal = -1;
		nptr++;
	}
	while (*nptr >= '0' && *nptr <= '9')
	{
		res = res * 10 + (*nptr++ - '0');
	if (res > (long)INT_MAX + (signal == -1))
	*error = 1;
	}
	if (*nptr != '\0')
		*error = 1;
	if (*error)
		return (0);
	return ((int)(res * signal));
}
