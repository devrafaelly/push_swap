/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_input.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/05 21:51:11 by codespace         #+#    #+#             */
/*   Updated: 2025/11/05 22:11:54 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_valid_number(char **numbers)
{
	int	i;
	int	j;

	i = 0;
	while (numbers[i])
	{
		j = 0;
		if (numbers[i][j] == '-' || numbers[i][j] == '+')
				j++;
		if (!numbers[i][j])
			return (0);
		while (numbers[i][j])
		{
			if (!isdigit(numbers[i][j]))
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	check_duplicates(char **numbers)
{
	long	value_i;
	long	value_j;
	int	i;
	int	j;

	i = 0;
	while (numbers[i])
	{
		value_i = ft_atol(numbers[i]);
		if (value_i > INT_MAX || value_i < INT_MIN)
			return (0);
		j = i + 1;
		while(numbers[j])
		{
			value_j = ft_atol(numbers[j]);
		    if (value_j > INT_MAX || value_j < INT_MIN)
			    return (0);
			if (value_i == value_j)
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}
