/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/21 19:05:20 by marvin            #+#    #+#             */
/*   Updated: 2025/10/21 19:05:20 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	**parse_args(int ac, char **av)
{
	char	**numbers;

	if (ac == 2)
		numbers = ft_split(av[1], ' ');
	else
		numbers = av + 1;
	return (numbers);
}

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
	int	value_i;
	int	value_j;
	int	error;
	int	i;
	int	j;

	i = 0;
	while (numbers[i])
	{
		value_i = overflow_atoi(numbers[i], &error);
		if (error)
			return (0);
		j = i + 1;
		while(numbers[j])
		{
			value_j = overflow_atoi(numbers[j], &error);
			if (error)
				return (0);
			if (value_i == value_j)
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}
