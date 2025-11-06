/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafaoliv <rafaoliv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/21 19:05:23 by marvin            #+#    #+#             */
/*   Updated: 2025/10/21 19:05:23 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char **av)
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	if (ac < 2)
        return (0);
	stack_a = NULL;
	stack_b = NULL;
	stack_a = init_stack(ac, av);
	if (!stack_a)
		return (1);
	assign_index(stack_a);
	if (!is_sorted(stack_a))
	{
		if (stack_size(stack_a) <= 5)
			sort_small(&stack_a, &stack_b);
		else
			algorithm(&stack_a, &stack_b);
	}
	free_stack(stack_a);
	free_stack(stack_b);
	return (0);
}
