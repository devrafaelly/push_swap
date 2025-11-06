/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafaoliv <rafaoliv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/21 19:05:20 by marvin            #+#    #+#             */
/*   Updated: 2025/10/21 19:05:20 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_stack	*build_stack(char **numbers)
{
	t_stack	*stack;
	t_stack	*node;
	int	i;

	stack = NULL;
	i = 0;
	while (numbers[i])
	{
		node = new_stack_node(ft_atoi(numbers[i]));
		if (!node)
		{
			free_stack(&stack);
			return (NULL);
		}
		stack_add_back(&stack, node);
		i++;
	}
	return (stack);
}

t_stack	*init_stack(int ac, char **av)
{
	t_stack	*stack;
	char	**numbers;

	if (ac <= 1)
		return (NULL);
	numbers = parse_args(ac, av);
	if (!numbers)
		return (NULL);
	if (!is_valid_number(numbers))
		return (error());
	if (!check_duplicates(numbers))
		return (error());
	stack = build_stack(numbers);
	if (ac == 2)
		numbers = memory_cleaner(numbers, 1);
	return (stack);
}
